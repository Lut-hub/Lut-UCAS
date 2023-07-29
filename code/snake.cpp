#include "snake.h"
#include <cmath>

void generate_pits(int num) {
	for (int i = 0; i < num; i++) {
		Pit pit{};
	}
}


void Snake::Draw() {
	list<Node>::iterator j;
	for (j = snake.begin(); j != snake.end(); j++) {
		j->draw();
	}
}

void Snake::Move_ai() {      //蛇进行移动
	// Change_direction();
	switch (direction)
	{
	case UP:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE);
		snake.push_front(Node(snake.front().id_x(), snake.front().id_y() - 1, HEAD));
		Board[snake.front().id_y()][snake.front().id_x()] = HEAD;
		break;
	case DOWN:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE);
		snake.push_front(Node(snake.front().id_x(), snake.front().id_y() + 1, HEAD));
		Board[snake.front().id_y()][snake.front().id_x()] = HEAD;
		break;
	case RIGHT:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE);
		snake.push_front(Node(snake.front().id_x() + 1, snake.front().id_y(), HEAD));
		Board[snake.front().id_y()][snake.front().id_x()] = HEAD;
		break;
	case LEFT:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE);
		snake.push_front(Node(snake.front().id_x() - 1, snake.front().id_y(), HEAD));
		Board[snake.front().id_y()][snake.front().id_x()] = HEAD;
		break;
	default:
		break;
	}
}


void Snake::Update_snake_ai() {//更新蛇的状态
	if (!Need_grow) {
		Board[snake.back().id_y()][snake.back().id_x()] = NONE;
		snake.back().clear();
		snake.pop_back();
		Draw();
		return;
	} //如果无需增长，则不用把最后一个弹出，不用编写一个增长函数，因为可能找不到新的尾巴在哪
	Need_grow = false;
	Draw();
	return;
}


void Snake::Move_ai_1() {      //蛇进行移动
	// Change_direction();
	switch (direction)
	{
	case UP:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE1);
		snake.push_front(Node(snake.front().id_x(), snake.front().id_y() - 1, HEAD1));
		Board[snake.front().id_y()][snake.front().id_x()] = HEAD1;
		break;
	case DOWN:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE1);
		snake.push_front(Node(snake.front().id_x(), snake.front().id_y() + 1, HEAD1));
		Board[snake.front().id_y()][snake.front().id_x()] = HEAD1;
		break;
	case RIGHT:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE1);
		snake.push_front(Node(snake.front().id_x() + 1, snake.front().id_y(), HEAD1));
		Board[snake.front().id_y()][snake.front().id_x()] = HEAD1;
		break;
	case LEFT:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE1);
		snake.push_front(Node(snake.front().id_x() - 1, snake.front().id_y(), HEAD1));
		Board[snake.front().id_y()][snake.front().id_x()] = HEAD1;
		break;
	default:
		break;
	}
}


void Snake::Update_snake_ai_1() {//更新蛇的状态
	if (!Need_grow) {
		Board[snake.back().id_y()][snake.back().id_x()] = NONE;
		snake.back().clear();
		snake.pop_back();
		Draw();
		return;
	} //如果无需增长，则不用把最后一个弹出，不用编写一个增长函数，因为可能找不到新的尾巴在哪
	Need_grow = false;
	Draw();
	return;
}


void Snake::Move() {      //蛇进行移动
	Change_direction();
	switch (direction)
	{
	case UP:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE);
		snake.push_front(Node(snake.front().id_x(), snake.front().id_y() - 1, HEAD));
		break;
	case DOWN:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE);
		snake.push_front(Node(snake.front().id_x(), snake.front().id_y() + 1, HEAD));
		break;
	case RIGHT:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE);
		snake.push_front(Node(snake.front().id_x() + 1, snake.front().id_y(), HEAD));
		break;
	case LEFT:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE);
		snake.push_front(Node(snake.front().id_x() - 1, snake.front().id_y(), HEAD));
		break;
	default:
		break;
	}
}


void Snake::Update_snake() {//更新蛇的状态
	if (!Need_grow) {
		Board[snake.front().id_y()][snake.front().id_x()] = HEAD;
		Board[snake.back().id_y()][snake.back().id_x()] = NONE;
		snake.back().clear();
		snake.pop_back();
		Draw();
		return;
	} //如果无需增长，则不用把最后一个弹出，不用编写一个增长函数，因为可能找不到新的尾巴在哪
	Need_grow = false;
	Board[snake.front().id_y()][snake.front().id_x()] = HEAD;
	Draw();
	return;
}


void Snake::Move_1() {      //蛇进行移动
	Change_direction();
	switch (direction)
	{
	case UP:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE1);
		snake.push_front(Node(snake.front().id_x(), snake.front().id_y() - 1, HEAD1));
		break;
	case DOWN:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE1);
		snake.push_front(Node(snake.front().id_x(), snake.front().id_y() + 1, HEAD1));
		break;
	case RIGHT:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE1);
		snake.push_front(Node(snake.front().id_x() + 1, snake.front().id_y(), HEAD1));
		break;
	case LEFT:
		Board[snake.front().id_y()][snake.front().id_x()] = SNAKE;
		snake.front().update_type(SNAKE1);
		snake.push_front(Node(snake.front().id_x() - 1, snake.front().id_y(), HEAD1));
		break;
	default:
		break;
	}
}

void Snake::Update_snake_1() {//更新蛇的状态
	if (!Need_grow) {
		Board[snake.front().id_y()][snake.front().id_x()] = HEAD1;
		Board[snake.back().id_y()][snake.back().id_x()] = NONE;
		snake.back().clear();
		snake.pop_back();
		Draw();
		return;
	} //如果无需增长，则不用把最后一个弹出，不用编写一个增长函数，因为可能找不到新的尾巴在哪
	Need_grow = false;
	Board[snake.front().id_y()][snake.front().id_x()] = HEAD1;
	Draw();
	return;
}

bool Snake::Dead_1() {
	int coord_x = snake.front().id_x();
	int coord_y = snake.front().id_y();
	if (coord_x >= real_size || coord_y >= real_size || coord_x < 0 || coord_y < 0) {
		//蛇越界死掉
		return true;
	}
	if (Board[coord_y][coord_x] == SNAKE || Board[coord_y][coord_x] == PITS || Board[coord_y][coord_x] == HEAD) {
		//蛇头撞到自己或者撞到PIT
		return true;
	}
	return false;
}

void Snake::Change_direction() {
	int key;
	if (_kbhit()) { //如果检测到键盘敲击
		key = _getch();
		if (direction == UP) {  // 禁止无效输出
			switch (key) {
			case Key_up:
				direction = UP;
				break;
			case Key_left:
				direction = LEFT;
				break;
			case Key_right:
				direction = RIGHT;
				break;
			default:
				break;
			}
		}
		else if (direction == DOWN) {
			switch (key) {
			case Key_down:
				direction = DOWN;
				break;
			case Key_left:
				direction = LEFT;
				break;
			case Key_right:
				direction = RIGHT;
				break;
			default:
				break;
			}
		}
		else if (direction == LEFT) {
			switch (key) {
			case Key_up:
				direction = UP;
				break;
			case Key_down:
				direction = DOWN;
				break;
			case Key_left:
				direction = LEFT;
				break;
			default:
				break;
			}
		}
		else if (direction == RIGHT) {
			switch (key) {
			case Key_up:
				direction = UP;
				break;
			case Key_down:
				direction = DOWN;
				break;
			case Key_right:
				direction = RIGHT;
				break;
			default:
				break;
			}
		}

	}
}


void Snake::Eat(Food& _food) {//吃掉食物，并将食物换位置
	if (snake.front().id_x() == _food.fdid_x() && snake.front().id_y() == _food.fdid_y()) {
		Need_grow = true;
		_food.Update_idxy();
		length++;
	}
}


bool Snake::Dead() {
	int coord_x = snake.front().id_x();
	int coord_y = snake.front().id_y();
	if (coord_x >= real_size || coord_y >= real_size || coord_x < 0 || coord_y < 0) {
		//蛇越界死掉
		return true;
	}
	if (Board[coord_y][coord_x] == SNAKE || Board[coord_y][coord_x] == PITS || Board[coord_y][coord_x] == HEAD1) {
		//蛇头撞到自己或者撞到PIT
		return true;
	}
	return false;
}

struct father_crood
{
	int x = 0;
	int y = 0;
};

stack<Direction> Snake::bfs_short(int x, int y) {
	stack<Direction> path;  //记录路径
	queue<Coord> coord;  //记录坐标
	
	bool visited[Size][Size];
	for (int j = 0; j < Size; j++) {
		for (int i = 0; i < Size; i++) {
			visited[j][i] = false;
		}
	}

	father_crood father[Size][Size];  //记录父节点坐标

	coord.push(Coord(virtual_snake.front().id_x(), virtual_snake.front().id_y()));

	while (!coord.empty()) {
		Coord temp = coord.front();
		coord.pop();
		if (temp.id_x() == x && temp.id_y() == y) {
			//找到了目标
			while (temp.id_x() != virtual_snake.front().id_x() || temp.id_y() != virtual_snake.front().id_y()) {
				//回溯路径
				if (father[temp.id_y()][temp.id_x()].x - 1 == temp.id_x()) {
					path.push(LEFT);
				}
				else if (father[temp.id_y()][temp.id_x()].x + 1 == temp.id_x()) {
					path.push(RIGHT);
				}
				else if (father[temp.id_y()][temp.id_x()].y - 1 == temp.id_y()) {
					path.push(UP);
				}
				else if (father[temp.id_y()][temp.id_x()].y + 1 == temp.id_y()) {
					path.push(DOWN);
				}
				temp.update(father[temp.id_y()][temp.id_x()].x, father[temp.id_y()][temp.id_x()].y);
			}
			return path;
		}
		if ((temp.id_x() + 1 < real_size && !visited[temp.id_y()][temp.id_x() + 1]
			&& virtual_board[temp.id_y()][temp.id_x() + 1] != SNAKE
			&& virtual_board[temp.id_y()][temp.id_x() + 1] != PITS
			&& virtual_board[temp.id_y()][temp.id_x() + 1] != HEAD1)
			||(temp.id_y() == y && temp.id_x() + 1 == x)) {
			coord.push(Coord(temp.id_x() + 1, temp.id_y()));
			father[temp.id_y()][temp.id_x() + 1].x = temp.id_x();
			father[temp.id_y()][temp.id_x() + 1].y = temp.id_y();
			visited[temp.id_y()][temp.id_x() + 1] = true;
		}
		if ((temp.id_x() - 1 >= 0 && !visited[temp.id_y()][temp.id_x() - 1] 
			&& virtual_board[temp.id_y()][temp.id_x() - 1] != SNAKE
			&& virtual_board[temp.id_y()][temp.id_x() - 1] != PITS
			&& virtual_board[temp.id_y()][temp.id_x() - 1] != HEAD1)
			||(temp.id_y() == y && temp.id_x() - 1 == x)) {
			coord.push(Coord(temp.id_x() - 1, temp.id_y()));
			father[temp.id_y()][temp.id_x() - 1].x = temp.id_x();
			father[temp.id_y()][temp.id_x() - 1].y = temp.id_y();
			visited[temp.id_y()][temp.id_x() - 1] = true;
		}
		if ((temp.id_y() + 1 < real_size && !visited[temp.id_y() + 1][temp.id_x()]
			&& virtual_board[temp.id_y() + 1][temp.id_x()] != SNAKE
			&& virtual_board[temp.id_y() + 1][temp.id_x()] != PITS
			&& virtual_board[temp.id_y() + 1][temp.id_x()] != HEAD1)
			|| (temp.id_y() + 1 == y && temp.id_x() == x)) {
			coord.push(Coord(temp.id_x(), temp.id_y() + 1));
			father[temp.id_y() + 1][temp.id_x()].x = temp.id_x();
			father[temp.id_y() + 1][temp.id_x()].y = temp.id_y();
			visited[temp.id_y() + 1][temp.id_x()] = true;
		}
		if ((temp.id_y() - 1 >= 0 && !visited[temp.id_y() - 1][temp.id_x()]
			&& virtual_board[temp.id_y() - 1][temp.id_x()] != SNAKE
			&& virtual_board[temp.id_y() - 1][temp.id_x()] != PITS
			&& virtual_board[temp.id_y() - 1][temp.id_x()] != HEAD1)
			||(temp.id_y() - 1 == y && temp.id_x() == x)) {
			coord.push(Coord(temp.id_x(), temp.id_y() - 1));
			father[temp.id_y() - 1][temp.id_x()].x = temp.id_x();
			father[temp.id_y() - 1][temp.id_x()].y = temp.id_y();
			visited[temp.id_y() - 1][temp.id_x()] = true;
		}
	}

	return path;
}


void Snake::Virtual_move(Direction dir) {
	switch (dir) {
	case UP:
		if (virtual_snake.front().id_y() - 1 >= 0) {
			virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = SNAKE;    //原来的头变成身体
			virtual_snake.front().update_type(SNAKE);
			virtual_snake.push_front(Node(virtual_snake.front().id_x(), virtual_snake.front().id_y() - 1, HEAD));
		}
		break;
	case DOWN:
		if (virtual_snake.front().id_y() + 1 < real_size) {
			virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = SNAKE;
			virtual_snake.front().update_type(SNAKE);
			virtual_snake.push_front(Node(virtual_snake.front().id_x(), virtual_snake.front().id_y() + 1, HEAD));   
		}
		break;
	case LEFT:
		if (virtual_snake.front().id_x() - 1 >= 0) {
			virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = SNAKE;
			virtual_snake.front().update_type(SNAKE);
			virtual_snake.push_front(Node(virtual_snake.front().id_x() - 1, virtual_snake.front().id_y(), HEAD));     
		}
		break;
	case RIGHT:
		if (virtual_snake.front().id_x() + 1 < real_size) {
			virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = SNAKE;
			virtual_snake.front().update_type(SNAKE);
			virtual_snake.push_front(Node(virtual_snake.front().id_x() + 1, virtual_snake.front().id_y(), HEAD));
		}
		break;
	default:
		break;

	}

}


Direction Snake::longest_path(int x, int y) {
	int distance = -1;
	Direction dir = NO;
	for (int j = -1; j <= 1; j++) {
		for (int i = -1; i <= 1; i++) {
			if ((j * i == 0) && (i + j != 0) ) {//确保蛇的头部的是邻居

				for (int m = 0; m < Size; m++) {
					for (int n = 0; n < Size; n++) {
						virtual_board[m][n] = Board[m][n];
					}
				}

				virtual_snake.clear();
				list<Node>::iterator t;
				for (t = snake.begin(); t != snake.end(); t++) {
					virtual_snake.push_back(*t);
				}


				if (virtual_snake.front().id_x() + i >= 0 && virtual_snake.front().id_x() + i < real_size
					&& virtual_snake.front().id_y() + j >= 0 && virtual_snake.front().id_y() + j < real_size) {

					if (Board[virtual_snake.front().id_y() + j][virtual_snake.front().id_x() + i] != SNAKE 
						&& Board[virtual_snake.front().id_y() + j][virtual_snake.front().id_x() + i] != PITS
						&& Board[virtual_snake.front().id_y() + j][virtual_snake.front().id_x() + i] != HEAD1) {

						if (abs(x - virtual_snake.front().id_x()) + abs(y - virtual_snake.front().id_y()) > distance) {
							if (j == -1) Virtual_move(UP);
							else if (j == 1) Virtual_move(DOWN);
							else if (i == -1) Virtual_move(LEFT);
							else if (i == 1) Virtual_move(RIGHT);


							if (virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] != FOOD) {
								virtual_board[virtual_snake.back().id_y()][virtual_snake.back().id_x()] = NONE;
								virtual_snake.pop_back();
							}

							virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = HEAD;


							if (bfs_short(virtual_snake.back().id_x(), virtual_snake.back().id_y()).size() > 1) {  //两个不能邻接
								distance = abs(x - virtual_snake.front().id_x()) + abs(y - virtual_snake.front().id_y());
								if (j == -1) dir = UP;
								else if (j == 1) dir = DOWN;
								else if (i == -1) dir = LEFT;
								else if (i == 1) dir = RIGHT;
							}
						}

					}
				}
				
			}
		}
	}

	return dir;
}


void Snake::Ai(Food& food) {// 贪吃蛇AI，根据food的坐标和Board数组生成下一步要走的方向
	//初始化
	for (int j = 0; j < Size; j++) {
		for (int i = 0; i < Size; i++) {
			virtual_board[i][j]= Board[i][j];
		}
	}

	virtual_snake.clear();
	list<Node>::iterator j;
	for (j = snake.begin(); j != snake.end(); j++) {
		virtual_snake.push_back(*j);
	}

	stack<Direction> head_foot = bfs_short(food.fdid_x(), food.fdid_y());
	stack<Direction> head_food = head_foot;
	stack<Direction> short_head_tail = bfs_short(virtual_snake.back().id_x(), virtual_snake.back().id_y());
	while (!head_food.empty()) {  //虚拟走到食物的位置
		Direction dir = head_food.top();
		head_food.pop();
		Virtual_move(dir);
		if (virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] == FOOD) {
			virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = HEAD;
			break;
		}
		virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = HEAD;   //最后更新头的位置，先检查有没有吃到食物
		virtual_board[virtual_snake.back().id_y()][virtual_snake.back().id_x()] = NONE;
		virtual_snake.pop_back();
	}
	
	if (abs(virtual_snake.front().id_x() - virtual_snake.back().id_x()) + abs(virtual_snake.front().id_y() - virtual_snake.back().id_y()) != 1 ) {
		//吃完食物后不能挨着蛇尾不然就撞死了
		stack<Direction> head_tail = bfs_short(virtual_snake.back().id_x(), virtual_snake.back().id_y());

		if (!head_foot.empty()) {
			if (!head_tail.empty()) {
				this->direction = head_foot.top();
				return;
			}
		}
	}
	
	Direction dir = longest_path(virtual_snake.back().id_x(), virtual_snake.back().id_y());
	if (dir != NO) {//走了一步之后，蛇尾可以到达
		this->direction = dir;
		return;
	}
	

	//再不行，走最近路
	
	if (short_head_tail.size() > 1) {  //当距离大于一格再追尾巴，蛇头会故意撞尾巴
		this->direction = short_head_tail.top();
		return;
	}

	//如果蛇尾无法到达，那么就随便走一步

	vector<Direction> dir_list;

	for (int j = -1; j <= 1; j++) {
		for (int i = -1; i <= 1; i++) {
			if ((j * i == 0) && (i + j != 0)) {//确保可以蛇的头部的是邻居
				for (int j = 0; j < Size; j++) {
					for (int i = 0; i < Size; i++) {
						virtual_board[i][j] = Board[i][j];
					}
				}

				virtual_snake.clear();
				list<Node>::iterator t;
				for (t = snake.begin(); t != snake.end(); t++) {
					virtual_snake.push_back(*t);
				}

				if (virtual_snake.front().id_x() + i >= 0 && virtual_snake.front().id_x() + i < real_size
					&& virtual_snake.front().id_y() + j >= 0 && virtual_snake.front().id_y() + j < real_size) {

					if (Board[snake.front().id_y() + j][snake.front().id_x() + i] != SNAKE 
						&& Board[snake.front().id_y() + j][snake.front().id_x() + i] != PITS
						&& Board[snake.front().id_y() + j][snake.front().id_x() + i] != HEAD1) {
						
						if (j == -1) Virtual_move(UP);
						else if (j == 1) Virtual_move(DOWN);
						else if (i == -1) Virtual_move(LEFT);
						else if (i == 1) Virtual_move(RIGHT);

						if (virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] != FOOD) {
							virtual_board[virtual_snake.back().id_y()][virtual_snake.back().id_x()] = NONE;
							virtual_snake.pop_back();
						}

						virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = HEAD;

						if (bfs_short(virtual_snake.back().id_x(), virtual_snake.back().id_y()).size() > 1) {
							if (j == -1) dir_list.push_back(UP);
							else if (j == 1) dir_list.push_back(DOWN);
							else if (i == -1) dir_list.push_back(LEFT);
							else if (i == 1) dir_list.push_back(RIGHT);
						}
					}
				}

			}
		}
	}

	if (!dir_list.empty()) {
		this->direction = dir_list[rand() % dir_list.size()];
		return;
	}
	

	return;

}

//

stack<Direction> Snake::bfs_short_1(int x, int y) {
	stack<Direction> path;  //记录路径
	queue<Coord> coord;  //记录坐标

	bool visited[Size][Size];
	for (int j = 0; j < Size; j++) {
		for (int i = 0; i < Size; i++) {
			visited[j][i] = false;
		}
	}

	father_crood father[Size][Size];  //记录父节点坐标

	coord.push(Coord(virtual_snake.front().id_x(), virtual_snake.front().id_y()));

	while (!coord.empty()) {
		Coord temp = coord.front();
		coord.pop();
		if (temp.id_x() == x && temp.id_y() == y) {
			//找到了目标
			while (temp.id_x() != virtual_snake.front().id_x() || temp.id_y() != virtual_snake.front().id_y()) {
				//回溯路径
				if (father[temp.id_y()][temp.id_x()].x - 1 == temp.id_x()) {
					path.push(LEFT);
				}
				else if (father[temp.id_y()][temp.id_x()].x + 1 == temp.id_x()) {
					path.push(RIGHT);
				}
				else if (father[temp.id_y()][temp.id_x()].y - 1 == temp.id_y()) {
					path.push(UP);
				}
				else if (father[temp.id_y()][temp.id_x()].y + 1 == temp.id_y()) {
					path.push(DOWN);
				}
				temp.update(father[temp.id_y()][temp.id_x()].x, father[temp.id_y()][temp.id_x()].y);
			}
			return path;
		}
		if ((temp.id_x() + 1 < real_size && !visited[temp.id_y()][temp.id_x() + 1]
			&& virtual_board[temp.id_y()][temp.id_x() + 1] != SNAKE
			&& virtual_board[temp.id_y()][temp.id_x() + 1] != PITS
			&& virtual_board[temp.id_y()][temp.id_x() + 1] != HEAD)
			|| (temp.id_y() == y && temp.id_x() + 1 == x)) {
			coord.push(Coord(temp.id_x() + 1, temp.id_y()));
			father[temp.id_y()][temp.id_x() + 1].x = temp.id_x();
			father[temp.id_y()][temp.id_x() + 1].y = temp.id_y();
			visited[temp.id_y()][temp.id_x() + 1] = true;
		}
		if ((temp.id_x() - 1 >= 0 && !visited[temp.id_y()][temp.id_x() - 1]
			&& virtual_board[temp.id_y()][temp.id_x() - 1] != SNAKE
			&& virtual_board[temp.id_y()][temp.id_x() - 1] != PITS
			&& virtual_board[temp.id_y()][temp.id_x() - 1] != HEAD)
			|| (temp.id_y() == y && temp.id_x() - 1 == x)) {
			coord.push(Coord(temp.id_x() - 1, temp.id_y()));
			father[temp.id_y()][temp.id_x() - 1].x = temp.id_x();
			father[temp.id_y()][temp.id_x() - 1].y = temp.id_y();
			visited[temp.id_y()][temp.id_x() - 1] = true;
		}
		if ((temp.id_y() + 1 < real_size && !visited[temp.id_y() + 1][temp.id_x()]
			&& virtual_board[temp.id_y() + 1][temp.id_x()] != SNAKE
			&& virtual_board[temp.id_y() + 1][temp.id_x()] != PITS
			&& virtual_board[temp.id_y() + 1][temp.id_x()] != HEAD)
			|| (temp.id_y() + 1 == y && temp.id_x() == x)) {
			coord.push(Coord(temp.id_x(), temp.id_y() + 1));
			father[temp.id_y() + 1][temp.id_x()].x = temp.id_x();
			father[temp.id_y() + 1][temp.id_x()].y = temp.id_y();
			visited[temp.id_y() + 1][temp.id_x()] = true;
		}
		if ((temp.id_y() - 1 >= 0 && !visited[temp.id_y() - 1][temp.id_x()]
			&& virtual_board[temp.id_y() - 1][temp.id_x()] != SNAKE
			&& virtual_board[temp.id_y() - 1][temp.id_x()] != PITS
			&& virtual_board[temp.id_y() - 1][temp.id_x()] != HEAD)
			|| (temp.id_y() - 1 == y && temp.id_x() == x)) {
			coord.push(Coord(temp.id_x(), temp.id_y() - 1));
			father[temp.id_y() - 1][temp.id_x()].x = temp.id_x();
			father[temp.id_y() - 1][temp.id_x()].y = temp.id_y();
			visited[temp.id_y() - 1][temp.id_x()] = true;
		}
	}

	return path;
}


void Snake::Virtual_move_1(Direction dir) {
	switch (dir) {
	case UP:
		if (virtual_snake.front().id_y() - 1 >= 0) {
			virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = SNAKE;    //原来的头变成身体
			virtual_snake.front().update_type(SNAKE1);
			virtual_snake.push_front(Node(virtual_snake.front().id_x(), virtual_snake.front().id_y() - 1, HEAD1));
		}
		break;
	case DOWN:
		if (virtual_snake.front().id_y() + 1 < real_size) {
			virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = SNAKE;
			virtual_snake.front().update_type(SNAKE1);
			virtual_snake.push_front(Node(virtual_snake.front().id_x(), virtual_snake.front().id_y() + 1, HEAD1));
		}
		break;
	case LEFT:
		if (virtual_snake.front().id_x() - 1 >= 0) {
			virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = SNAKE;
			virtual_snake.front().update_type(SNAKE1);
			virtual_snake.push_front(Node(virtual_snake.front().id_x() - 1, virtual_snake.front().id_y(), HEAD1));
		}
		break;
	case RIGHT:
		if (virtual_snake.front().id_x() + 1 < real_size) {
			virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = SNAKE;
			virtual_snake.front().update_type(SNAKE1);
			virtual_snake.push_front(Node(virtual_snake.front().id_x() + 1, virtual_snake.front().id_y(), HEAD1));
		}
		break;
	default:
		break;

	}

}


Direction Snake::longest_path_1(int x, int y) {
	int distance = -1;
	Direction dir = NO;
	for (int j = -1; j <= 1; j++) {
		for (int i = -1; i <= 1; i++) {
			if ((j * i == 0) && (i + j != 0)) {//确保蛇的头部的是邻居

				for (int m = 0; m < Size; m++) {
					for (int n = 0; n < Size; n++) {
						virtual_board[m][n] = Board[m][n];
					}
				}

				virtual_snake.clear();
				list<Node>::iterator t;
				for (t = snake.begin(); t != snake.end(); t++) {
					virtual_snake.push_back(*t);
				}


				if (virtual_snake.front().id_x() + i >= 0 && virtual_snake.front().id_x() + i < real_size
					&& virtual_snake.front().id_y() + j >= 0 && virtual_snake.front().id_y() + j < real_size) {

					if (Board[virtual_snake.front().id_y() + j][virtual_snake.front().id_x() + i] != SNAKE
						&& Board[virtual_snake.front().id_y() + j][virtual_snake.front().id_x() + i] != PITS
						&& Board[virtual_snake.front().id_y() + j][virtual_snake.front().id_x() + i] != HEAD) {

						if (abs(x - virtual_snake.front().id_x()) + abs(y - virtual_snake.front().id_y()) > distance) {
							if (j == -1) Virtual_move(UP);
							else if (j == 1) Virtual_move(DOWN);
							else if (i == -1) Virtual_move(LEFT);
							else if (i == 1) Virtual_move(RIGHT);


							if (virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] != FOOD) {
								virtual_board[virtual_snake.back().id_y()][virtual_snake.back().id_x()] = NONE;
								virtual_snake.pop_back();
							}

							virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = HEAD1;


							if (bfs_short(virtual_snake.back().id_x(), virtual_snake.back().id_y()).size() > 1) {  //两个不能邻接
								distance = abs(x - virtual_snake.front().id_x()) + abs(y - virtual_snake.front().id_y());
								if (j == -1) dir = UP;
								else if (j == 1) dir = DOWN;
								else if (i == -1) dir = LEFT;
								else if (i == 1) dir = RIGHT;
							}
						}

					}
				}

			}
		}
	}

	return dir;
}


void Snake::Ai_1(Food& food) {// 贪吃蛇AI，根据food的坐标和Board数组生成下一步要走的方向
	//初始化
	for (int j = 0; j < Size; j++) {
		for (int i = 0; i < Size; i++) {
			virtual_board[i][j] = Board[i][j];
		}
	}

	virtual_snake.clear();
	list<Node>::iterator j;
	for (j = snake.begin(); j != snake.end(); j++) {
		virtual_snake.push_back(*j);
	}

	stack<Direction> head_foot = bfs_short(food.fdid_x(), food.fdid_y());
	stack<Direction> head_food = head_foot;
	stack<Direction> short_head_tail = bfs_short(virtual_snake.back().id_x(), virtual_snake.back().id_y());
	while (!head_food.empty()) {  //虚拟走到食物的位置
		Direction dir = head_food.top();
		head_food.pop();
		Virtual_move(dir);
		if (virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] == FOOD) {
			virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = HEAD1;
			break;
		}
		virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = HEAD1;   //最后更新头的位置，先检查有没有吃到食物
		virtual_board[virtual_snake.back().id_y()][virtual_snake.back().id_x()] = NONE;
		virtual_snake.pop_back();
	}

	if (abs(virtual_snake.front().id_x() - virtual_snake.back().id_x()) + abs(virtual_snake.front().id_y() - virtual_snake.back().id_y()) != 1) {
		//吃完食物后不能挨着蛇尾不然就撞死了
		stack<Direction> head_tail = bfs_short(virtual_snake.back().id_x(), virtual_snake.back().id_y());

		if (!head_foot.empty()) {
			if (!head_tail.empty()) {
				this->direction = head_foot.top();
				return;
			}
		}
	}

	Direction dir = longest_path(virtual_snake.back().id_x(), virtual_snake.back().id_y());
	if (dir != NO) {//走了一步之后，蛇尾可以到达
		this->direction = dir;
		return;
	}


	//再不行，走最近路

	if (short_head_tail.size() > 1) {  //当距离大于一格再追尾巴，蛇头会故意撞尾巴
		this->direction = short_head_tail.top();
		return;
	}

	//如果蛇尾无法到达，那么就随便走一步

	vector<Direction> dir_list;

	for (int j = -1; j <= 1; j++) {
		for (int i = -1; i <= 1; i++) {
			if ((j * i == 0) && (i + j != 0)) {//确保可以蛇的头部的是邻居
				for (int j = 0; j < Size; j++) {
					for (int i = 0; i < Size; i++) {
						virtual_board[i][j] = Board[i][j];
					}
				}

				virtual_snake.clear();
				list<Node>::iterator t;
				for (t = snake.begin(); t != snake.end(); t++) {
					virtual_snake.push_back(*t);
				}

				if (virtual_snake.front().id_x() + i >= 0 && virtual_snake.front().id_x() + i < real_size
					&& virtual_snake.front().id_y() + j >= 0 && virtual_snake.front().id_y() + j < real_size) {

					if (Board[snake.front().id_y() + j][snake.front().id_x() + i] != SNAKE
						&& Board[snake.front().id_y() + j][snake.front().id_x() + i] != PITS
						&& Board[snake.front().id_y() + j][snake.front().id_x() + i] != HEAD) {

						if (j == -1) Virtual_move(UP);
						else if (j == 1) Virtual_move(DOWN);
						else if (i == -1) Virtual_move(LEFT);
						else if (i == 1) Virtual_move(RIGHT);

						if (virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] != FOOD) {
							virtual_board[virtual_snake.back().id_y()][virtual_snake.back().id_x()] = NONE;
							virtual_snake.pop_back();
						}

						virtual_board[virtual_snake.front().id_y()][virtual_snake.front().id_x()] = HEAD1;

						if (bfs_short(virtual_snake.back().id_x(), virtual_snake.back().id_y()).size() > 1) {
							if (j == -1) dir_list.push_back(UP);
							else if (j == 1) dir_list.push_back(DOWN);
							else if (i == -1) dir_list.push_back(LEFT);
							else if (i == 1) dir_list.push_back(RIGHT);
						}
					}
				}

			}
		}
	}

	if (!dir_list.empty()) {
		this->direction = dir_list[rand() % dir_list.size()];
		return;
	}


	return;

}