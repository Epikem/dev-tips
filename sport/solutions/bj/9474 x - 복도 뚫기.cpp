/*


일단 테케수 100에다 센서수 1000이므로, 모든 센서간 거리를 계산하게 되면 1,0000,0000 여기까진 가능하다. 그러나 복도하고까지 계산하면 터질 것이다.

일단 무식하게 본다면 답 자체는 
모든 벽 또는 센서간의 조합 중 최소 거리가 된다.
그림에서는 센서가 가로로 한 개만 놓여있지만, 조건상 입력이 그럴 리는 없다.

그러면 모든 센서간, 모든 벽간의 모든 거리 조합의 조합 수는 몇가지가 되나?
센서중에서 고르는 1000C2+센서와 벽을 고르는 1000*2 정도인가?

대체 이 문제가 mst와 무슨 상관이지.

생각해보니 조합 중 최소거리가 아닌 것이, 지나갈 수 있기만 하면 되므로, 공간중 가장 넓은 곳으로 지나갈 것이다.



센서들의 위치와 r을 이용해, 거리를 계산할 필요가 있는 쌍을 생각하고, 

왼쪽 아래에서부터 시작해서, 가장 벽에 가까운 원을 기준으로, mst를 돌리되, 오른쪽 벽에 닿으면 끝난다. 그런데, 그 과정에서 병목 센서군을 찾아야 하므로, 다음 센서를 찾을 때 이전 센서를 가리키게 해서, 오른쪽 벽에 도달하면 이전으로 계속 돌아가면서 그 리스트를 얻는다.
\

문제는, 원들이 위치정보로만 주어져 있어서, 어떻게 링크들을 정렬해서 돌릴지 모르겠다.

mst는 트리이므로, 트리의 중간부터 조사해서 분리시키면 트리가 끊어진다.
그러나 여기에서 아래쪽 또는 위쪽 센서부터 조사한다면 트리가 끊어지지는 않을 것이다. 그렇다면, 아래쪽 센서부터 시작해서 ??
근데 또, 왼쪽 벽에서 시작해서 왼쪽 벽으로 가는 경우 등이 문제가 된다.

질문답변을 보니 벽도 노드로 생각한 후 mst 돌려서 마지막에 뽑힌 간선길이가 지름이라는데.. 대체 왜 그럴까?? 이해가 안 된다.





*/

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

struct sensor{
    int x,y,r;
};

bool comp(sensor& a, sensor& b){
    return a.y < b.y;
}

float ans=0.0f;

int uf[1005];
float dist[1005][1005];
bool visited[1005];

int find(int a){
    if(a==uf[a]) return a;
    uf[a]=find(uf[a]);
    return uf[a];
}

void solve(){
    int tc,t,T,w,W,n,N,x,y,r,a,b,c,i,j,k,tmp,g;
    cin>>T;
    sensor ss[1005];
    fill(visited,visited+1005,false);
    rep1(T,tc){
        cin>>W;
        cin>>N;
        rep(N, n){
            uf[n]=n;
        }
        rep(N, n){
            cin>>x>>y>>r;
            ss[n]={x,y,r};
            // cout<<ss[n].x<< ' '<<ss[n].y<< ' '<<ss[n].r<<endl;
        }

        rep(N, i){
            rep(N, j){
                dist[i][j]=sqrtf((ss[i].x-ss[j].x)*(ss[i].x-ss[j].x)+(ss[i].y-ss[j].y)*(ss[i].y-ss[j].y));
            }
        }

        sort(ss,ss+N,comp);

        rep(N, i){
            g=find(i);

            if(!visited[g]){
                visited[g]=true;
                
            }
        }

        rep(N, i){
            cout<<ss[i].x<< ' '<<ss[i].y<< ' '<<ss[i].r<<endl;
        }
    }
}

int main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}
