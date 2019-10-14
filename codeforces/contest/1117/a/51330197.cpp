

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+9;

int arr[N];

class ABestSubsegment {
public:
	void solve(std::istream& cin, std::ostream& cout) {
		cout << fixed << setprecision(2);
		ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		int n;
		cin >> n;

		int mxNum = 0, cnt = 0, mx = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			mxNum = max(mxNum, arr[i]);
		}

		for (int j = 0; j < n; ++j) {
			if(arr[j] == mxNum) {
				++cnt;
				mx = max(mx, cnt);
			} else
				cnt = 0;
		}
		cout << mx;
	}
};


int main() {
	ABestSubsegment solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
