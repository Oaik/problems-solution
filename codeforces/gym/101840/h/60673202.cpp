#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, M = 1e6 + 1, OO = 1e9 + 1;
const long long MOD = 1e9 + 7;

vector<int> facts, divsors;
void divisorsOfNumber(int n) {
	int i;
	for (i = 1; i * i < n; i++) {
		if (n % i == 0) {
			divsors.push_back(i);
			divsors.push_back(n / i);
		}
	}
	if (i * i == n)
		divsors.push_back(i);
	sort(divsors.begin(), divsors.end());
}
void factorize(int n) {
	int i, d = 1;
	for (i = 2; i * i <= n; i += d, d = 2) {
		while (n % i == 0) {
			n /= i;
			facts.push_back(i);
		}
	}
	if (n != 1)
		facts.push_back(n);
}
int main() {
	fastIO
	read("halfnice.in")
//	read("input.in")
	int T,
	cases = 0;
	cin >> T;
	while (T--) {
		ll a, b;
		cin >> a >> b;
		string best = "" , num , numL ,numR;
		while (b >= a) {
			num = to_string(b);
			numL = num.substr(0, (int) num.size() / 2);
			numR = num.substr((int) num.size() / 2);
			int numLI = stoi(numL), numRI = stoi(numR);
			facts.clear();
			factorize(numLI);
			for (int i : facts) {
				if (numRI / i == 0)
					continue;
				string temp = to_string((ll)(numRI / i) * i);
				temp = string(((int) numR.size() - (int) temp.size()), '0')+ temp;
				if (best < temp && temp != "0") {
					best = temp;
				}
			}
			b -= (ll)stoll(numR) + (ll)1;
			if (best != "") {
				break;
			}
		}
		cout << "Case " << ++cases << ": ";
		if(best == "")
			cout << "impossible" << el;
		else
			cout<< numL << best << el;
	}
	return 0;
}

