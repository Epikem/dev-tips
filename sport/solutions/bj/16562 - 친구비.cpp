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
//#include <bits/stdc++.h>

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
#define rep1(t, tmpv) \
    for (int tmpv = 1; tmpv <= t; tmpv++)
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

// 친구비
// https://www.acmicpc.net/problem/16562

int arr[10005];
int dist[10005];

int getRoot(int a){
  if(arr[a]==a) return a;
  // path compression
  auto ret=getRoot(arr[a]);
  arr[a]=ret;
  return ret;
}

int getDist(int a){
  if(arr[a]==a) return dist[a];
  // path compression
  auto ret=min(getDist(arr[a]), dist[a]);
  dist[a]=ret;
  return ret;
}

void merge(int a, int b){
  int roota=getRoot(a);
  int rootb=getRoot(b);
  dist[roota]=min<int>(getDist(b), getDist(a));
  dist[rootb]=min<int>(getDist(a), getDist(b));
  arr[rootb]=roota;
}

bool check(int a, int b){
  return getRoot(a) == getRoot(b);
}

void solve(){
  int N,M,K;
  cin>>N>>M>>K;
  int tt,v,w,tmp;
  rep1(N,tt){
    arr[tt]=tt;
    cin>>dist[tt];
  }
  rep(M,tt){
    cin>>v>>w;
    merge(v,w);
  }
  // 최소비용: 준석이 set로부터 시작해서 모든 set를 합칠때까지 최소 비용
  // 그런데, 합쳐진 set이 다른 set과 연결되어 비용이 낮아지는 경우도 있다.
  // 그러면, 모든 set간의 최소 비용들을 일단 기준으로 하면 될 것이다.
  // set간의 최소가 아닌 비용은 고려할 필요가 없을 것 같다.
  // 그러면 set 정보를 기반으로 그래프를 구축해야 하나?
  // 그래프 구축할 때 set간의 최소 비용은 어떻게 찾지?
  // 아예 학생간 거리를 써서 merge할 때 그 정보도 포함해가며 최소거리 정보를 
  // 유지한다면 될 거 같다.
  // 그러면 그래프 구축은 어떻게?
  // 루트들을 중심으로 구축하면 될 거 같다.
  // 루트들을 얻으려면 getRoot와 set를 쓰거나, getRoot해서 자기자신이 나오는 노드만
  // 리스트에 넣어놓고 정점 리스트로 쓰면 된다.
  // 그러면, 전체 최소 비용은 결국 어떻게 구하나?
  // 잠깐 이거 탐색 문제가 아닌게, 어차피 준석 기준으로만 다른 친구들과 연결해야 하고 
  // 다른 친구들끼리 연결하는건 merge과정에서만 일어난다!
  // 따라서 그냥 준석 set가 아닌 모든 그룹까지의 최소 거리들을 구하면 된다.
  ll ans=0;
  for(int t=1;t<=N;t++){
    if(t==getRoot(t)){
      // 루트들에 대해
      // 준석이가 따로 그룹이 있는 것이 아니므로(아싸ㅠㅠ) 모든 루트들을 매수하면 된다.
      ans+=getDist(t);
    }
  }
  if(ans>K){
    cout << "Oh no\n";
  } else cout<<ans<<endl;

}

int main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}