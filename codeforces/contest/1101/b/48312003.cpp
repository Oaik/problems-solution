#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}

vector<int> vec1, vec2, vec3, vec4;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string str;
	cin >> str;
	int n = str.length(), start = -1, end = 0, startx = 0, endx = 0, cnt = 0, res = 3;
	bool found = false, foundx = false;
	if(!found) {
		for (int i = 0; i < n && !found; ++i) {
			if(str[i] == '[') {
				start = i;
    			for (int j = n-1; j >= 0 && start > -1  && !found; --j) {
    				if(str[j] == ']' && j > start) {
    					end = j;
    					// find first and last :
    					for (int z = start+1; z < end && !found; ++z) {
    						if(str[z] == ':') {
    							for (int q = end-1; q > start && q > z; --q) {
    								if(str[q] == ':') {
    									for (int w = z+1; w < q; ++w) {
    										if(str[w] == '|')
    											++cnt;
    									}
    									res = max(res, cnt+4);
    									found = true;
    									break;
    								}
    							}
    							break;
    						}
    					}
    					break;
    				}
    			}
			    break;
			}
		}
	}

	if(res > 3)
		cout << res;
	else
		cout << -1;

}