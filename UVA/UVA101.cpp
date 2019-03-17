#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((ll) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);
ll dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "rt", stdin);
	freopen("output.in", "wt", stdout);
#endif
}

int const N = 1e6 + 9, M = 100 + 9, OO = 1e9;

int main() {
	cout << fixed << setprecision(6);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n;
	cin >> n;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; ++i) {
		vec.push_back( { i, 0 });
	}
	vector<vector<int>> res(n);
	for (int i = 0; i < n; ++i) {
		res[i].push_back(i);
	}
	string str, type;
	int a, b;
	while (cin >> str, str != "quit") {
		cin >> a >> type >> b;
		if (a == b || vec[a].first == vec[b].first)
			continue;
		if (str == "move") {
			if (type == "onto") {
				// remove all above A
				auto it = vec[a]; // index of vector and its position
				int svv = it.second + 1;
				for (int i = it.second + 1; i < sz(res[it.first]); ++i) {
					int c = res[it.first][i];
					vec[c] = {c, sz(res[c])}; // update
					res[c].push_back(c); // move
//					res[it.first].erase(res[it.first].begin() + i); // delete
				}
				// edit here
				res[it.first].erase(res[it.first].begin() + svv, res[it.first].end()); // delete

				// remove all above B
				auto itt = vec[b]; // index of vector and its position
				int sv = itt.second + 1;
				for (int i = itt.second + 1; i < sz(res[itt.first]); ++i) {
					int c = res[itt.first][i];
					vec[c] = {c, sz(res[c])}; // update
					res[c].push_back(c); // move
//					res[itt.first].erase(res[itt.first].begin() + i); // delete
				}
				// here was error line 60 to 63 (sovled here)
				// TODO Solve it above
				res[itt.first].erase(res[itt.first].begin() + sv, res[itt.first].end()); // delete

				res[it.first].erase(res[it.first].begin() + it.second); // delete

				vec[a] = {itt.first, sz(res[itt.first])}; // update
				res[itt.first].push_back(a); // move

			} else {
				// find a
				auto it = vec[a]; // index of vector and its position
				int svv = it.second + 1;
				for (int i = it.second + 1; i < sz(res[it.first]); ++i) {
					int c = res[it.first][i];
					vec[c] = {c, sz(res[c])}; // update
					res[c].push_back(c); // move
//					res[it.first].erase(res[it.first].begin() + i); // delete
				}
				// edit here
				res[it.first].erase(res[it.first].begin() + svv, res[it.first].end()); // delete

				res[it.first].erase(res[it.first].begin() + it.second); // delete
				auto itt = vec[b];
				vec[a] = {itt.first, sz(res[itt.first])}; // update
				res[itt.first].push_back(a); // move
			}
		} else {
			if (type == "onto") {
				// remove all above B
				auto itt = vec[b]; // index of vector and its position
				int sv = itt.second + 1;
				for (int i = itt.second + 1; i < sz(res[itt.first]); ++i) {
					int c = res[itt.first][i];
					vec[c] = {c, sz(res[c])}; // update
					res[c].push_back(c); // move
//					res[itt.first].erase(res[itt.first].begin() + i); // delete
				}
				// edit
				res[itt.first].erase(res[itt.first].begin() + sv, res[itt.first].end()); // delete

				// find a
				auto it = vec[a]; // index of vector and its position
				int svit = vec[a].first, svt = vec[a].second, endit = sz(res[svit]);
				int svv = it.second;
				for (int i = it.second; i < endit; ++i) {
					int c = res[it.first][i];
					vec[c] = {itt.first, sz(res[itt.first])}; // update
					res[itt.first].push_back(c); // move
				}
				// edit here
				res[it.first].erase(res[it.first].begin() + svv, res[it.first].end()); // delete

//				res[svit].erase(res[svit].begin() + svt, res[svit].begin() + endit); // delete

			} else {
				// find a
				auto it = vec[a], itt = vec[b]; // index of vector and its position
				int svit = vec[a].first, svt = vec[a].second, endit = sz(res[svit]);
				int svv = it.second;
				for (int i = it.second; i < sz(res[it.first]); ++i) {
					int c = res[it.first][i];
					vec[c] = {itt.first, sz(res[itt.first])}; // update
					res[itt.first].push_back(c); // move
				}
				res[it.first].erase(res[it.first].begin() + svv, res[it.first].end()); // delete

//				res[svit].erase(res[svit].begin() + svt, res[svit].begin() + endit); // delete
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << i << ':';
		for (int j = 0; j < sz(res[i]); ++j) {
			cout << " " << res[i][j];
		}
		cout << "\n";
	}
}

