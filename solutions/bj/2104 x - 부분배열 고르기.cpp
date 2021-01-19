#include <sstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<ctime>
#include<cmath>
#include<map>
#include<unordered_map>
#include<stack>
#include<random>
#include<queue>
#include<list>
#include<math.h>
#include<cstring>
#include <cstdio>
#include <iomanip>      // std::setprecision
using namespace std;
const long long int INF = 2000000000000000000;
#define ll long long int
#define ld long double
//#define key pair<ld,ld>
#define ii pair<int,int>
#define iii pair<pair<int, int>, int>
//#define si set<int>
#define vii vector<pair<int,int> >
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int> >
#define vvii(h,w,v) vvi(h, vi(w, v));	// initialize vvi
#define vs vector<string>
#define all(v) v.begin(),v.end()
#define pb emplace_back
//#define mp make_pair
#define f first
#define s second
#define nu 100001
#define mod 1000000007
#define mul(x,y) ((ll)(x)*(y))%mod
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(t) cin>>t; for(int tmpv = 0; tmpv < t; tmpv++)
#define writeLine(arg) cout << arg << '\n'
#define pairof(type) pair<type, type>
#define vit std::vector<int>::iterator
#define divby2 >> 1
#define mulby2 << 1
#define swap(a, b) a^=b; b^=a; a^=b;
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
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int dxo[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int dyo[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dig = 10;
const int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int digarr[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
const int bt = 31;

//ds MOD(ds a, ds b)
//{
//	if (a > b)
//		return a - b;
//	else
//		return b - a;
//}

inline ds MSD(ds n) {
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
	return x && (!(x&(x - 1)));
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
			res = (res*x) % mod;
		y = y >> 1;
		x = (x*x) % mod;
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

inline ds Readin() {
	int K = 0; char C = ' ';
	while (C < '0' or C > '9') C = getchar();
	while (C <= '9' and C >= '0') K = (K << 1) + (K << 3) + C - '0', C = getchar();
	return K;
}

inline ds mult(ds a, ds b, ds c) {
	if (b == 1) return a % c;
	if (b % 2 == 0) {
		ds tt = mult(a, b / 2, c);
		return (tt * tt) % c;
	}
	else return mult(a, b - 1, c) * a % c;
}

int N;
int Arr[100007];
vii Mins;
vii RevMins;
vii Sections;

// 3 1 6 4 5 2
// 어떤 기준으로 풀어야 하지?
// i부터 j까지 최소, 길이 최대 10만이므로 2차원 저장 불가..
// 최적 부분 구조가 어떻게 될까?
// 모든 시작점부터 좌우로 퍼지는 식으로 해도 또한 시간초과. 10만*10만이므로.
// 자료구조 필요한거 아닌가..?
// 아니면, 슬라이딩 윈도우?
// 슬라이딩 윈도우도 길이 1부터 10만까지, 0부터 끝까지 하면 대략 10만^2/2니까 무리로 보이는데.
// 길이 1: 3  1  6  4  5  2
// 길이 2: 4  7  10 9  7  2
// 길이 3: 10 11 ..
// 10만^2은 무려 100억이므로 애초에 nlogn 또는 nlgn을 찾아야한다.
// 최장 증가수열 찾듯이 해야할거 같은데.
// 지금까지 최적을 알고 있다면, 새 수가 들어왔을 때 ....
// 전체에서 시작한다면?
// 전체에서 시작해서, 각 최소값 인덱스부분을 기준으로 나눈다면 반드시 최솟값이 증가하므로 찾을 수 있지 않나.
// 3 1 6 4 5 2, 0, 5에서
// 3   6 4 5 2, 0,0  2,5
// ...
// 될 듯.
// 문제는, 여기서 알아야 하는게
// 현재 구간의 다음 제거할 최솟값을 알아야 함. 아 이게 어렵네.
// 그냥 다음 제거할 최솟값은 전역에서 하나씩 지워도 되니까, 그 최솟값의 인덱스는 아니까 그게 이 라운드의 이 구간에 해당 안되면 무시하면
// 되지 않을까. 근데 분할된 상태랑 전역이랑 뒤섞이는거 같은데. 재귀함수에서 curMin을 꺼내버리면 다른 재귀트리는 못쓰게 된다.
// 그러면 현재 curMin 레벨을 매개변수로 만들자. 각 단계에서 한 단계씩 하니까. 근데 문제 설명에 같은 숫자가 없다는 말이 없다. 흠..
// 5 4 1 3 7 6 8 4 6 2  
// 1로 분리한 뒤, 2, 3 지우고, 4를 지워야 할 때,

// 그냥 모든 레벨 시도하게 했더니 결국 시간초과다.
// 아예 재귀적이 아니라 반복적으로 하고, 각 구간을 관리하면?
// 이렇게 해도 1 2 3 4 5 6 ... 100000면 n^2이 되겠구나..
// 구간에서 변화만 계산하려 해도 이번 최솟값이 얼마인지 모른다
// 어 그럼 어차피 다음에 계산하게 된다면 이번 최솟값을 최솟값으로 하는 구간만 계산한다면 최솟값을 아니까
// 제외된 부분만 빼고 이번 최솟값을 곱하면 답이 된다.
// (3+1+6+4+5+2)*1 -> (6+4+5+2)*2, (3)*3 -> ...
// 그럼 문제는 이 최솟값을 최소로 하는 구간을 알아야 한다. -> 어떻게?
// 절차를 명확히 해 보자
// 1단계: 전체 구간 계산
// 2단계: 최초 최솟값인 1의 인덱스인 2를 기준으로 분리. -> 3, 6 4 5 2가 되는데, 다음 최솟값 2를 꺼내서,
// 계산은 두 구간 중 다음 최솟값인 2를 마지막으로 하는 구간 6 4 5 2의 합 * 2를 계산한다.
// 3단계: 이번 최솟값인 2의 인덱스인 6을 기준으로 '분리' -> 6 4 5가 되는데, 다음 최솟값 3을 꺼내서, 
// 계산은 3을 최소로 하는 구간인 [3]의 점수를 계산.
// 그렇다면, 각 구간을 저장하되, 최솟값을 인덱스로 해서 꺼낼 수 있어야 한다. 문제는 같은 최솟값이 여러 개 있는 경우.
// 또, '분리'를 정확히 어떻게 하나.
// l > r이 아닌 구간 두개를 최솟값 기준으로 구간리스트에 넣되, 

ii curMin = { 1000001,-1 };

ll getAns(int l, int r, int lvl) {
	if (l > r) return -1;
	if (l == r) return Arr[l];

	ll sums = 0;
	int minv = 9999999;
	for (int i = l; i < r; i++)
	{
		sums += Arr[i];
		if (minv > Arr[i]) {
			minv = Arr[i];
		}
	}
	sums *= minv;

	ii thismin = Mins[lvl];
	int minidx = thismin.second;
	int minval = thismin.first;

	if (l <= minidx && minidx < r) {
		ll cand = max(getAns(l, minidx, lvl + 1), getAns(minidx + 1, r, lvl + 1));
		return max(sums, cand);
	}
	else {
		return max(sums, getAns(l, r, lvl + 1));
	}
}
//
//ll getAns(int l, int r){
//	if (l > r) return -1;
//
//	ll sums = 0;
//	for (int i = l; i < r; i++)
//	{
//		sums += Arr[i];
//	}
//
//	if (l <= curMin.second && curMin.second < r) {
//		ll la = getAns(l, curMin.second - 1);
//		ll ra = getAns(curMin.second + 1, r);
//	}
//
//
//}

void solve() {
	N = Readin();
	for (int i = 0; i < N; i++) {
		Arr[i] = Readin();
		if (Arr[i] < curMin.first) {
			curMin = { Arr[i], i };
		}
		Mins.push_back({ Arr[i], i });
		RevMins.push_back({ i, Arr[i] });
	}

	sort(all(Mins));
	Sections.push_back({ 0, N });
	ll ans = -1;
	int lvl = 0;
	while (lvl < Mins.size()) {
		// 각 구간 해당시 분리.
		auto nextMins = Mins[lvl];
		lvl++;
		// 현재 상태 각 구간 값 탐색
		for (auto section : Sections) {
			int l = section.first, r = section.second;
			ll sums = 0;
			int minv = 9999999;
			for (int i = l; i < r; i++)	///////.....
			{
				sums += Arr[i];
				if (minv > Arr[i]) {
					minv = Arr[i];
				}
			}
			sums *= minv;
			if (sums > ans) ans = sums;
			// 각 구간 해당시 분리.
			if (l <= nextMins.second && nextMins.second < r) {
				Sections.erase(find(all(Sections), section));//////.....
				Sections.push_back({ l, nextMins.second });
				Sections.push_back({ nextMins.second+1, r });
			}
		}
	}

	for (auto section : Sections) {
		int l = section.first, r = section.second;
		ll sums = 0;
		int minv = 9999999;
		for (int i = l; i < r; i++)
		{
			sums += Arr[i];
			if (minv > Arr[i]) {
				minv = Arr[i];
			}
		}
		sums *= minv;
		if (sums > ans) ans = sums;
	}

	//ll ans = getAns(0, N, 0);

	printf("%lld", ans);
}

int main()
{
	//fastio;
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	solve();
	return 0;
}
