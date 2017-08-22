//
// Created by nirjhor on 8/22/17.
//

#include "Swarm.h"

namespace ciderFireNamespace {
    Swarm::Swarm() {
        m_pParticles = new Particle[NPARTICLES];
    }

    Swarm::~Swarm() {
        delete [] m_pParticles;
    }
}