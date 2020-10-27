#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
const int MAX_SIZE = 1001;
char decompressed[MAX_SIZE][MAX_SIZE];
/*void decompress(string::iterator& it, int y, int x,int size) {
	char head = *(it++);

	if (head == 'b' || head == 'w') {
		for (int dy = 0; dy < size; ++dy)
			for (int dx = 0; dx < size; ++dx)
				decompressed[y + dx][x + dx] = head;
	}
	else {
		int half = size / 2;
		decompress(it, y, x, half);
		decompress(it, y, x + half, half);
		decompress(it, y + half, x, half);
		decompress(it, y + half, x + half, half);
	}
}*/
string reverse(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'w' || head == 'b')
		return string(1, head);
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	
	int c;
	cin >> c;
	while (c--) {
		string s;
		cin >> s;
		string::iterator it = s.begin();
		cout << reverse(it) << endl;

	}
	return 0;
}