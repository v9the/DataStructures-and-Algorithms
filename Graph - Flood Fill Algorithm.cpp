#include <bits/stdc++.h>
using namespace std;

int mat[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
              {1, 1, 1, 1, 1, 1, 0, 0},
              {1, 0, 0, 1, 1, 0, 1, 1},
              {1, 2, 2, 2, 2, 0, 1, 0},
              {1, 1, 1, 2, 2, 0, 1, 0},
              {1, 1, 1, 2, 2, 2, 2, 0},
              {1, 1, 1, 1, 1, 2, 1, 1},
              {1, 1, 1, 1, 1, 2, 2, 1},
              };

void print() {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
}

void flood_fill (int i, int j, int color) {
	if (i < 0 || j < 0 || i > 7 || j > 7 || mat[i][j] != 2) {
		return;
	}
	mat[i][j] = color;
	flood_fill(i, j + 1, color);
	flood_fill(i + 1, j, color);
	flood_fill(i, j - 1, color);
	flood_fill(i - 1, j, color);
}
int main() {
	print();
	flood_fill(3, 2, 100);
	cout << '\n';
	print();
}