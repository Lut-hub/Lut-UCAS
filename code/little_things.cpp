#include"little_things.h"

node_type Board[Size][Size];       //��Ϸ��С
int real_size;  //ʵ�ʴ�С

vector<Coord> Empty_box;

void my_find_empty_box() {   //�ҵ��յĸ���
	//�Ƚ�Empty_box���
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
	//����������ת��Ϊ��������
	return x * Box + Offset + (Box_size - Box)/2;
}


void find_empty_pits() {
	//�Ƚ�Empty_box���
	Empty_box.clear();
	for (int i = 1; i < real_size - 1; i+=2) {
		for (int j = 1; j < real_size - 1; j+=2) {
			if (Board[i][j] == NONE) {
				Empty_box.push_back(Coord(j, i));
			}
		}
	}

}