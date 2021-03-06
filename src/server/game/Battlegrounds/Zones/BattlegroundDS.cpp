/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Battleground.h"
#include "BattlegroundDS.h"
#include "Language.h"
#include "Player.h"
#include "Object.h"
#include "ObjectMgr.h"
#include "WorldPacket.h"

BattlegroundDS::BattlegroundDS()
{
    m_BgObjects.resize(BG_DS_OBJECT_MAX);

    m_StartDelayTimes[BG_STARTING_EVENT_FIRST]  = BG_START_DELAY_1M;
    m_StartDelayTimes[BG_STARTING_EVENT_SECOND] = BG_START_DELAY_30S;
    m_StartDelayTimes[BG_STARTING_EVENT_THIRD]  = BG_START_DELAY_15S;
    m_StartDelayTimes[BG_STARTING_EVENT_FOURTH] = BG_START_DELAY_NONE;
    //we must set messageIds
    m_StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_ARENA_ONE_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_ARENA_THIRTY_SECONDS;
    m_StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_ARENA_FIFTEEN_SECONDS;
    m_StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_ARENA_HAS_BEGUN;
}

BattlegroundDS::~BattlegroundDS()
{

}

void BattlegroundDS::Update(uint32 diff)
{
    Battleground::Update(diff);
if (GetStatus() == STATUS_IN_PROGRESS)
    {
        // first knockback
        if(m_uiKnockback < diff && KnockbackCheck)
        {
            //dalaran sewers = 617;
            for(BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
            {
                Player * plr = sObjectMgr.GetPlayer(itr->first);
                if (plr && plr->GetDistance2d(1214, 765) <= 50 && plr->GetPositionZ() > 10)
                    plr->KnockBackPlayerWithAngle(6.40f, 35, 5);
                if (plr && plr->GetDistance2d(1369, 817) <= 50 && plr->GetPositionZ() > 10)
                    plr->KnockBackPlayerWithAngle(3.03f, 35, 5);
            }
            KnockbackCheck = false;

        }else m_uiKnockback -= diff;

        // just for sure if knockback wont work from any reason teleport down
        if(m_uiTeleport < diff && TeleportCheck)
        {
            //dalaran sewers = 617;
            for(BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
            {
                Player * plr = sObjectMgr.GetPlayer(itr->first);
                if (plr && plr->GetDistance2d(1214, 765) <= 50 && plr->GetPositionZ() > 10)
                    plr->TeleportTo(617, 1257+urand(0,2), 761+urand(0,2), 3.2f, 0.5f);
                if (plr && plr->GetDistance2d(1369, 817) <= 50 && plr->GetPositionZ() > 10)
                    plr->TeleportTo(617, 1328+urand(0,2), 815+urand(0,2), 3.2f, 3.5f);
            }
            TeleportCheck = false;
            // close the gate
        }else m_uiTeleport -= diff;
		}

    if (getWaterFallTimer() < diff)
    {
        if (isWaterFallActive())
        {
            setWaterFallTimer(urand(BG_DS_WATERFALL_TIMER_MIN, BG_DS_WATERFALL_TIMER_MAX));
            for (uint32 i = BG_DS_OBJECT_WATER_1; i <= BG_DS_OBJECT_WATER_2; ++i)
                SpawnBGObject(i, getWaterFallTimer());
            setWaterFallActive(false);
        }
        else
        {
            setWaterFallTimer(BG_DS_WATERFALL_DURATION);
            for (uint32 i = BG_DS_OBJECT_WATER_1; i <= BG_DS_OBJECT_WATER_2; ++i)
                SpawnBGObject(i, RESPAWN_IMMEDIATELY);
            setWaterFallActive(true);
        }
    }
    else
        setWaterFallTimer(getWaterFallTimer() - diff);
}

void BattlegroundDS::StartingEventCloseDoors()
{
    for (uint32 i = BG_DS_OBJECT_DOOR_1; i <= BG_DS_OBJECT_DOOR_2; ++i)
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);
}

void BattlegroundDS::StartingEventOpenDoors()
{
    for (uint32 i = BG_DS_OBJECT_DOOR_1; i <= BG_DS_OBJECT_DOOR_2; ++i)
        DoorOpen(i);

    for (uint32 i = BG_DS_OBJECT_BUFF_1; i <= BG_DS_OBJECT_BUFF_2; ++i)
        SpawnBGObject(i, 60);

    setWaterFallTimer(urand(BG_DS_WATERFALL_TIMER_MIN, BG_DS_WATERFALL_TIMER_MAX));
    setWaterFallActive(false);

    for (uint32 i = BG_DS_OBJECT_WATER_1; i <= BG_DS_OBJECT_WATER_2; ++i)
        SpawnBGObject(i, getWaterFallTimer());
}

void BattlegroundDS::AddPlayer(Player *plr)
{
    Battleground::AddPlayer(plr);
    //create score and add it to map, default values are set in constructor
    BattlegroundDSScore* sc = new BattlegroundDSScore;

    m_PlayerScores[plr->GetGUID()] = sc;

    UpdateArenaWorldState();
}

void BattlegroundDS::RemovePlayer(Player * /*plr*/, uint64 /*guid*/)
{
    if (GetStatus() == STATUS_WAIT_LEAVE)
        return;

    UpdateArenaWorldState();
    CheckArenaWinConditions();
}

void BattlegroundDS::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    if (!killer)
    {
        sLog.outError("BattlegroundDS: Killer player not found");
        return;
    }

    Battleground::HandleKillPlayer(player,killer);

    UpdateArenaWorldState();
    CheckArenaWinConditions();
}

void BattlegroundDS::HandleAreaTrigger(Player *Source, uint32 Trigger)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    switch(Trigger)
    {
        case 5347:
        case 5348:
            break;
        default:
            sLog.outError("WARNING: Unhandled AreaTrigger in Battleground: %u", Trigger);
            Source->GetSession()->SendAreaTriggerMessage("Warning: Unhandled AreaTrigger in Battleground: %u", Trigger);
			if (Source->GetTeam() == ALLIANCE)
				Source->TeleportTo(617, 1257+urand(0,2), 761+urand(0,2), 3.2f, 0.5f);
			else
				Source->TeleportTo(617, 1328+urand(0,2), 815+urand(0,2), 3.2f, 3.5f);
            break;
    }
}

bool BattlegroundDS::HandlePlayerUnderMap(Player *player)
{
    player->TeleportTo(GetMapId(), 1299.046, 784.825, 9.338, 2.422, false);
    return true;
}

void BattlegroundDS::FillInitialWorldStates(WorldPacket &data)
{
    data << uint32(3610) << uint32(1);                                              // 9 show
    UpdateArenaWorldState();
}

void BattlegroundDS::Reset()
{
    //call parent's class reset
    Battleground::Reset();
    m_uiTeleport = 5000;
    TeleportCheck = true;
    m_uiKnockback = 3000;
    KnockbackCheck = true;
}


bool BattlegroundDS::SetupBattleground()
{
    // gates
    if (!AddObject(BG_DS_OBJECT_DOOR_1, BG_DS_OBJECT_TYPE_DOOR_1, 1350.95, 817.2, 20.8096, 3.15, 0, 0, 0.99627, 0.0862864, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_DS_OBJECT_DOOR_2, BG_DS_OBJECT_TYPE_DOOR_2, 1232.65, 764.913, 20.0729, 6.3, 0, 0, 0.0310211, -0.999519, RESPAWN_IMMEDIATELY)
    // water
        || !AddObject(BG_DS_OBJECT_WATER_1, BG_DS_OBJECT_TYPE_WATER_1, 1291.56, 790.837, 7.1, 3.14238, 0, 0, 0.694215, -0.719768, 120)
        || !AddObject(BG_DS_OBJECT_WATER_2, BG_DS_OBJECT_TYPE_WATER_2, 1291.56, 790.837, 7.1, 3.14238, 0, 0, 0.694215, -0.719768, 120)
    // buffs
        || !AddObject(BG_DS_OBJECT_BUFF_1, BG_DS_OBJECT_TYPE_BUFF_1, 1291.7, 813.424, 7.11472, 4.64562, 0, 0, 0.730314, -0.683111, 120)
        || !AddObject(BG_DS_OBJECT_BUFF_2, BG_DS_OBJECT_TYPE_BUFF_2, 1291.7, 768.911, 7.11472, 1.55194, 0, 0, 0.700409, 0.713742, 120))
    {
        sLog.outErrorDb("BatteGroundDS: Failed to spawn some object!");
        return false;
    }

    return true;
}
