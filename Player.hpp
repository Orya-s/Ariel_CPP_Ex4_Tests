#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

namespace pandemic {

    class Player
    {
        protected:
            Board& board;
            City location; 
            std::vector<City> cards; // cards in hand // vector ? set ?

        public:
            Player(Board& b, City c) : board(b), location(c) {}
            ~Player() {}

            virtual Player& drive(City neighbor) ;
            virtual Player& fly_direct(City city) ;
            virtual Player& fly_charter(City city) ;
            virtual Player& fly_shuttle(City city) ;
            virtual Player& build(City city) ;
            virtual Player& discover_cure(Color color) ;
            virtual Player& treat(City city) ;
            virtual std::string role() ;
            virtual Player& take_card(City city) ;
            virtual void remove_cards();
    };
}