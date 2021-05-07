#pragma once
#include "Color.hpp"
#include <vector>
#include <string>


namespace pandemic {

    class City_info
    {
        private:
            int pandemic_level;
            // Color color;
            bool research_station;
            // std::vector<std::string> neighbors;     // neighbors - map / vector ?
                
        public:
            Color color;  // public because doesn't change between games
            std::vector<std::string> neighbors;
        
            City_info() {}
            ~City_info() {}

    };



	// Defines a city on the board
	enum class City {
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
        // ,        Last // for iteraiting
	};
}