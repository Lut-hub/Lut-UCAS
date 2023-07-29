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
	settextstyle(25, 0, _T("����"));
	outtextxy(300, 250, _T("����ģʽ"));
	outtextxy(300, 300, _T("AIģʽ"));
	outtextxy(300, 350, _T("�˻���սģʽ"));
	outtextxy(300, 400, _T("AI-AI��սģʽ"));
	settextstyle(100, 0, _T("����"));
	outtextxy(300, 2, _T("̰����"));
	settextstyle(30, 0, _T("����"));
	setcolor(BLUE);
	outtextxy(300, 200, _T("��ѡ��Ϸģʽ��"));
}

void map_size() {//��ư���ѡ���ͼ��С
	setcolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(0, 0, 900, 620);
	setcolor(BLACK);
	settextcolor(BLACK);
	settextstyle(25, 0, _T("����"));
	outtextxy(300, 250, _T("С"));
	outtextxy(400, 250, _T("��"));
	outtextxy(500, 250, _T("��"));
	settextstyle(100, 0, _T("����"));
	outtextxy(300, 2, _T("̰����"));
	settextstyle(30, 0, _T("����"));
	setcolor(BLUE);
	outtextxy(300, 200, _T("��ѡ���ͼ��С��"));
}

void information(int score, bool loss) {  //չʾ��Ϸ��Ϣ
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
	settextstyle(20, 0, _T("����"));
	settextcolor(LIGHTCYAN);
	outtextxy(Box_size * real_size + 85, 15, _T("��ͷ"));
	settextcolor(BLUE);
	outtextxy(Box_size * real_size + 85, 40, _T("����"));
	settextcolor(RED);
	outtextxy(Box_size * real_size + 85, 65, _T("ʳ��"));
	settextcolor(BLACK);
	outtextxy(Box_size * real_size + 85, 90, _T("�ϰ���"));
	
	settextcolor(BROWN);
	outtextxy(Box_size * real_size + 61, 135, _T("������"));
	
	if(loss)
	{
		settextstyle(20, 0, _T("����"));
		settextcolor(RED);
		outtextxy(Box_size * real_size + 61, 155, _T("��Ϸ����"));
		outtextxy(Box_size * real_size + 61, 175, _T("�����������"));
	}
	TCHAR str[10];
	_itot(score, str, 10);
	settextcolor(BLACK);
	outtextxy(Box_size * real_size + 135, 135, str);

}

void information_1(int score, bool loss) {  //չʾ��Ϸ��Ϣ
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
	settextstyle(20, 0, _T("����"));
	settextcolor(BROWN);
	outtextxy(Box_size * real_size + 85, 15, _T("��ͷ"));
	settextcolor(GREEN);
	outtextxy(Box_size * real_size + 85, 40, _T("����"));
	settextcolor(RED);
	outtextxy(Box_size * real_size + 85, 65, _T("ʳ��"));
	settextcolor(BLACK);
	outtextxy(Box_size * real_size + 85, 90, _T("�ϰ���"));

	settextcolor(BROWN);
	outtextxy(Box_size * real_size + 61, 135, _T("������"));

	if (loss)
	{
		settextstyle(20, 0, _T("����"));
		settextcolor(RED);
		outtextxy(Box_size * real_size + 61, 155, _T("��Ϸ����"));
		outtextxy(Box_size * real_size + 61, 175, _T("�����������"));
	}
	TCHAR str[10];
	_itot(score, str, 10);
	settextcolor(BLACK);
	outtextxy(Box_size * real_size + 135, 135, str);

}


void information_2(int score, bool loss) {  //չʾ��Ϸ��Ϣ
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
	settextstyle(20, 0, _T("����"));
	setfillcolor(LIGHTCYAN);
	outtextxy(Box_size * real_size + 85, 235, _T("��ͷ"));
	settextcolor(BLUE);
	outtextxy(Box_size * real_size + 85, 260, _T("����"));
	settextcolor(RED);
	outtextxy(Box_size * real_size + 85, 285, _T("ʳ��"));
	settextcolor(BLACK);
	outtextxy(Box_size * real_size + 85, 310, _T("�ϰ���"));

	settextcolor(BROWN);
	outtextxy(Box_size * real_size + 61, 355, _T("������"));

	settextstyle(20, 0, _T("����"));
	settextcolor(RED);
	outtextxy(Box_size * real_size + 61, 395, _T("�����������"));
	if (loss)
	{
		settextstyle(20, 0, _T("����"));
		settextcolor(RED);
		outtextxy(Box_size * real_size + 61, 375, _T("��Ϸ����"));
		outtextxy(Box_size * real_size + 61, 395, _T("�����������"));
	}
	TCHAR str[10];
	_itot(score, str, 10);
	settextcolor(BLACK);
	outtextxy(Box_size * real_size + 135, 355, str);

}

void clear() {
	//��ռ��̻���������ֹ��ʼʱ������Ⱦ
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
						//����ģʽ
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
						//AḬ����
						player.Ai(food);

						player.Move_ai();
						player.Eat(food);
						if (player.Dead())
							break;
						player.Update_snake_ai();
						information(player.score(), false);
						settextstyle(20, 0, _T("����"));
						settextcolor(RED);
						outtextxy(Box_size * real_size + 61, 175, _T("�����������"));
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
						//�˻�̰����
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
						if (player2.Dead_1())//���º��ٿ����᲻��������ֹ��AI�ߴ���
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
						//AI-AḬ����

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
