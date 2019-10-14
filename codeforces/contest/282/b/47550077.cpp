#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<char> answer;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	ll a = 0, b = 0;
	int n, x, y;
	bool ok = false;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		if (abs(a + x - b) <= 500) {
			a += x;
			answer.push_back('A');
		} else if (abs(b + y - a) <= 500) {
			b += y;
			answer.push_back('G');
		} else {
			ok = true;
			break;
		}
	}
	if(ok) {
		cout << -1;
		return 0;
	} else {
		for(char lt: answer) {
			cout << lt;
		}
	}
}
