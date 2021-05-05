#pragma once
#include "Color.hpp"

namespace pandemic {

    class City_info
    {
        private:
            int pandemic_level;
            Color color;
            bool research_station;
            // neighbors - map / vector ?
                // map<City n, Color c>
        public:
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