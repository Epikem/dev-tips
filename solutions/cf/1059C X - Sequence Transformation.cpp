#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

#define M_PI 3.14159265358979323846
#define ll long long
#define VII(name, n, m, v) vector<vector<int> > name(n, vector<int>(m, v))

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

bool desc(int a, int b) {
	return a > b;
}

void solve()
{
	int N;
	cin >> N;

	vector<int> divis(1000008);
	//지금 필요한 건 어떤 i에 대해 i를 제외하고 i의 약수 중 가장 큰 수를 divis[i]에 저장하는 것. 그렇게 꼬리를 물고 들어가면 된다.

	for (int i = 1; i <= 1000000; i++) {
		divis[i] = 1;
		for (int j = 2; j * j < i; j++)
		{
			if (i % j == 0) {
				divis[i] = i / j;
				break;
			}

		}
	}

	//sort(divisors.begin(), divisors.end(), desc);

	vector<int> ans(N);
	int next = N;
	ans[0] = N;
	for (int i = 1; i < N; i++)
	{
		ans[i] = divis[next];
		next = divis[next];
	}

	for (int i = N - 1; i >= 0; i--)
	{
		cout << ans[i] << ' ';
	}

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
