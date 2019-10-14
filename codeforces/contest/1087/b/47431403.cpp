#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n,k;
	cin>>n>>k;
	for(int i=k-1;i>0;i--) 
	    if(n%i==0)
	        return cout<<i+(n/i)*k,0;
}