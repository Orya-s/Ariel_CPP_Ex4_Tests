#pragma once
#ifndef RESEARCHER
#define RESEARCHER
#include "Player.hpp"

namespace pandemic {

    class Researcher : public Player
    {  // can discover a cure from every city , doesn't need to ba in a research station
     
        public:
            using Player::Player;
            Researcher &discover_cure(Color);
            std::string role();

    };
}
#endif // !RESEARCHER
