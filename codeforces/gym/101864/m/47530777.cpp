#include<bits/stdc++.h>
using namespace std;
#define D(x)    cout << #x " = " <<(x) << endl
#define MAX     100000
typedef long long int LL;

vector<int> multiply(vector<int> &a, vector<int> &b){
    vector<int> ret;
    ret.resize(a.size() + b.size());

    int i, j;
    for(i = 0; i < (int) a.size(); i++)
        for(j = 0; j < (int) b.size(); j++)
            ret[i + j] += a[i] * b[j];

    while(!ret.back()) ret.pop_back();
    return ret;
}

vector<int> a, b, c, orig_c;


int main()
{
    //freopen("in.txt", "r", stdin);

    int t,  n, k, i, v;
    scanf("%d", &t);
    while(t--){
        a.clear(), b.clear(), c.clear();

        scanf("%d", &n);
        for(i = 1; i <= n; i++){
            scanf("%d", &v);
            a.push_back(v);
        }

        scanf("%d", &k);
        for(i = 1; i <= k; i++){
            scanf("%d", &v);
            c.push_back(v);
        }
        orig_c = c;

        for(int p = 0; p < (int) c.size() - (int) a.size() + 1; p++){
            for(int l = 0; l < p; l++){
                int r = p - l;
                if(r < (int) a.size()) c[p] -= (b[l] * a[r]);
            }

            assert(c[p] % a[0] == 0);
            b.push_back(c[p]/a[0]);
        }

        printf("%d\n", (int) b.size());
        for(i = 0; i < (int) b.size(); i++){
            printf("%d", b[i]);
            if(i + 1 == (int) b.size()) puts("");
            else printf(" ");
        }

        assert(multiply(a, b) == orig_c);
    }
    return 0;
}