#pragma once

#include <list>
#include <iostream>
#include <queue>
#include <stack>
#include <conio.h>
#include "little_things.h"

using namespace std;


extern node_type Board[Size][Size];       //��Ϸ��С
extern int real_size;

extern vector<Coord> Empty_box;

class Food {  //����ʳ����
public:
	Food() { Update_idxy(); };
	Food(int _x, int _y) { food.update(_x, _y); Board[food.id_y()][food.id_x()] = FOOD; };
	void marker_board() {//����������ʳ��λ��
		Board[food.id_y()][food.id_x()] = FOOD;
	}
	void Update_idxy() {
		my_find_empty_box();
		if (!Empty_box.empty()) {
			food.clear();
			int x = rand() % Empty_box.size();
			Coord id = Empty_box[x];
			food.update(id.id_x(), id.id_y());
			food.draw();
			marker_board();
		}
	};
	int fdid_x() { return food.id_x(); };
	int fdid_y() { return food.id_y(); };
private:
	Node food{ 0, 0, FOOD };
};


class Pit {//����������
public:
	Pit() {//�����ʼ������
		find_empty_pits();
		int x = rand() % Empty_box.size();
		Coord id = Empty_box[x];
		pit.update(id.id_x(), id.id_y());
		//pit.update(7, 0);
		pit.draw();
		Board[pit.id_y()][pit.id_x()] = PITS;    //��������������λ��
	}

private:
	Node pit{ 0, 0, PITS };
};

void generate_pits(int num);  //��������

class Snake {              //��������
	public:
		Snake() {         //��ʼ����
			snake.push_back(Node(5, 0, HEAD));
			Board[0][5] = HEAD;

			//snake.push_back(Node(5, 1, HEAD));
			//Board[1][5] = HEAD;
			//snake.push_back(Node(5, 0, SNAKE));
			//Board[0][5] = SNAKE;


			snake.push_back(Node(4, 0, SNAKE));
			Board[0][4] = SNAKE;
			snake.push_back(Node(3, 0, SNAKE));
			Board[0][3] = SNAKE;
			
			//snake.push_back(Node(3, 1, SNAKE));
			//Board[1][3] = SNAKE;
			//snake.push_back(Node(3, 2, SNAKE));
			//Board[2][3] = SNAKE;
			//snake.push_back(Node(4, 2, SNAKE));
			//Board[2][4] = SNAKE;
			//snake.push_back(Node(4, 3, SNAKE));
			//Board[3][4] = SNAKE;
			
			direction = RIGHT;
			Need_grow = false;
			length = 3;
		}
		Snake(int len) {
			snake.push_back(Node(5, real_size - 1, HEAD1));
			Board[real_size - 1][5] = HEAD;
			snake.push_back(Node(4, real_size - 1, SNAKE1));
			Board[real_size - 1][4] = SNAKE;
			snake.push_back(Node(3, real_size - 1, SNAKE1));
			Board[real_size - 1][3] = SNAKE;
			direction = RIGHT;
			Need_grow = false;
			length = 3;
		}
		void Move();
		void Move_1();
		void Move_ai();
		void Move_ai_1();
		void Change_direction();
		void Eat(Food& _food);
		bool Dead();
		bool Dead_1();
		void Draw();
		void Update_snake();
		void Update_snake_1();
		void Update_snake_ai();
		void Update_snake_ai_1();
		int score() { return length - 3; };
		void Ai(Food& _food);
		void Ai_1(Food& _food);
		void Virtual_move(Direction dir);
		stack<Direction> bfs_short(int x, int y);
		Direction longest_path(int x, int y);
		void Virtual_move_1(Direction dir);
		stack<Direction> bfs_short_1(int x, int y);
		Direction longest_path_1(int x, int y);

	private:
		list<Node> snake;      //�����ߣ�����ֻ�ù�עͷ��β����Ϊÿ���ƶ�ֻ�ý�ͷ��ǰ�ƶ�һ�񣬰�β��ɾ������
		Direction direction;
		list<Node> virtual_snake;
		node_type virtual_board[Size][Size]; 
		bool Need_grow;
		int length;
};