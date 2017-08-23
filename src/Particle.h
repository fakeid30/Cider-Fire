//
// Created by nirjhor on 8/22/17.
//

#pragma once

namespace ciderFireNamespace {
    struct Particle {
        double m_x;
        double m_y;


        double m_xspeed;
        double m_yspeed;

    public:
        Particle();

        virtual ~Particle();

        void update();

    };


}
