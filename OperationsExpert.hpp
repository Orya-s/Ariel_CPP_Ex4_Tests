#pragma once
#include "Player.hpp"

namespace pandemic {

    class OperationsExpert : Player
    {
        private:
            Board& board;
            City location; 
            std::vector<City> cards;

        public:
            OperationsExpert(Board& b, City c) : Player(b, c) , board(b), location(c) {}
            ~OperationsExpert() {}


            virtual Player drive(City neighbor) ;
            virtual Player fly_direct(City city) ;
            virtual Player fly_charter(City city) ;
            virtual Player fly_shuttle(City city) ;
            Player build() ;
            virtual Player discover_cure(Color color) ;
            virtual Player treat(City city) ;
            virtual std::string role() ;
            virtual Player& take_card(City city) ;

    };
}
 