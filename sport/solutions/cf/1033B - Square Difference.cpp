
void solve()
{
	int T;
	cin >> T;
	ll a, b, c;
	for (int t = 0; t < T; t++)
	{
		cin >> a >> b;
		if (a >= b + 2) {
			cout << "NO" << endl;
			continue;
		}
		else 
		if ((a + b) % (a - b) == 0) {
			ll kk = (a + b);
			string ss = "YES";
			for (ll i = 2; i * i <= kk; i++)
			{
				if (kk % i == 0) {
					ss = "NO";
					break;
				}
			}
			cout << ss << endl;
		}
		else cout << "NO" << endl;
	}
}
