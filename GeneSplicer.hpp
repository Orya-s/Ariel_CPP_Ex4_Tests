#pragma once
#ifndef GS
#define GS
#include "Player.hpp"

namespace pandemic {

    class GeneSplicer : public Player
    {  // can discover a cure from every city , doesn't need to ba in a research station
     
        public:
            using Player::Player;
            GeneSplicer &discover_cure(Color);
            std::string role();

    };
}
#endif // !GS
