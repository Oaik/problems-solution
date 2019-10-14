#include <bits/stdc++.h>

using namespace std;
#define ll long long

int sum[200010][2];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string a,b;
	cin>>a>>b;
	sum[0][0] = b[0] == '0';
	sum[0][1] = b[0] == '1';
	for(int i = 1;i < b.size();i++)sum[i][0] = sum[i-1][0] + (b[i] == '0'),sum[i][1] = sum[i-1][1] + (b[i] == '1');
	long long res = 0;
	for(int i = 0;i < a.size();i++){
		if(a[i] == '0')res += sum[b.size()+i-a.size()][1] - (i?sum[i-1][1]:0);
		else res += sum[b.size()+i-a.size()][0] - (i?sum[i-1][0]:0);
	}
	cout<<res<<'\n';
	return 0;
	return 0;
}
