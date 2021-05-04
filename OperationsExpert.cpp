#include "OperationsExpert.hpp"

using namespace std;

namespace pandemic {

    Player OperationsExpert::drive(City neighbor) 
    {
        return *this;
    }

    Player OperationsExpert::fly_direct(City city) 
    {
        return *this;
    }

    Player OperationsExpert::fly_charter(City city) 
    {
        return *this;
    }

    Player OperationsExpert::fly_shuttle(City city) 
    {
        return *this;
    }

    Player OperationsExpert::build() 
    {
        return *this;
    }

    Player OperationsExpert::discover_cure(Color color) 
    {
        return *this;
    }

    Player OperationsExpert::treat(City city) 
    {
        return *this;
    }

    string OperationsExpert::role() 
    {
        return "";
    }

    Player& OperationsExpert::take_card(City city) 
    {
        return *this;
    }
}
