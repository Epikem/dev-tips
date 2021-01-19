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

ll n, m;

ll binSearchT(ll lo, ll hi) {
	if (hi - lo < 10) {
		ll tt = lo;
		while ((tt * (tt - 1) / 2) - m < 0) {
			tt++;
		}
		return tt;
	}

	ll mid = lo + hi;
	mid /= 2;

	ll diff1 = (mid * (mid - 1) / 2) - m;
	ll diff2 = ((mid + 1) * (mid) / 2) - m;

	if (diff1 < 0) {
		return binSearchT(mid, hi);
	}
	else {
		if (diff2 >= 0) {
			return binSearchT(lo, mid);
		}
		//else if(diff1 >= 0 && diff2 < 0)
		else {
			if (diff1 == 0) return mid;
			else return mid + 1;
		}
	}
}

void solve() {

	cin >> n >> m;

	ll min, max;

	min = n - 2 * m;
	if (min < 0) min = 0;

	int tt = 0;
	while ((tt * (tt - 1) / 2) - m < 0) {
		tt++;
	}

	//tt = binSearchT(0, n*n);

	max = n - tt;
	if (max < 0) max = 0;

	cout << min << ' ' << max << endl;


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