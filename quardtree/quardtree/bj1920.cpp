#pragma warning (disable: 4996)
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

int main() {

	int n, m;
	vector<long long> a;
	vector<long long> v;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long temp;
		scanf("%lld", &temp);
		a.push_back(temp);

	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		long long temp;
		scanf("%lld", &temp);
		v.push_back(temp);
	}
	sort(a.begin(), a.end());

	
	for (int i = 0; i < v.size(); i++) {
		bool ok = true;
		long long target = v[i];
		int low = 0;
		int high = a.size() - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (a[mid] == target) {
				ok = false;
				printf("1\n");
				break;
			}
			else {
				if (a[mid] > target) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
		}
		if (ok)
			printf("0\n");

	}
	return 0;
}