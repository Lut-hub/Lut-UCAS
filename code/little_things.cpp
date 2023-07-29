#include"little_things.h"

node_type Board[Size][Size];       //游戏大小
int real_size;  //实际大小

vector<Coord> Empty_box;

void my_find_empty_box() {   //找到空的格子
	//先将Empty_box清空
	Empty_box.clear();
	for (int i = 1; i < real_size - 1; i++) {
		for (int j = 1; j < real_size - 1; j++) {
			if (Board[i][j] == NONE) {
				int de = 0;
				for (int m = -1; m <= 1; m++) {
					for (int n = -1; n <= 1; n++) {
						if ((m * n == 0) && (m + n != 0)) {
							if (Board[i + m][j + n] == PITS)
								de++;
						}
					}
				}

				if (de > 1)
					continue;

				Empty_box.push_back(Coord(j, i));
			}
		}
	}
}


int decodert(int x) {
	//将数组坐标转化为画布坐标
	return x * Box + Offset + (Box_size - Box)/2;
}


void find_empty_pits() {
	//先将Empty_box清空
	Empty_box.clear();
	for (int i = 1; i < real_size - 1; i+=2) {
		for (int j = 1; j < real_size - 1; j+=2) {
			if (Board[i][j] == NONE) {
				Empty_box.push_back(Coord(j, i));
			}
		}
	}

}