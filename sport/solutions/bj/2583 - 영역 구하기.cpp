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

int getArra(int x, int y);

int mm[101][101];
int dx[] = { -1,0,0,1 };
int dy[] = { 0, -1, 1, 0 };
int m, n, k;

void solve()
{
	//cout << "dsddsd" << endl;
	cin >> n >> m >> k;
	//for (int i = 0; i < 101; i++) {
	//	memset(m[i], 0, sizeof(int) * 101);
	//}

	for (int kk = 0; kk < k; kk++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				mm[x][y] = 1;
			}
		}
	}

	
	int ans = 0;
	vector<int> areas;
	
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			if (mm[x][y] == 1 || mm[x][y] == 2) continue;

			ans++;
			areas.push_back(getArra(x, y));

		}
	}

	sort(areas.begin(), areas.end());

	cout << ans << endl;
	int sizee = areas.size();
	for (int r = 0; r < sizee; r++) {
		cout << areas[r] << ' ';
	}
}

int getArra(int x, int y) {
	if (mm[x][y] == 1 || mm[x][y] == 2 || x < 0 || y < 0 || x >= m || y >= n) return 0;

	if (mm[x][y] == 0) {
		int tmp = 0;
		int xx, yy;
		mm[x][y] = 2;
		for (int d = 0; d < 4; d++)
		{
			xx = x + dx[d];
			yy = y + dy[d];
			tmp += getArra(xx, yy);
		}
		return 1 + tmp;
	}
}

int main()
{
	fastio;
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	solve();
	return 0;
}
