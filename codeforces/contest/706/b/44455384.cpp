#include <bits/stdc++.h>


using namespace std;
   long long  n ,arr[100000],q;

long long x;
bool can (int y)
{
    if(arr[y]<=x)
        return 1 ;

    return 0;

}

int main()
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   sort(arr,arr+n);
   cin>>q;
   while(q--)
   {
       cin>>x;
       long long s=0,e=n-1;int mid =0;
       while (s<=e)
       {

            int mid=s+(e-s)/2;
            if(can(mid))
                   s=mid+1;
                else
                e=mid-1;

       }

    cout << s << "\n";
   }
}