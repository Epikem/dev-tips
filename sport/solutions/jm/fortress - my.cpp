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


int T, N, x, y, r;

//외벽은 하나 뿐이고, 새로 주어지는 원에 대해 직계 부모를 찾을 수 있나?
// 트리의 부모는 하나 뿐이니. 예를 들어 1번 테케에서 반지름 10과 5가 뒤바뀌어도 같은 결과가 되려면,
// 10이 들어올 때 10이 5의 새로운 부모가 되고, 10의 부모는 15가 되어야 한다. 
// 원은 겨우 100개 이므로, 새로운 입력에 대해 모든 원에 대해 비교해도 된다.
// 원간의 관계는 겹치지 않으므로 여기서는 세 가지. 부모, 자식, 무관계
// 반대로 말하면 무관계가 아니면 반드시 부모거나 자식인 것.
// 자식의 반지름이 부모보다 클 수 없으므로,
// 무관계 = 반지름 합 < 거리
// 부모자식 = !무관계
// 부모 = (!무관계) && (자식보다 반지름 큼)
// 이렇게 된다.
// 이제 문제는 새 원 입력에 대한처리를 완성하는 것
// 왜 한꺼번에 안 하느냐면, 하나를 읽을 때에 대한 처리조차 지금 생각이 안 나기 때문에.
// 자 새 원이 들어왔고, 이전 원까지의 모든 부모자식관계 정리는 되어있다고 할 때,
// 음 그럼 그 부모자식 관계의 정리는 어떻게 되어야 하지? 당연 트리지.
// 그러면 이미 있던 트리가 필요하네.
// 그리고 자식 수는 2개보다 많을 수 있으니 sibling형식으로 구조체를 만들어야 겠다.
// 그래도 이번 성벽에 대한 판단이 필요하므로 또 x,y,r정보도 필요할 듯.
// 자 그러면 실제 케이스에서 생각해보자
//
//  a
// b c
//de f
// 이때 b보다 작고 e보다 큰 b의 자식인 원이 입력되면?
// c,f는 무관계, a,b는 부모, d 또는 e는 자식 또는 무관계로 나올 것이다.
// 모든 원에 대해 매번 할 것이므로 전부 할당해 놓자. 아니 그냥 push back하면 될 듯.
// vector<tree>와 vector<tree*>는 어떻게 달라지는걸까.

// 근데 이거 이렇게 해서 찾으면 상당히 여러 가지 변형이 일어나는데 결국 그것도 써 주려면 상당히 복잡할 듯./
// 일반화하자면 새 노드가 b,c,d,...을 자식으로 하는 부모 a 사이로 들어갈 경우일 듯.
// 그러면 a는 이 노드의 부모가 되지만 b,c,d...의 부모가 이 노드가 될 수도 있고 아니라면 a가 부모가 될 수도 있다.

// 그림으로 그려보니 확실히 알겠다. 가장 깊은 부모 대상을 찾았으면 이제 구해야 할 것은/
// 그 부모의 바로 아래 모든 자식들에 대해 이 새 노드의 자식이 된다면 이 새 노드의 자식으로,
// 아니면 전부 그 부모 바로 아래 자식으로 하면 된다.

struct tree
{
	int parent;
	vector<int> childs;
	int x;
	int y;
	int r;
	int depth;
};

std::vector<tree*> tt;

float dist(int a, int b) {
	return sqrt((tt[a]->x - tt[b]->x) * (tt[a]->x - tt[b]->x) + (tt[a]->y - tt[b]->y) * (tt[a]->y - tt[b]->y));
}

int checkRelation(int curf, int tarf) {
	// 0: 무관계
	// 1: 부모
	// -1: 자식
	if (curf >= tt.size() || tarf >= tt.size()) {
		return 924902029;
	}
	if (((float)(tt[curf]->r + tt[tarf]->r)) < dist(curf, tarf)) {
		return 0;
	}

	if (tt[curf]->r > tt[tarf]->r) {
		return 1;
	}
	else {
		return -1;
	}
}

void increaseChildDepth(int c) {
	vector<int>& childs = tt[c]->childs;
	tt[c]->depth++;
	for (auto cc : childs) {
		increaseChildDepth(cc);
	}
}

vector<bool> visited(120, false);
int getDist(int start, int end) {
	if (start < 0 || start >= N) return 99999999;
	if (start == end) return 0;

	int dist = 999799;
	int tmp;
	for (auto child : tt[start]->childs) {
		if (!visited[child]) {
			visited[child] = true;
			tmp = getDist(child, end) + 1;
			if (tmp < dist) {
				dist = tmp;
			}
		}
	}

	if(tt[start]->parent != -1)
		if (!visited[tt[start]->parent]) {
			visited[tt[start]->parent] = true;
			tmp = getDist(tt[start]->parent, end) + 1;
			if (tmp < dist) {
				dist = tmp;
			}
		}

	return dist;
}

void solve() {
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		tt.clear();

		cin >> N;
		cin >> x >> y >> r;
		tree* root = new tree();
		root->depth = 0;
		root->parent = -1;
		root->x = x;
		root->y = y;
		root->r = r;
		tt.push_back(root);

		//troot->childs
		for (int n = 1; n < N; n++)
		{

			cin >> x >> y >> r;

			tree* node = new tree();
			//node->depth = 1;
			//node->parent = NULL;
			node->x = x;
			node->y = y;
			node->r = r;
			tt.push_back(node);

			const int sky = -1234;

			int deepestParent = sky;	// 깊이
			int deepdepth = sky;
			for (int targetCircle = 0; targetCircle < tt.size(); targetCircle++)
			{
				if (n == targetCircle) continue;

				int relation = checkRelation(targetCircle, n);
				if (relation == 1) {
					if (deepestParent != sky) {
						deepdepth = tt[deepestParent]->depth;
					}
					if (tt[targetCircle]->depth > deepdepth) {
						deepestParent = targetCircle;
					}
				}
			}

			//if (deepestParent != 0) {	// 이것이 이 노드의 새 부모.
				// 먼저 그 부모의 자식들부터 처리해야 한다.

			vector<int> dpschilds = tt[deepestParent]->childs;
			vector<int> stillchilds;

			for (auto child : dpschilds)
			{
				int relation = checkRelation(n, child);
				if (relation == 1) {
					tt[child]->parent = n;
					tt[n]->childs.push_back(child);
					increaseChildDepth(child);
					//tt[child]->depth++;////////////////////
				}
				else if (relation == 0) {
					tt[child]->parent = deepestParent;
					stillchilds.push_back(child);
				}
				else if (relation == -1) {
					cout << "Error";
				}

			}

			// 이제 그 부모를 새노드의 부모로 설정.
			tt[n]->parent = deepestParent;
			tt[n]->depth = tt[deepestParent]->depth + 1;
			stillchilds.push_back(n);
			tt[deepestParent]->childs = stillchilds;
			//}

		}

		int maxdepth = -223;
		int start = -23;
		int ans = -323;

		for (int i = 0; i < N; i++)
		{
			if (tt[i]->depth > maxdepth) {
				maxdepth = tt[i]->depth;
				start = i;
			}
		}

		for (int j = 0; j < N; j++)
		{
			visited = vector<bool>(120, false);
			int tmp = getDist(start, j);
			if (tmp > ans) {
				ans = tmp;
			}
		}
		

		cout << ans << endl;

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
