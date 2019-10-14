#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int n;
	cin>>n;

	string a;
	cin>>a;

	ll cnt=0;

	ll l=0, r=0;
	while(a[l]==a[0])
		l++;
	while(a[n-1-r]==a[n-1])
		r++;
	if(a[0]!=a[n-1]) 
		cnt=(1+l+r)%998244353;
	else
		cnt=((l+1)*(r+1))%998244353 ;
	
	cout<<cnt;
	
   return 0;
}