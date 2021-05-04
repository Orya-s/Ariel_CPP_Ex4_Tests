#pragma once
#ifndef OE
#define OE
#include "Player.hpp"

namespace pandemic {

    class OperationsExpert : public Player
    {  // can build in every city he's in , no need for the city's card
     
        public:
            using Player::Player;
            OperationsExpert &build();
            std::string role();

    };
}
#endif // !OE
