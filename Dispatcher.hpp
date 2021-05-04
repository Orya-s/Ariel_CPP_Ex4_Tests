#pragma once
#ifndef DISPATCHER
#define DISPATCHER
#include "Player.hpp"

namespace pandemic {

    class Dispatcher : public Player
    {  // when in a city with a research station - can take a flight to any other destination , no card neccesary
        
        public:
            using Player::Player;
            Dispatcher &fly_direct(City city);
            std::string role();

    };
}
#endif // !DISPATCHER
