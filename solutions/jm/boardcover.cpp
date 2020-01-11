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
#include<cstring>
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

//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
//const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 998244353;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int dxo[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int dyo[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dig = 10;
const int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int digarr[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
const int bt = 31;

//ds MOD(ds a, ds b)
//{
//	if (a > b)
//		return a - b;
//	else
//		return b - a;
//}
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

int C, N, M;
int mm[20][20];

int dxs[] = { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, -1 };
int dys[] = { 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1 };

ii findnextpos() {
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (!mm[y][x]) {
				return { y,x };
			}
		}
	}

	return { 999, 999 };
}

int fillmap(int lasty, int lastx) {
	if (lastx < 0 || lastx >= M || lasty < 0 || lasty >= N) {
		return 0;
	}
	int fillx;
	int filly;
	int ret = 0;

	for (int dir = 0; dir < 4; dir++)
	{
		vii filltarget;
		for (int ddir = 0; ddir < 3; ddir++)
		{
			fillx = lastx + dxs[dir*3 + ddir];
			filly = lasty + dys[dir * 3 + ddir];
			if (fillx < 0 || fillx >= M || filly < 0 || filly >= N || mm[filly][fillx]) {
				filltarget.clear();
				break;
			} 
			filltarget.push_back({ filly, fillx });
			
		}
		if (filltarget.size() == 0) continue;

		for (auto t : filltarget)
		{
			mm[t.first][t.second] = 1;
		}

		ii next = findnextpos();
		if (next.first == 999) {
			ret++;
		}
		else {
			ret += fillmap(next.first, next.second);
		}


		for (auto t : filltarget)
		{
			mm[t.first][t.second] = 0;
		}
	}

	return ret;
}

void solve(){
	cin >> C;
	for (int c = 0; c < C; c++)
	{
		cin >> N >> M;
		memset(mm, 0, sizeof(mm));
		int lastx = 99999;
		int lasty = 99999;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				char w;
				cin >> w;
				if (w == '#') {
					mm[y][x] = 1;
				}
				else {
					if (lastx == 99999) {
						lastx = x;
						lasty = y;
					}
					mm[y][x] = 0;
				}
			}
		}

		cout << fillmap(lasty, lastx) << endl;

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
