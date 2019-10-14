#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std ;

int main(void)
{
    char s1[15], s2[15] ;

    scanf("%s%s", s1, s2) ;

    int n = strlen(s1) ;
    
    int answerPosition = 0 ;
    for(int i=0;i<n;i++)
        answerPosition += (s1[i]=='+'?1:-1) ;

    int finalPosition = 0 ;
    int moves = 0 ;
    for(int i=0;i<n;i++)
    {
        if(s2[i]=='?')
            moves++ ;
        else
            finalPosition += (s2[i]=='+'?1:-1) ;
    }

    int distance = answerPosition-finalPosition ;
    double answer ;
    if((distance+moves)%2!=0 || moves<abs(distance))
        answer = 0 ;
    else
    {
        int m = (moves+abs(distance))/2 ;
        int c = 1 ;
        for(int i=0;i<m;i++)
            c *= moves-i ;
        for(int i=2;i<=m;i++)
            c /= i ;
        answer = (double)c/(1<<moves) ;
    }

    printf("%.12f\n", answer) ;

    return 0 ;
}