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

int n, m;
void solve() {

	// 모든 순열들에 대해 공통되는 부분만이 답이 될 수 있다.
	// 그걸 어떻게 효율적으로 찾을 것인가?
	// 각 숫자에 대해 그 숫자 뒤에 나오는 숫자에 대해 등록한다면?
	// 만약 이미 있는데 그와 다른 숫자를 등록하려 한다면 그 시도는 이미 실패한 것.
	// 1 2 3
	// 2 3 1

	// 맵에 1:2, 2:3 저장.
	// 2:3 확인. 3:1 실패(어떻게?)
	// 아니 근데 결국 구하려는게 가능한 모든 공통 순열인데, 그건 기본적으로 2^x승 아닌가.
	// 그럼 어떻게 빠르게 공통 순열들을 구하며, 그 순열들의 부분집합을 구하지?
	// 위 예시에서는 1,2,3,23뿐이지만,

	// 1 2 3 4
	// 2 3 4 1

	// 이렇게 나올 경우 1,2,3,4,23,34,234가 된다. 근데 우리가 구하려는 것은 경우의 수이지 그 순열 자체가 아니다.
	// 아마도 계산으로 가능하지 않을까. 1개는 무조건 다 되고, 2개 이상인 것에 대해 위의 경우 2 3 4가 공통으로 나온다.-> 23 34 234
	// 아 이건 그냥 부분집합이 아니라 연속된 부분집합이므로 시작점과 끝점만 정해주는 이중 for문정도로 구할 수 있겠다.
	// 근데 그래도 너무 느리지 않나? 몇 가지 있는지? 아..
	// 길이 7이라 치면, 7+6+...+1 결국 7*8/2 = 28 바로 계산이 된다./
	// 근데 1은 전부 포함시킬 것이므로 7+6+...+2 까지만 하면 될 듯.

	// 그럼 이제 모든 순열에 대해 공통 부분 또는 그 길이들을 어떻게 효율적으로 구할지 생각해 보자.
	// 이것도 일종의 그래프라 볼 수 있으므로, 각 숫자를 방문했는지를 visited로 체크하고, 
	// 공통되는지 확인은 위에서처럼 하자. 근데 위 방법은 두 순열은 비교를 해도, 세개 이상의 복잡한 경우는 조금 어렵지 않나?
	// 아니 어차피 모든 것에 공통이면 세개 이상에도 되어야 할 것이다.

	vector<int> chain(100010, -1);
	vector<int> arr(100010, -10);
	cin >> n >> m;

	int val = -1;
	int bef = -1;
	cin >> bef;
	arr[0] = bef;
	for (int i = 1; i < n; i++)
	{
		cin >> val;
		chain[bef] = val;	// 체인 연결. 바로 이전 인덱스와 연결 시키므로 붙어있음.
		arr[i] = val;
		bef = val;
	}
	for (int mm = 1; mm < m; mm++)
	{
		cin >> bef;
		for (int i = 1; i < n; i++)
		{
			// 인접 두 값에 대해, chain[앞 값] = 뒤 값 인지 확인해야 한다.
			cin >> val;
			if (chain[bef] != val) {
				chain[bef] = -2;	//뒷값-앞값이 연결되어있지 않음.
			}
			if (i == n - 1) {	// 마지막에 나온 값은 연결할 뒷값이 없음.
				//connected[bef] = false;
				chain[val] = -2;
			}
			bef = val;
		}

	}
	ll ans = 0;

	int curlen = 1;

	for (int i = 1; i <= n; i++)
	{
		// arr[i] 는 i번째 원소 값
		// chain[val]은 val 값의 다음에 나오는 연결된 값의 값
		// chain이 연결되는 동안 curlen 증가하면서 더하기.
		// chain이 연결된다: chain[arr[i-1]]==arr[i]
		if (chain[arr[i - 1]] == arr[i]) {
			curlen++;
		}
		else {
			curlen = 1;
		}
		ans += curlen;
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
