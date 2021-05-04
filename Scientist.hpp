#pragma once
#ifndef SCIENTIST
#define SCIENTIST
#include "Player.hpp"

namespace pandemic {

    class Scientist : public Player
    {  // can discover a cure with only N cards 
     
        public:
            using Player::Player;
            Scientist &discover_cure(Color);
            std::string role();

    };
}
#endif // !SCIENTIST
