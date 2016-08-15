
#include "maze.h"

int Randomize(int);

Maze :: Maze(void) {
	width = max_width;
	height = max_height;
	for (int i = 0; i <= width; i++) {
		for (int j = 0; j <= height; j++ ) {
			horizontal_wall[i][j] = false;
			vertical_wall[i][j] = false;
			maze_position[i][j] = 0;
		}
	} //initialize walls (above&left) false and not visited

	for (int i = 0; i < width; i++) {
		horizontal_wall[i][0] = true;
		horizontal_wall[i][height] = true;
	} //set bottom and top edges as walls

	for (int i = 0; i < height; i++ ) {
		vertical_wall[0][i] = true;
		vertical_wall[width][i] = true;
	} //set right and left edges as walls

	maze_position[width-1][height-1] = 2;
	build_maze();
}  //default constructor

Maze :: Maze(int w, int h) {
	width = w;
	height = h;
	for (int i = 0; i <= width; i++) {
		for (int j = 0; j <= height; j++ ) {
			horizontal_wall[i][j] = false;
			vertical_wall[i][j] = false;
			maze_position[i][j] = 0;
		}
	} //initialize walls (above&left) false and not visited

	for (int i = 0; i < width; i++) {
		horizontal_wall[i][0] = true;
		horizontal_wall[i][height] = true;
	} //set bottom and top edges as walls

	for (int i = 0; i < height; i++ ) {
		vertical_wall[0][i] = true;
		vertical_wall[width][i] = true;
	} //set right and left edges as walls

	maze_position[width-1][height-1] = 2;
	build_maze();
} //constructor

void Maze :: clear(void) {
	for (int i = 0; i <= width; i++) {
		for (int j = 0; j <= height; j++ ) {
			horizontal_wall[i][j] = false;
			vertical_wall[i][j] = false;
			maze_position[i][j] = 0;
		}
		
	} //initialize walls (above&left) false and not visited

	for (int i = 0; i < width; i++) {
		horizontal_wall[i][0] = true;
		horizontal_wall[i][height] = true;
	} //set bottom and top edges as walls

	for (int i = 0; i < height; i++ ) {
		vertical_wall[0][i] = true;
		vertical_wall[width][i] = true;
	} //set right and left edges as walls
} //clear

void Maze :: build_maze( ) {
	clear( );
	maze_position[width-1][height-1] = 2;
	make_maze(0, 0, width, height, 15);
} //build_maze

void Maze :: make_maze(int left, int top, int right, int bottom, int depth) {
	/*//cout << "Entering make_maze " << endl;*/
	if ((top == bottom -1 ) || (left == right - 1) || (depth == 0)) {
		//do nothing
	} // if done 
        else {
		if ((rand() % 2) == 0) 
			divideHorizontally(left, top, right, bottom, depth);
		else 
			divideVertically(left, top, right, bottom, depth);
	} //still have more maze to fill in

} //make_maze

void Maze :: divideHorizontally (int left, int top, int right, int bottom, int depth) {
	int x, y;
	x = Randomize(right - left -1) + left;
	y = Randomize(bottom - top -2) + top + 1;
	/*cout << "left = " << left << ", right = " << right 
               << ", top = " << top << ", bottom = " << bottom << endl;
	cout << "Dividing horizontally, x = " << x << ", y = " << y << endl;*/
	for (int i = left; i <= x-1; i++ ) 
		set_horizontal_wall(i, y);
	
	for (int i = x+ 1; i < right; i++ ) 
		set_horizontal_wall(i, y);
	
	make_maze(left, y, right, bottom, depth -1);
	make_maze(left, top, right, y, depth -1);
} //divideHorizontally

void Maze :: divideVertically (int left, int top, int right, int bottom, int depth) {
	int x, y;
	x = Randomize(right - left - 2) + left + 1;
	y = Randomize(bottom - top -1) + top;
	/*cout << "left = " << left << ", right = " << right 
               << ", top = " << top << ", bottom = " << bottom << endl;
	cout << "Dividing vertically, x = " << x << ", y = " << y << endl;*/
	for (int i = top; i <= y-1; i++ ) 
		set_vertical_wall(x, i);
	
	for (int i = y+ 1; i < bottom; i++ ) 
		set_vertical_wall(x, i);
	
	make_maze(left, top, x, bottom, depth -1);
	make_maze(x, top, right, bottom, depth -1);
} //divideVertically

void Maze::print_maze( ) {
	for (int j = 0; j <= height; j++) {
		for(int i = 0; i <  width; i++ ) {
			if (horizontal_wall[i][j]) 
				cout << "---";
			else 
				cout << "   ";
		} //do the walls above
		cout << endl;
		for(int i = 0; i <= width; i++) {
			if(vertical_wall[i][j]) 
				cout << "|";
			else 
				cout << " ";
			
			if (maze_position[i][j] == 0) 
				cout <<  "  ";
			else if (maze_position[i][j] == 1) 
				cout << "X ";
			else 
				cout << "$ ";
		} //do left walls and then handle path
		cout << endl;
	}//for every row in the maze
}//print_maze

void Maze::set_horizontal_wall(int x, int y) {
	if ((x < 0) || (x >= width) || (y < 0) || (y > height)) 
		cout << "Error!  value out of range!  Horizontal wall not set." << endl;
	else 
		horizontal_wall[x][y] = true;
}//set_horizontal_wall

void Maze::set_vertical_wall(int x, int y) {
	if ((x < 0) || (x > width) || (y < 0) || (y >= height)) 
		cout << "Error!  value out of range!  Vertical wall not set." << endl;
	else
		vertical_wall[x][y] = true;
}//set_vertical_wall

void Maze::remove_horizontal_wall(int x, int y) {
	if ((x < 0) || (x >= width) || (y < 0) || (y > height)) 
		cout << "Error!  value out of range!  Horizontal wall not removed." << endl;
	else
		horizontal_wall[x][y] = false;
} //remove_horizontal_wall

void Maze::remove_vertical_wall(int x, int y) {
	if ((x < 0) || (x > width) || (y < 0) || (y >= height))
		cout << "Error!  value out of range!  Vertical wall not removed." << endl;
	else
		vertical_wall[x][y] = false;
} //remove_vertical_wall

void Maze::set_position(int x, int y, int val)
{
	if ((x < 0) || (x >= width) || (y < 0) || (y >= height))
		cout << "Error!  Position out of range!  Position not set." << endl;
	else
		maze_position[x][y] = val;
} //set_position


int Maze::get_position(int x, int y)
{
	if ((x < 0) || (x >= width) || (y < 0) || (y >= height)) {
		cout << "Error!  Position out of range!  No value returned" << endl;
		return -1;
	} //error 
	else
		return maze_position[x][y];
} //get_position

bool Maze::is_horizontal_wall(int x, int y) {
	if ((x < 0) || (x >= width) || (y < 0) || (y > height)) {
		cout << "Error.  Horizontal wall position out of range. " << endl;
		return true;
	} //error 
        else
		return horizontal_wall[x][y];
} //is_horizontal_wall
	
bool Maze::is_vertical_wall(int x, int y) {
	if ((x < 0) || (x > width) || (y < 0) || (y >= height)) {
		cout << "Error.  Vertical wall position out of range. " << endl;
		return true;
	} //error
	else
		return vertical_wall[x][y];
} //is_vertical_wall

int Maze::get_width( ) {
	return width;
} //get_width

int Maze::get_height( ) {
	return height;
} //get_height

/**********Randomize*****************************
 *Get a random number between 0 and range        *
 *************************************************/
int Randomize(int range)
{
    return (int)((double)rand()/((double)RAND_MAX+1.0) * (double)(range+1));
  
} //Randomize
