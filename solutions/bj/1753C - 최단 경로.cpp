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

int MAX = 999999;

//int dist[20020];

void solve() {
	int v, e;
	int k;
	cin >> v >> e;
	cin >> k;

	// 각 노드에 대해 엣지 정보를 알 수 있어야 함.
	// priority queue는 현재 노드로부터 가장 최단거리인 검색 시작할 다음 노드를 가져올 수 있어야 함.
	// 

	int start, end, weight;

	vector<pair<int, int>> adj[20020];
	priority_queue<pair<int, int>> pq;

	pq.push({ k, 0 });

	vector<int> dist(v + 1, MAX);
	
	//memset(dist, MAX, sizeof(int));
	dist[k] = 0;

	for (int i = 0; i < e; i++)
	{
		cin >> start >> end >> weight;

		adj[start].push_back(make_pair(end, weight));
	}

	while (!pq.empty())
	{
		int cost = pq.top().second;
		int pos = pq.top().first;
		pq.pop();

		if (cost > dist[pos]) continue;

		for (int i = 0; i < adj[pos].size(); i++)
		{
			int npos = adj[pos][i].first;
			int ncost = cost + adj[pos][i].second;

			if (ncost < dist[npos]) {
				dist[npos] = ncost;
				pq.push({ npos, ncost });
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == MAX) {
			cout << "INF" << endl;
		}
		else cout << dist[i] << endl;
	}

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


	//priority_queue<pair<int, int>> pq;

	//pq.push({ 10000, 0 });
	//pq.push({ 10, 99 });
	//pq.push({ 8000, 222 });
	//pq.push({ 27, 35 });
	//pq.push({ 500, 77 });
	//pq.push({ 800, 4 });
	//pq.push({ 777, 88 });

	//while (!pq.empty())
	//{
	//	int pos = pq.top().first;
	//	int cost = pq.top().second;
	//	pq.pop();
	//	cout << pos << ' ' << cost << endl;
	//}

	return 0;
}

