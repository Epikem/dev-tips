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


void solve() {
	int N;
	cin >> N;
	int popped = 0;
	vector<int> arr(200020, -1);

	for (int n = 0; n < N; n++)
	{
		int c;
		cin >> c;
		arr[c] = n + 1;
	}
	string ans = "";
	for (int n = 0; n < N; n++)
	{
		int b;
		cin >> b;

		int k = arr[b];
		int pops = k - popped;
		if(pops >= 0)
			popped = k;
		else pops = 0;
		ans += to_string(pops) + " ";
		//cout << pops << ' ';
	}

	cout << ans << endl;


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
