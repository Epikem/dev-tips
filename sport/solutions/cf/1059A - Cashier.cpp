#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

#define M_PI 3.14159265358979323846
#define ll long long

void solve()
{
	int n, l, a;
	cin >> n >> l >> a;
	int ti, li;
	int cur = 0;
	int ans = 0;
	int curbreak = 0;
	for (int i = 0; i < n; i++)
	{
		// 다음 손님 읽기
		cin >> ti >> li;
		// 손님 사이에 휴식 누적 안됨.
		curbreak = 0;
		// cur부터 ti+li즉 이번 손님 끝까지.
		while(cur < ti + li)
		{
			//일 시작 전.
			if (cur < ti) {
				curbreak++;
			}
			// break 단위인 a보다 크다면
			if (curbreak >= a) {
				ans++;
				curbreak -= a;
			}
			cur++;
		}
		curbreak = 0;

	}

	// 남은 시간 처리
	while (cur < l)
	{
		curbreak++;
		if (curbreak >= a) {
			ans++;
			curbreak -= a;
		}
		cur++;
	}

	// i번째 오는 손님이 ti시간에 와서 li시간 만큼 해야 하고ㅡ,
	// 시간이 겹치지는 않고
	// 그때 최대 쉬는 횟수 구하기.

	cout << ans << endl;
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	solve();
	return 0;
}
