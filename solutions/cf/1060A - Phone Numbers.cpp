#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define M_PI 3.14159265358979323846

void solve() {
	int n;
	std::cin >> n;
	string s;
	std::cin >> s;

	int eights = 0;
	int ans = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] - '0' == 8) {
			eights++;
		}
	}

	int cards = n - eights;

	while (eights > 0 && cards + eights >= 11) {
		ans++;
		eights--;
		for (int i = 1; i <= 10; i++)
		{1
			if (cards > 0) cards--;
			else eights--;
		}
	}

	cout << ans << endl;


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
