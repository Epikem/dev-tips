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

ll N, T;
ll rr = 0;
ll ans = 0;
vector<int> arr;
vector<int> tmp;

void solve() {
	cin >> N >> T;

	for (int iii = 0; iii < N; iii++)
	{
		int ip;
		cin >> ip;
		arr.push_back(ip);
		rr += arr[iii];
	}
	if (T > rr) {
		ans = (T / rr) * N;
		T = T % rr;
	}

	ll newsize = 0;
	ll newsum = 0;
	//for (int iii = 0; iii < N; iii++)
	//{
	//	if (arr[iii] <= T) {
	//		newa.push_back(arr[iii]);
	//		newsize++;
	//		newsum += arr[iii];
	//	}
	//}
	//N = newsize;

	while (true)
	{
		newsum = 0;
		newsize = 0;
		tmp.clear();
		for (int iii = 0; iii < N; iii++)
		{
			if (arr[iii] <= T) {
				tmp.push_back(arr[iii]);
				newsize++;
				newsum += arr[iii];
			}
		}
		arr = tmp;
		N = newsize;
		if (newsum == 0) {
			break;
		}
	
		if (T < newsum) {
			int found = 0;
			for (int iii = 0; iii < N; iii++)
			{
				int aa = arr[iii];
				if (T >= aa) {
					T -= aa;
					ans++;
					found++;
				}
			}
			if (!found) {
				break;
			}
		}
		else {
			ans += (T / newsum) * newsize;
			T = T % newsum;
		}
	}

	cout << ans << endl;

	// 아.. round보다는 값이 훨씬 작은 몇 가게들을 계속 돌겠군.

	// n에 따라 걸리는 게 아니라 a와 T의 차이에 따라 돌기 때문에 round에서 빠져나온 지금도 여전히 T가 클 가능성이 있다.
	// 최악의 경우, a의 반이 10^9이고, 나머지 반이 1이면, round합은 10^9 * 10^5 = 10^14이므로 T는 여전히 10^14수준,
	// 그래도 이걸 또 round로 해서 풀어나가면 될거 같기도 했는데, 아까처럼 모든 가게가 T보다 작지만 round합보다 T가 작은 경우가 있을 수 있다.
	// 이 상태에서 T가 클 수도 있나? 생각해보면 .. T=10^14수준일 때, 모든 가게가 10^13수준이어도 가능..
	// 아니 근데 round합보다 T가 작으면 그 라운드를 직접 돌면 그 라운드의 가게 가격 수준보다 낮아진다는거네.
	// 


	//for (int iii = 0; iii < N; iii++)
	//{
	//	if (T < arr[iii]) continue;
	//	else {
	//		ans++;
	//		T -= arr[iii];
	//	}
	//}
	//for (int iii = 0; iii < N; iii++)
	//{
	//	if (T < arr[iii]) continue;
	//	else {
	//		ans++;
	//		T -= arr[iii];
	//	}
	//}
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
