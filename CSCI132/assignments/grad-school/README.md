# Grad Schools

This project was created as an excercise in data structures (CSCI132 - Spring 2014) to choose the best
sort to use in a list for the given situation. 

The program scores and sorts a list of graduate schools by specific rankings indicated by the user. 
Each grad school object holds a list of school objects that stores the rankings to specific aspects of 
the school (number of women, AI program, Theory program, faculty publications, etc). A rating of the
school is computed for each school given the weight of each aspect. Insertion sort was used because the 
size of the list was small. It was the most efficient in terms of space compared to the other sorts. If 
the size of the list was different, then insertion sort may not have been the best sort to use. 