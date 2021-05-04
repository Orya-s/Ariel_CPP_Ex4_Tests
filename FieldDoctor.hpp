#pragma once
#ifndef FD
#define FD
#include "Player.hpp"

namespace pandemic {

    class FieldDoctor : public Player
    {  // can treat a neighbor city , without throwing the city's card
     
        public:
            using Player::Player;
            FieldDoctor &treat(City city);
            std::string role();

    };
}
#endif // !FD
