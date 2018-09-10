#include <iostream>
using namespace std;

int arr[201];
bool visited[201];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 2*n+1; ++i)
		cin >> arr[i];
	arr[2*n+1] = 0;;
	for (int j = 0; j < k; ++j) {
		for (int i = 2*n; i >= 0; --i) {
			if (arr[i] > arr[i-1] + 1 && arr[i] > arr[i+1] + 1 && !visited[i]) {
				visited[i] = 1, --arr[i];
				break;
			}
		}
	}
	cout << arr[0];
	for (int i = 1; i < 2*n+1; ++i)
		cout << " " << arr[i];
}

