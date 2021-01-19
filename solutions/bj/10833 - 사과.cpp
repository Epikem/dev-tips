 
void solve() {
	int T;
	cin >> T;
	int ans = 0;

	FOR(t, 0, T, 1) {
		int a, b;
		cin >> a >> b;

		ans += b - (a * (b / a));
	}

	cout << ans << endl;
}
