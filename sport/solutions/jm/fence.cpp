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
#define siter string::iterator
#define viter vi::iterator
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
//void matmul(int s[N][N], int a[N][N]) {
//	int v[N][N];
//	for (int i = 0; i < N; ++i) {
//		for (int j = 0; j < N; ++j) {
//			int n = 0;
//			for (int k = 0; k < N; ++k) n += s[i][k] * a[k][j];
//			v[i][j] = n;
//		}
//	}
//	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) s[i][j] = v[i][j];
//}
//
//void exp(int a[N][N], int n) {
//	if (n == 1) return;
//	if (n % 2 == 0) {
//		matmul(a, a);
//		exp(a, n / 2);
//	}
//	else {
//		int r[N][N];
//		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) r[i][j] = a[i][j];
//		exp(a, --n);
//		matmul(a, r);
//	}
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

int C;
vi arr;
int N;
int maxval = -1;

int maxlens[20050];
int curlens[20050];

int GetMaxSize() {
	int curheight = 0;
	int maxheight = 0;

	for (int i = 0; i < N; i++)
	{
		curheight = arr[i];
		if (curheight > maxheight) {
			maxheight = curheight;
		}
		for (int j = 1; j <= curheight; j++)
		{
			curlens[j]++;
			if (curlens[j] > maxlens[j]) {
				maxlens[j] = curlens[j];
			}
		}
		for (int j = curheight + 1; j < 10000; j++)
		{
			curlens[j] = 0;
		}
	}

	for (int i = 1; i <= maxheight; i++)
	{
		int mult = maxlens[i] * (i);
		if (mult > maxval) {
			maxval = mult;
		}
	}

	return maxval;
}

void solve() {
	cin >> C;
	arr.resize(20020);

	for (int c = 0; c < C; c++)
	{
		cin >> N;
		maxval = -1;
		memset(maxlens, 0, sizeof(maxlens));
		memset(curlens, 0, sizeof(curlens));

		for (int n = 0; n < N; n++)
		{
			cin >> arr[n];
		}

		int ans = GetMaxSize();

		cout << ans << endl;
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
