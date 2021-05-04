#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic {

    FieldDoctor &FieldDoctor::treat(City city) 
    {
        return *this;
    }

    string FieldDoctor::role() 
    {
        return "";
    }

}
