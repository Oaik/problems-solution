#include <bits/stdc++.h>
using namespace std;
#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
typedef long long ll;
#define PI		acos(-1)
void Yahia74() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin); //freopen("output.in", "w", stdout);
#endif
	cout << fixed << setprecision(9);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e7 + 5, M = 5e5 + 74, OO = 0x3f3f3f3f;

int main() {
	Yahia74();
	double v, s;
	cin >> v >> s;
	double A1 = 360.0 / v;
	double A2 = (180 - (A1 ))/2.0;
	double s1 = sin(A1* (PI/180.0));
	double s2 = sin(A2* (PI/180.0));
	double r = (s2 * s)/s1;
	double Area = r*r*PI;
	cout<<Area;


	return 0;
}
