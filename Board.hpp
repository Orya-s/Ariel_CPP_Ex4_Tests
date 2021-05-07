#pragma once
#include "City.hpp"
#include <iostream>
#include <vector>
#include <map>

namespace pandemic {

    class Board
    {
        private:
            std::vector<City> found_cure; // vector<City> where cures_found
            std::map<City, City_info> cities; // cities   // map<City, City_info> cities ?
            int temp; // for [] operator

        public:
            Board() 
            {
                init_game();
            }
            ~Board() {}

            
            int& operator[] (City s) ;  
            bool is_clean() ;
            void remove_cures() ;  
            friend std::ostream& operator<< (std::ostream& output, const Board& board);
    };

}    
