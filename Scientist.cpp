#include "Scientist.hpp"
#include <algorithm>

using namespace std;

namespace pandemic {

    Scientist &Scientist::discover_cure(Color color) 
    {
        if (board.is_cured(color))
        {
            return *this;
        }
        
        if (board.cities.at(location).has_station())
        {
            int counter = 0;
            for (auto& it : cards) 
            {
                if (board.cities.at(it).color == color)
                {
                    counter++;
                }
            }
            if (counter >= min_cards)
            {
                board.add_cure(color);

                //removing min_cards 
                counter = min_cards;
                for (auto& it : cards) 
                {
                    if (counter != 0)
                    {
                        if (board.cities.at(it).color == color)
                        {
                            remove(cards.begin(), cards.end(), it);
                            counter--;
                        }
                    }
                }
            }
            else
            {
                throw invalid_argument("Illegal action: you don't have enough cards to discover a cure");
            }
        }
        else
        {
            throw invalid_argument("Illegal action: Your location doesn't have a research station");
        }
        
        return *this;
    }

    string Scientist::role() 
    {
        return "Scientist";
    }
}
