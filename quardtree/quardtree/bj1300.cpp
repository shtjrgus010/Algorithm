#pragma warning(disable:4996)
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;
vector<vector<long long >> v;

int main() {

	int n;
	scanf("%d", &n);

	long long k;
	long long ans = 0;
	scanf("%lld", &k);
	long long left = 1;
	long long right = k;
	while (left <= right) {
		int mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 1; i <= n; i++) sum += min(mid / i, n);
		if (sum < k) left = mid + 1;
		else ans = mid, right = mid - 1;
	}
	printf("%d",ans);

	return 0;
}