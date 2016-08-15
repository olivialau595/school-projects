#include <string>
#include <iostream>
using namespace std;

#ifndef SCHOOL_H
#define SCHOOL_H
class School {
  public:
	string name;	  // name of the school
	string state;	  // state in which school is located
	int women;		// rating of percentage of women PhD's (1 to 10)
	int rateAI;		// rating of AI program (1 to 10)
	int rateSys;	  // rating of Computer Systems program (1 to 10)
	int rateTheory;	  // rating of Theory program (1 to 10)
	int effectiveness;	// rating of effectiveness in educating research scholars 
	int ratePubs;	  // rating of impact of publications per faculty member 
	int overallRating;	// overall rating that considers all of the above factors 

	School ();
	School (string myName, string myState, int theWomen, int myRateAI, int myRateSys,
		int myRateTheory, int myEffectiveness, int myRatePubs);
	void printSchoolInfo ();
	void computeRating (int weightWomen, int weightAI, int weightSys, 
			    int weightTheory, int weightEffect, int weightPubs);
};

bool operator ==(const School &x,const School &y);
bool operator >(const School &x,const School &y);
bool operator <(const School &x,const School &y);
bool operator >=(const School &x,const School &y);
bool operator <=(const School &x,const School &y);
bool operator !=(const School &x,const School &y);


#endif
