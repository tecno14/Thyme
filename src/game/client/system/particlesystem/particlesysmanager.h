/**
 * @file
 *
 * @author OmniBlade
 *
 * @brief Manager class for the engines particle systems.
 *
 * @copyright Thyme is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#pragma once

#include "always.h"
#include "rtsutils.h"
#include "snapshot.h"
#include "subsysteminterface.h"
#include <list>
#include <vector>

#ifdef THYME_USE_STLPORT
#include <hash_map>
#else
#include <unordered_map>
#endif

class Particle;
class ParticleSystem;
class ParticleSystemTemplate;

#ifdef THYME_USE_STLPORT
typedef std::hash_map<const AsciiString, ParticleSystemTemplate *, rts::hash<AsciiString>, rts::equal_to<AsciiString>>
partsystempmap_t;
#else
typedef std::unordered_map<const AsciiString, ParticleSystemTemplate *, rts::hash<AsciiString>, rts::equal_to<AsciiString>>
partsystempmap_t;
#endif

class ParticleSystemManager : public SubsystemInterface, public SnapShot
{
    enum
    {
        PARTICLE_ARRAY_SIZE = 14,
    };
public:
    ParticleSystemManager();
    virtual ~ParticleSystemManager();

    virtual void Init() override;
    virtual void Reset() override;
    virtual void Update() override;

    virtual void CRC_Snapshot(Xfer *xfer) override {}
    virtual void Xfer_Snapshot(Xfer *xfer) override;
    virtual void Load_Post_Process() override {}

private:
    Particle *m_allParticlesHead[PARTICLE_ARRAY_SIZE];
    Particle *m_allParticlesTail[PARTICLE_ARRAY_SIZE];
    int m_uniqueSystemID;
    std::list<ParticleSystem *> m_allParticleSystemList;
    int m_particleCount;
    unsigned m_unkInt1;
    unsigned m_particleSystemCount;
    int m_onScreenParticleCount;
    int m_someGameLogicValue;
    int m_unkInt2;
    partsystempmap_t m_templateStore;
};