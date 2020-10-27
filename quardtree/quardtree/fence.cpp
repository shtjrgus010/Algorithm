#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<string>
using namespace std;
vector<int> h;
int solve(int left, int right) {
	if (left == right) return h[left];
	int mid = (left + right) / 2;
	int ret = max(solve(left, mid), solve(mid + 1, right));
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height * 2);
	while (left < lo || hi < right) {
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;

}
int main() {

	int c;
	cin >> c;
	while (c--) {
		h.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			h.push_back(temp);
		}
		cout << solve(0, n - 1) << endl;

	}
	return 0;
}