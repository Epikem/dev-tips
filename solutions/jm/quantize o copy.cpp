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
const int BIG = 987654321;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digvec[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
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
int N,S;
vector<int> vec;
vector<int> seps;
ll a2[101];
ll a1[101];
// ll midpointCache[101][101];
int cache[101][11];
// int getDiff(int x, int y){
//     if(diffCache[x][y]!=-1){
//         return diffCache[x][y];
//     }

//     int& ret=diffCache[x][y];
//     ret=(x-y)*(x-y);
//     diffCache[y][x]=ret;
//     return ret;
// }

int getMinCost(int lo, int hi){
    int k=hi-lo+1;
    int sum1=a1[hi]-(lo==0?0:a1[lo-1]);
    int sum2=a2[hi]-(lo==0?0:a2[lo-1]);
    // cout << lo << ' ' << hi << ' ' << k << endl;
    // int m=(int)roundf((float)(sum1)/(float)k);
    int m=int(0.5+(double)sum1/(hi-lo+1));
    // cout << m << endl;
    int cost=k*m*m-2*(sum1)*m+(sum2);
    return cost;
}
ll getminx(int sep, int count){
    if(count==S+1){
        // for (int i = 0; i < seps.size(); i++)
        // {
        //     cout << seps[i] << ' ';
        // }
        
        // cout << endl;
        ll ret=0;
        for (int s = 0; s < S; s++)
        {
            // cout << "calculating seps:" << s << ' ' <<seps[s] << ' ' << seps[s+1] << endl;
            if(s==S-1){
                ret+=getMinCost(seps[s],N);
            } else ret+=getMinCost(seps[s],seps[s+1]);
        }
        return ret;
    }
    
    ll ret=10123456789ll;
    for (int i = sep+1; i < N; i++)
    {
        seps.push_back(i);
        ret=min(ret, getminx(i, count+1));
        seps.pop_back();
    }
    return ret;
}
int getmin(int from, int left){
    if(from==N) return 0;
    if(left==0) return BIG;
    // if(left==S && from>=N){
    //     return 0;
    // }
    int& ret=cache[from][left];
    if(ret!=-1) return ret;
    ret=BIG;

    for (int partSize = 1; from+partSize <= N; partSize++)
    {
        ret=min(ret,getmin(from+partSize, left-1) + getMinCost(from, from+partSize-1));
    }
    return ret;
    
}


void solve()
{
    int C;
    cin >> C;
    for(int c=0;c<C;c++){
        for (int y = 0; y < 101; y++)
        {
            for (int x = 0; x < 11; x++)
            {
                cache[y][x]=-1;
            }
        }
        cin >> N >> S;
        int tmp;
        for (int y = 0; y < 101; y++)
        {
            a1[y]=0;
            a2[y]=0;
        }
        
        vec.clear();
        seps.clear();
        for (int i = 0; i < N; i++)
        {
            cin >> tmp;
            vec.push_back(tmp);
        }
        
        sort(all(vec));
        a1[0]=vec[0];
        a2[0]=vec[0]*vec[0];
        for (int i = 1; i < N; i++)
        {
            a1[i]=a1[i-1]+vec[i];
            a2[i]=a2[i-1]+vec[i]*vec[i];
        }
        
        seps.push_back(0);
        

        // 모든 수들이 1000 이하이므로, 양자화는 1000 이하의 수들로만 하면 된다.
        // 1000 이하의 수에서 S개를 고르면 되는 것인데, 여전히 작진 않다.
        // 이게 동적계획법 파트에 있어서 그렇지, 아니었다면 무조건 탐욕법을 시도하다가 실패하게 되버릴거 같은데.
        // 어째서 이게 동적계획법일까. 그리고 어떻게 부분 구조를 찾아야 하는가.
        // 일단 가장 간단하게 생각나는 것은, 인덱스별이 아닌 선택 숫자별로 생각하는 것인데,
        // 그건 좀 당연한 것 같지만 cpp라면 가능할지도. 다 선택됬다면 계산을 하고, 아니면 
        // 더 높은 다음 수를 선택하는 식으로. 그러면 결국 C(1000,S)번 계산해야한다. 가지치기를 늘릴 수 없을까?
        // 다 선택 후 계산을 할 게 아니라, 어차피 증가하면서 선택하므로 이번 선택을 했을 때, 이번 선택보다 작은 수들은 전부 이번 선택으로 계산될 것이다. 따라서 반복문에서 다음 수로 그게 가장 낮은걸로 선택하면 될까?
        // 그렇지는 않다. 그러면 무조건 낮은 수를 선택하게 되버린다. 
        // 궁금한 게, 인덱스 기준이 아닌, 숫자 기준으로는 탐욕법을 써도 되지 않나??
        // 예를 들어, 1부터 1000까지 증가시키면서, 그 숫자가 추가됬을 때 얼마나 전체 cost가 줄어드는지 계산해서 가장 많이 줄이는 숫자를 추가하는 식으로 한다면?
        // 문제는 이후로 계산을 할 때 이전 숫자들로 양자화할지 이번 숫자로 양자화할지 계속 달라진다는 점. 하지만 그 점은 위의 방식에서도 고려되야 하는것은 마찬가지다.
        // 게다가 시도해보니 위의 탐욕법도 모든 closest를 갱신후 계산한다면 이중 반복문이 된다.
        // 
        // vec=&vec[0];
        
        cout << getmin(0,S) << endl;
    }

}

int main(int argc, char **argv)
{
    fastio;
    // Debug = IsDebug(argc, argv);
    
    if(argc>1){
        string s=argv[1];
        if(s=="TestMode"){
            cout << argv[1] << endl;
            freopen("./input.txt", "r", stdin);
        }
    }
    
// #ifndef ONLINE_JUDGE
//     freopen("./input.txt", "r", stdin);
//     // freopen("./output.txt", "w", stdout);
//     // freopen("./sport/cpp/input.txt", "r", stdin);
//     // freopen("./sport/cpp/output.txt","w",stdout);
//     // if(IsDebug(argc, argv)){
//     //     freopen("./input.txt", "r", stdin);
//     //     freopen("./output.txt","w",stdout);
//     // }
// #endif
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