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

//int main()
//{
//	//cout<<setprecision(12)<<fixed;
//	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	ll T; cin >> T;
//	while (T--)
//	{
//		ll a, b; cin >> a >> b;
//		ll f = 0;
//		if (a - b != 1)f = 1;
//		ll x = a + b;
//		ll fl = 0;
//		for (ll i = 2; i <= (ll)sqrt(x) + 1; i++)
//			if (x%i == 0) { fl = 1; break; }
//		if (fl)f = 1;
//		if (f)cout << "NO" << endl;
//		else cout << "YES" << endl;
//
//	}
//}

int n;
int arr[100100];
bool searchCaseMap[100100][2];

// int index : before point index.
// bool turn : if true, alices' turn.
// returns : if true, alice has win case. so alice wins.
bool searchCase(int index, bool turn) {
	if (searchCaseMap[index][turn] > 0) {
		return searchCaseMap[index][turn];
	}
	//if have no move, lose.
	bool canwin = false;
	// edge cases...

	// 딱히 처리할 엣지 케이스가 없다.

	// starts from leftmost jumped index, search toward rightmost
	for (int i = index % arr[index]; i < n; i+= arr[index])
	{
		if (arr[i] > arr[index]) {
			canwin = !searchCase(i, !turn);
			if (canwin) {
				searchCaseMap[index][turn] = canwin;
				return canwin;
			}
		}
	}
	searchCaseMap[index][turn] = canwin;
	return canwin;
}

void solve()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (searchCase(i, true)) {
			cout << "A";
		}
		else cout << "B";
	}

	cout << endl;
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
