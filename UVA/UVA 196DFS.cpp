#include <bits/stdc++.h>

using namespace std;

#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define lp(i,n) 	for(int i=0;i<(int)n;i++)
#define lpv(i,a,n) 	for(int i=a;i<=(int)n;i++)
#define clr(a,b)	memset(a,b,sizeof(a))
typedef long long ll;

void YAHIA() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(8);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
int row, col, sheet[1005][18250];
string formula[1005][18250], str;
int dfs(int r, int c) {
	if (sheet[r][c] != INT_MIN)
		return sheet[r][c];

	string str2 = formula[r][c];
	sheet[r][c] = 0;
	lpv(k,1,sz(str2)-1){
		int row2 = 0, col2 = 0;
		while (str2[k] != '+') {
			if (str2[k] >= 'A' && str2[k] <= 'Z') {
				col2 = 26 * col2 + str2[k] - 'A' + 1;
			} else {
				row2 = 10 * row2 + str2[k] - '0';
			}
			++k;
			if (k == sz(str2))
				break;
		}
		sheet[r][c] += dfs(row2, col2);
	}
	return sheet[r][c];
}
int main() {
	YAHIA();
	int T;
	cin >> T;
	while (T--) {
		clr(sheet, 0);
		cin >> col >> row;
		lpv(i,1,row){
			lpv(j,1,col){
				cin >> str;
				if (str[0] == '=') {
					sheet[i][j] = INT_MIN;
					formula[i][j] = str;
				} else {
					stringstream ss(str);
					ss >> sheet[i][j];
				}
			}
		}
		lpv(i,1,row)
			lpv(j,1,col)
				if (sheet[i][j] == INT_MIN)
					dfs(i, j);

		lpv(i,1,row){
			cout << sheet[i][1] ;
			for (int j = 2; j <= col; ++j)
				 cout << " " << sheet[i][j];
			cout << el ;
		}
	}

	return 0;
}

