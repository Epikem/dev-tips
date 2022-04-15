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

struct edge{
    int u,v;  
};

// edge links[11];
int indeg[11];
int indeg2[11];
vector<int> links[11];
int mins[11];
int maxs[11];

// void solve(){
//     priority_queue<int> q;

//     // q.push(-1);
//     // q.push(-4);
//     // q.push(-8);
//     // q.push(-2);
//     // q.push(-3);
//     // q.push(-6);
//     // q.push(-9);

//     q.push(1);
//     q.push(4);
//     q.push(8);
//     q.push(2);
//     q.push(3);
//     q.push(6);
//     q.push(9);
//     while(!q.empty()){
//         auto t=q.top();q.pop();
//         cout<<t<< ' ';
//     }
//     cout<<endl;

// }

void solve(){
    int nn,nnn;cin>>nn;int i,j;
    char ch;
    rep1(nn,i){
        cin>>ch;
        if(ch=='<'){
            // for(int j=i;j<=nn;j++){
            //     indeg[j]++;
            // }
            indeg[i]++;
            indeg2[i]++;
            links[i-1].push_back(i);
        }else {
            // for(int j=i-1;j>=0;j--){
            //     indeg[j]++;
            // }
            indeg[i-1]++;
            indeg2[i-1]++;
            links[i].push_back(i-1);
        }
    }

    priority_queue<int> q;
    rep(nn+1, i){
        // cout<<indeg[i]<<endl;
        if(indeg[i]==0){
            q.push(i);
        }
    }

    vector<int> lis;

    while(!q.empty()){
        int next=q.top();q.pop();
        cout<<next<<endl;
        
        lis.push_back(next);

        for(int j=links[next].size()-1; j>=0;j--){
            int v=links[next][j];
            indeg[v]--;
            links[next].pop_back();
            if(indeg[v]==0){
                q.push(v);
            }
        }
    }

    int curmin=0;
    int curmax=9;

    rep(lis.size(), i){
        cout<<lis[i]<<endl;
        maxs[lis[lis.size()-i-1]]=curmax--;
        cout<<lis.size()-lis[i]<<' ';
        mins[lis.size()-lis[i]]=curmin++;
    }

    rep(nn+1, i){
        cout<<maxs[i];
    }
    cout<<endl;
    rep(nn+1, i){
        cout<<mins[i];
    }

    
    // priority_queue<int> qq;

    // rep(nn+1, i){
    //     // cout<<indeg[i]<<endl;
    //     if(indeg2[i]==0){
    //         qq.push(-i);
    //     }
    // }

    // // vector<int> lis;3
    // lis.clear();

    // while(!qq.empty()){
    //     int next=-qq.top();qq.pop();
    //     cout<<next<<endl;
        
    //     lis.push_back(next);

    //     for(int j=links[next].size()-1; j>=0;j--){
    //         int v=links[next][j];
    //         indeg2[v]--;
    //         links[next].pop_back();
    //         if(indeg[v]==0){
    //             qq.push(-v);
    //         }
    //     }
    // }
    // // int curmin=0;

    // rep(lis.size(), i){
    //     cout<<lis[i]<<endl;
    //     mins[lis[i]]=curmin++;
    // }

    // rep(nn+1, i){
    //     cout<<mins[i];
    // }
}

int main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}
