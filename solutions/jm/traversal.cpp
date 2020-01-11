#include <sstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<ctime>
#include<cmath>
#include<map>
#include<stack>
#include<random>
#include<queue>
#include<list>
#include<math.h>
using namespace std;
const long long int INF = 2000000000000000000;
#define ll long long int
#define ld long double
#define key pair<ld,ld>
#define ii pair<int,int>
#define si set<int>
#define vii vector<pair<int,int> >
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int> >
#define vs vector<string>
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define nu 100001
#define mod 1000000007
#define mul(x,y) ((ll)(x)*(y))%mod
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using ds = int;

//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
//const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
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

struct tree
{
	tree* parent;
	tree* left;
	tree* right;
	int val;
};

vector<int> preordered;
vector<int> inordered;
int prepos = 0;
int inpos = 0;

int C, len, inp;

void testf(vector<int> param) {
	for (int i = 0; i < param.size(); i++)
	{
		cout << param[i];
	}
	param.pop_back();
	cout << endl;
}

tree* ConstructTree(ii rangestart, int rangelen, tree* parent) {
	if (rangelen == 0) return NULL;
	auto it = find(inordered.begin(), inordered.end(), preordered[rangestart.first]);
	int rootindex = distance(inordered.begin(), it);

	// 시작:
	// pre: [rangestart.first, ... , rangestart.first + rangelen - 1]
	// in:  [rangestart.second, ..., rootindex - 1, rootindex, rootindex + 1, ... , rangestart.second + rangelen - 1]

	// 그렇다면 다음 pre range는 다음과 같이 된다.
	// (rootindex - 1) - (rangestart.second)
	// prerange 자체는 start가 rangestart.first + 1이고 위 길이를 이용하면 다음과 같다.
	// [rangestart+1, (rangestart+1)+(len)]
	
	// 다음은 in range
	// (rangestart.second + rangelen) - (rootindex + 1)

	tree* t = new tree();
	t->parent = parent;
	t->val = preordered[rangestart.first];

	int prerangelen = (rootindex - 1) - (rangestart.second) + 1;
	ii prestart = { rangestart.first + 1, rangestart.second };

	int inrangelen = (rangestart.second + rangelen - 1) - (rootindex + 1) + 1;
	ii instart = { rangestart.first + prerangelen + 1 ,rootindex + 1 };

	if (prerangelen <= 0) {
		t->left = NULL;
	}
	else {
		t->left = ConstructTree(prestart, prerangelen, t);
	}
	if (inrangelen <= 0) {
		t->right = NULL;
	}
	else {
		t->right = ConstructTree(instart, inrangelen, t);
	}

	return t;
}

void postorder(tree* tree) {
	if (tree->left != NULL) {
		postorder(tree->left);

	}
	if (tree->right != NULL) {
		postorder(tree->right);

	}
	cout << tree->val << ' ';
}

void solve() {
	cin >> C;
	for (int c = 0; c < C; c++)
	{
		cin >> len;
		preordered.clear();
		inordered.clear();
		for (int i = 0; i < len; i++)
		{
			cin >> inp;
			preordered.push_back(inp);
		}
		for (int i = 0; i < len; i++)
		{
			cin >> inp;
			inordered.push_back(inp);
		}

		tree* tt = ConstructTree({ 0, 0 }, len, NULL);

		postorder(tt);
		cout << endl;
	}

}

int main()
{
	fastio;
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	solve();
	return 0;
}
