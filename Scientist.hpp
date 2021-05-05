#pragma once
#include "Player.hpp"

namespace pandemic {

    class Scientist : public Player
    {  // can discover a cure with only N cards 
        private:
            int min_cards_to_discover;
        public:
            Scientist(Board& b, City c, int min_cure) : Player::Player(b, c), min_cards_to_discover(min_cure) {}
            Scientist &discover_cure(Color);
            std::string role();

    };
}

