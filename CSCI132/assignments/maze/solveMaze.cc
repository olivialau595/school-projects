/***********************************************************
* Name: Olivia Lau
* Program file: solveMaze.cc
* Class: CSCI 132
* Assignment: Assignment 5
* Date: March 17, 2014
* Purpose: Program to draw a random maze and solve it using recursion
* Input: user inputs dimensions of maze
* Postcondition: Maze is drawn and solved (if possible)
**************************************************************/
 
#include "maze.h"

bool solve(Maze &, int, int);
bool isWallAbove(Maze &, int, int);
bool isWallBelow(Maze &, int, int);
bool isWalltoLeft(Maze &, int, int);
bool isWalltoRight(Maze &, int, int);

int main()  {
	int width, height;
	char answer;
	
	cout << "Do you want me to solve a maze (y/n)? ";
	cin >> answer;

	while (answer == 'y') {
		cout << "Enter number for width of maze: " ;
		cin >> width;
		cout  << "Enter number for height of maze: ";
		cin >> height;

		Maze myMaze(width, height);
		cout << "Maze to be solved: " << endl;
		myMaze.print_maze();
		if (!solve(myMaze, 0, 0)) {
			cout << "Couldn't solve this maze!" << endl;
		} //if maze not solved
		
		cout << "Do you want me to solve another maze (y/n)? ";
		cin >> answer;
                cout << answer << endl;
	} // while solving another maze
		
	return 0;
} //end main program


//Precondition: Maze object is initialized,
//              user has entered dimensions of maze
//Postcondition: returns true or false depending on if maze is solved
//-----------------------------------------------------------------
bool solve(Maze &theMaze, int x, int y) {

  bool flag = false;         //flag to mark if there is a working next step

  //base cases
  if(theMaze.get_position(x, y) == 2){
      theMaze.print_maze();
      return true;
  }
  else if(theMaze.get_position(x,y) == 1)
    return false;
    
  else{
    //sets the oposition to 1
      theMaze.set_position(x, y, 1);

      //checks wall above
      if(!isWallAbove(theMaze, x, y))
	  flag = solve(theMaze, x, y - 1);

      //checks wall below
      if(!isWallBelow(theMaze, x, y) && !flag)
	  flag = solve(theMaze, x, y + 1);

      //checks left wall
      if(!isWalltoLeft(theMaze, x, y) && !flag)
	  flag = solve(theMaze, x - 1, y);
   
      //checks right wall
      if(!isWalltoRight(theMaze, x, y) && !flag)
	  flag = solve(theMaze, x + 1, y);

      //if no possible positions, then set back to zero, else return true
      if(!flag)
	theMaze.set_position(x, y, 0);
      else 
	return true;
  }

} //end solve

//pre: maze object is initialized and position (x, y) is picked
//post: returns true if there is no wall above, false if otherwise
//-------------------------------------------------------------------------
bool isWallAbove(Maze &theMaze, int x, int y) {

  return theMaze.is_horizontal_wall(x, y);

} //end isWallAbove

//pre: maze object is initialized and position (x, y) is picked
//post: returns true if there is no wall below, false if otherwise
//-------------------------------------------------------------------------
bool isWallBelow(Maze &theMaze, int x, int y) {

  return theMaze.is_horizontal_wall(x, y+1);

} //end isWallBelow

//pre: maze object is initialized and position (x, y) is picked
//post: returns true if there is no wall on left, false if otherwise
//-------------------------------------------------------------------------
bool isWalltoLeft(Maze &theMaze, int x, int y) {

  return theMaze.is_vertical_wall (x, y);

} //end isWalltoLeft

//pre: maze object is initialized and position (x, y) is picked
//post: returns true if there is no wall on right, false if otherwise
//-------------------------------------------------------------------------
bool isWalltoRight(Maze &theMaze, int x, int y) {

  return theMaze. is_vertical_wall (x+1, y);

} //end isWalltoRight
