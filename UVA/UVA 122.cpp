#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.in", "w", stdout);
	map<string, bool> visited;
	vector<pair<string, int>> store;
	vector<vector<pair<string, int>>> res(256);
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string str, b;
	int n, a, bsz, root = -1, szvec = 0;
	string idx = "";
	bool can = true;
	while(cin >> str) {
		n = str.length();
		if(n <= 2) {
			if(root == -1 || !can) {
				cout << "not complete" << endl;
			} else {
				sort(store.begin(), store.end());
				for(auto it: store) {
					if(!visited[it.first.substr(0, it.first.length()-1)]) {
						cout << "not complete" << endl;
						can = false;
						break;
					}
				}
				if(can) {
					szvec = store.size();
					for(int i = 0; i < szvec; i++) {
						res[store[i].first.length()].push_back(store[i]);
					}
					cout << root;
					sort(res.begin(), res.end());
					for(auto it: res) {
						for(auto itt: it) {
							cout << " " << itt.second;
						}
					}
					cout << endl;
				}
			}
			visited.clear();
			store.clear();
			res = vector<vector<pair<string, int>>>(256);
			root = -1;
			can = true;
			continue;
		}
		int pos = str.find(",");
		b = str.substr(pos+1, n - (pos + 2));
		if(visited[b] == 1 || !can) {
			can = false;
			continue;
		}
		visited[b] = 1;
		a = stoi(str.substr(1, pos-1));
		if(b.empty()) {
			root = a;
			visited[""] = 1;
			continue;
		}
		store.push_back({b, a});
	}
}

