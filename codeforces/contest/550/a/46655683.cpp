#include <bits/stdc++.h>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define ll long long

using namespace std;

int main() {
	string str;
	cin >> str;
	int n = str.length()-1;
	int ab = 1e5, ba = 1e6; // bool
	bool oka = false, okb = false;
	for (int i = 0; i < n && (!oka || !okb); ++i) {
		if( !oka && i - ba != 0 && str[i] == 'A' && str[i+1] == 'B' ) {
			ab = i+1;
			oka = true;
		} else if(!okb && i - ab != 0 && str[i] == 'B' && str[i+1] == 'A' ) {
			ba = i+1;
			okb= true;
		}
	}
	if(oka && okb) {
		cout << "YES";
		return 0;
	}
	oka = false, okb = false;
	for (int i = n; i > 0 && (!oka || !okb); --i) {
		if(!okb && i - ab != 0 && str[i] == 'A' && str[i-1] == 'B' ) {
			ba = i-1;
			okb = true;
		} else if(!oka && i - ba != 0 && str[i] == 'B' && str[i-1] == 'A' ) {
			ab = i-1;
			oka = true;
		}
	}
	if(okb && oka)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
