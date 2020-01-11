int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	int T;
	cin >> T;
	FOR(t, 0, T, 1) {
		int r;
		char* str = new char[230];
		cin >> r >> str;
		FOR(ii, 0, strlen(str), 1) {
			FOR(rr, 0, r, 1) {
				cout << str[ii];
			}
		}
		cout << endl;
	}
}