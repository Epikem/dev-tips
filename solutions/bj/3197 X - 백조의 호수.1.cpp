#include <sstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<ctime>
#include<cmath>
#include<map>
#include<stack>
#include<random>
#include<queue>
#include<list>
#include<math.h>
#include<string.h>
using namespace std;
const long long int INF = 2000000000000000000;

#define ll long long int
#define ld long double
#define key pair<ld,ld>
#define ii pair<int,int>
#define si set<int>
#define vii vector<pair<int,int> >
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int> >
#define vs vector<string>
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define nu 100001
#define mod 1000000007
#define mul(x,y) ((ll)(x)*(y))%mod
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using ds = int;
ds MOD(ds a, ds b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}
ds max3(ds a, ds b, ds c)
{
	return max(c, max(a, b));
}
ds min3(ds a, ds b, ds c)
{
	return min(a, min(b, c));
}
ds power(ds x, ds y)
{
	ds res = 1;
	while (y > 0)
	{
		if (y & 1)
			res = (res*x) % mod;
		y = y >> 1;
		x = (x*x) % mod;
	}
	return res;
}
ds logg(ds a)
{
	ds x = 0;
	while (a > 1)
	{
		x++;
		a /= 2;
	}
	return x;
}
ds gcd(ds a, ds b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

// 1 : 물
// 0 : 빙하
// 2 : 백조 1
// 3 : 백조 2
// 4 : 바다
int arr[1505][1505];

// 스킵된 물 영역
int ee[1505];

// 스킵된 백조 영역
int dd[1505];

bool vswan[1505][1505];
bool vice[1505][1505];

void solve()
{
	int n, m;

	cin >> n >> m;
	
	// 물 영역
	vector<pair<int, int> > ww;
	// 백조 탐색 영역
	vector<pair<int, int> > ss;

	// 백조 영역 2
	vector<int> zz, xx;


	int leftIce = 0;

	//백조 번호
	int bekjo = 0;

	int dx[] = {-1, +1, 0, 0};
	int dy[] = {0 , 0, -1, +1};

	for (int i = 0; i < n + 2; i++)	// 범위 초과 방지 위해 1~ 인덱스 사용
	{
		memset(arr[i], -1, sizeof(int)*(m + 2));	// -1로 초기화
	}

	string sss; // 맵 읽을 문자열
	for (int i = 1; i <= n; i++)
	{
		cin >> sss;
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = sss[j - 1];	//!! 1인덱스 사용중이므로 ss 접근은 -1 해줘야 함.
			char k = arr[i][j];
			if (k == '.') {
				arr[i][j] = 1;
				ww.push_back({ i, j });
			}
			else if (k == 'X') {
				arr[i][j] = 0;
			}
			else {
				// 두 백조 영역 구별.
				if (bekjo == 0) {
					ss.pb({ i, j });
					arr[i][j] = 5;
				}
				else {
					arr[i][j] = 6;
				}
				//백조 영역은 물 공간이기도 하다.
				ww.push_back({ i, j });

				bekjo++;
			}
		}
	}

	// 계속 진행
	int i = 0;
	int ans = 0;
	while (true)
	{

		//cout << "print" << endl;
		//for (int i = 1; i <= n; i++)
		//{
		//	for (int j = 1; j <= m; j++)
		//	{
		//		cout << arr[i][j];
		//	}
		//	cout << endl;
		//}

		int len = ss.size();
		for (; i < len; i++)
		{
			int x = ss[i].f, y = ss[i].s;
			if (vswan[x][y]) continue;
			int ds = 0;
			for (int d = 0; d < 4; d++)
			{
				x = ss[i].first + dx[d];
				y = ss[i].second + dy[d];

				if (arr[x][y] == 6) {
					cout << ans << endl;
					return;
				}
				
				if (arr[x][y] == 1) {
					arr[x][y] = 5;
					ss.push_back({ x,y });
					len++;
				}

				if (arr[x][y] == 5) ds++;
			}

			if (ds == 4) {
				vswan[x][y] = 1;
			}
		}

		ans++;
		len = ww.size();
		for (int j = 0; j < len; j++)
		{
			int x = ww[j].f, y = ww[j].s;
			if (vice[x][y]) continue;

			int ds = 0;
			for (int d = 0; d < 4; d++)
			{
				x = ww[j].first + dx[d];
				y = ww[j].second + dy[d];

				if (arr[x][y] == 0) {
					arr[x][y] = 1;
					ww.push_back({ x,y });
					//len++;
				}
				
				if (arr[x][y] >= 1) ds++;
			}

			if (ds == 4) {
				vice[x][y] = 1;
			}
		}


		i = 0;

	}


	return;
}


int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#else
	fastio;
#endif

	solve();
	return 0;
}
