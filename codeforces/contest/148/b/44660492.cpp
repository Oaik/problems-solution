#include <bits/stdc++.h>

using namespace std;


int main()
{
  double v1,v2,t,f,c,girl=0,dragon=0,ans=0;
  scanf("%lf %lf %lf %lf %lf",&v1,&v2,&t,&f,&c );
  girl=t*v1;
  if(v1<v2){
  for(int i = 0; i>=0 ; i++){
    t = (girl/(v2-v1));girl += t*v1;
     if(girl>=c) break;
     else
        { ans++; t = (girl/v2)+f;girl += t*v1;}}
       }
  cout<<ans<<endl;

}