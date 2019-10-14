#include <bits/stdc++.h>

using namespace std;
#define ll long long

map<char, int> mp;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string sr;
    int ans = 0;
    bool foundOdd = false;
    cin >> sr;
    for(char s: sr) {
    	mp[s]++;
    }
    for(auto m: mp) {
    	if(m.second & 1) {
    		if(foundOdd) {
    			ans += m.second;
    		} else
    			foundOdd = true;
    	}
    }
    cout << ((ans & 1) ? "Second" : "First");
}
