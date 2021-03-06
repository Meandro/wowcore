/*
 * Copyright (C) 2009-2010 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "ScriptPCH.h"
#include "trial_of_the_crusader.h"

enum DeathKnightSpells
{
        N_10_SPELL_FROST_STRIKE         = 66047,
        N_25_SPELL_FROST_STRIKE         = 67935,
        H_10_SPELL_FROST_STRIKE         = 67936,
        H_25_SPELL_FROST_STRIKE         = 67937,
        N_10_SPELL_DEATH_COIL           = 66019,
        N_25_SPELL_DEATH_COIL           = 67929,
        H_10_SPELL_DEATH_COIL           = 67930,
        H_25_SPELL_DEATH_COIL           = 67931,
        N_10_SPELL_ICY_TOUCH            = 66021,
        N_25_SPELL_ICY_TOUCH            = 67938,
        H_10_SPELL_ICY_TOUCH            = 67939,
        H_25_SPELL_ICY_TOUCH            = 67940,
    SPELL_CHAINS_OF_ICE         = 66020,
    SPELL_ICEBOUND_FORTITUDE    = 66023,
    SPELL_STRANGULATE           = 66018,
    SPELL_DEATH_GRIP            = 68755,
};

enum WarriorSpells
{
        N_10_SPELL_MORTAL_STRIKE        = 65926,
    N_25_SPELL_MORTAL_STRIKE    = 68782,
        H_10_SPELL_MORTAL_STRIKE        = 68783,
        H_25_SPELL_MORTAL_STRIKE        = 68784,
    SPELL_BLADESTORM                    = 63784,
    SPELL_INTERCEPT                             = 67540,
    SPELL_ROLLING_THROW                 = 67546,
        SPELL_CHARGE                            = 68764,
        SPELL_DISARM                            = 65935,
        SPELL_INTIMIDATING_SHOUT        = 65930,
        SPELL_RETALATION                        = 65932,
        SPELL_SHATTERING_THROW          = 65940,
        SPELL_SUNDER_ARMOR                      = 65936,
};

enum MageSpells
{
        N_10_SPELL_ARCANE_BARRAGE       =       65799,
        N_25_SPELL_ARCANE_BARRAGE       =       67994,
        H_10_SPELL_ARCANE_BARRAGE       =       67995,
        H_25_SPELL_ARCANE_BARRAGE       =       67996,
        N_10_SPELL_ARCANE_BLAST         =       65791,
        N_25_SPELL_ARCANE_BLAST         =       67997,
        H_10_SPELL_ARCANE_BLAST         =       67998,
        H_25_SPELL_ARCANE_BLAST         =       67999,
        N_10_SPELL_ARCANE_EXPLOSION     =       65800,
        N_25_SPELL_ARCANE_EXPLOSION     =       65800,
        H_10_SPELL_ARCANE_EXPLOSION     =       65801,
        H_25_SPELL_ARCANE_EXPLOSION     =       65802,
        N_10_SPELL_FROSTBOLT            =       65807,
        N_25_SPELL_FROSTBOLT            =       68003,
        H_10_SPELL_FROSTBOLT            =       68004,
        H_25_SPELL_FROSTBOLT            =       68005,
        SPELL_BLINK                                     =       65793,
        SPELL_COUNTER_SPELL                     =       65790,
        SPELL_FROST_NOVA                        =       65792,
        SPELL_POLYMORPH                         =       65801,
        SPELL_ICE_BLOCK                         =       65802,
};

enum HealShamanenSpells
{
        SPELL_CLEANSE_SPIRIT                    =       66056,
        SPELL_EARTH_SHIELD                              =       66063,
        SPELL_HEROISM                                   =       65983,
        SPELL_HEX                                               =       66054,
        N_10_SPELL_LESSER_HEALING_WAVE  =       66055,
        N_25_SPELL_LESSER_HEALING_WAVE  =       68115,
        H_10_SPELL_LESSER_HEALING_WAVE  =       68116,
        H_25_SPELL_LESSER_HEALING_WAVE  =       68117,
        N_10_SPELL_RIPTIDE                              =       66053,
        N_25_SPELL_RIPTIDE                              =       68118,
        H_10_SPELL_RIPTIDE                              =       68119,
        H_25_SPELL_RIPTIDE                              =       68120,
        N_10_SPELL_EARTH_SHOCK                  =       65973,
        N_25_SPELL_EARTH_SHOCK                  =       68100,
        H_10_SPELL_EARTH_SHOCK                  =       68101,
        H_25_SPELL_EARTH_SHOCK                  =       68102,
};

enum HunterSpells
{
        N_10_SPELL_AIMED_SHOOT                  =       65883,
        N_25_SPELL_AIMED_SHOOT                  =       67977,
        H_10_SPELL_AIMED_SHOOT                  =       67978,
        H_25_SPELL_AIMED_SHOOT                  =       67979,
        N_10_SPELL_EXPLOSIV_SHOOT               =       65866,
        N_25_SPELL_EXPLOSIV_SHOOT               =       67983,
        H_10_SPELL_EXPLOSIV_SHOOT               =       67984,
        H_25_SPELL_EXPLOSIV_SHOOT               =       67985,
        SPELL_FROST_TRAP                                =       65880,
        SPELL_SHOOT                                             =       65868,
        SPELL_STEADY_SHOOT                              =       65867,
        SPELL_WING_CLIP                                 =       66207,
        SPELL_WYVERN_STING                              =       65877,
        SPELL_CALL_PET                                  =       67777,
        SPELL_DETERRENCE                                =       65871,
        SPELL_DIESENGAGE                                =       65869,
};

enum RogueSpells
{
        N_10_SPELL_EVISCERATE                   =       65957,
        N_25_SPELL_EVISCERATE                   =       68094,
        H_10_SPELL_EVISCERATE                   =       68095,
        H_25_SPELL_EVISCERATE                   =       68096,
        SPELL_BLADE_FLURRY                              =       65956,
        SPELL_BLIND                                             =       65960,
        SPELL_CLOAK_OF_SHADOW                   =       65961,
        SPELL_FAN_OF_KNIVES                             =       65955,
        SPELL_HEMORRHAGE                                =       65954,
        SPELL_SHADOW_STEP                               =       68760,
};

enum RetroPaladinSpells
{
        SPELL_AVENGING_WRATH                    = 66011,
        SPELL_CRUSUADER_STRIKE                  = 66003,
        SPELL_DIVINE_SHIELD                             = 66010,
        SPELL_DIVINE_STORM                              = 66006,
        SPELL_HUMMER_OF_JUSTICE                 = 66007,
        SPELL_HAND_OF_PROTECTION                = 66009,
        SPELL_JUNDGEMENT_OF_COMMAND             = 68019,
        SPELL_REPENTANCE                                = 66008,
        SPELL_SEAL_OF_COMMAND                   = 68021,
};

enum HolyPaladinSpells
{
        SPELL_CLEANCE                = 68623,
    SPELL_FLASH_OF_LIGHT         = 68010,
    SPELL_HAND_OF_FREEDOM        = 68758,
    SPELL_HOLY_LIGHT             = 68012,
    SPELL_HOLY_SHOCK             = 68016,
};

enum BalanceDruidSpells
{
        SPELL_BARKSKIN              = 65860,
    SPELL_CYCLONE               = 65859,
    SPELL_ENTANGLING_ROOTS      = 65857,
        SPELL_FAERIE_FIRE           = 65863,
        SPELL_FORCE_OF_NATURE       = 65861,
        SPELL_INSECT_SWARM          = 67943,
        SPELL_MOONFIRE              = 67946,
        SPELL_STARFIRE              = 67949,
        SPELL_WRATH                 = 67952,
};

enum RestorDruidSpells
{
        SPELL_LIFEBLOOM             = 67959,
    SPELL_NATURE_GRASP          = 66071,
    SPELL_NOURISH               = 67967,
    SPELL_REGROWTH              = 67970,
    SPELL_REJUVENATION          = 67973,
    SPELL_THORNS                = 66068,
    SPELL_TRANQUILITY           = 67976,
};

enum RestorShamanenSpells
{
        //SPELL_CLEANSE_SPIRIT          = 68629,
    SPELL_EARTH_SHIRLD                  = 66063,
    SPELL_EARTH_SHOCK                   = 68102,
//  SPELL_HEROISM                               = 65983,
//   SPELL_HEX                                  = 66054,
    SPELL_LESSER_HEALING_WAVE   = 68116,
    SPELL_RIPTIDE                               = 68120,
};

enum DisziPriestSpells
{
        SPELL_DISPELL_MAGIC                     = 68626,
    SPELL_FLASH_HEAL                    = 68024,
    SPELL_MANA_BURN                             = 68028,
    SPELL_PENANCE                               = 68030,
    SPELL_POWER_WORLD_SHIELD    = 68034,
    SPELL_RSYCHIC_SCREAM                = 65543,
    SPELL_RENEW                                 = 68037,
};

enum ShadowPriestSpells
{
        SPELL_DISPERSION                        = 65544,
    SPELL_MIND_BLAST                    = 68040,
    SPELL_MIND_FLAY                             = 68044,
    SPELL_PSYCHIC_HORROR                = 65545,
    SPELL_SHADOW_WORLD_PAIN             = 68089,
    SPELL_SILENCE                               = 65542,
    SPELL_VAMPIRIC_TOUCH                = 68092,
};

enum WarlockSpells
{
        SPELL_CORRUPTION                        = 68135,
        SPELL_CURSE_OF_AGONY            = 68138,
        SPELL_CURSE_OF_EXHAUSTION       = 65815,
        SPELL_DEATH_COIL_W          = 68139,
        SPELL_FEAR                                      = 65809,
        SPELL_HELLFIRE                          = 68147,
        SPELL_SEARING_PAIN                      = 68150,
        SPELL_SHADOW_BOLT                       = 68152,
        SPELL_UNSTABLE_AFFLICTION       = 68155
};

//m_creature->ModifyPower(POWER_MANA, 1000);

enum HardmodeSpells
{
        SPELL_PVP_TRINKET                       = 65547,
};

/********************************/
/* Gorgrim Shadowcleave - 34458 */
/* Death Knight                 */
/********************************/

class boss_gorgrim_shadowcleave : public CreatureScript
{
public:
    boss_gorgrim_shadowcleave() : CreatureScript("boss_gorgrim_shadowcleave") { }

    struct boss_gorgrim_shadowcleaveAI : public ScriptedAI
    {
        boss_gorgrim_shadowcleaveAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                    m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

        void Reset()
        {
        }

            void KilledUnit(Unit* who)
            {
                    if(!m_pInstance)
                            return;
            }

            void EnterCombat(Unit* pWho)
        {
        }

            void JustDied(Unit* pKiller)
        {
                    if(!m_pInstance)
                            return;

            if(!me->FindNearestCreature(34458, 200, true)
                    && !me->FindNearestCreature(34451, 200, true)
                    && !me->FindNearestCreature(34459, 200, true)
                    && !me->FindNearestCreature(34448, 200, true)
                    && !me->FindNearestCreature(34449, 200, true)
                    && !me->FindNearestCreature(34445, 200, true)
                    && !me->FindNearestCreature(34456, 200, true)
                    && !me->FindNearestCreature(34447, 200, true)
                    && !me->FindNearestCreature(34441, 200, true)
                    && !me->FindNearestCreature(34454, 200, true)
                    && !me->FindNearestCreature(34455, 200, true)
                    && !me->FindNearestCreature(34444, 200, true)
                    && !me->FindNearestCreature(34450, 200, true)
                    && !me->FindNearestCreature(34453, 200, true))
                    {
                    m_pInstance->SetData(PHASE_5, DONE);
                    }
            }

            void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                    DoMeleeAttackIfReady();
            }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_gorgrim_shadowcleaveAI(pCreature);
    }

};

/****************************/
/* Birana Stormhoof - 34451 */
/* Druid                    */
/****************************/

class boss_birana_stormhoof : public CreatureScript
{
public:
    boss_birana_stormhoof() : CreatureScript("boss_birana_stormhoof") { }

    struct boss_birana_stormhoofAI : public ScriptedAI
    {
        boss_birana_stormhoofAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                    m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

        void Reset()
        {
        }

            void KilledUnit(Unit* who)
            {
                    if(!m_pInstance)
                            return;
            }

            void EnterCombat(Unit* pWho)
        {
        }

            void JustDied(Unit* pKiller)
        {
                    if(!m_pInstance)
                            return;

            if(!me->FindNearestCreature(34458, 200, true)
                    && !me->FindNearestCreature(34451, 200, true)
                    && !me->FindNearestCreature(34459, 200, true)
                    && !me->FindNearestCreature(34448, 200, true)
                    && !me->FindNearestCreature(34449, 200, true)
                    && !me->FindNearestCreature(34445, 200, true)
                    && !me->FindNearestCreature(34456, 200, true)
                    && !me->FindNearestCreature(34447, 200, true)
                    && !me->FindNearestCreature(34441, 200, true)
                    && !me->FindNearestCreature(34454, 200, true)
                    && !me->FindNearestCreature(34455, 200, true)
                    && !me->FindNearestCreature(34444, 200, true)
                    && !me->FindNearestCreature(34450, 200, true)
                    && !me->FindNearestCreature(34453, 200, true))
                    {
                            m_pInstance->SetData(PHASE_5, DONE);
                    }
            }

            void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                    DoMeleeAttackIfReady();
            }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_birana_stormhoofAI(pCreature);
    }

};

/*************************/
/* Erin Misthoof - 34459 */
/* Druid                 */
/*************************/

class boss_erin_misthoof : public CreatureScript
{
public:
    boss_erin_misthoof() : CreatureScript("boss_erin_misthoof") { }

    struct boss_erin_misthoofAI : public ScriptedAI
    {
        boss_erin_misthoofAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                    m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

        void Reset()
        {
        }

            void KilledUnit(Unit* who)
            {
                    if(!m_pInstance)
                            return;
            }

            void EnterCombat(Unit* pWho)
        {
        }

            void JustDied(Unit* pKiller)
        {
                    if(!m_pInstance)
                            return;

            if(!me->FindNearestCreature(34458, 200, true)
                    && !me->FindNearestCreature(34451, 200, true)
                    && !me->FindNearestCreature(34459, 200, true)
                    && !me->FindNearestCreature(34448, 200, true)
                    && !me->FindNearestCreature(34449, 200, true)
                    && !me->FindNearestCreature(34445, 200, true)
                    && !me->FindNearestCreature(34456, 200, true)
                    && !me->FindNearestCreature(34447, 200, true)
                    && !me->FindNearestCreature(34441, 200, true)
                    && !me->FindNearestCreature(34454, 200, true)
                    && !me->FindNearestCreature(34455, 200, true)
                    && !me->FindNearestCreature(34444, 200, true)
                    && !me->FindNearestCreature(34450, 200, true)
                    && !me->FindNearestCreature(34453, 200, true))
                    {
                            m_pInstance->SetData(PHASE_5, DONE);
                    }
            }

            void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                    DoMeleeAttackIfReady();
            }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_erin_misthoofAI(pCreature);
    }

};

/************************/
/* Ruj'kah - 34448      */
/* Hunter               */
/************************/

class boss_rujkah : public CreatureScript
{
public:
    boss_rujkah() : CreatureScript("boss_rujkah") { }

    struct boss_rujkahAI : public ScriptedAI
    {
        boss_rujkahAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                    m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

        void Reset()
        {
        }

            void KilledUnit(Unit* who)
            {
                    if(!m_pInstance)
                            return;
            }

            void EnterCombat(Unit* pWho)
        {
        }

            void JustDied(Unit* pKiller)
        {
                    if(!m_pInstance)
                            return;

            if(!me->FindNearestCreature(34458, 200, true)
                    && !me->FindNearestCreature(34451, 200, true)
                    && !me->FindNearestCreature(34459, 200, true)
                    && !me->FindNearestCreature(34448, 200, true)
                    && !me->FindNearestCreature(34449, 200, true)
                    && !me->FindNearestCreature(34445, 200, true)
                    && !me->FindNearestCreature(34456, 200, true)
                    && !me->FindNearestCreature(34447, 200, true)
                    && !me->FindNearestCreature(34441, 200, true)
                    && !me->FindNearestCreature(34454, 200, true)
                    && !me->FindNearestCreature(34455, 200, true)
                    && !me->FindNearestCreature(34444, 200, true)
                    && !me->FindNearestCreature(34450, 200, true)
                    && !me->FindNearestCreature(34453, 200, true))
                    {
                            m_pInstance->SetData(PHASE_5, DONE);
                    }
            }

            void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                    DoMeleeAttackIfReady();
            }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_rujkahAI(pCreature);
    }

};

/**********************************/
/* Ginselle Blightslinger - 34449 */
/* Mage                           */
/**********************************/

class boss_ginselle_blightslinger : public CreatureScript
{
public:
    boss_ginselle_blightslinger() : CreatureScript("boss_ginselle_blightslinger") { }

    struct boss_ginselle_blightslingerAI : public ScriptedAI
    {
        boss_ginselle_blightslingerAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                    m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

        void Reset()
        {
        }

            void KilledUnit(Unit* who)
            {
                    if(!m_pInstance)
                            return;
            }

            void EnterCombat(Unit* pWho)
        {
        }

            void JustDied(Unit* pKiller)
        {
                    if(!m_pInstance)
                            return;

            if(!me->FindNearestCreature(34458, 200, true)
                    && !me->FindNearestCreature(34451, 200, true)
                    && !me->FindNearestCreature(34459, 200, true)
                    && !me->FindNearestCreature(34448, 200, true)
                    && !me->FindNearestCreature(34449, 200, true)
                    && !me->FindNearestCreature(34445, 200, true)
                    && !me->FindNearestCreature(34456, 200, true)
                    && !me->FindNearestCreature(34447, 200, true)
                    && !me->FindNearestCreature(34441, 200, true)
                    && !me->FindNearestCreature(34454, 200, true)
                    && !me->FindNearestCreature(34455, 200, true)
                    && !me->FindNearestCreature(34444, 200, true)
                    && !me->FindNearestCreature(34450, 200, true)
                    && !me->FindNearestCreature(34453, 200, true))
                    {
                            m_pInstance->SetData(PHASE_5, DONE);
                    }
            }

            void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                    DoMeleeAttackIfReady();
            }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_ginselle_blightslingerAI(pCreature);
    }

};

/******************************/
/* Liandra Suncaller - 34445  */
/* Paladin                    */
/******************************/

class boss_liandra_suncaller : public CreatureScript
{
public:
    boss_liandra_suncaller() : CreatureScript("boss_liandra_suncaller") { }

    struct boss_liandra_suncallerAI : public ScriptedAI
    {
        boss_liandra_suncallerAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                    m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

        void Reset()
        {
        }

            void KilledUnit(Unit* who)
            {
                    if(!m_pInstance)
                            return;
            }

            void EnterCombat(Unit* pWho)
        {
        }

            void JustDied(Unit* pKiller)
        {
                    if(!m_pInstance)
                            return;

            if(!me->FindNearestCreature(34458, 200, true)
                    && !me->FindNearestCreature(34451, 200, true)
                    && !me->FindNearestCreature(34459, 200, true)
                    && !me->FindNearestCreature(34448, 200, true)
                    && !me->FindNearestCreature(34449, 200, true)
                    && !me->FindNearestCreature(34445, 200, true)
                    && !me->FindNearestCreature(34456, 200, true)
                    && !me->FindNearestCreature(34447, 200, true)
                    && !me->FindNearestCreature(34441, 200, true)
                    && !me->FindNearestCreature(34454, 200, true)
                    && !me->FindNearestCreature(34455, 200, true)
                    && !me->FindNearestCreature(34444, 200, true)
                    && !me->FindNearestCreature(34450, 200, true)
                    && !me->FindNearestCreature(34453, 200, true))
                    {
                            m_pInstance->SetData(PHASE_5, DONE);
                    }
            }

            void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                    DoMeleeAttackIfReady();
            }
    };
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_liandra_suncallerAI(pCreature);
    }
};

/********************************/
/* Malithas Brightblade - 34456 */
/* Paladin                      */
/********************************/


class boss_malithas_brightblader : public CreatureScript
{
public:
    boss_malithas_brightblader() : CreatureScript("boss_malithas_brightblader") { }

struct boss_malithas_brightbladeAI : public ScriptedAI
{
    boss_malithas_brightbladeAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
                m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

    void Reset()
    {
    }

        void KilledUnit(Unit* who)
        {
                if(!m_pInstance)
                        return;
        }

        void EnterCombat(Unit* pWho)
    {
    }

        void JustDied(Unit* pKiller)
    {
                if(!m_pInstance)
                        return;

        if(!me->FindNearestCreature(34458, 200, true)
                && !me->FindNearestCreature(34451, 200, true)
                && !me->FindNearestCreature(34459, 200, true)
                && !me->FindNearestCreature(34448, 200, true)
                && !me->FindNearestCreature(34449, 200, true)
                && !me->FindNearestCreature(34445, 200, true)
                && !me->FindNearestCreature(34456, 200, true)
                && !me->FindNearestCreature(34447, 200, true)
                && !me->FindNearestCreature(34441, 200, true)
                && !me->FindNearestCreature(34454, 200, true)
                && !me->FindNearestCreature(34455, 200, true)
                && !me->FindNearestCreature(34444, 200, true)
                && !me->FindNearestCreature(34450, 200, true)
                && !me->FindNearestCreature(34453, 200, true))
                {
                        m_pInstance->SetData(PHASE_5, DONE);
                }
        }

        void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

                DoMeleeAttackIfReady();
        }
};

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_malithas_brightbladeAI(pCreature);
    }

};
/*****************************/
/* Caiphus the Stern - 34447 */
/* Priest                    */
/*****************************/

class boss_caiphus_the_stern : public CreatureScript
{
public:
    boss_caiphus_the_stern() : CreatureScript("boss_caiphus_the_stern") { }

    struct boss_caiphus_the_sternAI : public ScriptedAI
    {
        boss_caiphus_the_sternAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                    m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

        void Reset()
        {
        }

            void KilledUnit(Unit* who)
            {
                    if(!m_pInstance)
                            return;
            }

            void EnterCombat(Unit* pWho)
        {
        }

            void JustDied(Unit* pKiller)
        {
                    if(!m_pInstance)
                            return;

            if(!me->FindNearestCreature(34458, 200, true)
                    && !me->FindNearestCreature(34451, 200, true)
                    && !me->FindNearestCreature(34459, 200, true)
                    && !me->FindNearestCreature(34448, 200, true)
                    && !me->FindNearestCreature(34449, 200, true)
                    && !me->FindNearestCreature(34445, 200, true)
                    && !me->FindNearestCreature(34456, 200, true)
                    && !me->FindNearestCreature(34447, 200, true)
                    && !me->FindNearestCreature(34441, 200, true)
                    && !me->FindNearestCreature(34454, 200, true)
                    && !me->FindNearestCreature(34455, 200, true)
                    && !me->FindNearestCreature(34444, 200, true)
                    && !me->FindNearestCreature(34450, 200, true)
                    && !me->FindNearestCreature(34453, 200, true))
                    {
                            m_pInstance->SetData(PHASE_5, DONE);
                    }
            }

            void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                    DoMeleeAttackIfReady();
            }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_caiphus_the_sternAI(pCreature);
    }

};

/*********************************/
/* Vivienne Blackwhisper - 34441 */
/* Priest                        */
/*********************************/

class boss_vivienne_blackwhisper : public CreatureScript
{
public:
    boss_vivienne_blackwhisper() : CreatureScript("boss_vivienne_blackwhisper") { }

    struct boss_vivienne_blackwhisperAI : public ScriptedAI
    {
        boss_vivienne_blackwhisperAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                    m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

        void Reset()
        {
        }

            void KilledUnit(Unit* who)
            {
                    if(!m_pInstance)
                            return;
            }

            void EnterCombat(Unit* pWho)
        {
        }

            void JustDied(Unit* pKiller)
        {
                    if(!m_pInstance)
                            return;

            if(!me->FindNearestCreature(34458, 200, true)
                    && !me->FindNearestCreature(34451, 200, true)
                    && !me->FindNearestCreature(34459, 200, true)
                    && !me->FindNearestCreature(34448, 200, true)
                    && !me->FindNearestCreature(34449, 200, true)
                    && !me->FindNearestCreature(34445, 200, true)
                    && !me->FindNearestCreature(34456, 200, true)
                    && !me->FindNearestCreature(34447, 200, true)
                    && !me->FindNearestCreature(34441, 200, true)
                    && !me->FindNearestCreature(34454, 200, true)
                    && !me->FindNearestCreature(34455, 200, true)
                    && !me->FindNearestCreature(34444, 200, true)
                    && !me->FindNearestCreature(34450, 200, true)
                    && !me->FindNearestCreature(34453, 200, true))
                    {
                            m_pInstance->SetData(PHASE_5, DONE);
                    }
            }

            void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                    DoMeleeAttackIfReady();
            }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_vivienne_blackwhisperAI(pCreature);
    }

};

/************************/
/* Maz'dinah - 34454    */
/* Rogue                */
/************************/

class boss_mazdinah : public CreatureScript
{
public:
    boss_mazdinah() : CreatureScript("boss_mazdinah") { }

    struct boss_mazdinahAI : public ScriptedAI
    {
        boss_mazdinahAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                    m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

            void KilledUnit(Unit* who)
            {
                    if(!m_pInstance)
                            return;
            }

            void EnterCombat(Unit* pWho)
        {
        }

            void JustDied(Unit* pKiller)
        {
                    if(!m_pInstance)
                            return;

            if(!me->FindNearestCreature(34458, 200, true)
                    && !me->FindNearestCreature(34451, 200, true)
                    && !me->FindNearestCreature(34459, 200, true)
                    && !me->FindNearestCreature(34448, 200, true)
                    && !me->FindNearestCreature(34449, 200, true)
                    && !me->FindNearestCreature(34445, 200, true)
                    && !me->FindNearestCreature(34456, 200, true)
                    && !me->FindNearestCreature(34447, 200, true)
                    && !me->FindNearestCreature(34441, 200, true)
                    && !me->FindNearestCreature(34454, 200, true)
                    && !me->FindNearestCreature(34455, 200, true)
                    && !me->FindNearestCreature(34444, 200, true)
                    && !me->FindNearestCreature(34450, 200, true)
                    && !me->FindNearestCreature(34453, 200, true))
                    {
                            m_pInstance->SetData(PHASE_5, DONE);
                    }
            }

            void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                    DoMeleeAttackIfReady();
            }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_mazdinahAI(pCreature);
    }

};

/***************************/
/* Broln Stouthorn - 34455 */
/* Shaman                  */
/***************************/

class boss_broln_stouthorn : public CreatureScript
{
public:
    boss_broln_stouthorn() : CreatureScript("boss_broln_stouthorn") { }

    struct boss_broln_stouthornAI : public ScriptedAI
    {
        boss_broln_stouthornAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                    m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

            void KilledUnit(Unit* who)
            {
                    if(!m_pInstance)
                            return;
            }

            void EnterCombat(Unit* pWho)
        {
        }

            void JustDied(Unit* pKiller)
        {
                    if(!m_pInstance)
                            return;

            if(!me->FindNearestCreature(34458, 200, true)
                    && !me->FindNearestCreature(34451, 200, true)
                    && !me->FindNearestCreature(34459, 200, true)
                    && !me->FindNearestCreature(34448, 200, true)
                    && !me->FindNearestCreature(34449, 200, true)
                    && !me->FindNearestCreature(34445, 200, true)
                    && !me->FindNearestCreature(34456, 200, true)
                    && !me->FindNearestCreature(34447, 200, true)
                    && !me->FindNearestCreature(34441, 200, true)
                    && !me->FindNearestCreature(34454, 200, true)
                    && !me->FindNearestCreature(34455, 200, true)
                    && !me->FindNearestCreature(34444, 200, true)
                    && !me->FindNearestCreature(34450, 200, true)
                    && !me->FindNearestCreature(34453, 200, true))
                    {
                            m_pInstance->SetData(PHASE_5, DONE);
                    }
            }

            void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                    DoMeleeAttackIfReady();
            }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_broln_stouthornAI(pCreature);
    }

};

/************************/
/* Thrakgar - 34444     */
/* Shaman               */
/************************/

class boss_thrakgar : public CreatureScript
{
public:
    boss_thrakgar() : CreatureScript("boss_thrakgar") { }

    struct boss_thrakgarAI : public ScriptedAI
    {
        boss_thrakgarAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                    m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

        void Reset()
        {
        }

            void KilledUnit(Unit* who)
            {
                    if(!m_pInstance)
                            return;
            }

            void EnterCombat(Unit* pWho)
        {
        }

            void JustDied(Unit* pKiller)
        {
                    if(!m_pInstance)
                            return;

            if(!me->FindNearestCreature(34458, 200, true)
                    && !me->FindNearestCreature(34451, 200, true)
                    && !me->FindNearestCreature(34459, 200, true)
                    && !me->FindNearestCreature(34448, 200, true)
                    && !me->FindNearestCreature(34449, 200, true)
                    && !me->FindNearestCreature(34445, 200, true)
                    && !me->FindNearestCreature(34456, 200, true)
                    && !me->FindNearestCreature(34447, 200, true)
                    && !me->FindNearestCreature(34441, 200, true)
                    && !me->FindNearestCreature(34454, 200, true)
                    && !me->FindNearestCreature(34455, 200, true)
                    && !me->FindNearestCreature(34444, 200, true)
                    && !me->FindNearestCreature(34450, 200, true)
                    && !me->FindNearestCreature(34453, 200, true))
                    {
                            m_pInstance->SetData(PHASE_5, DONE);
                    }
            }

            void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                    DoMeleeAttackIfReady();
            }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_thrakgarAI(pCreature);
    }

};

/*************************/
/* Harkzog - 34450       */
/* Warlock               */
/*************************/

class boss_harkzog : public CreatureScript
{
public:
    boss_harkzog() : CreatureScript("boss_harkzog") { }

    struct boss_harkzogAI : public ScriptedAI
    {
        boss_harkzogAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                    m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

        void Reset()
        {
        }

            void KilledUnit(Unit* who)
            {
                    if(!m_pInstance)
                            return;
            }

            void EnterCombat(Unit* pWho)
        {
        }

            void JustDied(Unit* pKiller)
        {
                    if(!m_pInstance)
                            return;

            if(!me->FindNearestCreature(34458, 200, true)
                    && !me->FindNearestCreature(34451, 200, true)
                    && !me->FindNearestCreature(34459, 200, true)
                    && !me->FindNearestCreature(34448, 200, true)
                    && !me->FindNearestCreature(34449, 200, true)
                    && !me->FindNearestCreature(34445, 200, true)
                    && !me->FindNearestCreature(34456, 200, true)
                    && !me->FindNearestCreature(34447, 200, true)
                    && !me->FindNearestCreature(34441, 200, true)
                    && !me->FindNearestCreature(34454, 200, true)
                    && !me->FindNearestCreature(34455, 200, true)
                    && !me->FindNearestCreature(34444, 200, true)
                    && !me->FindNearestCreature(34450, 200, true)
                    && !me->FindNearestCreature(34453, 200, true))
                    {
                            m_pInstance->SetData(PHASE_5, DONE);
                    }
            }

            void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                    DoMeleeAttackIfReady();
            }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_harkzogAI(pCreature);
    }

};

/********************************/
/* Narrhok Steelbreaker - 34453 */
/* Warrior                      */
/********************************/

class boss_narrhok_steelbreaker : public CreatureScript
{
public:
    boss_narrhok_steelbreaker() : CreatureScript("boss_narrhok_steelbreaker") { }

    struct boss_narrhok_steelbreakerAI : public ScriptedAI
    {
        boss_narrhok_steelbreakerAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                    m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

        void Reset()
        {
        }

            void KilledUnit(Unit* who)
            {
                    if(!m_pInstance)
                            return;
            }

            void EnterCombat(Unit* pWho)
        {
        }

            void JustDied(Unit* pKiller)
        {
                    if(!m_pInstance)
                            return;

            if(!me->FindNearestCreature(34458, 200, true)
                    && !me->FindNearestCreature(34451, 200, true)
                    && !me->FindNearestCreature(34459, 200, true)
                    && !me->FindNearestCreature(34448, 200, true)
                    && !me->FindNearestCreature(34449, 200, true)
                    && !me->FindNearestCreature(34445, 200, true)
                    && !me->FindNearestCreature(34456, 200, true)
                    && !me->FindNearestCreature(34447, 200, true)
                    && !me->FindNearestCreature(34441, 200, true)
                    && !me->FindNearestCreature(34454, 200, true)
                    && !me->FindNearestCreature(34455, 200, true)
                    && !me->FindNearestCreature(34444, 200, true)
                    && !me->FindNearestCreature(34450, 200, true)
                    && !me->FindNearestCreature(34453, 200, true))
                    {
                            m_pInstance->SetData(PHASE_5, DONE);
                    }
            }

            void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

                    DoMeleeAttackIfReady();
            }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_narrhok_steelbreakerAI(pCreature);
    }
};

void AddSC_boss_tc_horde_champions()
{
    new boss_gorgrim_shadowcleave;
    new boss_birana_stormhoof;
    new boss_erin_misthoof;
    new boss_rujkah;
    new boss_ginselle_blightslinger;
    new boss_liandra_suncaller;
    new boss_malithas_brightblader;
    new boss_caiphus_the_stern;
    new boss_vivienne_blackwhisper;
    new boss_mazdinah;
    new boss_broln_stouthorn;
    new boss_thrakgar;
    new boss_harkzog;
    new boss_narrhok_steelbreaker;
}