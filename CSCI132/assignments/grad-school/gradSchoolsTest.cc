//
// gradSchoolTest.cc
//
// code to test the creation of a GradSchools object that stores and sorts
// multiple instances of a School
#include <iostream>
#include "gradSchools.h"
#include "gradSchools.cc"
#include "school.h"
#include "school.cc"
#include "sortable_list.h"
#include "sortable_list.cc"
#include "list.h"
#include "list.cc"
using namespace std;

GradSchools makeGradSchools () {
	// Note that the ratings here are somewhat arbitrary
	GradSchools newSchools;
	newSchools.addSchool("MIT", "Massachusetts", 5, 10, 9, 10, 10, 7);
	newSchools.addSchool("Stanford", "California", 9, 8, 5, 8, 10, 9);
	newSchools.addSchool("CMU", "Pennsylvania", 6, 9, 9, 7, 8, 6);
	newSchools.addSchool("UC Berkeley", "California", 4, 6, 8, 9, 9, 9);
	newSchools.addSchool("Cornell", "New York", 9, 5, 8, 9, 9, 8);
	newSchools.addSchool("Univ. of Illinois", "Illinois", 4, 7, 7, 7, 7, 7);
	newSchools.addSchool("Univ. of Washington", "Washington", 7, 5, 7, 8, 8, 8);
	newSchools.addSchool("Princeton", "New Jersey", 8, 4, 5, 8, 7, 10);
	return newSchools;
} //makeGradSchools

int main (void) {
	GradSchools myGradSchools = makeGradSchools();
	int weightWomen = 5;
	int weightAI = 5; 
	int weightSys = 2;
	int weightTheory = 0;
	int weightEffectiveness = 5;
	int weightPubs = 4;
	myGradSchools.rankSchools(weightWomen, weightAI, weightSys, weightTheory,
				  weightEffectiveness, weightPubs);
	cout << endl;
	myGradSchools.rankSchoolsFactor("AI");
	myGradSchools.rankSchoolsFactor("women");
	myGradSchools.printGradSchools();
	
	return 0;
} //end main
	
