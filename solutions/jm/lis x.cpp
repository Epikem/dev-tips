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
#define rep(t) \
    cin >> t;  \
    for (int tmpv = 0; tmpv < t; tmpv++)
#define writeLine(arg) cout << arg << '\n'
#define pairof(type) pair<type, type>
#define vit std::vector<int>::iterator
#define divby2 >> 1
#define mulby2 << 1
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
void sampleBasicBitOperations()
{
    cout << "(225 & 498) : " << (225 & 498) << endl;
    cout << "(-225 & 225) :" << (-225 & 225) << endl;
    cout << "(225 | 498) :" << (225 | 498) << endl;
    cout << "(225 | 498) :" << (225 | 498) << endl;
    cout << "(225 ^ 498) :" << (225 ^ 498) << endl;
    cout << "(225 ^ 498) :" << (225 ^ 498) << endl;
    cout << "(~498) :" << (~498) << endl;
    cout << "(225 << 2) :" << (225 << 2) << endl;
    cout << "(225242 >> 2) :" << (225242 >> 2) << endl;
}

bool faultyIsBitSet(unsigned long long a, int b)
{
    return ((a & (1 << b)) > 0);
}

bool isBitSet(unsigned long long a, int b)
{
    return (a & ((unsigned long long)1 << b)) > 0;
}

void sampleMostFaultsOfBitOperations()
{
    int c = (6 & 4 == 4);
    int d = ((6 & 4) == 4);
    cout << "(6 & 4 == 4) : " << c << endl;
    cout << "((6 & 4) == 4) : " << d << endl;
    cout << "faultyIsBitSet(8589934593, 33) : " << faultyIsBitSet(8589934593, 33) << endl;
    cout << "isBitSet(8589934593, 33) : " << isBitSet(8589934593, 33) << endl;
    cout << "(1073741824 >> 33) : " << (1073741824 >> 33) << endl;
}

int bitCountSlow(int x)
{
    if (x == 0)
        return 0;
    return x % 2 + bitCountSlow(x / 2);
}

void printSet(int set)
{
    //string s = "";

    //for (int i = 0; i < __builtin_popcount(set); i++)
    //{
    //    if (set & (1 << i))
    //    {
    //        s += "1";
    //    }
    //    else
    //    {
    //        s += "0";
    //    }
    //}
    //cout << s << endl;
}
void printSet(int set, int length)
{
    string s = "";

    for (int i = 0; i < length; i++)
    {
        if (set & (1 << i))
        {
            s += "1";
        }
        else
        {
            s += "0";
        }
    }
    cout << s << endl;
}
class bitSet
{
private:
    int val;

public:
    bitSet(int v)
    {
        this->val = v;
    }

    int addElement(int v)
    {
        this->val |= v;
        return this->val;
    }

    int getValue()
    {
        return this->val;
    }

    int allOn(int len)
    {
        this->val = (1 << len) - 1;
        return this->val;
    }

    int allOff()
    {
        this->val = 0;
        return this->val;
    }

    int hasElement(int v)
    {
        return (this->val & (1 << v));
    }

    int removeElement(int v)
    {
        this->val &= ~(1 << v);
        return this->val;
    }

    int toggleElement(int v)
    {
        this->val ^= (1 << v);
        return this->val;
    }

    int addSet(int s)
    {
        this->val |= s;
        return this->val;
    }

    int getIntersection(int s)
    {
        this->val &= s;
        return this->val;
    }

    int removeSet(int s)
    {
        this->val &= ~s; // 0->1??
        return this->val;
    }

    int toggleSet(int s)
    {
        this->val ^= s;
        return this->val;
    }

    int countElementsSlow()
    {
        return bitCountSlow(this->val);
    }

    int countElements()
    {
#if defined(_MSC_VER)
        //// code specific to Visual Studio compiler
        //return __popcnt(this->val);
#else
        return __builtin_popcount(this->val);
#endif
    }

    int findMinElementIndex()
    {
#if defined(_MSC_VER)
        //DWORD index = 0;
        //return _BitScanForward(&index, this->val); // index?
#else
        return __builtin_ctz(this->val);
#endif
    }

    int findMinElement()
    {
        return (this->val & -this->val);
    }

    int removeMinElement()
    {
        this->val &= (this->val - 1);
        return this->val;
    }

    void doForAllSubsets(void (*f)(int, int))
    {
        for (int subset = this->val; subset; subset = ((subset - 1) & this->val))
        {
            (*f)(subset, this->countElements());
        }
    }
};

vi subset;
void IterSubsets(int k);

int m, n, x, T;

int arr[505];
int mins[505];
int cache[505][505];
int search(int cur, int start, int len){
    // cout << ' ' << cur << ' ' << start << ' ' << len << endl;
    if(cur>=n){
        return len;
    }
    int& ret=cache[start][len];
    if(arr[cur]<=arr[start]){
        ret=max(search(cur+1, cur, 1), search(cur+1, start, len));
        return ret;// 그런데, 지금까지 선택한게 길었다면? 문제가 된다. 이 경우
        // 이 문제의 경우 len=3인 것을 포기하고 1로 바꾸면서 넘어가느냐, 아니면 
        // len=3을 유지하느냐의 문제다. 그렇다면 sum을 저장하는 대신, 시작점 s를 나타낸다면?
        // 문제는, 그걸로 저장이 될까..
    }
    // 여기서 중요한 건 cur의 값보다도 현재까지 선택한 최대 수인 start다.
    // arr[cur+1]이 start보다 큰 경우에도, 선택하지 않는게 득일 수 있다.
    ret = max(search(cur+1, cur, len+1), search(cur+1, start, len));
    return ret;
}

// 역시 cache를 505x505로 하니 메모리 초과가 되버리는거 같다.
// 그렇다면, 그냥 모든 수 500가지에 대해, 그 수를 기준으로 치고, 500개 중 넘는 걸 세는 것을 해서
// 최대 길이를 저장한다면? 시간복잡도 500*500*50=250000*50=1250,0000 cpp로는 충분할지도. 하지만 이건
// 전혀 동적계획이 아닌데.. 어? 그렇다는건, 현재 쓰는 코드도 start를 지정하면 cache에서 start를 뺄 수 있는것 아닌가?
// 그렇긴 한데..
// 

void solve()
{
    int C;
    cin >> C;
    
    for(int c=0;c<C;c++){
        cin >> n;
        // 어떻게 풀었었는지 까먹었다.
        for(int t=0;t<n;t++){
            cin >> arr[t];
        }

        // 특정 수를 선택하면, 기준 수가 늘어나버리고,
        // 선택하지 않으면 길이가 짧아진다.
        // 즉, 길이가 길거나 선택 수가 작은 정보들을 우선순위 큐를 사용하여 관리한다면?
        // 아니면, 각 길이별로 배열에, 그 최소 선택수를 저장하여 관리하면서,
        // 높은 수를 만나게 되면 길이+1 칸에 그 높은수를 저장한다면?,
        // 그러면 특정 수에 대해 어느 칸에 더할 수 있는지 매 번 찾아야 한다..
        
        // for(int i=0;i<n;i++){

        // }
        // cout << "wrfsdsd"<<endl;
        cout << search(0,0,0) << '\n';
    }

}

int main(int argc, char **argv)
{
    fastio;
    // Debug = IsDebug(argc, argv);
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    // freopen("./output.txt", "w", stdout);
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

void IterSubsets(int k)
{
    if (k == n + 1)
    {
        // 부분집합 처리
        x++;
        cout << "x : " << x << ", size : " << subset.size() << '\n';
        cout << subset.size() << '\n';
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << '\n';
        }
    }
    else
    {
        //    cout << k << endl;
        subset.push_back(k);
        IterSubsets(k + 1);
        subset.pop_back();
        IterSubsets(k + 1);
    }
}