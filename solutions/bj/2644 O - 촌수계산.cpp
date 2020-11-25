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

int vv[101];
int parents[101];

int search(int start, int end);

void solve() {
	int n;
	cin >> n;

	int start, end;
	cin >> start >> end;

	int M;
	cin >> M;

	for (int m = 0; m < M; m++)
	{
		int parent, child;
		cin >> parent >> child;

		parents[child] = parent;
	}

	int ans = search(start, end);
	if (ans >= 0) {
		cout << ans << endl;
	}
}

int search(int start, int end) {
	// 최초의 공통 조상을 찾아야 한다. 그런데 현재 깊이를 모르므로 어떤 식으로 해야할지?
	// 따로 마지막 부모를 만날 때까지 배열을 만들면서 비교? 그 배열끼리 공통 부분을 다시 또 역으로 찾아야 하는데
	// 비효율적일 거 같다. 한 쪽의 부모들로만 배열을 만든 후, 다른 한쪽을 올리면서 그 배열에서 찾게 하면 배열을 
	// 하나만 써도 되지만, 그래도 시간은 똑같이 걸린다. 근데 생각해보니 이렇게 풀어도 100명 정도니 아마도 될 거 같긴 하다.
	// 100*100이어봤자.

	vector<int> pa(101, 99999999);	// 인덱스: 조상의 번호, 값: start~조상까지 거리, 조상이 아니면 큰 값.
	int i = start;
	int count = 0;

	while (true) {

		pa[i] = count++;
		i = parents[i];	// 다음 부모로 전진
		if (parents[i] == 0) {
			pa[i] = count;
			break;
		}
	}

	vector<int>::iterator it;
	int count2 = 0, pa2 = end;

	bool found = false;
	int sharedparent = 0;
	while (pa2 != 0) {
		//int minn = 99999;
		for (int kk = 1; kk <= 100; kk++)
		{
			if (pa[pa2] < pa[sharedparent]) { // end와 start의 공통 조상 중 start로부터 가장 가까운 조상 찾기
				found = true;
				sharedparent = pa2;
				//minn = pa[pa2];
			}
		}
		//if (pa[pa2] != 0) {
		//	found = true;
		//	sharedparent = pa2;
		//}
		if (found) {
			break;
		}
		pa2 = parents[pa2];
		count2++;
	}
	if (!found) {
		cout << "-1" << endl;
		return -1;
	}

	return pa[sharedparent] + count2;
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
