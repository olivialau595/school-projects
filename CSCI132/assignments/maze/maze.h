#include <iostream>
#include <cstdlib>

using namespace std;

const int max_width = 50;
const int max_height = 50;

class Maze {
	public:
		Maze( );
		Maze(int w, int h);
		void clear( );
		void build_maze( );
		void print_maze( );
		void set_horizontal_wall(int x, int y);
		void set_vertical_wall(int x, int y);
		void remove_horizontal_wall(int x, int y);
		void remove_vertical_wall(int x, int y);
		void set_position(int x, int y, int val);
		int get_position(int x, int y);
		int get_width();
		int get_height();
		bool is_horizontal_wall(int x, int y);
		bool is_vertical_wall(int x, int y);
	private:
		int width, height;
		bool horizontal_wall[max_width +1][max_height+1];
		bool vertical_wall[max_width +1][max_height + 1];
		int maze_position[max_width + 1][max_height + 1];
		void make_maze(int left, int top, int right, int bottom, int depth);
		void divideHorizontally (int left, int top, int right, int bottom, int depth);
		void divideVertically (int left, int top, int right, int bottom, int depth);
};
