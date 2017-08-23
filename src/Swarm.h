//
// Created by nirjhor on 8/22/17.
//

#pragma once

#include "Particle.h"

namespace ciderFireNamespace {
    class Swarm {
    public:
        const static int NPARTICLES = 5000;

    private:
        Particle *m_pParticles;

    public:
        Swarm();

        virtual ~Swarm();

        void update();

        const Particle *const getParticles() { return m_pParticles; };

    };


}
