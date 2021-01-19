#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

#define M_PI 3.14159265358979323846
#define ll long long

void solve()
{
	int n, m;

	cin >> n >> m;

	vector<vector<int> > map(1010, vector<int>(1010, 0));
	vector<vector<int> > map2(1010, vector<int>(1010, 0));
	//bool mgg[1010][1010];
	string mapline;
	for (int i = 0; i < n; i++)
	{
		cin >> mapline;

		for (int j = 0; j < m; j++)
		{
			if (mapline[j] == '.') {
				map[i][j] = false;
			}
			else map[i][j] = true;
		}
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 2][j] && map[i][j + 2]) {
				map2[i][j] = true;
				map2[i+1][j] = true;
				map2[i+2][j] = true;
				map2[i][j + 1] = true;

				map2[i][j+2] = true;
				map2[i + 1][j+2] = true;
				map2[i + 2][j+2] = true;
				map2[i + 2][j + 1] = true;
			}
			
		}
	}

	string ans = "YES";
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] != map2[i][j]) {
				ans = "NO";
			}
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
