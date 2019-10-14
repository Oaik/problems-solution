#include <bits/stdc++.h>

using namespace std;
#define ll long long

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int f=a*d,s=b*c;
	if(f>s)
		swap(f,s);
	f=s-f;
	int g=gcd(f,s);
	cout << f/g << "/" << s/g<< endl;
}
