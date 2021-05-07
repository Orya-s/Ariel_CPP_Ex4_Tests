#pragma once
#include "Color.hpp"
#include <vector>
#include <string>


namespace pandemic {

	// Defines a city on the board
	enum City {
        Algiers,
        Atlanta,
        Baghdad,
        Bangkok,
        Beijing,
        Bogota,
        BuenosAires,
        Cairo,
        Chennai,
        Chicago,
        Delhi,
        Essen,
        HoChiMinhCity,
        HongKong,
        Istanbul,
        Jakarta,
        Johannesburg,
        Karachi,
        Khartoum,
        Kinshasa,
        Kolkata,
        Lagos,
        Lima,
        London,
        LosAngeles,
        Madrid,
        Manila,
        MexicoCity,
        Miami,
        Milan,
        Montreal,
        Moscow,
        Mumbai,
        NewYork,
        Osaka,
        Paris,
        Riyadh,
        SanFrancisco,
        Santiago,
        SaoPaulo,
        Seoul,
        Shanghai,
        StPetersburg,
        Sydney,
        Taipei,
        Tehran,
        Tokyo,
        Washington
	};


    class City_info
    {
        private:
            int pandemic_level;
            bool research_station;
                
        public:
            Color color;  // public because doesn't change between games
            std::vector<City> neighbors;
        

            City_info() {}
            City_info(Color c, std::vector<City> n) : color(c) , neighbors(n) {}
            ~City_info() {}

            void set_cubes(int n)
            {
                pandemic_level = n;
            }
            int& operator[] (int cubes) 
            {
                return pandemic_level=cubes;
            }
            bool& has_station()
            {
                return research_station;
            }
            void build_station()
            {
                research_station = true;
            }

    };



}