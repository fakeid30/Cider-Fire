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
        int lastTime;

    public:
        Swarm();

        virtual ~Swarm();

        void update(int elapsed);

        const Particle *const getParticles() { return m_pParticles; };

    };


}
