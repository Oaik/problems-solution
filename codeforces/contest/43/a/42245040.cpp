#include <iostream>
using namespace std;

int main() {
	int n = 0, team1 = 1, team2 = 0;
	string inp1, inp2, cmp;
	cin >> n >> inp1;
	while(--n) {
		cin >> cmp;
		if (inp1 == cmp)
			++team1;
		else
			++team2, inp2 = cmp;
	}
	if (team1 > team2)
		cout << inp1;
	else
		cout << inp2;
}
