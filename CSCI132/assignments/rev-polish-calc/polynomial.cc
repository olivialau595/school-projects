/************************************************************************
* Name: Olivia Lau
* Date: March 10, 2014
* Course: CSCI 132
* Assignment: Assignment 4
* Program: polynomial.cc
* Purpose: Implementation of polynomial class
* Precondition: polynomial object has been declared
* Postcondition: varies by function, see function postcondition
***************************************************************************/
#include <iostream>
#include <math.h>        //need to include this library to use pow(x, y)
#include "polynomial.h"
using namespace std;

void Polynomial :: equals_difference(Polynomial p, Polynomial q)
/**********************************************************************
* Pre: None
* Post: The Polynomial object is reset as the difference of the two parameters.
**********************************************************************/
{
  clear();              //clears polynomial object

  while (!p.empty() || !q.empty())
    {
      Term pterm, qterm;

      //if p's degree is greater then add term to polynomial
      if (p.degree() > q.degree())
	{
	  p.serve_and_retrieve (pterm);
	  append (pterm);
	}
      //if q's degree is greater then add the negative of the
      //term to polynomial
      else if (q.degree() > p.degree())
	{
	  q.serve_and_retrieve (qterm);
	  qterm.coefficient *= (-1);
	  append (qterm);
	}
      else
	{
	  //saves the term from each polynomial 
	  p.serve_and_retrieve (pterm);
	  q.serve_and_retrieve (qterm);

	  //checks to see if they are opposite
	  if(pterm.coefficient - qterm.coefficient != 0)
	    {
	      Term answerterm (pterm.degree, 
			       pterm.coefficient - qterm.coefficient);
	      append(answerterm);
	    }
	}
    }//end while

}//end equals_difference

void Polynomial :: equals_product(Polynomial p, Polynomial q)
/**********************************************************************
* Pre: None
* Post: The Polynomial object is reset as the product of the two parameters.
**********************************************************************/
{
  clear();            //clears polynomial object

  Polynomial temp1;   //temp polynomial to hold mult_term answer
  Polynomial temp2;   //temp polynomial to hold the addition of 2 polynomials
  Polynomial total;   //total of all polynomials
  Term tempterm;      //temporary term from polynomial q

  while (!q.empty())
    {
      q.serve_and_retrieve(tempterm);

      //multiplies the polynomial p with tempterm from q
      temp1.mult_term(p, tempterm);

      //adds the polynomials
      temp2.equals_sum(total, temp1);
      total = temp2;
    }

  //copies total to polynomial object
  while(!total.empty())
    {
      total.serve_and_retrieve (tempterm);
      append (tempterm);
    }

}//end equals_product


void Polynomial :: mult_term(Polynomial p, Term t)
/**********************************************************************
* Pre: None
* Post: The Polynomial object is reset as the product of the polynomial,
*       p, and the single term, t.
**********************************************************************/
{
  clear();                    //clears polynomial object

  Term tempterm;              //temp term used for serve and retrieve
  Term addterm = Term(0, 0);  //term that gets appended to polynomial

  //multiplies each term in temp polynomial with t and stores in p
  while(!p.empty())
    {
      p.serve_and_retrieve(tempterm);

      //multiply the coefficients
      addterm.coefficient = tempterm.coefficient * t.coefficient;

      //add the degrees
      addterm.degree = tempterm.degree + t.degree;
      append (addterm);
    }

}//end mult_term

double Polynomial :: evaluate (double number)
/**********************************************************************
* Pre: None
* Post: Evaluates the Polynomial object at number.
**********************************************************************/
{
   Polynomial p = *this;  //uses the object "receiving the message", but
                          //does not change the object data.
   double answer;         //variable for the answer
   Term temp;             //variable to hold term from polynomial

   while (!p.empty())
     {
       p.serve_and_retrieve (temp);

       //adds evaluated term to answer variable
       answer += ((temp.coefficient) * (pow (number, temp.degree)));
     }

   return answer;
} //end evaluate

Error_code Polynomial :: equals_quotient(Polynomial p, Polynomial q)
/**********************************************************************
* Pre: None
* Post: The Polynomial object is reset as the quotient of the two parameters.
**********************************************************************/
{
  cout << "This function not yet implemented." << endl;
  return success;
} //end equals_quotient()


void Polynomial :: print( )
/**********************************************************************
* Pre: None
* Post: The Polynomial is printed to cout. If the polynomial is empty, 
*       0 is printed.
**********************************************************************/
{
  
  double r;
  Polynomial temp;
  bool first_term = true;
  while (!empty( )) {
    Term print_term;
    serve_and_retrieve(print_term);
    temp.append(print_term);
    if (first_term) { // In this case, suppress printing an initial +.
      first_term = false;
      if (print_term.coefficient < 0) {
        cout << "- ";
      } 
    } else if (print_term.coefficient < 0) {
      cout << " - ";
    } else {
      cout << " + ";
    }
    if (print_term.coefficient >= 0) {    
      r = print_term.coefficient;
    } else {
      r = -(print_term.coefficient);
    } 
    if (r != 1) {
      cout << r;
    } 
    if (print_term.degree > 1) {
      cout << " X^" << print_term.degree;
    } 
    if (print_term.degree == 1) {
      cout << " X";
    }
    if (r == 1 && print_term.degree == 0) {
      cout << " 1";
    }
  } //end while
  if (first_term) {
    cout << "0"; // Print 0 for an empty Polynomial.
  } //end if
  cout << endl;
  while(!temp.empty( )) {
    Term temp_term;
    temp.serve_and_retrieve(temp_term);
    append(temp_term);
  }
} // end print()

void Polynomial :: read( )
/**********************************************************************
* Pre: None
* Post: The Polynomial is read from cin.
**********************************************************************/
{
  clear( );                  /* An Extended_queue function */
  double coefficient;
  int last_exponent, exponent;
  bool first_term = true;
  cout << "Enter the coefficients and exponents for the polynomial, "
       << "one pair per line. Exponents must be in descending order." << endl
       << "Enter a coefficient of 0 or an exponent of 0 to terminate." << endl;
  do {
    cout << "\tcoefficient? " << flush;
    cin >> coefficient;
    if (coefficient != 0.0) {
      cout << "\texponent? " << flush;
      cin >> exponent;
      if ((!first_term && exponent >= last_exponent) || exponent < 0) {
        exponent = 0;
        cout << "Bad exponent: Polynomial terminates without its last term."
             << endl;
      } else {
        Term new_term(exponent, coefficient);
        append(new_term);
        first_term = false;
      } //end if
      last_exponent = exponent;
    }
  } while (coefficient != 0.0 && exponent != 0); //end do-while
} // end read()

void Polynomial :: equals_sum(Polynomial p, Polynomial q)
/**********************************************************************
* Pre: None
* Post: The Polynomial object is reset as the sum of the two parameters.
**********************************************************************/
{
  clear( );
  while (!p.empty( ) || !q.empty( )) {
    Term p_term, q_term;
    if (p.degree( ) > q.degree( )) {
      p.serve_and_retrieve(p_term);
      append(p_term);
    } else if (q.degree( ) > p.degree( )) {
      q.serve_and_retrieve(q_term);
      append(q_term);
    } else {
      p.serve_and_retrieve(p_term);
      q.serve_and_retrieve(q_term);
      if (p_term.coefficient + q_term.coefficient != 0) {
        Term answer_term(p_term.degree, p_term.coefficient + q_term.coefficient);
        append(answer_term);
      } //end inner if
    } //end if-else
  } // end while
} //end equals_sum()


int Polynomial :: degree( ) const
/**********************************************************************
* Pre: None
* Post:If the Polynomial is identically 0, a result of -1 is returned. 
*      Otherwise the degree of the Polynomial is returned.
**********************************************************************/
{
  if (empty( )) return -1;
  Term lead;
  retrieve(lead);
  return lead.degree;
} //end degree( )

