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
//const long long int INF = 2000000000000000000;

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
#define fi first
#define se second
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

int aa[303][303];
int dd[303][303];

int getMaxOre(int x, int y) {
	//if (x == 4 && y == 0) {
	//	cout << 'd';
	//}
	if (dd[x][y] > 0) {
		return dd[x][y];
	}

	if (x == 0 && y == 0) {
		dd[x][y] = aa[x][y];
		return dd[x][y];
	}
	else if (x == 0) {
		dd[x][y] = getMaxOre(x, y - 1) + aa[x][y];
		return dd[x][y];
	}
	else if (y == 0) {
		dd[x][y] = getMaxOre(x - 1, y) + aa[x][y];
		return dd[x][y];
	}

	int a = getMaxOre(x-1, y);
	int b = getMaxOre(x, y-1);
	dd[x][y] = max(a, b) + aa[x][y];
	return dd[x][y];
}

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> aa[i][j];
		}
	}

	cout << getMaxOre(n - 1, m - 1) << endl;

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

