#include <bits/stdc++.h>

using namespace std;
#define ll long long

int arr1[60] = {};
int arr2[60] = {};
int arr3[60] = {};

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string st1, st2, st3;
	int n;
	cin >> n;
	cin >> st1 >> st2 >> st3;
	int m = st1.length();
	for (int i = 0; i < m; ++i) {
		arr1[st1[i] - 'A']++;
		arr2[st2[i] - 'A']++;
		arr3[st3[i] - 'A']++;
	}
	int mx1 = 0, mx2 = 0, mx3 = 0;
	for (int i = 0; i < 60; ++i) {
		mx1 = max(mx1, arr1[i]);
		mx2 = max(mx2, arr2[i]);
		mx3 = max(mx3, arr3[i]);
	}
	if(n == 1) {
		if(mx1 == m)
			--mx1;
		else
			++mx1;
		if(mx2 == m)
			--mx2;
		else
			++mx2;
		if(mx3 == m)
			--mx3;
		else
			++mx3;
		if(mx1 > mx2 && mx1 > mx3) {
			cout << "Kuro";
		} else if(mx2 > mx1 && mx2 > mx3) {
			cout << "Shiro";
		} else if(mx3 > mx1 && mx3 > mx2) {
			cout << "Katie";
		} else {
			cout << "Draw";
		}
		return 0;
	}
	int dif1 = m - mx1, dif2 = m - mx2, dif3 = m - mx3;
	if(dif1 >= n) // n < dif1
		mx1 += n;
	else {
		mx1 += dif1;
	}
	if(dif2 >= n)
		mx2 += n;
	else {
		mx2 += dif2;
	}
	if(dif3 >= n)
		mx3 += n;
	else {
		mx3 += dif3;
	}

	if(mx1 > mx2 && mx1 > mx3) {
		cout << "Kuro";
	} else if(mx2 > mx1 && mx2 > mx3) {
		cout << "Shiro";
	} else if(mx3 > mx1 && mx3 > mx2) {
		cout << "Katie";
	} else {
		cout << "Draw";
	}
}
