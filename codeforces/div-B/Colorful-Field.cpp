#include<iostream>
#include <vector>
#include <algorithm>
#include<memory.h>

#define all(v) ((v).begin()), ((v).end())

using namespace std;
int main() {
	vector<pair<int, int>> wasted;
	string friutsNames[3] = { "Grapes", "Carrots", "Kiwis" };
	int n, m, k, t, a, b, cnt = 0;
	scanf("%i%i%i%i", &n, &m, &k, &t);
	for (int i = 0; i < k; ++i) {
		scanf("%i%i",&a, &b);
		wasted.push_back(make_pair(a,b));
	}
	sort(all(wasted));
	for (int i = 0; i < t; ++i) {
		cnt = 0;
		scanf("%i%i",&a, &b);
		auto p = std::make_pair(a, b);
		if(binary_search(wasted.begin(), wasted.end(), p))
			cout << "Waste\n";
		else {
			for (int j = 0; j < k; ++j) {
				if ( (a > wasted[j].first) || ( (a == wasted[j].first) && (b > wasted[j].second) ) ) {
					++cnt;
				} else
					break;
			}
			cout << friutsNames[(((a-1)*m + b - cnt) % 3)] << "\n";
		}
	}
}

