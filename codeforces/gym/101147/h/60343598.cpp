#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;

int grid[12][12][12];
int mem[12][12][12];

bool valid(int f,int y ,int x){
	return f >= 1 && f<=10 && x >= 1 && x<=10 && y >= 1 && y<=10;
}
int solve(int f ,int y ,int x){
	if(!valid(f,y,x))
		return 0;
	int &ret = mem[f][y][x];
	if(~ret)
		return ret;
	int ch1 = solve(f-1,y,x) + grid[f][y][x];
	int ch2 = solve(f,y+1,x) + grid[f][y][x];
	int ch3 = solve(f,y,x+1)+ grid[f][y][x];
	ret = max(ch1,max(ch2,ch3));
	return ret;
}
int main() {
//	fastIO
	read("commandos.in")
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		while(n--){
			int f,y,x,h;
			scanf("%d %d %d %d",&f,&y,&x,&h);
			grid[f][y][x] = h;
		}
		clr(mem,-1);
		printf("%d\n",solve(10,1,1));
		clr(grid,0);
	}
	return 0;
}


