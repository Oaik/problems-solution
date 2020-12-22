#include <bits/stdc++.h>
#define ll long long
#define SZ(vvv) ((int)vvv.size())
#define all(vvv) (vvv.begin(), vvv.end())
#define fastIO cout << fixed << setprecision(6), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
const int N = 1e5 + 9, M 	= 1e2 + 3, MOD = 1e9 + 7, B = 31;
const ll INF = 1e15;

vector<int> sort_cyclic_shifts(string const& s) {
	int n = s.size();
	const int alphabet = 256;
	vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
	for (int i = 0; i < n; i++)
		cnt[s[i]]++;
	for (int i = 1; i < alphabet; i++)
		cnt[i] += cnt[i-1];
	for (int i = 0; i < n; i++)
		p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for (int i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i-1]])
			classes++;
		c[p[i]] = classes - 1;
	}
	vector<int> pn(n), cn(n);
	for(int k = 0; (1 << k) < n; ++k) {
		for(int i = 0; i < n; ++i) {
			pn[i] = p[i] - (1 << k);
			if(pn[i] < 0)
			 pn[i] += n;
		}
		fill(cnt.begin(), cnt.begin() + classes, 0);
		for(int i = 0; i < n; ++i)
			cnt[c[pn[i]]]++;
		for(int i = 1; i < classes; ++i)
			cnt[i] += cnt[i - 1];
		for(int i = n - 1; i >= 0; --i) {
			--cnt[c[pn[i]]];
			p[cnt[c[pn[i]]]] = pn[i];
		}
		cn[p[0]] = 0;
		classes = 1;
		pair<int, int> prv = {c[p[0]], c[(p[0] + (1 << k)) % n]};
		for(int i = 1; i < n; ++i) {
			pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
			classes += (cur != prv);
			cn[p[i]] = classes - 1;
			prv = cur;
		}
		swap(cn, c);
	}
	return p;
}

int sz1;
int ans;

vector<int> lcpBuild(string const& s, vector<int> const &p) {
	int n = SZ(s);
	vector<int> lcp(n - 1, 0), rank(n, 0);
	vector <int> vec;
	for(int i = 0; i < n; ++i)
		rank[p[i]] = i;
	int k = 0;
	for(int i = 0; i < n; ++i) {
		if(rank[i] + 1 == n) {
			k = 0;
			continue;
		}
		int j = p[rank[i] + 1];
		while(s[i + k] == s[j + k])
			++k;
		if(min(i, j) < sz1 && max(i , j) > sz1)
			ans = max(ans, k);
		lcp[rank[i]] = k;
		if(k) --k;
	}
	for(int i = 0; i < n; ++i) {
		if(rank[i] + 1 == n)
			continue;
		int j = p[rank[i] + 1];
		if(min(i, j) < sz1 && max(i , j) > sz1 && lcp[rank[i]] == ans)
			vec.push_back(min(i, j));
	}
	if(!ans) cout << "No common sequence.\n";
	else {
			set<string> st;
			for (int it: vec)
				st.insert(s.substr(it, ans));
			for(auto it: st)
					cout << it << '\n';
	}
	return lcp;
}

vector<int> suffix_array_construction(string s) {
    s += '@';
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    lcpBuild(s, sorted_shifts);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}


void runtestcase() {
	bool awlmra = 1;
	string s, t;
	while(cin >> s >> t) {
		if(!awlmra)
			cout << '\n';
		sz1 = SZ(s);
		s += '$';
		s += t;
		suffix_array_construction(s);
		ans = 0, awlmra = 0;
	}
}

int main() {
#ifdef LOCAL
  freopen("input.in", "rt", stdin);
  freopen("output.in", "wt", stdout);
#endif
  fastIO;
	int t = 1, tt = 1;
	//cin >> t;
	while(t--) {
		runtestcase();
		++tt;
	}
}

