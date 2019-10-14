#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
bool f[1111][1111],best[1111][1111];
pair<int,int> p[3];
int main()
{
	for(int i=0;i<3;i++)cin>>p[i].x>>p[i].y;
	sort(p,p+3);
	set<pair<int,int>> s;
	for(int i=min(min(p[0].y,p[1].y),p[2].y);i<=max(max(p[0].y,p[1].y),p[2].y);i++)s.insert({p[1].x,i});
	for(int i=p[0].x;i<=p[1].x;i++)s.insert({i,p[0].y});
	for(int i=p[1].x;i<=p[2].x;i++)s.insert({i,p[2].y});
	cout<<s.size()<<'\n';
	for(auto x:s)cout<<x.x<<' '<<x.y<<'\n';
}