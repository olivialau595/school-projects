//Name: Olivia Lau
//Date: April 22, 2014
//Assignment: Assignment 8
//Program File: school.cc
//Class: CSCI 132
//Purpose: Implementation of school functions
//Precondition: School object is initialized
//Postcondition: varies by function
//-----------------------------------------------------------------------

#include "school.h"


School :: School()
//default constructor
//precondition: none
//postcondition: sets all instance variables to zero
//---------------------------------------------------------
{
  women = 0;
  rateAI = 0;
  rateSys = 0;
  rateTheory = 0;
  effectiveness = 0;
  ratePubs = 0;
  overallRating = 0;
}

School :: School (string myName, string myState, int theWomen, int myRateAI, 
		  int myRateSys, int myRateTheory, int myEffectiveness, 
		  int myRatePubs)
//overloaded constructor
//precondition: none
//postcondition: sets all variables to given parameters
//--------------------------------------------------------------
{
  name = myName;
  state = myState;
  women = theWomen;
  rateAI = myRateAI;
  rateSys = myRateSys;
  rateTheory = myRateTheory;
  effectiveness = myEffectiveness;
  ratePubs = myRatePubs;
  overallRating = 0;
}

void School :: printSchoolInfo()
//precondition: school object is initialized
//postcondition: information for the school is printed on screen
//-----------------------------------------------------------
{
  cout << "\nName: " << name;
  cout << "\nState: " << state;
  cout << "\nRating of number of women in PhD's: " << women;
  cout << "\nRating of AI program: " << rateAI;
  cout << "\nRating of System programs: " << rateSys;
  cout << "\nRating of Theory program: " << rateTheory;
  cout << "\nEffectiveness rating: " << effectiveness;
  cout << "\nRating of faculty publications: " << ratePubs;
  cout << "\nOverall rating: " << overallRating;
}

void School :: computeRating (int weightWomen, int weightAI, int weightSys, 
			      int weightTheory, int weightEffect, 
			      int weightPubs)
//precondition: school object is initialized
//postcondition: the overall rating is calculated using the weight of
//              each factor
//------------------------------------------------------------
{
  //multiply each factor weight with the factor and sum up 
  overallRating = (weightWomen * women) + (weightAI * rateAI) + 
    (weightSys * rateSys) + (weightTheory * rateTheory) + 
    (weightEffect * effectiveness) + (weightPubs * ratePubs);
}

bool operator == (const School &x, const School &y)
//precondition: 2 school objects are initialized
//postcondition: returns true if the overall rating is equal
//-----------------------------------------------------------
{
  return (x.overallRating == y.overallRating);
}

bool operator > (const School &x, const School &y)
//precondition: 2 school objects are initialized
//postcondition: returns true if the overall rating for x is greater than 
//              the overall rating for y
//-------------------------------------------------------------------
{
  return (x.overallRating > y.overallRating);
}

bool operator < (const School &x, const School &y)
//precondition: 2 school objects are initialized
//postcondition: returns true if the overall rating for x is less than 
//              the overall rating for y
//----------------------------------------------------------------------

{
  return (x.overallRating < y.overallRating);
}

bool operator >= (const School &x, const School &y)
//precondition: 2 school objects are initialized
//postcondition: returns true if the overall rating for x is greater than 
//              or equal to the overall rating for y
//-----------------------------------------------------------

{
  return (x.overallRating >= y.overallRating);
}

bool operator <= (const School &x, const School &y)
//precondition: 2 school objects are initialized
//postcondition: returns true if the overall rating for x is less than 
//              or equal to the overall rating for y
//-----------------------------------------------------------

{
  return (x.overallRating <= y.overallRating);
}

bool operator != (const School &x, const School &y)
//precondition: 2 school objects are initialized
//postcondition: returns true if the overall rating for x is not equal to 
//              the overall rating for y
//-----------------------------------------------------------

{
  return (x.overallRating != y.overallRating);
}
