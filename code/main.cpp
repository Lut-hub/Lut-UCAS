#include "snake.h"
#include <windows.h>
#include <string>
#include <easyx.h>

#pragma warning(disable : 4996)

void buttion() {
	setcolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(0, 0, 900, 620);
	setcolor(BLACK);
	settextcolor(BLACK);
	settextstyle(25, 0, _T("宋体"));
	outtextxy(300, 250, _T("单人模式"));
	outtextxy(300, 300, _T("AI模式"));
	outtextxy(300, 350, _T("人机对战模式"));
	outtextxy(300, 400, _T("AI-AI对战模式"));
	settextstyle(100, 0, _T("宋体"));
	outtextxy(300, 2, _T("贪吃蛇"));
	settextstyle(30, 0, _T("宋体"));
	setcolor(BLUE);
	outtextxy(300, 200, _T("请选游戏模式："));
}

void map_size() {//设计按键选择地图大小
	setcolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(0, 0, 900, 620);
	setcolor(BLACK);
	settextcolor(BLACK);
	settextstyle(25, 0, _T("宋体"));
	outtextxy(300, 250, _T("小"));
	outtextxy(400, 250, _T("中"));
	outtextxy(500, 250, _T("大"));
	settextstyle(100, 0, _T("宋体"));
	outtextxy(300, 2, _T("贪吃蛇"));
	settextstyle(30, 0, _T("宋体"));
	setcolor(BLUE);
	outtextxy(300, 200, _T("请选择地图大小："));
}

void information(int score, bool loss) {  //展示游戏信息
	setcolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(Box_size * real_size + 51, 9, Box_size * real_size + 251, 209);
	setfillcolor(LIGHTCYAN);
	solidrectangle(Box_size * real_size + 61, 15, Box_size * real_size + 81, 35);
	setfillcolor(BLUE);
	solidrectangle(Box_size * real_size + 61, 40, Box_size * real_size + 81, 60);
	setfillcolor(RED);
	solidrectangle(Box_size * real_size + 61, 65, Box_size * real_size + 81, 85);
	setfillcolor(BLACK);
	solidrectangle(Box_size * real_size + 61, 90, Box_size * real_size + 81, 110);
	settextstyle(20, 0, _T("宋体"));
	settextcolor(LIGHTCYAN);
	outtextxy(Box_size * real_size + 85, 15, _T("蛇头"));
	settextcolor(BLUE);
	outtextxy(Box_size * real_size + 85, 40, _T("蛇身"));
	settextcolor(RED);
	outtextxy(Box_size * real_size + 85, 65, _T("食物"));
	settextcolor(BLACK);
	outtextxy(Box_size * real_size + 85, 90, _T("障碍物"));
	
	settextcolor(BROWN);
	outtextxy(Box_size * real_size + 61, 135, _T("分数："));
	
	if(loss)
	{
		settextstyle(20, 0, _T("宋体"));
		settextcolor(RED);
		outtextxy(Box_size * real_size + 61, 155, _T("游戏结束"));
		outtextxy(Box_size * real_size + 61, 175, _T("按任意键返回"));
	}
	TCHAR str[10];
	_itot(score, str, 10);
	settextcolor(BLACK);
	outtextxy(Box_size * real_size + 135, 135, str);

}

void information_1(int score, bool loss) {  //展示游戏信息
	setcolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(Box_size * real_size + 51, 9, Box_size * real_size + 251, 209);
	setfillcolor(BROWN);
	solidrectangle(Box_size * real_size + 61, 15, Box_size * real_size + 81, 35);
	setfillcolor(GREEN);
	solidrectangle(Box_size * real_size + 61, 40, Box_size * real_size + 81, 60);
	setfillcolor(RED);
	solidrectangle(Box_size * real_size + 61, 65, Box_size * real_size + 81, 85);
	setfillcolor(BLACK);
	solidrectangle(Box_size * real_size + 61, 90, Box_size * real_size + 81, 110);
	settextstyle(20, 0, _T("宋体"));
	settextcolor(BROWN);
	outtextxy(Box_size * real_size + 85, 15, _T("蛇头"));
	settextcolor(GREEN);
	outtextxy(Box_size * real_size + 85, 40, _T("蛇身"));
	settextcolor(RED);
	outtextxy(Box_size * real_size + 85, 65, _T("食物"));
	settextcolor(BLACK);
	outtextxy(Box_size * real_size + 85, 90, _T("障碍物"));

	settextcolor(BROWN);
	outtextxy(Box_size * real_size + 61, 135, _T("分数："));

	if (loss)
	{
		settextstyle(20, 0, _T("宋体"));
		settextcolor(RED);
		outtextxy(Box_size * real_size + 61, 155, _T("游戏结束"));
		outtextxy(Box_size * real_size + 61, 175, _T("按任意键返回"));
	}
	TCHAR str[10];
	_itot(score, str, 10);
	settextcolor(BLACK);
	outtextxy(Box_size * real_size + 135, 135, str);

}


void information_2(int score, bool loss) {  //展示游戏信息
	setcolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(Box_size * real_size + 51, 229, Box_size * real_size + 251, 429);
	setfillcolor(LIGHTCYAN);
	solidrectangle(Box_size * real_size + 61, 235, Box_size * real_size + 81, 255);
	setfillcolor(BLUE);
	solidrectangle(Box_size * real_size + 61, 260, Box_size * real_size + 81, 280);
	setfillcolor(RED);
	solidrectangle(Box_size * real_size + 61, 285, Box_size * real_size + 81, 305);
	setfillcolor(BLACK);
	solidrectangle(Box_size * real_size + 61, 310, Box_size * real_size + 81, 330);
	settextstyle(20, 0, _T("宋体"));
	setfillcolor(LIGHTCYAN);
	outtextxy(Box_size * real_size + 85, 235, _T("蛇头"));
	settextcolor(BLUE);
	outtextxy(Box_size * real_size + 85, 260, _T("蛇身"));
	settextcolor(RED);
	outtextxy(Box_size * real_size + 85, 285, _T("食物"));
	settextcolor(BLACK);
	outtextxy(Box_size * real_size + 85, 310, _T("障碍物"));

	settextcolor(BROWN);
	outtextxy(Box_size * real_size + 61, 355, _T("分数："));

	settextstyle(20, 0, _T("宋体"));
	settextcolor(RED);
	outtextxy(Box_size * real_size + 61, 395, _T("按任意键返回"));
	if (loss)
	{
		settextstyle(20, 0, _T("宋体"));
		settextcolor(RED);
		outtextxy(Box_size * real_size + 61, 375, _T("游戏结束"));
		outtextxy(Box_size * real_size + 61, 395, _T("按任意键返回"));
	}
	TCHAR str[10];
	_itot(score, str, 10);
	settextcolor(BLACK);
	outtextxy(Box_size * real_size + 135, 355, str);

}

void clear() {
	//清空键盘缓冲区，防止开始时按键污染
	while (_kbhit()) {
			_getch();
	}
}


int main() {
	srand(time(0));
	initgraph(900, 620);
	setbkcolor(WHITE);
	cleardevice();
	
	ExMessage ms;
	map_size();
	while (1) {
		if (peekmessage(&ms, EM_MOUSE)) {
			if (ms.message == WM_LBUTTONDOWN) {
				if (ms.x > 275 && ms.x < 350 && ms.y > 250 && ms.y < 300) {
					real_size = 16;
					break;
				}
				else if (ms.x > 375 && ms.x < 450 && ms.y > 250 && ms.y < 300) {
					real_size = 20;
					break;
				}
				else if (ms.x > 475 && ms.x < 550 && ms.y > 250 && ms.y < 300) {
					real_size = 30;
					break;
				}
			}
		}

	}
	cleardevice();
	buttion();
	ExMessage msg;
	
	while (1) {
		if (peekmessage(&msg, EM_MOUSE)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 300 && msg.x < 600 && msg.y > 250 && msg.y < 300) {
					cleardevice();
					clear();

					for (int j = 0; j < Size; j++) {
						for (int i = 0; i < Size; i++) {
							Board[i][j] = NONE;
						}
					}

					setcolor(BLACK);
					rectangle(9, 9, Box_size * real_size + 11, Box_size * real_size + 11);
					Snake player{};
					generate_pits(Num_Pits);
					Food food{};

					while (1) {
						//单人模式
						player.Move();
						player.Eat(food);
						if (player.Dead())
							break;
						player.Update_snake();
						information(player.score(), false);
						Sleep(100);
					}
					information(player.score(), true);
					while (1) {
						if (_kbhit()) {
							break;
						}
					}

					cleardevice();
					buttion();
				}
				else if (msg.x > 300 && msg.x < 600 && msg.y > 300 && msg.y < 350) {
					cleardevice();
					clear();

					for (int j = 0; j < Size; j++) {
						for (int i = 0; i < Size; i++) {
							Board[i][j] = NONE;
						}
					}

					setcolor(BLACK);
					rectangle(9, 9, Box_size * real_size + 11, Box_size * real_size + 11);
					Snake player{};
					generate_pits(Num_Pits);
					Food food{};

					while (1) {
						//AI贪吃蛇
						player.Ai(food);

						player.Move_ai();
						player.Eat(food);
						if (player.Dead())
							break;
						player.Update_snake_ai();
						information(player.score(), false);
						settextstyle(20, 0, _T("宋体"));
						settextcolor(RED);
						outtextxy(Box_size * real_size + 61, 175, _T("按任意键返回"));
						if (_kbhit()) {
							break;
						}
						Sleep(10);
					}
					information(player.score(), true);
					while (1) {
						if (_kbhit()) {
							break;
						}
					}

					cleardevice();
					buttion();
				}
				else if (msg.x > 300 && msg.x < 600 && msg.y > 350 && msg.y < 400) {
					cleardevice();
					clear();

					for (int j = 0; j < Size; j++) {
						for (int i = 0; i < Size; i++) {
							Board[i][j] = NONE;
						}
					}

					setcolor(BLACK);
					rectangle(9, 9, Box_size * real_size + 11, Box_size * real_size + 11);
					Snake player{};
					Snake player2{3};
					generate_pits(Num_Pits);
					Food food{};

					while (1) {
						//人机贪吃蛇
						player2.Move_1();
						player2.Eat(food);
						if (player2.Dead_1())
							break;
						player2.Update_snake_1();

						//player2.Ai_1(food);
						//player2.Move_ai_1();
						//player2.Eat(food);
						//if (player2.Dead_1())
							//break;
						//player2.Update_snake_ai_1();

						player.Ai(food);
						player.Move_ai();
						player.Eat(food);
						if (player.Dead())
							break;
						player.Update_snake_ai();
						if (player2.Dead_1())//更新后再看看会不会死，防止从AI蛇穿过
							break;
						information_1(player2.score(), false);
						Sleep(100);
					}

					information_1(player2.score(), true);
					while (1) {
						if (_kbhit()) {
							break;
						}
					}
					while (1) {
						if (_kbhit()) {
							break;
						}
					}

					cleardevice();
					buttion();
				}

				else if (msg.x > 300 && msg.x < 600 && msg.y > 400 && msg.y < 450) {
					cleardevice();
					clear();

					for (int j = 0; j < Size; j++) {
						for (int i = 0; i < Size; i++) {
							Board[i][j] = NONE;
						}
					}

					setcolor(BLACK);
					rectangle(9, 9, Box_size * real_size + 11, Box_size * real_size + 11);
					Snake player{};
					Snake player2{ 3 };
					generate_pits(Num_Pits);
					Food food{};

					while (1) {
						//AI-AI贪吃蛇

						player2.Ai_1(food);
						player2.Move_ai_1();
						player2.Eat(food);
						if (player2.Dead_1())
							break;
						player2.Update_snake_ai_1();

						player.Ai(food);
						player.Move_ai();
						player.Eat(food);
						if (player.Dead())
							break;
						player.Update_snake_ai();
						information_1(player2.score(), false);
						information_2(player.score(), false);
						Sleep(50);
						if (_kbhit()) {
							break;
						}
					}
					information_2(player.score(), true);
					information_1(player2.score(), true);
					while (1) {
						if (_kbhit()) {
							break;
						}
					}
					while (1) {
						if (_kbhit()) {
							break;
						}
					}

					cleardevice();
					buttion();
					}
			}
		}
	}

	getchar();
	closegraph();
	return 0;
	
}
