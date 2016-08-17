/*************************************************
 * File name: card.cc
 * Purpose: Implementation of Card and Deck classes
 *          Card class defines objects that behave
 *                 like playing cards.
 *          Deck class defines objects that behave
 *                 like deck of playing cards.
 *          Created for use in CSCI 132
 * Author: CSCI 132 Instructor
 * Date modified: January 9, 2011
 ************************************************/
#include "card.h"

Card::Card ( ) {
//Pre:
//     None
//Post:
//     Creates a card object which as value and suit given as the Ace of Clubs.
  value = Ace;
  suit = Clubs;
} // end Card()

Card::Card (Card_value init_value, Card_suit init_suit ) {
//Pre:
//     None
//Post:
//     Creates a card object which as value and suit given as the init_value and init_suit.
  value = init_value;
    suit = init_suit;
} // end Card(Card_value, Card_suit)
  
Card_value Card::get_value( ) {
//Pre:
//     None
//Post:
//     Returns the value of the calling card object.
  return value;
} // end get_value()

Card_suit Card::get_suit () {
//Pre:
//     None
//Post:
//     Returns the suit of the calling card object.
  return suit;
} // end get_suit()

void Card::write_value() {
//Pre:
//     None
//Post:
//     Writes the value of the calling card object to the monitor.

  switch(value) {
  case Ace:
    cout << "Ace";
    break;
  case Two:
    cout << "Two";
    break;
  case Three:
    cout << "Three";
    break;
  case Four:
    cout << "Four";
    break;
  case Five:
    cout << "Five";
    break;
  case Six:
    cout << "Six";
    break;
  case Seven:
    cout << "Seven";
    break;
  case Eight:
    cout << "Eight";
    break;
  case Nine:
    cout << "Nine";
    break;
  case Ten:
    cout << "Ten";
    break;
  case Jack:
    cout << "Jack";
    break;
  case Queen:
    cout << "Queen";
    break;
  case King:
    cout << "King";
    break;
  } //end switch
}//end write_value()

void Card::write_suit() {
//Pre:
//     None
//Post:
//     Writes the suit of the calling card object to the monitor

  switch(suit) {
  case Clubs:
    cout << "Clubs";
    break;
  case Diamonds:
    cout << "Diamonds";
    break;
  case Hearts:
    cout << "Hearts";
    break;
  case Spades:
    cout << "Spades";
    break;
  } //end switch
} //end write suit

void Card::write_card() {
//Pre:
//     None
//Post:
//     Writes the value and suit of the calling card object to the monitor.

  write_value();
  cout << " of ";
  write_suit();
} // end write_card()

void Card::set_value(Card_value new_value ) {
//Pre:
//     None
//Post:
//     Sets the value of the calling card object to new_value.
  value = new_value;
} // end set_value()

void Card::set_suit (Card_suit new_suit) {
//Pre:
//     None
//Post:
//     Sets the suit of the calling card object to new_suit.
  suit = new_suit;
} // end set_suit()


Deck::Deck( ) {
//Pre:
//     None
//Post:
//     Creates a new deck with 52 cards in order.
  for (int i = 0; i < 52; i++ ) {
    card_Deck[i].set_value((Card_value)(i%13));
    card_Deck[i].set_suit((Card_suit) (i/13));
  }
  dealCount = 0;
} // end Deck()

void Deck::shuffle( ) {
//Pre:
//     None
//Post:
//     Randomizes the order of the 52 cards in the deck.

  for (int i = 51; i > 0 ; i--) {
    Card tempCard;
    int randCard = Randomize(i);
    tempCard = card_Deck[i];
    card_Deck[i] = card_Deck[randCard];
    card_Deck[randCard] = tempCard;

  }
  dealCount = 0;
} // end shuffle()

Card Deck::dealCard( ) {
//Pre:
//     There are undealt cards left in the deck.
//Post:
//     Returns the card object at the top of the deck.

  Card myCard;
  if (dealCount >= 52 ) {
    cout << "Card deck empty" << endl;
    return myCard;
  }else {
    dealCount++;
    return card_Deck[dealCount -1];
  }
} // end dealCard()

/**********Randomize*****************************
 *Get a random number between 0 and range        *
 *************************************************/
int Randomize(int range)
//Pre:
//     range is a positive integer.
//Post:
//     returns a random number between 0 and range.

{
  
  return (int)(((double)rand()/((double)RAND_MAX + 1.0)) * (double)(range + 1));
  
} // end Randomize()


