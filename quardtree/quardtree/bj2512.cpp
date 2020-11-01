
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m;
const int MAX = 10000 + 1;
vector<int>v;
int a[MAX];

int main() {

	cin >> n;
	int max_val = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		if (max_val < temp) {
			max_val = temp;
		}
	}	
	cin >> m;
	int sum = 0;
	int ans = 0;
	int left = 1, right = max_val;
	while (left <= right) {
		sum = 0;
		int mid = (left + right) / 2;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++) {
			if (v[i] > mid) {
				a[i] = mid;
			}
			else {
				a[i] = v[i];
			}
			sum += a[i];
		}
		
		if (sum > m) {
			
			right = mid - 1;
		}
		else {
			ans = mid;
			left = mid + 1;
		}
		
	}
	
	cout << ans << endl;
	
	return 0;
}