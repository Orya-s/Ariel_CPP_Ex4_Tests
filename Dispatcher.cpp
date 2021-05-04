#include "Dispatcher.hpp"

using namespace std;

namespace pandemic {

    Dispatcher &Dispatcher::fly_direct(City city) 
    {
        return *this;
    }

    string Dispatcher::role() 
    {
        return "";
    }

}
