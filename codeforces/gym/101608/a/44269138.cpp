#include<cstdio>
int T,n,k;
int main(){
    freopen("tabs.in","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        if(n==1)puts("0");
        else if(k==1||k==n)puts("1");
        else puts("2");
    }
}