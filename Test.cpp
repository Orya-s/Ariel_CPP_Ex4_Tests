#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include "doctest.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace pandemic;
using namespace std;

static const City All[] = { City::Algiers,
    City::Atlanta, City::Baghdad, City::Bangkok, City::Beijing, City::Bogota, City::BuenosAires,
    City::Cairo, City::Chennai, City::Chicago, City::Delhi, City::Essen, City::HoChiMinhCity, City::HongKong,
    City::Istanbul, City::Jakarta, City::Johannesburg, City::Karachi, City::Khartoum, City::Kinshasa,
    City::Kolkata, City::Lagos, City::Lima, City::London, City::LosAngeles,City::Madrid, City::Manila,
    City::MexicoCity, City::Miami, City::Milan, City::Montreal, City::Moscow, City::Mumbai, City::NewYork,
    City::Osaka, City::Paris, City::Riyadh, City::SanFrancisco, City::Santiago, City::SaoPaulo, City::Seoul,
    City::Shanghai, City::StPetersburg, City::Sydney, City::Taipei, City::Tehran, City::Tokyo, City::Washington };


TEST_CASE("Board class tests")
{
    Board board;  
    CHECK(board.is_clean());
    int disease_cubes = 0;
    for ( const auto c : All )
    {
        board[c] = (disease_cubes % 10);
        // cout << board[c] << endl;
        
        CHECK_EQ(board[c], (disease_cubes % 10));

        disease_cubes++;
    }
    CHECK_FALSE(board.is_clean());
}


TEST_CASE("OperationsExpert tests , drive tests") // can build in every city he's in, no need for a card
{
    Board board;
    OperationsExpert player {board, City::Madrid}; 
	player.take_card(City::MexicoCity)
	 .take_card(City::SanFrancisco)
	 .take_card(City::NewYork)
	 .take_card(City::BuenosAires)
	 .take_card(City::Osaka);

    CHECK_NOTHROW(player.build());

    Dispatcher otherPlayer {board, City::Madrid}; 
	otherPlayer.take_card(City::MexicoCity)
	 .take_card(City::SanFrancisco)
	 .take_card(City::NewYork)
	 .take_card(City::BuenosAires)
	 .take_card(City::Osaka);

    CHECK_THROWS(otherPlayer.build(City::Madrid));

    // drive test
    CHECK_NOTHROW(player.drive(City::NewYork));  // neighbor
    CHECK_THROWS(player.drive(City::Osaka)); // not neighbor
    CHECK_NOTHROW(otherPlayer.drive(City::NewYork));  // neighbor
    CHECK_THROWS(otherPlayer.drive(City::Osaka)); // not neighbor
}

TEST_CASE("Dispatcher tests , fly_shuttle tests") // when in a city with a research station - can take 
    // a flight to any other destination , no card neccesary
{
    Board board;
    Dispatcher player {board, City::SanFrancisco}; 
	player.take_card(City::Algiers)
	 .take_card(City::SanFrancisco)
	 .take_card(City::Baghdad)
	 .take_card(City::Cairo)
	 .take_card(City::Delhi);

    CHECK_THROWS(player.fly_direct(City::NewYork)); // no research station yet
    CHECK_NOTHROW(player.build(City::SanFrancisco));
    CHECK_NOTHROW(player.fly_direct(City::NewYork)); // SF has a research staion

    // fly_shuttle tests
    player.take_card(City::NewYork);
    CHECK_NOTHROW(player.build(City::NewYork));
    CHECK_NOTHROW(player.fly_shuttle(City::SanFrancisco)); // NY & SF have a research staion


    Scientist otherPlayer {board, City::SanFrancisco, 3}; 
	otherPlayer.take_card(City::Algiers)
	 .take_card(City::SanFrancisco)
	 .take_card(City::Baghdad)
	 .take_card(City::Cairo)
	 .take_card(City::Delhi);
    
    CHECK_THROWS(otherPlayer.fly_direct(City::NewYork)); // no research station yet
    CHECK_NOTHROW(otherPlayer.build(City::SanFrancisco));
    CHECK_THROWS(otherPlayer.fly_direct(City::NewYork)); // SF has a research staion , but not a dispatcher
}


TEST_CASE("Scientist tests , fly_direct tests") // can discover a cure with only N cards 
{
    Board board;
    board[City::Moscow] = 1; 

    Scientist player {board, City::SanFrancisco, 3}; 
	player.take_card(City::Algiers)
	 .take_card(City::SanFrancisco)
	 .take_card(City::Baghdad)
	 .take_card(City::Cairo)
	 .take_card(City::Delhi);

    CHECK_NOTHROW(player.build(City::SanFrancisco));
    CHECK_THROWS(player.discover_cure(Color::Black));  // only 2 black cards
    player.take_card(City::Moscow);
    CHECK_NOTHROW(player.discover_cure(Color::Black));  // 3 = n black cards


    Researcher otherPlayer {board, City::SanFrancisco}; 
	otherPlayer.take_card(City::Algiers)
	 .take_card(City::SanFrancisco)
	 .take_card(City::Baghdad)
	 .take_card(City::Cairo)
	 .take_card(City::Delhi);
    CHECK_NOTHROW(otherPlayer.build(City::SanFrancisco));
    CHECK_THROWS(otherPlayer.discover_cure(Color::Black)); // has 2 blacks
    otherPlayer.take_card(City::Moscow);
    CHECK_THROWS(otherPlayer.discover_cure(Color::Black));  // not a scientist


    // fly_direct tests
    CHECK_THROWS(otherPlayer.fly_direct(City::SaoPaulo)); 
    otherPlayer.take_card(City::SaoPaulo);
    CHECK_NOTHROW(otherPlayer.fly_direct(City::SaoPaulo));
}


TEST_CASE("Researcher tests , fly_charter tests") // can discover a cure from every city , 
    // doesn't need to ba in a research station
{
    Board board;
    board[City::Sydney] = 2; 
    Researcher player {board, City::Jakarta}; 
	player.take_card(City::Jakarta)
	 .take_card(City::Manila)
	 .take_card(City::Seoul)
	 .take_card(City::Cairo)
	 .take_card(City::HongKong);

    CHECK_THROWS(player.discover_cure(Color::Black));  // only has 4 reds
    player.take_card(City::Shanghai);
    CHECK_NOTHROW(player.discover_cure(Color::Black));  // has 5 reds , doesn't need a research station


    Medic otherPlayer {board, City::Jakarta}; 
	otherPlayer.take_card(City::Algiers)
	 .take_card(City::Manila)
	 .take_card(City::Seoul)
	 .take_card(City::Cairo)
	 .take_card(City::HongKong);

    CHECK_THROWS(otherPlayer.discover_cure(Color::Black));  // only has 4 reds
    otherPlayer.take_card(City::Shanghai);
    CHECK_THROWS(otherPlayer.discover_cure(Color::Black));  // has 5 reds, but doesn't have research station


    // fly_charter tests
    CHECK_THROWS(otherPlayer.fly_charter(City::SaoPaulo)); // doesn't have the Jakarta card
    otherPlayer.take_card(City::Jakarta);
    CHECK_NOTHROW(otherPlayer.fly_charter(City::SaoPaulo));
}


TEST_CASE("Medic tests , build tests") // when treating a pandemic removes all cubes , not just one 
{
    Board board;
    board[City::London] = 3; 
    Medic player {board, City::London}; 
	player.take_card(City::Atlanta)
	 .take_card(City::Johannesburg)
	 .take_card(City::Lima)
	 .take_card(City::Lagos)
	 .take_card(City::Paris);

    CHECK_NOTHROW(player.treat(City::London));
    CHECK_EQ(board[City::London], 0);


    Virologist otherPlayer {board, City::London}; 
	otherPlayer.take_card(City::Atlanta)
	 .take_card(City::Johannesburg)
	 .take_card(City::Lima)
	 .take_card(City::Lagos)
	 .take_card(City::Paris);
    
    CHECK_NOTHROW(otherPlayer.treat(City::London));
    CHECK_FALSE(board[City::London] == 0);  // not a Medic , reomves only one cube
}