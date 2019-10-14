#include <iostream>

using namespace std;

int main()
{
    int n, k, m;
    int x, y;
    cin>>n>>k;
    cin>>m;
    for (int i=1;i<=m;++i)
    {
        cin>>x>>y;
        int sum = x+y;
        int dif = x-y;
        if (k<=sum&&sum<=2*n-k && abs(dif) <= k)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}