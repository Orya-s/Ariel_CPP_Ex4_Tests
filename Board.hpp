#pragma once
#include "City.hpp"
#include <iostream>

namespace pandemic {

    class Board
    {
        private:
            // int cures_found; ?
            // cities
            int temp; // for [] operator

        public:
            Board() {}
            ~Board() {}

        int& operator[] (City s) ;  
        bool is_clean() ;
        void remove_cures() ;  
        friend std::ostream& operator<< (std::ostream& output, const Board& board);
    };

}    
