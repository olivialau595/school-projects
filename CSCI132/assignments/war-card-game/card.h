/*************************************************
 * File name: card.h
 * Purpose: Specification of Card and Deck classes
 *          Card class defines objects that behave
 *                 like playing cards.
 *          Deck class defines objects that behave
 *                 like deck of playing cards.
 *          Created for use in CSCI 132
 * Author: CSCI 132 Instructor
 * Date modified: September 9, 2013
 ************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef CARD_H
#define CARD_H
enum Card_suit {Clubs, Diamonds, Hearts, Spades};
enum Card_value {Ace, Two, Three, Four, Five, Six, Seven,
                 Eight, Nine, Ten, Jack, Queen, King};
int Randomize(int);

class Card {
  // new class used to store information about a single playing card
  
public:
  Card( );
  Card (Card_value value, Card_suit suit); 
  Card_value get_value( );
  Card_suit get_suit ();  
  void write_value();
  void write_suit();
  void write_card();
  void set_value(Card_value new_value);
  void set_suit (Card_suit new_suit);

private:
  Card_value value;
  Card_suit suit;
};

class Deck {

 public:
  Deck ();
  void shuffle ();
  Card dealCard();
 
 private:
  Card card_Deck[52];
  int dealCount;
};


#endif
