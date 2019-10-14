#include<bits/stdc++.h>
using namespace std;

string s;
int n,ans,a[1000000];
int x,k,m;
int main()
{
    cin>>s;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        x--;
        a[x]++;
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if((a[i]%2)==1)
           k++;
        if(k%2==1)
           swap(s[i],s[s.size()-i-1]);
    }
    cout<<s;
}