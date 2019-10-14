#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define ll long long

using namespace std;

const double EPS = (1e-8);
const double PI = acos(-1.0);
const ll INF = 1e9;

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
void contest() {
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.in", "w", stdout);
	#endif
}
using namespace std;

map<char, int> mpS;
map<char, int> mpT;
int main()
{
    string a, b;
    cin >> a >> b;
    int k = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (k == b.size()) break;
        if (a[i] == b[k]) ++k;
    }
    if (k == b.size())
    {
        puts("automaton");
        return 0;
    }
    sort(all(a));
    sort(all(b));
    if (a == b)
    {
        puts("array");
        return 0;
    }
    k = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (k == b.size()) break;
        if (a[i] == b[k]) ++k;
    }
    if (k == b.size())
    {
        puts("both");
        return 0;
    }
    puts("need tree");
    return 0;
}
