#include <algorithm>
#include <iostream>
#include <string>

void solve() {
	int n;
	std::cin >> n;

	n = 1000 - n;
	int s500 = n / 500;
	int s100 = n / 100 - 5 * s500;
	n -= s500 * 500 + s100 * 100;
	int s50 = n / 50;
	int s10 = n / 10 - 5 * s50;
	n -= s50 * 50 + s10 * 10;
	int s5 = n / 5;
	int s1 = n / 1 - 5 * s5;

	std::cout << s500 + s100 + s50 + s10 + s5 + s1;
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
