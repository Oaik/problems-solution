int Manacher(string& s) { // Finding all sub-palindromes in O(N)
	int n = sz(s);
	vector<int> d1(n);
	//d1[i] and d2[i], denoting the number of
	//palindromes accordingly with odd and even lengths with
	//centers in the position  i
	// with d2 the center of aa is pos 1 idx-0
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		d1[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}
	vector<int> d2(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			k++;
		}
		d2[i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k;
		}
	}
	int sum = 0;
	for (auto& it : d1) sum += it;
	for (auto& it : d2) sum += it;
	return sum;
}
