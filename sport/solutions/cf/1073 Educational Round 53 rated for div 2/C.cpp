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
ds MOD(ds a, ds b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}
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


void solve() {
	int N;
	cin >> N;

	string ss;
	cin >> ss;

	int x, y;
	cin >> x >> y;

	if (abs(x) + abs(y) > N || (N % 2) != ((abs(x) + abs(y)) % 2)) {
		cout << "-1" << endl;
		//주의해야할게 짝수 문제도 생길거 같은데?

		// RR 인데 1, 0이면? 어떻게 바꿔도 짝수들만 방문하므로 1,0을 갈 수 없다. 홀수도 마찬가지인가?
		// RRR인데 2,0이면? 마찬가지다.갈 수 없다.
		return;
	}

	// 어차피 바꿔야 하는 명령은 특정 명령일 테고,  
	// 바꿀 명령을 먼저 찾은 다음, 아니 애초에 결정적이므로,
	// 명령은 그냥 x,y로부터 찾아진다. 근데 그러면 바꿀 명령이랑 길이 차이가 다르고 아예 다른 배열인데,
	// 아 여기서 또 중요한게, L과 R은 반대, D와 U가 반대다. 
	// 근데 또 헷갈리게 하는 점은 바꾸는 명령 갯수가 아닌 길이를 줄이라고 하다보니 반대를 쓰면 더 손해인 경우도 분명히 있을 거란 점이다..
	// 만약 그런 경우가 존재하지 않는 다면 쉽게 풀 수도 있다.
	// DRRRD
	// 2 -1
	// 이런 경우 
	// DRRUD 
	// 이렇게 바꾸면 된다. 

	// 예를 들어 세 개의 명령 RDD를 ULL로 바꿔야 한다면?
	// (-2, 1) - (1, -2) = (-3, 3)

	// RDD가 아닌 다른 명령들을 바꿔서 ULL로 할 수도 있나? 
	// DDDDD 라던가. (-3, 3) - (0, -5) = (-3, 8) x
	// LLUUU

	// 더 작은 경우를 생각해보자, R을 U로 바꾸면 (1,0)을 (0,1)로 바꿨으니, 도착지는 (-1, 1)만큼 바뀐다.
	// UD를 UL로 바꾸면? (0,0)을 (-1,1)로 바꿨으니, 똑같다.
	// ㅁㅊ... 어켐품.

	// 일단 바꿔야 할 변화량은 쉽게 구할 수 있다.

	int ops = ss.length();
	int curx = 0, cury = 0;
	for (int sss = 0; sss < ops; sss++)
	{
		if (ss[sss] == 'L') {
			curx -= 1;
		} else if (ss[sss] == 'R') {
			curx += 1;
		}
		else if (ss[sss] == 'U') {
			cury += 1;
		}
		else if (ss[sss] == 'D') {
			cury -= 1;
		}
	}

	int diffx = x - curx, diffy = y - cury;

	// 문제는 이 변화량으로 명령 개수의 최소가 아닌 변화 명령의 길이를 최소로 변화시키게 하는걸 어떻게 찾지?
	// 주어진 길이에 대해, 이 위치에서 이 길이만큼 변화시켜서 도착할 수 있음을 확인할 수 있다면?
	// 그게 가능한 길이 중 최소를 찾으면 되는데, 이 작업은 너무 오래걸릴 거 같다.
	// 길이 1에 대해 순회하면서, 이 명령을 바꿔서 diffx, diffy 만족시킬 수 있는가? 확인하면서, 길이 증가시켜 나가면 풀 수는 있다.
	// 여기서 어떻게 최적화하지? 길이가 diffx diffy차이에 따라 범위가 크기 때문에,,
	// 그렇다고 한 가지 길이만 순회해 풀 수도 없는게 길이에 손해를 봐도 건너뛰면서 차이나는 경우가 분명 존재한다.
	// 
	// 일단 지금 문제는, 어떤 명령을 바꿔야 하는지도 모르고 있다.
	// R을 U로 바꾸는 것과, D를 L로 바꾸는 것이 서로 호환된다.
	// R-D, U-L, 등등 여러 가지도 마찬가지일 것이다.
	// 아 역으로 생각해보자!명령 하나로부터!
	// L을 바꿔서 얻을 수 있는 변화들은? L-U (0,1)-(-1,0)=(1,1), L-R (2,0), L-D (1,-1)

	// 특정위치 X의 명령들을 Y로 바꾸면, X는 뺄셈이 되므로 반대 명령이 적용되는것과 같다. 그러면 각 위치들에 대해, ...
	// 아니 안 바꿔는 경우도 있다..
	// 일정 구간 X를 Y로 바꾼다는건, X를 무효화하는 -X를 뒤에 추가하고, 다시 X와 길이가 같은 새 명령 Y를 추가하는 것과 같다.
	// X(-X)Y .. 그래서 뭐
	
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

