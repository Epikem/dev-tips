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
#define pii pair<int, int>
#define piii pair<int, pair<int, int> >
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

void PrintString(string str){
    cout << str << '\n';
}
void print ( int x ) {
  printf("%d\n", x);
}
template<class T>
void PrintVector(vector<T>& t){
    for (int i = 0; i < t.size(); i++)
    {
        cout<< t[i] << ' ';
    }
    cout<<'\n';
}

using namespace std;

int N,M,K;

struct road{
    ll length;
    int goal;
    bool operator<(const road& rhs) const
    {
        return length < rhs.length;
    }
};

vector<road> roads[10005];
priority_queue<road, vector<road> > pq;
ll dist[10005];
ll ans;
bool visited[10005][21];
ll cache[10005][21];
int parent[10005];

ll d(int city, int pack){
    visited[city][pack]=true;
    if(city==1){
        return 0;
    }
    else if(pack==0){
        return dist[city];
    } else if(cache[city][pack]) return cache[city][pack];

    ll minD=MOD2;

    for (auto neighbor: roads[city])
    {
        int i=neighbor.goal;
        
        // 2. d(connectedCity, pack)으로부터 연결. (이전 간선중에 pack개 이미 선택)
        if(!visited[i][pack]){
            cout<<"go1 "<<i<< ' ' <<pack<<endl;
            if(d(i, pack)+neighbor.length<minD){
                minD=d(i, pack)+neighbor.length;
            }
            cout<<"out1 "<<i<< ' ' <<pack<< ' ' << minD <<endl;
        }

        // 1. d(city, pack-1)로부터 (이번 간선중에 포장.)
        if(!visited[i][pack-1]){
            cout<<"go2 "<<i<< ' ' <<pack-1<<endl;
            if(d(i, pack-1)<minD){
                minD=d(i, pack-1);
            }
            cout<<"out2 "<<i<< ' ' <<pack-1<< ' ' << minD <<endl;
        }
        
    }
    cache[city][pack]=minD;
    return cache[city][pack];
}

void solve(){
    cin>>N>>M>>K;
    int u,v,w;
    
    rep(M, i){
        cin>>u>>v>>w;
        roads[u].push_back(road{w,v});
        roads[v].push_back(road{w,u});
    }

    rep1(N+10, i){
        dist[i]=MOD2;
    }

    dist[1]=0;
    pq.push(road{-0, -1});
    while(!pq.empty()){
        auto t=pq.top();pq.pop();
        int cur=-t.goal;

        for(auto target: roads[cur]){
            ll length=target.length;
            int goal=target.goal;

            if(dist[goal]>dist[cur]+length){ // updatable
                parent[goal]=cur;
                dist[goal]=dist[cur]+length;
                pq.push(road{-dist[goal], -goal});
            }
        }
    }

    // cout<<dist[10]<<endl;
    // cout<<dist[11]<<endl;
    // cout<<dist[12]<<endl;
    // cout<<dist[N]<<endl;

    // cout<<d(12,0)<<endl;
    // cout<<d(11,0)<<endl;
    // cout<<d(11,1)<<endl;
    // cout<<d(12,1)<<endl;
    // cout<<d(400,0)<<endl;
    cout<<d(N,K)<<endl;
}


int main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}