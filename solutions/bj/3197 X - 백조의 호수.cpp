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
#include<string.h>
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

// 1 : 물
// 0 : 빙하
// 2 : 백조 1
// 3 : 백조 2
// 4 : 바다
int arr[1505][1505];

// 스킵된 물 영역
int ee[1505];

// 스킵된 백조 영역
int dd[1505];

void solve()
{
	int n, m;

	cin >> n >> m;
	
	// 물 영역
	vector<int> qq, ww;
	// 백조 영역
	vector<int> aa, ss;

	// 백조 영역 2
	vector<int> zz, xx;

	int leftIce = 0;

	//백조 번호
	int bekjo = 0;

	for (int i = 0; i < n + 2; i++)	// 범위 초과 방지 위해 1~ 인덱스 사용
	{
		memset(arr[i], -1, sizeof(int)*(m + 2));	// -1로 초기화
	}

	string sss; // 맵 읽을 문자열
	for (int i = 1; i <= n; i++)
	{
		cin >> sss;
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = sss[j - 1];	//!! 1인덱스 사용중이므로 ss 접근은 -1 해줘야 함.
			char k = arr[i][j];
			if (k == '.') {
				arr[i][j] = 1;
				qq.push_back(i);
				ww.push_back(j);
			}
			else if (k == 'X') {
				arr[i][j] = 0;
			}
			else {
				// 두 백조 영역 구별.
				if (bekjo) arr[i][j] = 3;
				else arr[i][j] = 2;
				//백조 영역은 물 공간이기도 하다.
				qq.push_back(i);
				ww.push_back(j);

				aa.push_back(i);
				ss.push_back(j);
				bekjo++;
			}
		}
	}

	// 계속 진행
	int ans = 0;
	while (true)
	{
		int added = 0;
		// 일단 백조 영역을 최대한 늘려보고, 더 안늘어나면 다음날로 넘기면서 빙하를 녹인다.

		// 여전히 시간초과 발생.
		// 아무래도 백조 영역을 늘릴 때 새로 늘어난 부분과 못늘어난 부분 구별해서 백조 영역만 늘릴 때는 새로 늘어난 부분만 체크하고 
		// 날이 바뀔 때만 못늘어난 부분들 전체를 재검사 해야할듯.
		int bekjopoints = aa.size();
		for (int i = 0; i < bekjopoints; i++)
		{
			if (dd[i] > 0) continue;
			int z = aa[i], x = ss[i];
			int v = arr[z][x];
			if (v == 1) continue;
			//cout << "broadening bekjo region at " << z << ' ' << x << endl;


			if (arr[z - 1][x] == v && arr[z + 1][x] == v && arr[z][x - 1] == v && arr[z][x + 1] == v) {
				dd[i] = 1;	// 백조 영역으로 둘러싸인 영역.
				continue;
			}
			
			int* reff = &arr[z - 1][x];
			if (*reff == 1) {
				added++;
				*reff = v;
				aa.push_back(z - 1);
				ss.push_back(x);
			}
			reff = &arr[z + 1][x];
			if (*reff == 1) {
				added++;
				*reff = v;
				aa.push_back(z + 1);
				ss.push_back(x);
			}
			reff = &arr[z][x - 1];
			if (*reff == 1) {
				added++;
				*reff = v;
				aa.push_back(z);
				ss.push_back(x - 1);
			}
			reff = &arr[z][x + 1];
			if (*reff == 1) {
				added++;
				*reff = v;
				aa.push_back(z);
				ss.push_back(x + 1);
			}

			if (v == 3) {
				if (arr[z - 1][x] == 2 || arr[z + 1][x] == 2 || arr[z][x - 1] == 2 || arr[z][x + 1] == 2) {
					// 3 백조 영역이 2 백조 영역 발견.
					cout << ans << endl;
					return;
				}
			}
			else {
				if (arr[z - 1][x] == 3 || arr[z + 1][x] == 3 || arr[z][x - 1] == 3 || arr[z][x + 1] == 3) {
					// 2 백조 영역이 3 백조 영역 발견.
					cout << ans << endl;
					return;
				}
			}

		}

		// 백조 영역 안늘어남. 다음날로.
		if (added == 0) {
			ans++;

			int waterpoints = qq.size();
			for (int i = 0; i < waterpoints; i++)
			{
				if (ee[i] > 0) continue;

				int z = qq[i], x = ww[i];
				int v = arr[z][x];
				//cout << "broadening water region at " << z << ' ' << x << endl;

				int* reff = &arr[z - 1][x];
				if (*reff == 0) {
					added++;
					*reff = v;
					qq.push_back(z - 1);
					ww.push_back(x);

					if (v > 1) {
						aa.pb(z - 1);
						ss.pb(x);
					}
				}
				reff = &arr[z + 1][x];
				if (*reff == 0) {
					added++;
					*reff = v;
					qq.push_back(z + 1);
					ww.push_back(x);

					if (v > 1) {
						aa.pb(z + 1);
						ss.pb(x);
					}
				}
				reff = &arr[z][x - 1];
				if (*reff == 0) {
					added++;
					*reff = v;
					qq.push_back(z);
					ww.push_back(x - 1);

					if (v > 1) {
						aa.pb(z);
						ss.pb(z - 1);
					}
				}
				reff = &arr[z][x + 1];
				if (*reff == 0) {
					added++;
					*reff = v;
					qq.push_back(z);
					ww.push_back(x + 1);

					if (v > 1) {
						aa.pb(z);
						ss.pb(x + 1);
					}
				}

				if (arr[z - 1][x] == 1 && arr[z + 1][x] == 1 && arr[z][x - 1] == 1 && arr[z][x + 1] == 1) {
					ee[i] = 1;	// 물 영역으로 둘러싸인 영역.
					continue;
				}

			}
		}
		added = 0;
		//cout << "next round " << endl;
		//for (int i = 1; i <= n; i++)
		//{
		//	for (int j = 1; j <= m; j++)
		//	{
		//		cout << arr[i][j];
		//	}
		//	cout << endl;
		//}

	}


	return;
}


int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#else
	fastio;
#endif

	solve();
	return 0;
}
