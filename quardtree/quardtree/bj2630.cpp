#pragma warning(disable:4996)
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX_SIZE = 128+1;
int a[MAX_SIZE][MAX_SIZE];
int n;
int blue = 0, white = 0;
void decompress( int x, int y, int size) {

	
	if (size == 1) {
		if (a[x][y] == 1) {
			blue++;
			
		}
		else {
			white++;
		}
		return;
	}
	bool zero = true, one = true;
	for (int i = x; i < x+ size; i++) {
		for (int j = y; j <y+size; j++) {
			if (a[i][j]) {
				zero = false;
			}
			else {
				one = false;
			}
		}
	}
	if (zero) {
		white++;
	}
	else if (one) {
		blue++;

	}
	else {
		decompress(x, y, size / 2);
		decompress(x, y + (size / 2), size / 2);
		decompress(x + (size / 2), y, size / 2);
		decompress(x + (size / 2), y + (size / 2), size / 2);
	}
	return;
	

}
int main() {


	cin >> n;
	memset(a, 0, sizeof(a));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	decompress(0, 0, n);
	cout << white << "\n";
	cout << blue << "\n";
	return 0;
}