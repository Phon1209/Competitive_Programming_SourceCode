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
int many[45][80005];
int fw[45][80005];
#define MOD 999999999
void add(int idx,int k,int lim,int val)
{
 //   printf("%d\n",val);
    while(idx<=lim)
    {
        fw[k][idx]+=val;
        fw[k][idx]%=MOD;
        idx+=(idx&(-idx));
    }
}
int sum(int idx,int k)
{
    int ret=0;
    while(idx>0)
    {
        ret+=fw[k][idx];
        ret%=MOD;
        idx-=(idx&(-idx));
    }
    return ret;
}
vector<int> v;
int main()
{
    sint2(n,k);
    for(int i=0;i<n;i++)
    {
        sint(tmp);
  //      tmp=n-tmp+1;
        v.pb(tmp);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int idx=v[i];
        many[1][i]=1;
   //     printf("%d\n",idx);
        add(idx,1,n,many[1][i]);
        for(int j=2;j<=k;j++)
        {
            many[j][i]=sum(n,j-1)-sum(idx,j-1);
            many[j][i]%=MOD;
 //           printf(">%d\n",many[j][i]);
            add(idx,j,n,many[j][i]);
        }
        ans+=many[k][i];
        ans%=MOD;
    }
    printf("%d\n",ans);
}
