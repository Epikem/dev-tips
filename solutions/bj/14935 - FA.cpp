#include <algorithm>
#include <iostream>
#include <string>

void solve() {
	long long x, n;

	std::string s;
	std::cin >> s;

	x = (s[0] - '0') * s.size();

	for (int i = 0; i < 1000000; i++) {
		n = x;
		s = std::to_string(n);
		n = (s[0] - '0') * s.size();
		if (n == x) {
			std::cout << "FA" << std::endl;
			return;
		}
		x = n;
	}
	std::cout << "NFA" << std::endl;
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
