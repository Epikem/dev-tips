#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>

#define M_PI 3.14159265358979323846

void solve() {
	int n;
	std::cin >> n;

	double s1 = n * n * M_PI;
	double s2 = 2 * n*n;

	std::cout << std::fixed << std::setprecision(6) << s1 << std::endl;
	std::cout << std::fixed << std::setprecision(6) << s2 << std::endl;
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
