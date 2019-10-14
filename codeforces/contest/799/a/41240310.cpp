#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, c, d, cakes = 0, timer = 0;
	cin >> a >> b >> c >> d;
	while(cakes < a) {
		timer += b;
		cakes += c;
	}
	int timeOne = timer;
	cakes = 0;
	timer = 0;
	while(cakes < a) {
		timer += b;
		if (timer > d)
			cakes += c;
		cakes += c;
	}
	if (timer < timeOne)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
