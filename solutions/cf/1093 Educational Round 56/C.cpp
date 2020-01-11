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
#define mod 1000000007
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

using ds = int;

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
const int MAXN = 100006;
// const int MAXN = 16;
ll bs[MAXN+6];
ll as[MAXN*2+6];

void solve()
{
    int n; cin >> n;


    // 중간까지는 ai에 할당가능한 최소값 할당하고, 이후부터는 최대 할당?
    // 어차피 ai 하나를 선택하면 다른 하나는 결정됨.
    // ai와 a(i+1)을 같은 값으로 할당해서는 안되는 경우가 어떤 기준으로 생기지?
    // 두 번째 예제를 보면, 0 0 1 1 1 2에서 어떤 숫자도 건드릴 수 없다.
    // 두 번째 0을 1로 바꾸면 뒤의 1을 0으로 해야 해서 틀려지고, 그건 쉬운 조건이지만,
    // 세 번째 1을 0으로 바꾸면 4번째 1이 2가 되는데, 이것이 그 뒤의 1보다 커지므로 또 모순이 된다. 이 부분이 어렵다.
    // 일종의 그리디로 보인다. ai를 어떤 값으로 해놓고  a(n-i+1)의 값이 그 뒷값보다 커지지 않았다면 될 것이다. 어차피 답이 분명 존재한다 했으므로 그리디로 하면 될 것.
    // 그리디로 하고있기 때문에 내 생각에 ai쪽에서는 모순이 생기지 않을 것이다. 뒤쪽에서만 모순이 생길 것이다. 근데 이렇게 curval을 1씩 증가시키면 10^18번 정도에 비례해 실행될텐데 괜찮을까? 절대 안 괜찮다. 1억번당 1초라고 보면 10^18하는데는 굉장히 오래걸리게 된다.
    // 따라서 뒤쪽의 관계를 읽어서 최대한 적게 증가시키는 값을 한 번에 찾아줘야 한다.

    ll curval = 0;

    as[n] = 9223372036854775807ll - 5;
    as[n+1] = 9223372036854775807ll - 5;
    
    for(int i = 0; i < n/2; i++){
        cin >> bs[i];

        bool assigned = false;
        while(!assigned){
            as[i] = curval;
            as[n - i-1] = bs[i] - curval;
            if(as[n - i-1] <= as[n - i]){
                // 모순 없는 경우
               assigned = true; 
            } else {
                //모순 있는 경우: curval 증가
                // as[n-i] 가 as[n-i+1]보다 큰 만큼.
                curval += as[n-i-1] - as[n-i];
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << as[i] << ' ';
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