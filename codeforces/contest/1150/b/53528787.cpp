#include <bits/stdc++.h>
#include <iomanip>
#include <iostream>

#define ll long long
#define scanint1(a) scanf("%d",&a)
#define scanint2(a,b) scanf("%d %d",&a,&b)
#define scanint3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scanint4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
#define scanint5(a,b,c,d,e) scanf("%d %d %d %d %d",&a,&b,&c,&d,&e)
#define scanint6(a,b,c,d,e,f) scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)
#define scanlong1(a) scanf("%ld",&a)
#define scanlong2(a,b) scanf("%ld %ld",&a,&b)
#define scanlong3(a,b,c) scanf("%ld %ld %ld",&a,&b,&c)
#define scanlong4(a,b,c,d) scanf("%ld %ld %ld %ld",&a,&b,&c,&d)
#define scanlong5(a,b,c,d,e) scanf("%ld %ld %ld %ld %ld",&a,&b,&c,&d,&e)
#define scanll1(a) scanf("%lld",&a)
#define scanll2(a,b) scanf("%lld %lld",&a,&b)
#define scanll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define scanll4(a,b,c,d) scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define scanll5(a,b,c,d,e) scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e)
#define read  freopen("simple.in","r",stdin);
#define write freopen("output.txt","w",stdout);
#define MAXN   10000005

using namespace std;

        const int N = 55;
        int n;
        int arr[N][N];
        bool valid(int i,int j){if(i>=0&&i<n&&j>=0&&j<n&&!arr[i][j]) return 1; else return 0; }
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        int main()

           {
               cin>>n;
               for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
               {
                   char x;
                   cin>>x;
                   if(x=='#') arr[i][j]=1;
                   else arr[i][j]=0;
               }

               for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
               {
                   int cur = arr[i][j];
                   if(cur) continue;
                   bool can=1;

                   for(int k=0;k<4;k++)
                   {
                     int x = i+dx[k];
                     int y = j+dy[k];
                     if(!valid(x,y)) {can=0; break;}
                   }
                   if(!can) continue;
                   arr[i][j]=1;
                   for(int k=0;k<4;k++)
                   {
                     int x = i+dx[k];
                     int y = j+dy[k];
                     if(valid(x,y)) {arr[x][y]=1;}
                   }
               }

               for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                  if(!arr[i][j]) cout<<"NO"<<endl,exit(0);


               cout<<"YES"<<endl;



               return 0;
           }