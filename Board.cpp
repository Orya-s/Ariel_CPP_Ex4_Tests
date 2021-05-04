
#include "Board.hpp"

namespace pandemic {

    int& Board::operator[] (City s) 
    {
        int ans = 0;
        return temp;
    }

    bool Board::is_clean() 
    {
        return false;
    }

    void Board::remove_cures() 
    {

    }

    std::ostream& operator<< (std::ostream& output, const Board& board)
    {
        return output;
    }

}