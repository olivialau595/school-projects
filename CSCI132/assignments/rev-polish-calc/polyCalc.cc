/*******************************************************************
* Name: Olivia Lau
* Date: March 10, 2014
* Course: CSCI 132
* Assignment: Assignment 4
* Program: polyCalc.cc
* Purpose:  A polynomial calculator.  This program allows a user to enter
* polynomials and perform arithmetic operations on them--addition and 
* subtraction-- and evaluate the polynomial at a particular real number.
* Results can be printed.
***************************************************************************/
#include <iostream>
#include "polynomial.h"
#include "queue.h"
#include "stack.h"
using namespace std;

void introduction();
void instructions();
char get_command();
bool do_command(char, Stack &);

int main(void)
/***************************************************************
* Post: The program has executed simple polynomial arithmetic 
*     commands entered by the user.
*     Uses: The classes Stack and Polynomial and the functions 
*     introduction, instructions,do_command, and get_command.
*****************************************************************/
{
  Stack stored_polynomials;
  introduction( );
  instructions( );
  while (do_command(get_command( ), stored_polynomials));
} //end main()

void introduction() 
/***************************************************************
* Pre: none.  
* Post: Prints out an introduction to the polynomial 
*     calculator.
*****************************************************************/

{
	cout << "Welcome to the polynomial calculator! " << endl;
	cout << "This program allows you to perform arithmetic operations on polynomials." 
             << "\n and evalute them." << endl << endl;
} //end introduction()


void instructions() 
/***************************************************************
* Pre: none.  
* Post: Prints out instructions for the polynomial 
*   calculator.
*****************************************************************/

{
	cout << "First enter a command, ?, =, +, -, *, e, or q " << endl;
	cout << "Each command allows specific operations as follows: " << endl;
	cout << "?: Allows entry of a polynomial.  " << endl
             << "   Each term of the polynomial is specified by two integers." 
	     << endl
	     << "   The first integer specifies the coefficient and "
	     << endl
	     << "   the second specifies the degree of the term." 
	     << endl;
	cout << "   Terms must be entered in order of decreasing degree." 
	     << endl;
	cout << "   Terms with coefficient of zero should be left out." 
	     << endl;
	cout << "   End of entry is indicated with a zero coefficient." 
	     << endl << endl;
	cout << "=: Print out polynomial at the top of the stack" 
	     << "(the result of the last operation). " << endl;
	cout << "+: Add the two polynomials at the top of the stack." << endl;
	cout << "-: Subtract the two polynomials at the top of the stack. " 
	     << endl;
	cout << "*: Multiply the two polynomials at the top of the stack. " 
	     << endl;
	cout << "e: Evaluate the polynomial at the top of the stack. " << endl;
}


char get_command() {
/********************************************************************
* Pre: none.
* Post: Gets a valid command from the user, converts it to lower case,
*       and returns it.
**********************************************************************/
  char ans;
  cout << "Enter a command: ?, =, +, -, *, e, or q" << endl;
  cin >> ans;
  ans = tolower(ans);
  while( (ans != '?') && (ans != '=') && (ans != '+') 
        && (ans != '-') && (ans != '*') && (ans != 'e') && (ans != 'q')) {
    cout << "Invalid command.  Please enter ?, =, +, -, *, e, or q" << endl;
    cin >> ans;
    cout << ans;
    ans = tolower(ans);
  } //end while
  return ans;
} //end get_command()

bool do_command(char command, Stack &stored_polynomials)
/***********************************************************************
* Pre: The first parameter specifies a valid calculator command.
* Post: The command specified by the first parameter has been applied to the
*       Stack of Polynomial objects given by the second parameter. A result of
*       true is returned unless command == q.
* Uses: The classes Stack and Polynomial. 
************************************************************************/
{
  Polynomial p, q, r;
  double number;

  switch (command) {
    case '?':
      p.read( );
      if (stored_polynomials.push(p) == overflow) {
        cout << "Warning: Stack full, lost polynomial" << endl;
      }
      break;

    case '=':
      if (stored_polynomials.empty( )) {
        cout << "Stack empty" << endl;
      } else {
        stored_polynomials.top(p);
        p.print( );
      } //end if
      break;

    case '+':
      if (stored_polynomials.empty( )) {
        cout << "Stack empty" << endl;
      } else {
        stored_polynomials.top(p);
        stored_polynomials.pop( );
        if (stored_polynomials.empty( )) {
          cout << "Stack has just one polynomial" << endl;
          stored_polynomials.push(p);
        } else {
          stored_polynomials.top(q);
          stored_polynomials.pop( );
          r.equals_sum(q, p);
          if (stored_polynomials.push(r) == overflow)
            cout << "Warning: Stack full, lost polynomial" << endl;
        } //end inner if-else
      } //end outer if-else
      break;

   case '-':
     //checks to see if stack is empty/has enough polynomials
     if (stored_polynomials.empty())
       cout << "Stack empty\n";
     else
       {
	 stored_polynomials.top (p);
	 stored_polynomials.pop();

	 if (stored_polynomials.empty())
	   {
	     cout << "Stack has just one polynomial\n";
	     stored_polynomials.push(p);
	   }
	 else
	   {
	     stored_polynomials.top(q);
	     stored_polynomials.pop();
	     r.equals_difference(q, p);

	     //checks to see if there is room to push answer
	     if (stored_polynomials.push(r) == overflow)
	       cout << "Warning: Stack full, lost polynomial\n";
	   }//end inner if-else
       }//end outer if-else
     break;
      
   case '*':
     //checks if stack is empty/has one polynomial
     if (stored_polynomials.empty())
       cout << "Stack empty\n";
     else
       {
	 stored_polynomials.top(p);
	 stored_polynomials.pop();

	 if (stored_polynomials.empty())
	   {
	     cout << "Stack has just one polynomial\n";
	     stored_polynomials.push(p);
	   }
	 else
	   {
	     stored_polynomials.top(q);
	     stored_polynomials.pop();
	     r.equals_product(p, q);

	     //checks if stack has room to push answer
	     if (stored_polynomials.push(r) == overflow)
	       cout << "Warning: Stack full, lost polynomial\n";
	   }//end inner if-else
       }//end outer if-else
      break;

   case 'e':
     //checks if stack is empty
    if(stored_polynomials.empty())
      cout << "Stack empty";
    else
      {
	cout << "Give an argument at which to evaluate the polynomial: ";
	cin >> number;

	stored_polynomials.top (p);

	//outputs answer
	cout << "The polynomial: ";
	p.print();
	cout << "     at " << number << " evaluates to "<< p.evaluate(number)
	     << endl;
      }
      break;

    case 'q':
      cout << "Calculation finished." << endl;
      return false;
  } //end switch

  return true;
} //end do_command()






