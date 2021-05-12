#include "Researcher.hpp"
#include <algorithm>

using namespace std;

namespace pandemic {

    Researcher &Researcher::discover_cure(Color color) 
    {
        if (board.is_cured(color))
        {
            return *this;
        }
        int counter = 0;
        for (auto& it : cards) 
        {
            if (board.cities.at(it).color == color)
            {
                counter++;
            }
        }
        if (counter >= 5)
        {
            board.add_cure(color);

            //removing 5 cards
            counter = 5;
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
        
        return *this;
    }

    string Researcher::role() 
    {
        return "Researcher";
    }
}
