#pragma once
// 一些杂七杂八

#include <vector>
#include <graphics.h>

using namespace std;

#define Size 30    //游戏大小
#define Box_size 20
#define Box 20

//画布的尺寸
#define Width 900
#define Height 610
#define Offset 10

#define Num_Pits 10   //障碍物的个数

#define Key_up 72
#define Key_down 80
#define Key_left 75
#define Key_right 77

enum node_type { NONE, SNAKE, FOOD, PITS, HEAD, SNAKE1, HEAD1 };
enum Direction {UP, DOWN, RIGHT, LEFT, NO };


int decodert(int x);   //将数组坐标转化为画布坐标

class Node {  // 各种组件的小节点
public:
	Node(const int _x, const int _y, const node_type _type) : x(_x), y(_y), type(_type) {}    //初始化
	void update(int new_x, int new_y) { this->x = new_x; this->y = new_y; };
	void update_type(const node_type _type) { this->type = _type; };
	int id_x() { return this->x; };        //对外接口
	int id_y() { return this->y; };
	node_type id_type() { return this->type; }
	void draw() {   //画出节点
		int boardx = decodert(this->x);
		int boardy = decodert(this->y);
		switch (this->type) {
		case SNAKE:
			setfillcolor(BLUE);
			solidrectangle(boardx, boardy, boardx + Box_size, boardy + Box_size);
			break;
		case FOOD:
			setfillcolor(RED);
			solidrectangle(boardx, boardy, boardx + Box_size, boardy + Box_size);
			break;
		case PITS:
			setfillcolor(BLACK);
			solidrectangle(boardx, boardy, boardx + Box_size, boardy + Box_size);
			break;
		case HEAD:
			setfillcolor(LIGHTCYAN);
			solidrectangle(boardx, boardy, boardx + Box_size, boardy + Box_size);
			break;
		case SNAKE1:
			setfillcolor(GREEN);
			solidrectangle(boardx, boardy, boardx + Box_size, boardy + Box_size);
			break;
		case HEAD1:
			setfillcolor(BROWN);
			solidrectangle(boardx, boardy, boardx + Box_size, boardy + Box_size);
			break;
		case NONE:
			setfillcolor(WHITE);
			solidrectangle(boardx, boardy, boardx + Box_size, boardy + Box_size);
			break;
		}
	}
	void clear() {   //清除节点
		int boardx = decodert(this->x);
		int boardy = decodert(this->y);
		setfillcolor(WHITE);
		solidrectangle(boardx, boardy, boardx + Box_size, boardy + Box_size);
	}
private:
	int x, y;
	node_type type;
};

class Coord {
public:
	Coord(int _x, int _y) : x(_x), y(_y) {}
	int id_x() { return this->x; };
	int id_y() { return this->y; };
	void update(int _x, int _y) { this->x = _x; this->y = _y; };
private:
	int x, y;
};


void my_find_empty_box();   //找到空的格子

void find_empty_pits();    //按照规则找到可以放pit的格子