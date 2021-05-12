#include "GeneSplicer.hpp"
#include <algorithm>

using namespace std;

namespace pandemic {

    GeneSplicer &GeneSplicer::discover_cure(Color color) 
    {
        if (board.is_cured(color))
        {
            return *this;
        }
        
        if (board.cities.at(location).has_station())
        {            
            if (cards.size() < 5)
            {
                throw invalid_argument("Illegal action: you don't have enough cards to discover a cure");
            }

            board.add_cure(color);

            //removing 5 cards
            int counter = 5;
            for (auto& it : cards) 
            {
                if (counter != 0)
                {
                    remove(cards.begin(), cards.end(), it);
                    counter--; 
                }
            }
        }
        else
        {
            throw invalid_argument("Illegal action: Your location doesn't have a research station");
        }
        
        return *this;
    }

    string GeneSplicer::role() 
    {
        return "GeneSplicer";
    }

}
