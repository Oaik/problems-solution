#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h>
#include<map>
#include<stack>
#include<sstream>
#include<queue>
#include<list>
#include<iomanip>
#include<bitset>
#include<limits.h>
#define INF  -1
#define MOD  1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define MP(a,b) make_pair(a,b)
#define fr first
#define sc second
using namespace std;

//--------------------- This code Written by " Abanob Ashraf " ----------------------------------
//------------------ I Hope To Learn Or Understand Any Thing from it ----------------------------
//----------------------------------- START -----------------------------------------------------

int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int N , M ;

    scanf("%d%d" , &N , &M) ;

    vector<set<int> > tie (N + 1) ;

    int a , b ;

    while (M--)
    {
        scanf("%d%d" , &a , &b) ;
        tie [a].insert(b) ;
        tie [b].insert(a) ;
    }


    int groups = 0 ;

    while (1)
    {
        vector<int> v ;

        for (int i = 1 ; i <= N ; i++)
        {
            if (tie [i].size() == 1)
                v.push_back(i) ;
        }

        for (int i = 0 ; i < (int) v.size() ; i++)
        {
            set<int>::iterator it = tie [ v[i] ].begin() ;
            tie [ v[i] ].clear() ;
            tie [ *it ].erase(v[i]) ;
        }

       if (v.size())
            groups++ ;
       else
            break ;
    }

    printf("%d" , groups ) ;

}
//------------------------------------ DONE -----------------------------------------------------