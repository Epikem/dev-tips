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
#define vvii(h,w,v) vvi(h, vi(w, v));	// initialize vvi
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

int C, H, W;

vvi bod;

vector<vii> pats = {
	{
		{0,0}, {0,1}, {1,0}
	},
	{
		{0,0}, {0,1}, {1,1}
	},{
		{0,0}, {1,0}, {1,1}
	},{
		{0,0}, {1,0}, {1,-1}
	}
};

int getAns(vvi& board) {
	int ret = 0;

	int y = -1, x = -1;
	for (int yy = 1; yy <= H; yy++)
	{
		for (int xx = 1; xx <= W; xx++)
		{
			if (bod[yy][xx] == 0) {
				y = yy; x = xx;
				break;
			}
		}
		if (y != -1 || x != -1) break;
	}
	if (y == -1) {
		return 1;
	}
	
	for (auto pat : pats) {
		bool blocked = false;
		for (auto pos : pat) {
			int ny = y + pos.first, nx = x + pos.second;
			if (nx == 0 || ny == 0 || nx > W || ny > H) {
				blocked = true;
			}
			if (bod[ny][nx] > 0) {
				blocked = true;
			}
			bod[ny][nx]++;
		}

		if (!blocked) {
			ret += getAns(bod);
		}

		for (auto pos : pat) {
			int ny = y + pos.first, nx = x + pos.second;
			bod[ny][nx]--;
		}
	}

	return ret;
}

void solve() {
	cin >> C;
	for (int c = 0; c < C; c++)
	{
		bod = vvii(28, 30, 0);
		int leftBlock = 0;

		cin >> H >> W;
		for (int y = 1; y <= H; y++)
		{
			string ss;
			cin >> ss;
			for (int x = 1; x <= W; x++)
			{
				if (ss[x-1] == '#') {
					bod[y][x] = 1;
				}
				else {
					bod[y][x] = 0;
					leftBlock++;
				}
			}
		}

		if (leftBlock % 3 != 0) {
			cout << 0 << endl;
		}
		else {
			cout << getAns(bod) << endl;
		}
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
