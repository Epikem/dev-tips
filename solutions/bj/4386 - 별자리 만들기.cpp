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

// https://www.acmicpc.net/problem/4386

float dists[105][105];
pair<float, float> positions[105];

struct link{
    int u,v;
    float w;
    link(): link(-1.0f,-1.0f,1000005.0f){};
    link(int u1, int v1, float w1): u(u1), v(v1), w(w1){};

    bool operator <(const link& e) const { return w<e.w; } 
};

int uf[105];

int find(int a){
    if(a==uf[a]) return a;
    return uf[a]=find(uf[a]);
}

bool merge(int a, int b){
    a=find(a);
    b=find(b);
    if(a==b) return false;
    uf[a]=b;
    // cout<<"merging "<<a<<' '<<b<<endl;
    return true;
}

void solve(){
    link links[10300];
    int n;
    cin>>n;
    int i; int j;
    float x,y;
    rep1(n, i){
        cin>>x>>y;
        positions[i]={x,y};
        uf[i]=i;
    }

    rep1(n, i){
        rep1(n, j){
            float x1=positions[i].first,x2=positions[j].first;
            float y1=positions[i].second,y2=positions[j].second;
            dists[i][j]=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
            links[i*n+j]={i, j, dists[i][j]};
        }
    }

    sort(links, links+10300);

    int cnt=0;
    int a=0,b=0;
    float cost=0.0f;
    rep1(10300, i){
        a=links[i].u,b=links[i].v;
        if(!merge(a,b)) continue;
        cost+=sqrtf(links[i].w);
        cnt++;
        // cout<<links[i].w<<endl;
        if(cnt==n-1)break;
    }
    
    cout<<setprecision(8)<<cost<<endl;
}

int main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}
