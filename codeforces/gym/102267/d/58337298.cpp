#include <bits/stdc++.h>
using namespace std;
#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
typedef long long ll;
#define PI		acos(-1)
void Yahia74() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin); //freopen("output.in", "w", stdout);
#endif
	cout << fixed << setprecision(9);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e7 + 5, M = 5e5 + 74, OO = 0x3f3f3f3f;
bool vis[14][14] ;
int dx[4] = {0,1,0,-1} , dy[4] ={1,0,-1,0} ;
int dx2[4] = {0,-1,0,1} , dy2[4] ={-1,0,1,0} ;
vector<char> moves ;
void visAllBlack(){
	vis[9][10] = vis[9][11] = vis[10][11] = vis[9][2] = vis[9][3] = vis[10][2] = vis[6][6] = vis[6][7] =  vis[7][6] = vis[7][7] = true ;
}
int isCrossed(int i,int j){
	if(i == 3 && j == 3){
		return 1 ;
	}else if(i == 3 && j == 10){
		return 2 ;
	}else if(i == 10 && j == 3){
		return 3 ;
	}else if(i == 10 && j == 10){
		return 4 ;
	}else {
		return 0 ;
	}
}
bool isValid(int i ,int j){
	return i >= 1 && j >= 1 && i <= 12 && j <= 12 ;
}
char getMoves(int d) {
	if(d ==0)
		return 'R' ;
	else if(d==1)
		return 'D' ;
	else if(d==2)
		return 'L' ;
	else if(d == 3)
		return 'U' ;
}
int path[14][14] ;
int r , c ;
void bfs(int x ,int y){
	queue<pair<pair<int,int>,int>> q;
	bool found = false ;
	int pos = -1 ;
	int fx , fy ;
	clr(path,-1);
	q.push(make_pair(make_pair(x,y),-1));
	vis[x][y] = true ;
	while(!q.empty() && !found){
		int sz = q.size();
		while(sz--){
			fx = q.front().first.first , fy = q.front().first.second ;
			if(isCrossed(fx,fy)){
				found = true ;
				pos = isCrossed(fx,fy);
				path[fx][fy] = q.front().second ;
				break ;
			}
			path[fx][fy] = q.front().second ;
			q.pop();
			vis[fx][fy] = true;
			for(int d =0 ; d <4 ;d++){
				int nx = fx + dx[d] , ny = fy + dy[d] ;
				if(isValid(nx,ny) && !vis[nx][ny]){
					q.push(make_pair(make_pair(nx,ny),d));
				}
			}
		}
	}
	int cx = fx , cy = fy ;
	while(cx != r || cy != c){
		moves.push_back(getMoves(path[cx][cy])) ;
		int tempx = cx , tempy =cy ;
		cx = cx + dx2[path[tempx][tempy]] , cy = cy + dy2[path[tempx][tempy]] ;
	}
}
int main() {
	Yahia74();
	int l ;
	cin >> l ;
	while(l--){
		cin >> r >> c ;
		clr(vis,false) ;
		visAllBlack() ;
		moves.clear();
		bfs(r,c) ;
		reverse(all(moves));
		if(isCrossed(r,c))
			moves.push_back(getMoves(1)) , moves.push_back(getMoves(3)) ;
		cout << sz(moves) << el ;
		for(char c : moves)
			cout << c ;
		cout << el ;
	}
	return 0;
}
