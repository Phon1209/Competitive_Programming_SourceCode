#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define mkt make_tuple
#define pb push_back
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define cstring(a,x) char a[x]; scanf("%s",a);
#define sstring(a) string a;cin>>a;
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#define debug(x) cout<< #x << " = " << x;endl;
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
map<int,int> mp;
int qs[1005];
#define MOD 9901;
int nCr[1005][1005];
void Generate()
{
    nCr[0][0]=1;
    for(int i=1;i<=1000;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)nCr[i][j]=nCr[i-1][j];
            else nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
            nCr[i][j]%=MOD;
        }
    }
}
int n,m;
int bs(int k)
{
    int l=1,r=n;
    int ret=n;
    while(l<=r)
    {
        int md=(l+r)/2;
        // debug(md);
        if(qs[md]>=k)
        {
            ret=md;
            // printf("return = %d!!\n",md);
            r=md-1;
        }
        else l=md+1;
    }
    return ret;
}
int a[1005];
int main()
{
    Generate();
    int2(n,m);
    qs[0]=0;
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
        qs[i]=qs[i-1]+a[i];
    }
    /*
    for(int i=1;i<=n;i++)
    {
        printf("%d ",qs[i]);
    }
    */
    // endl;
    mp[1]=1;
    mp[qs[n]]=n;
    // debug(1);
    for(int i=0;i<m;i++)
    {
        sint(tmp);
        mp[tmp]=bs(tmp);
    }
    auto it=mp.begin();
    auto it2=it;
    it2++;
    int ans=1;
    // debug(3);
    while(it2!=mp.end())
    {
        // debug(2);
        // printf("%d %d %d %d\n",it->F,it->S,it2->F,it2->S);
        ans*=nCr[it2->F - it->F][it2->S - it->S];
        ans%=MOD;
        it++;
        it2++;
    }
    printf("%d\n",ans);
}
/*

*/
