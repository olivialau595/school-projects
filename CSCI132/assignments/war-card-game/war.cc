//Olivia Lau                         war.cc
//February 7, 2014
//CSCI 132
//Purpose: Client code for war
//Precondition: none
//Postcondition: Client plays war game
//-------------------------------------------------

#include <iostream>
#include "stack.h"
#include "card.h"

using namespace std;

void movingDeck (Stack &draw, Stack &win);

int main()
{
  //declaration of the deck and 5 stacks
  Deck theDeck;
  Stack computerDraw;
  Stack computerWin;
  Stack playerDraw;
  Stack playerWin;
  Stack tie;

  //declaration of 2 card objects
  Card computerCard;
  Card playerCard;

  //variables
  int numberofcards;
  bool withinrange = false;
  char answer;
  int playertotal;
  int computertotal;

  theDeck.shuffle();

  cout << "\nShuffling cards.";
  cout << "\nHow many cards in each hand (not more than 26)? ";
  cin >> numberofcards;

  //asks client to enter cards in each hand 
  do
    {
      if(numberofcards > 26)
	{
	  cout << "That's too many cards. ";
	  cout << "Please enter a number less than 27: ";
	  cin >> numberofcards;
	}
      else if(numberofcards < 1)
	{
	  cout << "Too few cards. ";
	  cout << "Please enter a number greater than zero: ";
	  cin >> numberofcards;
	}
      else 
	  withinrange = true;
    }while (withinrange ==false);


  //draws the number of cards the client entered
  for(int i = 0; i < numberofcards; i++)
    {
      computerDraw.push(theDeck.dealCard());
      playerDraw.push(theDeck.dealCard());
    }

  cout << "\nDealing cards.";
  cout << "\n\nDo you want to begin playing (y/n)? ";
  cin >> answer;

  while (answer =='y')
    {
      //drawing card for player and computer
      computerDraw.top(computerCard);
      playerDraw.top(playerCard);

      //Display what each card is
      cout << "\nYour card is ";
      playerCard.write_card();
      cout << "\nThe computer's card is ";
      computerCard.write_card();

      //compares value of cards and pushes onto the correct stack
      if (computerCard.get_value() > playerCard.get_value())
        {
          computerWin.push(computerCard);
          computerWin.push(playerCard);
          cout << "\nComputer wins this round";
        }
      else if(playerCard.get_value() > computerCard.get_value())
        {
          playerWin.push(playerCard);
          playerWin.push(computerCard);
          cout << "\nYou win this round";
        }
      else
        {
          tie.push(computerCard);
          tie.push(playerCard);
          cout << "\nThis round is a tie\n";
        }

      //pops off top card on each draw stack
      computerDraw.pop();
      playerDraw.pop();
	
      //checks if either player has 0 cards
      if(computerWin.size() + computerDraw.size() == 0)
        {
          answer = 'n';
          cout <<"\n\nThe computer has no more cards left.";
        }
      if(playerWin.size() + playerDraw.size() == 0)
        {
          answer = 'n';
          cout << "\n\nYou have no more cards.";
        }
    
      //moves cards from win to draw deck when neccessary 
      if (computerDraw.empty())
        {
	  //only move deck if there are cards in the win pile
	  if(!computerWin.empty())
	    {
	      cout << "\n\nMoving computer's win pile to draw pile.\n";
	      movingDeck (computerDraw, computerWin);
	    }
        }
      if(playerDraw.empty())
        {
	  if(!playerWin.empty())
	    {
	      cout << "\nMoving your win pile to draw pile.\n";
	      movingDeck (playerDraw, playerWin);
	    }
        }
	    
      if (answer == 'y')
        {
	  cout << "\n\nDo you want to continue (y/n)? ";
	  cin >> answer;
        }
    }//end of while loop

  //calculates both player's total cards
  playertotal = playerDraw.size() + playerWin.size();
  computertotal = computerDraw.size() + computerWin.size();

  cout << "\nYou have " << playertotal  << " cards";
  cout << "\nThe computer has " << computertotal  << " cards";
  cout << "\nThere are " << tie.size() << " cards in the tie pile\n";

  //determines winner of the game
  if( playertotal > computertotal)
    cout << "You win!\n";
  else if(computertotal > playertotal)
    cout << "The computer wins!\n";
  else 
    cout << "It is a tie\n\n\n";

  return 0;
}//end of main


//Precondition: the player's or computer's draw deck has no more cards
//Postcondition: the player's or computer's win deck is moved to the draw deck
//---------------------------------------------------------------------------
void movingDeck (Stack &draw, Stack &win)
{
  Stack tempstack;
  Card tempcard;

  //pops off card in win stack and pushes onto  tempstack -- reverse order
  while (win.top(tempcard) == success)
    {
      draw.push(tempcard);

      //displays movesthe move
      cout << "Moving ";
      tempcard.write_card();
      cout << endl;

      win.pop();
    }
}//end of movingDeck


