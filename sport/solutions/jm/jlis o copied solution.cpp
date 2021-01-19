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

int a[101];
int b[101];
int cache[101][101];
const ll NEGINF=numeric_limits<ll>::min();

int jlis(int indexA, int indexB){
    int& ret=cache[indexA+1][indexB+1];
    if(ret!=-1) return ret;

    ret=0;
    ll am=(indexA==-1? NEGINF:a[indexA]);
    ll bm=(indexB==-1? NEGINF:b[indexB]);
    ll maxElement=max(am,bm);
    // cout << indexA << ' ' << indexB << ' ' << endl;
    for(int nextA=indexA+1;nextA<n;nextA++)
        if(maxElement<a[nextA])
            ret=max(ret, jlis(nextA,indexB)+1);
    for(int nextB=indexB+1;nextB<m;nextB++)
        if(maxElement<b[nextB])
            ret=max(ret, jlis(indexA,nextB)+1);
    return ret;
}

int getjlis(int ia,int ib){
    int& ret=cache[ia+1][ib+1];
    if(ret!=-1) return ret;
    ret=0;
    ll am=(ia==-1 ? NEGINF : a[ia]);
    ll bm=(ib==-1 ? NEGINF : b[ib]);
    ll larger=max(am,bm);
    for (int i = ia+1; i < n; i++)
    {
        if(larger<a[i]) ret=max(ret, getjlis(i,ib)+1);
    }
    for (int j = ib+1; j < m; j++)
    {
        if(larger<b[j]) ret=max(ret, getjlis(ia,j)+1);
    }
    // cout << ia << ' ' << ib << ' '<<ret << endl;
    return ret;
}

void solve()
{
    int C;
    cin >> C;
    for(int c=0;c<C;c++){
        cin >> n >> m;
        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < 101; j++)
            {
                cache[i][j]=-1;
            }
            
        }
        
        for(int nn=0;nn<n;nn++){
            cin >> a[nn];
        }
        for(int mm=0;mm<m;mm++){
            cin >> b[mm];
        }

        // 1,9,4 3,4,7 에서 1,3,4,7,9를 선택해야 한다.
        // 탐욕법으로는 안 되는건 알겠지만, 어떻게 여기서 재귀 구조를 찾지?
        // 숫자가 겹치는 경우, 범위가 서로 다른 경우, 등등 여러 경우가 있는데
        // 어떻게 일반화 시킬 수 있을까?
        // 다른 반대편 정보를 알지 않고 한쪽 정보만 고려해서는 되지 않는다.
        // 1,3,2 4,3,5
        // 인덱스 기반으로 재귀구조를 하는게 적합할까? 다른구조로 마땅한게 없긴 하다.
        // 아무래도 인덱스 기반으로 하게 되면 다음과 같이 정의될거 같은데,
        // jlis(ia,ib): a의 ia, b의 ib까지의 수열을 고려한 jlis
        // 그렇다면, ia나 ib를 늘려가면서 풀어야 할 것이다.
        // 문제는, ia나 ib가 늘어날 때 갑자기 지금까지 했던 선택이 바뀌는 경우가 존재할 수 있다는 것이다.
        // 예를 들어, 1,3,2 3,5 에서, jlis(2,2)=[1,3,5]이지만, jlis(3,2)=[1,2,3,5]가 된다.
        // 이전에 했던 선택을 바꿔야 할 수 있다는 것이다. 그러면 너무 복잡해진다.
        // 인덱스를 1 증가할 때마다, 이번 수를 선택할지 말지 선택해야 할 텐데,
        // 그 때마다 전체 선택해왔던 수들 중 이번 수보다 큰 것은 전부 포기하는 식으로?
        // 그러면 각 인덱스마다 2가지의 선택, 즉 2^n가지가 되버린다. 이걸 메모이제이션할 수 있을까?
        // 
        // 이전 문제의 경우 책에서는 lis(start)로 해서, start인덱스부터 시작한 최대를 구한다는 정의를 나타내었다. 어떻게 이게 가능할까? 그 start 이후로도 각 원소들을 어떻게 선택할지를 결정해야 할 텐데. 근데 바로 그것이 재귀적으로 lis(start)를 호출해서 해결된다.
        // lis(start)=for i:start~n, max(lis(i))
        // 마찬가지로 jlis도 그렇게 할 수 있을 것이다.
        // jlis(astart,bstart)=for i:astart~n,j:bstart~m, max(jlis(i,j))
        // int ans=getjlis(-1,-1);
        int ans=jlis(-1,-1);
        cout << ans << '\n';
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