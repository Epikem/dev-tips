void solve() {
	int T;
	cin to T;
	VI arr;

	VS inputs(2);
	int curtarget = 0;
	int cur = 0;
	int next = 1;

	VS ans;
	string ansstr = "";

	FOR(t, 0, T, 1) {
		cin >> curtarget;
		
		bool exit = false;
		while (!exit) {
			if (curtarget > cur) {
				arr.push_back(next);
				cur = next;
				next++;
				ansstr += "+\n";
			}
			if (cur >= curtarget) {
				if (arr.size() == 0) {
					cout << "NO" << endl;
					return;
				}
				ansstr += "-\n";
				cur = arr.back();
				arr.pop_back();
				if (cur == curtarget) {
					exit = true;
				}
			}

		}

	}

	cout << ansstr << endl;
}