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

using ds = ll;

//permanent constants
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
const int MAXN = 300004;
// const int MAXN = 16;
int types[MAXN+6];

ll ans = 0;
int type1 = 0;
int type2 = 0;
bool fail = false;

vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int vertex, int targetType){
    if(types[vertex] != 0 && types[vertex] != targetType){
        fail = true;
        return;
    }

    if(visited[vertex]){
        return;
    }
    visited[vertex] = true;

    if(targetType == 1){
        type1++;
    } else {
        type2++;
    }
    types[vertex] = targetType;

    for(int v : adj[vertex]){
        if(targetType == 1){
            dfs(v, 2);
        } else {
            dfs(v, 1);
        }
    }

}

void solve()
{
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        int n,m;
        cin >> n >> m;


        // 각 vertex에 숫자 1,2,3중 하나를 할당해서,
        // 모든 각각의 edge에 대해 연결된 vertex들의 숫자의 합이 홀수.

        // 일단, 짝수 숫자 할당은 아무 영향도 주지 않는다.
        // 홀수 vertex가 홀수 개 있어야 합이 홀수가 된다.
        // 즉 모든 간선에 대해 연결된 정점들이 합이 홀수가...
        // 근데 간선에 연결된 정점은 두개잖아? 그러니 당연히
        // 홀수인 정점은 딱 하나여야 하네.
        // 그러면 차수 문제일 가능성이 높다! 왜냐하면, 
        // 단 하나라도 인접한 두 정점이 모두 홀수거나 짝수여서는 안되기 때문!
        // 그래프가 그럼 임의의 한 정점에 대해 홀수로 시작한 그래프/짝수로 시작한 그래프 딱 두 가지로 사실상 타입이 나뉘어질거 같다.
        // dfs로 해도 될까? 이번 정점이 모순이 있는지 확인하려면 어떻게 해야 하지?
        // 일단 모든 정점을 타입을 0으로 시작한 뒤, 
        // 정점에 도달하면 타입을 갖고있는지 확인하여, 
        // 할당하려던 타입을 갖고있다면 내버려 둔다,
        // 잘못된 타입이라면 답은 0이 된다. 즉시 종료
        // 타입이 없다면 타입을 할당해 준다.
        // 처음 시작 정점을 아무거나 잡아서
        // 타입 1로 한 번 순회, 2로 한 번 순회해준다.
        // 순회를 하면서, 타입 1이 몇개인지, 2가 몇개인지 카운트해준다
        // 생각해보니, visited여도 잘못된 타입 할당하려 하는지 확인하기 위해 1번씩은 중첩 방문 해야할거 같은데, 그러면 너무 느려지려나?

        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        type1 = 0;
        type2 = 0;
        memset(visited, false, sizeof(visited));
        memset(types, 0, sizeof(types));
        fail = false;

        dfs(1, 1);

        if(fail) {
            cout << '0' << endl;
            continue;
        } else {

            ans = power(2, type1);
            // cout << ans << endl;

        }

        type1 = 0;
        type2 = 0;
        memset(visited, false, sizeof(visited));
        memset(types, 0, sizeof(types));
        fail = false;

        dfs(1, 2);

        if(fail) {
            cout << '0' << endl;
            continue;
        } else {

            ans += power(2, type1);
            cout << ans << endl;

        }

    }
    
}

bool IsDebug(int argc, char **argv){
    string ss;
    for(int i = 0; i < argc; i++){
        ss = argv[i];
        if(ss == "Debug"){
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt","w",stdout);
    // freopen("./sport/cpp/input.txt", "r", stdin);
    // freopen("./sport/cpp/output.txt","w",stdout);
    // if(IsDebug(argc, argv)){
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt","w",stdout);
    // }
#endif
    solve();
    return 0;
}