#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define sstring(a,x) char a[x]; scanf("%s",a);
#define sss(a,b,c) stringstream a; a<<b; a>>c
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
bitset<1200> bt;
vi v;
int a[30][1200];
int main()
{
    for(int i=2;i<=1200;i++)
    {
        if(bt[i])continue;
        v.pb(i);
        for(int j=i+i;j<=1200;j+=i)
        {
            bt[j]=1;
        }
    }
    a[0][0]=1;
    for(int i=0;i<v.size();i++)
    {
        int u=v[i];
//        printf("%d\n",u);
        for(int k=25;k>=1;k--)
        {
//            printf("B\n");
            for(int j=1150;j-u>=0;j--)
            {
                a[k][j]+=a[k-1][j-u];
            }
//            printf("A\n");
        }
    }
    while(1)
    {
        sint2(n,m);
        if(!n && !m)break;
        printf("%d\n",a[m][n]);
    }
}
/*

*/
