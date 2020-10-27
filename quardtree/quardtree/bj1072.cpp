#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<string>
using namespace std;

int main() {

	long long x, y, z;
	
	cin >> x >> y;
	z = (y * 100) / x;
	
	if (z >= 99) {
		cout << -1 << "\n";
	}
	long long low = 0, high = 1000000000;
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long tempz = (y + mid)*100 / (x + mid);
		
		if (tempz > z) {
			high = mid - 1;

		}
		else {
			
			low= mid +1; 
		
		}
			}
	cout << low;
	return 0;
}