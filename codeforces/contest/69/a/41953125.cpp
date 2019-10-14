#include <iostream>
using namespace std;

int main() {
	int x = 0, y = 0, z = 0, inp1 = 0, inp2 = 0, inp3 = 0, n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin>>inp1>>inp2>>inp3;
		x += inp1, y += inp2, z += inp3;
	}
	if(x == 0 && y == 0 && z == 0)
		cout << "YES";
	else
		cout << "NO";
}
