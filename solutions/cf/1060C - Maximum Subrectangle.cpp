#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

#define M_PI 3.14159265358979323846
#define ll long long

int c[2010][2010];
long asum[2010][2010];
long bsum[2010][2010];
//int dp[2010][2010];
//
//int dps(int x1, int x2, int y1, int y2) {
//	if (dp[x1][y1] > 0) {
//		return dp[x1][y1];
//	}
//
//
//}

void solve() {
	int n, m;
	
	cin >> n >> m;
	
	vector<int> a(n);
	vector<int> b(m);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	long x;

	cin >> x;

	// 생각을 해보자.
	// 각 구간의 합은 구할 수 있다.	asum[i][j] i부터 j+1개의 합.
	// 이제 뭐가 필요하지? 각 개수일 때 최소 합인 것을 찾아 그걸 기준으로 인덱싱을 해야 한다.
	// 

	long tmpsum = 0;
	vector<ll> as(2010, 9999999999);	// as[i] 개수 i개면서 합이 최소인 그 합.
	vector<ll> aa(2010);	// aa[i] 개수 i개면서 합이 최소인 경우의 x1

	vector<ll> bs(2010, 9999999999);	// as[i] 개수 i개면서 합이 최소인 그 합.
	vector<ll> ba(2010);	// aa[i] 개수 i개면서 합이 최소인 경우의 x1
	
	for (int i = 0; i < n; i++)
	{
		tmpsum = 0;
		for (int j = 0; i + j < n; j++)
		{
			tmpsum += a[i + j];
			asum[i][j] = tmpsum;
			if (tmpsum < as[j]) {
				as[j] = tmpsum;
				//aa[j] = i + 1;
				//ab[j] = i + j + 1;
				aa[j] = j + 1;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		tmpsum = 0;
		for (int j = 0; i + j < m; j++)
		{
			tmpsum += b[i + j];
			bsum[i][j] = tmpsum;
			if (tmpsum < bs[j]) {
				bs[j] = tmpsum;
				//ba[j] = i + 1;
				//bb[j] = i + j + 1;
				ba[j] = j + 1;
			}
		}
	}

	// 
	ll max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ll kk = aa[i] * ba[j];
			ll mm = as[i] * bs[j];
			if (kk > max && mm <= x) {
				max = kk;
			}
		}
	}

	cout << max << endl;
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
