#pragma warning(disable:4996)
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {

	long long s;
	scanf("%lld", &s);

	long long sum = 0;
	long long cnt = 1;
	while (1) {
		sum += cnt;
		if (sum > s) {
			--cnt;
			break;
		}
		++cnt;

	}
	printf("%lld", cnt);

	return 0;
}