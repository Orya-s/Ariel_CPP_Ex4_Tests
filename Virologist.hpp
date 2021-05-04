#pragma once
#ifndef VIROLOGIST
#define VIROLOGIST
#include "Player.hpp"

namespace pandemic {

    class Virologist : public Player
    {  // can treat any city if trows it's card - even when not there
     
        public:
            using Player::Player;
            Virologist &treat(City city);
            std::string role();

    };
}
#endif // !VIROLOGIST
