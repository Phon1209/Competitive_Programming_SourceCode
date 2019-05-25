#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("O3")
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
int a[50];
void _main()
{
    memset(a,0,sizeof(a));
    sint(d);
    sstring(s);
    int cnt=0;
    int dam=1;
    int tak=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='C')dam*=2;
        if(s[i]=='S')cnt++,tak+=dam,a[i]=dam;
    }
    if(cnt>d)
    {
        printf("IMPOSSIBLE\n");
        return;
    }
    int ans=0;
    while(tak>d)
    {
        for(int i=s.size()-1;i>0;i--)
        {
            if(a[i]!=0 && a[i-1]==0)
            {
                swap(a[i],a[i-1]);
                a[i-1]/=2;
                tak-=a[i-1];
                break;
            }
        }
        ans++;
    }
    printf("%d\n",ans);
}
int main()
{
    sint(t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        _main();
    }
}
/*

*/
