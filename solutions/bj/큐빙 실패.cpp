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
// int** faces;
int** rot;
int faces[7][3][3];
int tmp[3][3];
map<char,char> color={
    {'1', 'w'},
    {'2', 'r'},
    {'3', 'b'},
    {'4', 'o'},
    {'5', 'g'},
    {'6', 'y'}
};

// 이런 식으로 구현하게 되면 일단 한 면 rotate 구현하는데 24개의 연산을 구현해야 하고,
// 문제는 자체 회전 구현이다. 이걸 그냥 copy로 가능하면 좋겠지만 회전하는 면도 있기 때문에 문제다. 그리고 그렇게 하려면 아랫면에 대해서는 앞쪽이 1층이 되어야 함.
// 그럼 뒷면은? 좌우로 돌려서 뒷면으로 간다면 뒷면의 윗쪽면이 1층,
// 위아래로 돌려서 본다면 아랫쪽 층이 1층이 되어야 한다.
// 그렇다면 일단 임의의 면에 대해 그 면만 회전하는 것을 구현하고, 
// 층 회전에 대해서도, copy를 활용해 구현할 수도 있을거 같은데.
// 윗면을 돌린다고 치면, 앞면의 1층은, 왼쪽면의 1층으로 옮겨진다.
// 
void rotateSidesOnly(bool dir){
    if(dir){
        int tmp1,tmp2,tmp3;
        tmp1=faces[3][1][1];
        tmp2=faces[3][2][1];
        tmp3=faces[3][3][1];
        faces[3][1][1] = faces[1][3][1];
        faces[3][2][1] = faces[1][3][2];
        faces[3][3][1] = faces[1][3][3];
        faces[1][3][1]=faces[5][3][3];
        faces[1][3][2]=faces[5][2][3];
        faces[1][3][3]=faces[5][1][3];
        faces[5][3][3]=faces[6][1][1];
        faces[5][2][3]=faces[6][1][2];
        faces[5][1][3]=faces[6][1][3];
        faces[6][1][3]=tmp1;
        faces[6][1][2]=tmp2;
        faces[6][1][1]=tmp3;
    } else {
        int tmp1,tmp2,tmp3;
        tmp1=faces[1][3][1];
        tmp2=faces[1][3][2];
        tmp3=faces[1][3][3];
        faces[1][3][1] = faces[3][1][1];
        faces[1][3][2] = faces[3][2][1];
        faces[1][3][3] = faces[3][3][1];
        faces[5][3][3]=faces[1][3][1];
        faces[5][2][3]=faces[1][3][2];
        faces[5][1][3]=faces[1][3][3];
        faces[6][1][1]=faces[5][3][3];
        faces[6][1][2]=faces[5][2][3];
        faces[6][1][3]=faces[5][1][3];
        faces[5][3][3]=tmp1;
        faces[5][2][3]=tmp2;
        faces[5][1][3]=tmp3;
    }
}
void rotateFaceOnly(char f, bool dir){
    cout << f << ' ' << dir << endl;

    // memcpy(tmp, faces[1], sizeof(int)*9);
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            tmp[y][x] = faces[f][y][x];
            cout << tmp[y][x] << ' ';
        }
        cout << '\n';
        
    }
    
    if(dir)
    {
        faces[f][3][3] = tmp[1][3];
        faces[f][2][3] = tmp[1][2];
        faces[f][1][3] = tmp[1][1];

        faces[f][1][3] = tmp[1][1];
        faces[f][1][2] = tmp[2][1];
        faces[f][1][1] = tmp[3][1];

        faces[f][1][1] = tmp[3][1];
        faces[f][2][1] = tmp[3][2];
        faces[f][3][1] = tmp[3][3];

        faces[f][3][3] = tmp[3][3];
        faces[f][3][2] = tmp[2][3];
        faces[f][3][1] = tmp[1][3];
    } else{
        faces[f][1][3] = tmp[3][3];
        faces[f][1][2] = tmp[2][3];
        faces[f][1][1] = tmp[1][3];
        faces[f][1][1] = tmp[1][3];
        faces[f][2][1] = tmp[1][2];
        faces[f][3][1] = tmp[1][1];
        faces[f][3][1] = tmp[1][1];
        faces[f][3][2] = tmp[2][1];
        faces[f][3][3] = tmp[3][1];
        faces[f][3][3] = tmp[3][3];
        faces[f][2][3] = tmp[3][2];
        faces[f][1][3] = tmp[3][1];
    }
}

void rotateFront(bool dir){
    rotateFaceOnly(2, dir);
    rotateSidesOnly(dir);
}
void flipFace(int f){

}

void rotateCube(char f){
    if(f==2) return;
    if(f==1){
        rotateFaceOnly(3, false);
        rotateFaceOnly(5, true);
//         copy(&faces[1][0][0], &faces[1][3][3], &tmp);
// ///
//         copy(&faces[4][0][0], &faces[4][3][3], &tmp);

    }
}

void initCube(){
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            faces[1][x][y] = 1;
            faces[2][x][y] = 2;
            faces[3][x][y] = 3;
            faces[4][x][y] = 4;
            faces[5][x][y] = 5;
            faces[6][x][y] = 6;
        }
    }
    
    
    
}

void printUpperSide(){
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            cout << faces[1][y][x] << ' ';
        }
        cout << '\n';
    }
}

void printFrontSide(){
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            cout << faces[2][y][x] << ' ';
        }
        cout << '\n';
    }
}

void solve()
{
    // rotation을 어떻게 나타낼 것인가?
    // 대칭을 이용하여 한 번 구현하여 모든 면에 적용 가능해야 편할 것이다.
    // 문제는 옆면에도 영향이 가기 때문에 각 면을 독립적으로 생각할 수 없다는 것.
    // 데이터 표현을 어떻게 해야 할까.
    // 큐브 전체를 돌리는 연산이 있다면, 즉 보는 각도를 바꾸는 연산이 있다면 
    // 돌리는 면을 무조건 위로 만든 다음 돌리고 나서 원래 각도로 돌아오는 식으로 할 수도 있을듯.
    // 그런데 테스트 케이스 100개 * 1000횟수면 벌써 10만이므로 어느정도 효율적이어야 한다..
    // 일단 어떻게 저장해야할지조차 모르겠다.
    // 만약 면마다 2차원 배열을 만들어 저장한다면, 회전을 구현하는게 고역일 것이다.
    // 하지만 의외로, 큐브 자체 회전 연산을 구현하기 편하므로 생각보다 괜찮을지도.
    cin >> T;
    string st;
    for (int t = 0; t < T; t++)
    {
        cin >> n;
        initCube();
        for (int i = 0; i < n; i++)
        {
            cin >> st;
            rotateFront(true);
            printFrontSide();
            // rotateFront(st[0], st[1] == '+');
        }
        
    }
}

int main(int argc, char **argv)
{
    fastio;
    // Debug = IsDebug(argc, argv);
    it("starting");
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