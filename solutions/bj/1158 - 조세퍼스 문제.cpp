
void solve() {
	int N, M;
	cin >> N >> M;
	VI arr(N + 10);
	FOR(i, 1, N + 1, 1) {
		arr[i] = i;
		//cout << arr[i] << endl;
	}
	VI ans;
	int j = 0;
	int remain = N;
	while (remain > 0) {
		for (int c = 0; c < M; c++) {
			j++;
			if (j > N) {
				j = j - N;
			}
			while (arr[j] == 0) {
				j++;
				if (j > N) {
					j = j - N;
				}
			}
		}
		if (j > N) {
			j = j - N;
		}
		if (arr[j] > 0) {
			ans.push_back(j);
			arr[j] = 0;
			remain--;
			if (remain == 0) break;
		}
	}
	string s = "<";
	FOR(i, 0, N-1, 1) {
		s += std::to_string(ans[i]) + ", ";
	}
	s += std::to_string(ans[N-1]) + ">";
	cout << s << endl;


}