
	//const std::unordered_map<std::string, std::function<void()>> m{
	//	{"push",   [&]() { result = commands::push; }},
	//	{"pop",   [&]() { result = commands::pop; }},
	//	{"size", [&]() { result = commands::size; }},
	//	{"empty", [&]() { result = commands::empty; }},
	//	{"top", [&]() { result = commands::top; }},
	//};
	//const auto end = m.end();
	//std::vector<std::string> strings{ "push", "pop", "size", "empty", "top" };

  
void solve() {
	int T;
	cin to T;
	VS arr;
	enum commands {
		push = 1,
		pop = 2,
		size = 3,
		empty = 4,
		top = 5,
	};

	const std::unordered_map<std::string, commands> m{
		{"push", commands::push},
		{"pop", commands::pop},
		{"size", commands::size},
		{"empty", commands::empty},
		{"top", commands::top},
	};

	VS inputs(2);
	FOR(t, 0, T, 1) {
		cin >> inputs[0];
		auto it = m.find(inputs[0]);
		commands cmd = it->second;
		switch (cmd)
		{
		case commands::push:
			cin >> inputs[1];
			arr.push_back(inputs[1]);
			break;
		case pop:
			if (arr.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << arr.back() << endl;
				arr.pop_back();
			}
			break;
		case size:
			cout << arr.size() << endl;
			break;
		case empty:
			cout << ((arr.size() == 0) ? 1 : 0) << endl;
			break;
		case top:
			if (arr.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << arr.back() << endl;
			}
			break;
		default:
			break;
		}
	}
}