#include <algorithm>
#include <iostream>
#include <string>

#define MAX 1010
#define MOD 10007


int gets[MAX];

int get(int len);

void solve() {
	int n;
	std::cin >> n;
	//std::cout << n << std::endl;
	int ans = get(n) % MOD;
	std::cout << ans;
}

int get(int len) {
	if (gets[len] > 0) {
		return gets[len];
	}
	if (len == 1) {
		return 1;
	}
	else if (len == 2) {
		return 2;
	}
	gets[len ] = (get(len - 1) + get(len - 2)) % MOD;
	return gets[len];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	solve();
	return 0;
}
