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

        enter_city(neighbor);
        return *this;
    }


    Player& Player::fly_direct(City city) 
    {
        if (city == location)
        {
            throw invalid_argument("Illegal action: you can't fly to your location");
        }
        if (count(cards.begin(), cards.end(), city))
        {
            location = city;
            remove(cards.begin(), cards.end(), city);
        }
        else
        {
            throw invalid_argument("Illegal action: you don't have this city's card");
        }
        
        enter_city(city);
        return *this;
    }


    Player& Player::fly_charter(City city) 
    {
        if (city == location)
        {
            throw invalid_argument("Illegal action: you can't fly to your location");
        }
        if (count(cards.begin(), cards.end(), location))
        {
            remove(cards.begin(), cards.end(), location);
            location = city;
        }
        else
        {
            throw invalid_argument("Illegal action: you don't have the card of your location");
        }

        enter_city(city);
        return *this;
    }


    Player& Player::fly_shuttle(City city) 
    {
        if (city == location)
        {
            throw invalid_argument("Illegal action: you can't fly to your location");
        }
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
        
        enter_city(city);
        return *this;
    }


    Player& Player::build(City city) 
    {
        if (location == city && board.cities.at(city).has_station())
        {
            return *this;
        }
        if (location == city && count(cards.begin(), cards.end(), location))
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
        }
        else
        {
            throw invalid_argument("Illegal action: Your location doesn't have a research station");
        }
        
        return *this;
    }

    Player& Player::treat(City city) 
    {
        if (board[city] == 0)  // no disease cubes
        {
            throw invalid_argument("Illegal action: Your location doesn't have any disease cubes");
        }
        if (city != location)
        {
            throw invalid_argument("Illegal action: This city is not your location");
        }
        Color col = board.cities.at(city).color;
        if (board.is_cured(col))
        {
            board[city] = 0;
        }
        else
        {
            board[city]--;
        }
        
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
    
    void Player::enter_city(City c)
    {

    }
}