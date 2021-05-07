#include "Player.hpp"
#include <algorithm>

using namespace std;

namespace pandemic {

    Player& Player::drive(City neighbor) 
    {
        vector<City> n = board.cities.at(location).neighbors;

        if (count(n.begin(), n.end(), neighbor))
        {
            location = neighbor;
        }
        else
        {
            throw invalid_argument("Illegal action: this is not a neighbor city");
        }

        return *this;
    }


    Player& Player::fly_direct(City city) 
    {
        if (count(cards.begin(), cards.end(), city))
        {
            location = city;
            remove(cards.begin(), cards.end(), city);
        }
        else
        {
            throw invalid_argument("Illegal action: you don't have this city's card");
        }
        
        return *this;
    }


    Player& Player::fly_charter(City city) 
    {
        if (count(cards.begin(), cards.end(), location))
        {
            remove(cards.begin(), cards.end(), location);
            location = city;
        }
        else
        {
            throw invalid_argument("Illegal action: you don't have the card of your location");
        }

        return *this;
    }


    Player& Player::fly_shuttle(City city) 
    {
        if (board.cities.at(location).has_station())
        {
            if (board.cities.at(city).has_station())
            {
                location = city;
            }
            else
            {
                throw invalid_argument("Illegal action: this city doesn't have a research station");
            }
        }
        else
        {
            throw invalid_argument("Illegal action: Your location doesn't have a research station");
        }
        
        return *this;
    }


    Player& Player::build(City city) 
    {
        if (count(cards.begin(), cards.end(), location))
        {
            remove(cards.begin(), cards.end(), location);
            board.cities.at(location).build_station();
        }
        else
        {
            throw invalid_argument("Illegal action: you don't have the card of your location");
        }

        return *this;
    }


    Player& Player::discover_cure(Color color) 
    {
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
            if (counter >= 5)
            {
                board.add_cure(color);

                //removing 5 cards
                counter = 5;
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
                throw invalid_argument("Illegal action: you don't have enough cards to discover a cure");
            }
        }
        else
        {
            throw invalid_argument("Illegal action: Your location doesn't have a research station");
        }
        
        return *this;
    }

    Player& Player::treat(City city) 
    {
        return *this;
    }

    std::string Player::role() 
    {
        return "";
    }

    Player& Player::take_card(City city) 
    {
        cards.push_back(city);
        return *this;
    }

    void Player::remove_cards()
    {
        cards.clear();
    }
    
}