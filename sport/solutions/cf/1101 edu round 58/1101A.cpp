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
using namespace std;
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
#define rep(t) \
    cin >> t;  \
    for (int tmpv = 0; tmpv < t; tmpv++)
#define writeLine(arg) cout << arg << '\n'
#define pairof(type) pair<type, type>
#define vit std::vector<int>::iterator
#define divby2 >> 1
#define mulby2 << 1
#define swap(a, b) \
    a ^= b;        \
    b ^= a;        \
    a ^= b;
#define isOdd(n) n & 1
#define it(msg) \
    if (Debug)  \
        cerr << msg << '\n';

using ds = ll;

//permanent constants
bool Debug = false;
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
//const ll INF = 1e18 + 239;
const ll prost = 239;
const ll MOD = 998244353;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

//ds MOD(ds a, ds b)
//{
//	if (a > b)
//		return a - b;
//	else
//		return b - a;
//}

inline ds MSD(ds n)
{
    double K = log10(n);
    K = K - floor(K);
    int X = pow(10, K);
    return X;
}

/* Function to check if x is power of 2*/
inline bool isPowerOfTwo(int x)
{
    /* First x in the below expression is
		for the case when x is 0 */
    return x && (!(x & (x - 1)));
}

//// are all of the elements positive?
//all_of(first, first + n, ispositive());
//
//// is there at least one positive element?
//any_of(first, first + n, ispositive());
//
//// are none of the elements positive?
//none_of(first, first + n, ispositive());

//// copy 5 elements from source to target
//copy_n(source, 5, target);

//int a[5] = { 0 };
//char c[3] = { 0 };
//
//// changes a to {10, 11, 12, 13, 14}
//iota(a, a + 5, 10);
//iota(c, c + 3, 'a'); // {'a', 'b', 'c'}

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
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
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

inline ds Readin()
{
    int K = 0;
    char C = ' ';
    while (C < '0' or C > '9')
        C = getchar();
    while (C <= '9' and C >= '0')
        K = (K << 1) + (K << 3) + C - '0', C = getchar();
    return K;
}

inline ds mult(ds a, ds b, ds c)
{
    if (b == 1)
        return a % c;
    if (b % 2 == 0)
    {
        ds tt = mult(a, b / 2, c);
        return (tt * tt) % c;
    }
    else
        return mult(a, b - 1, c) * a % c;
}

int s = 0;
int adj[120][120];
bool vis[120];

int ans = 0;

void dfs(int v)
{
    if (vis[v])
        return;
    vis[v] = true;
    ans++;
    it("ans++");
    for (int i = 1; i <= 100; i++)
    {
        if (adj[v][i])
        {
            dfs(i);
        }
    }
}

void solve()
{
    int q;

    rep(q)
    {
        int l, r, d;
        cin >> l >> r >> d;
        int x = d;
        if(l <= x){
            x = (r / d + 1) * d;
        } 
        cout << x << endl;
    }
    // int n, m;
    // cin >> n;

    // rep(m){
    //     int u, v;
    //     cin >> u >> v;
    //     it("connecting nodes");
    //     it(u);
    //     it(v);
    //     adj[u][v] = 1;
    //     adj[v][u] = 1;
    // }

    // dfs(1);

    // cout << ans - 1 << endl;
}

bool IsDebug(int argc, char **argv)
{
    string ss;
    for (int i = 0; i < argc; i++)
    {
        ss = argv[i];
        if (ss == "TestMode")
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    fastio;
    Debug = IsDebug(argc, argv);
    it("starting");
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
    // freopen("./sport/cpp/input.txt", "r", stdin);
    // freopen("./sport/cpp/output.txt","w",stdout);
    // if(IsDebug(argc, argv)){
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt","w",stdout);
    // }
#endif
    solve();
    it("done");
    return 0;
}