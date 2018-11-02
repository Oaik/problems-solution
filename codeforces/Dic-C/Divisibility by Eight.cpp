#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <unordered_map>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define ll long long

const double EPS = (1e-7);
const ll INF = 1e9;

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void contest() {
	freopen("input.in", "r", stdin);
}


int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string str;
	cin >> str;
	int n = str.length();
	for (int i = 0; i < n; ++i) {
		if ( ((str[i]) - '0') % 8 == 0) {
			cout << "YES\n" << str[i];
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if ( ( ((str[i]) - '0') * 10 + ((str[j]) - '0') ) % 8 == 0) {
				cout << "YES\n" << ( ((str[i]) - '0') * 10 + ((str[j]) - '0') );
				return 0;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			for (int k = j+1; k < n; ++k) {
				if ( ( ((str[i]) - '0') * 100 + ((str[j]) - '0') * 10 + ((str[k]) - '0') ) % 8 == 0) {
					cout << "YES\n" << ((str[i]) - '0') * 100 + ((str[j]) - '0') * 10 + ((str[k]) - '0');
					return 0;
				}
			}
		}
	}
	cout << "NO";
}

