#include <iostream>
#include <cmath>

#define M_PI           3.14159265358979323846

using namespace std;

int main() {
	double d, sec, vol, h, v, e, newH, diffH;
	cin >> d >> h >> v >> e;
	vol = M_PI * pow(d/2, 2) * h;
	newH = ( (vol - v)/ (M_PI * pow(d/2, 2)) ) + e;
	diffH = h - newH;
	if (newH >= h) {
		cout << "NO";
		return 0;
	}
	sec = h/diffH;
	cout << "YES\n";
	cout << sec;
}
