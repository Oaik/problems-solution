#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--) {
		double d, b, a, discriminant, x1, x2;
		cin >> d;
		cout << fixed << setprecision(9);
		discriminant = d*d - 4*d;
		if (discriminant > 0) {
				x1 = (d + sqrt(discriminant)) / (2);
				x2 = (d - sqrt(discriminant)) / (2);
				cout << "Y " << x1 << " " << x2 << "\n";
			}

			else if (discriminant == 0) {
				x1 = (d + sqrt(discriminant)) / (2);
				cout << "Y " << x1 << " " << x1 << "\n";
			}

			else {
				cout << "N\n" ;
			}
	}
	return 0;
}