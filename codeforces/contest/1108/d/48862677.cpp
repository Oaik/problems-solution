
 #include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}



int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string str, lett = "RGB";
	int n, cnt = 0;
	cin >> n >> str;
	for (int i = 0; i < n; ++i) {
		if(i == n-1) {
			if(str[i] == str[i-1]) {
				++cnt;
				for (int j = 0; j < 3; ++j) {
					if(str[i] != lett[j]) {
						str[i] = lett[j];
						break;
					}
				}
			}
		}
		if(str[i] == str[i+1] || str[i] == str[i-1]) {
			++cnt;
			if(str[i] == str[i+2] && str[i] == str[i+1]) {
				++i;
				for (int j = 0; j < 3; ++j) {
					if(str[i] != lett[j] && str[i+1] != lett[j] && str[i-1] != lett[j]) {
						str[i] = lett[j];
						break;
					}
				}
			} else {
				for (int j = 0; j < 3; ++j) {
					if(str[i] != lett[j] && str[i+1] != lett[j] && str[i-1] != lett[j]) {
						str[i] = lett[j];
						break;
					}
				}
			}
		}
	}
	cout << cnt << "\n" << str;
}
