//Name: Olivia Lau
//Date: April 23, 2014
//Assignment: Assignment 8
//Program file: gradSchools.cc
//Purpose: implementation of gradSchools functions
//Precondition: gradSchools object has been initialized
//Postcondition: varies by function
//---------------------------------------------------------------

#include "gradSchools.h"


GradSchools :: GradSchools()
//default constructor
//Preconditions: none
//Postconditions: schools list is cleared out 
//---------------------------------------------------------------
{
  schools.clear();
}

void GradSchools :: addSchool (string name, string state, int women, 
			       int rateAI, int rateSys, int rateTheory, 
			       int effect, int ratePubs)
//Precondition: gradSchools object has been initialized
//Postconditions: a new school has been made and added to the list
//---------------------------------------------------------------
{
  //creates a school variable with all the parameters from function
  School theschool (name, state, women, rateAI, rateSys, rateTheory, 
		    effect, ratePubs);

  //inserts the school variable into the list
  schools.insert(schools.size(), theschool);
  
}

void GradSchools :: printGradSchools()
//Precondition: gradSchools object has been initilized
//Postcondition: Each school's information is printed out
{
  School temp;        //temporary school variable

  cout << "\nThere are 8 schools in the database:\n";

  //goes through the list to print out each school's information
  for (int i = 0; i < schools.size() ; i++)
    {
      schools.retrieve(i, temp);
      temp.printSchoolInfo();
      cout <<endl;
      
    }
}

void GradSchools :: computeRatings (int weightWomen, int weightAI, 
				    int weightSys, int weightTheory, 
				    int weightEffect, int weightPubs)
//Precondition: gradSchools object has been initialized and schools
//              have been added to the list
//Postcondition: Each school's rating has been computed
//-------------------------------------------------------------
{
  School temp;          //temporary variable to store school object

  //traverses list
  for(int i = 0; i < schools.size() ; i++)
    {
      schools.retrieve(i, temp);

      //computes the rating of school at position i
      temp.computeRating (weightWomen, weightAI, weightSys, 
			  weightTheory, weightEffect, weightPubs);

      //replaces the computed overall ranking with the old ranking
      schools.replace(i, temp);
    }
}

void GradSchools :: rankSchools (int weightWomen, int weightAI, 
				 int weightSys, int weightTheory, 
				 int weightEffect, int weightPubs)
//Precondition: gradSchools object has been initialized and school
//              have been added to the list
//Postconditions: schools are ranked based on the weight of each factor
//              and the schools are sorted from low to high.  The schools
//              are printed from high to low
//--------------------------------------------------------------
{

  //computes ratings based on the weight of each factor
  computeRatings(weightWomen, weightAI, weightSys, 
		 weightTheory, weightEffect, weightPubs);

  //sorts the list using insertion sort
  schools.insertion_sort();


  //prints out the schools in ranked order
  cout << "Ranking of Grad School programs, given your preferences:\n";

  School temp;           //temporary variable to hold school object

  //for loop to traverse list
  for (int i = schools.size()-1; i >= 0; i--)
    {
      //retrieves the school at position i and prints the name
      schools.retrieve(i, temp);
      cout << temp.name << endl;
    }

  cout << endl;
}

void GradSchools :: rankSchoolsFactor (string factor)
//Precondition: gradSchools object has been initialized and schools are added
//              to the list
//Postcondition: schools are ranked according to the factor given, and
//              the schools are ranked using computeRankings
//-------------------------------------------------------------------
{
  //saves first character in factor to char letter and makes lowercase
  char letter = tolower(factor.at(0));

  //switch case to see what the factor is
  switch (letter)
    {
      //women
    case 'w':
      rankSchools(1, 0, 0, 0, 0, 0);
      break;

      //AI
    case 'a':
      rankSchools(0, 1, 0, 0, 0, 0);
      break;

      //Systems
    case 's':
      rankSchools(0, 0, 1, 0, 0, 0);
      break;

      //Theory
    case 't':
      rankSchools(0, 0, 0, 1, 0, 0);
      break;

      //Effectiveness
    case'e':
      rankSchools(0, 0, 0, 0, 1, 0);
      break;

      //Publications
    case'p':
      rankSchools(0, 0, 0, 0, 0, 1);
      break;
    }
}
