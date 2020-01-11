#include <algorithm>
#include <iostream>
#include <string>

void solve() {
	int n;
	std::cin >> n;

	n = 1000 - n;
	int ans = 0;
	int multi = 100;
	while (n > 0) {
		if (n >= 5 * multi) {
			n -= 5 * multi;
			ans++;
		}
		else if (n >= multi) {
			n -= multi;
			ans++;
		}
		else {
			multi /= 10;
		}
	}

	std::cout << ans;
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
