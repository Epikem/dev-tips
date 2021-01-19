// NYAN NYAN
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
// ░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
// ░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
// ░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
// ░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
// ░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
// ░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
// ░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░ 
// ░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
// ░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
// ░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
// ░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_map>
#include <stack>
#include <random>
#include <queue>
#include <list>
#include <math.h>
#include <cstring>
#include <cstdio>
#include <iomanip> // std::setprecision
#include <cassert>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll1;
#define ll long long int
#define ld long double
//#define key pair<ld,ld>
#define ii pair<int, int>
#define iii pair<pair<int, int>, int>
//#define si set<int>
#define vii vector<pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvii(h, w, v) vvi(h, vi(w, v)); // initialize vvi
#define vs vector<string>
#define all(v) v.begin(), v.end()
#define pb emplace_back
//#define mp make_pair
#define fi first
#define se second
#define nu 100001
#define mod 998244353
#define mul(x, y) ((ll)(x) * (y)) % mod
#define tr(c, i) for (auto i = (c).begin(); i != (c).end(); i++)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(t, tmpv) \
    for (int tmpv = 0; tmpv < t; tmpv++)
#define reprange(s, e, tmpv) \
    for (int tmpv = s; tmpv < e; tmpv++)
#define writeLine(arg) cout << arg << '\n'
#define pairof(type) pair<type, type>
#define vit std::vector<int>::iterator
#define divby2 >> 1
#define mulby2 << 1
#define swapI(a, b) tmp = a; a = b; b = tmp;        
#define swapInline(a, b) \
    a ^= b;              \
    b ^= a;              \
    a ^= b;
#define isOdd(n) n & 1
#define it(msg) \
    if (Debug)  \
        cerr << msg << '\n';

using ds = ll;

//permanent constants
bool Debug = false;
//const double pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
//const ll INF = 1e18 + 239;
const ll prost = 239;
ll MOD = 998244353;
ll MOD2 = MOD * MOD;
int BIG = 987654321;
const int alf = 26;
const int dxd[4] = {-1, 0, 1, 0};
const int dyd[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digvec[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;
void printString(string str){
    cout << str << '\n';
}

using namespace std;

// https://www.acmicpc.net/problem/

// 최단경로 

// 방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.
// 입력

// 첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1≤V≤20,000, 1≤E≤300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 둘째 줄에는 시작 정점의 번호 K(1≤K≤V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.
// 출력

// 첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.
const int LARGE=1e8+5;

vii adjs[20005]; // 인접 점까지의 거리를 담은 지그재그 리스트들의 배열
int anss[20005]; // 시작점 기준 특정 점까지의 거리를 담은 배열
bool visited[20005]; // 특정 점을 방문했는지의 여부

void solve(){
  int V,E;
  cin>>V>>E;
  int K;
  cin>>K;

  // 두 정점 사이에 여러 간선이 가능. 방향그래프.
  // 인접행렬? 인접리스트? 

  int t;
  int u,v,w;
  rep(V+1, t){
      adjs[t]=vii();
  }
  rep(V+5, t){
      anss[t]=LARGE;
  }
  rep(E, t){
      cin>>u>>v>>w;
      adjs[u].push_back({v,w});
  }
  // 플로이드의 알고리즘? : 모든점에서 모든점으로 찾는 알고리즘.
  // 여기서는: 한 시작점에서 다른 모든 점으로 거리를 찾아야 하므로, 다익스트라를 써야 할 듯
  // 다익스트라:
  // 모든 점을 무한으로 잡고, 시작점 0으로 시작하여,
  // 큐에서 발견점을 하나 꺼내 탐색 점으로 두고, 탐색점 주변의 미발견 점을 발견점 큐에 넣으면서 거리를 갱신한다.
  // 여기에서 priority queue를 쓰는 경우도 있다고 했는데, (거리 가까운 순?) 그건 어떻게 하는 지 잘 모르겠다.

  priority_queue<ii, vii> q;

  anss[K]=0;
  q.push({-0, -K});

  while(!q.empty()){
    ii p=q.top(); q.pop(); // 큐에서 탐색점을 하나 꺼낸다.
    int dist = -p.first; // 탐색점은 탐색점까지의 거리 및 탐색점의 번호를 담고 있다.
    int no = -p.second;

    // 그럼 이제 탐색점 주변의 점들에 대해 순회한다.
    // 탐색점 주변의 점이 이미 발견된 점이면, 거리를 재 봐서 더 짧은 쪽을 쓰고,
    // 미발견 점이라면 (infㄷ), 거리를 탐색점+탐색점-미발견 점 거리로 하되,
    // 그 점도 새로운 탐색점으로 탐색해야 하므로 큐에 넣는다.

    for(auto po : adjs[no]){ // adj[u][i].first=to정점번호, second=거리
      // cout << po.first << ' ' << po.second << "search " << endl;
      if(dist+po.second<anss[po.first]){
        anss[po.first]=min(anss[po.first], dist+po.second);
        q.push({-anss[po.first], -po.first});
      } else continue;
    }
  }

  for (int i = 1; i <= V; i++)
  {
    if(anss[i]>=LARGE) cout<< "INF\n";
    else cout << anss[i] << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  solve();
  return 0;
}