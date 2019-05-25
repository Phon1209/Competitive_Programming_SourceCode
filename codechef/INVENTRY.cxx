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
void _main()
{
    sint(n);
    sstring(s);
    int pos=-1;
    int cnt=0;
    for(int i=0;i<n;i++)
        if(s[i]=='#')cnt++;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='.'){
            pos=i;
            break;
        }
    }
    if(pos==cnt || pos==-1 || cnt==n)
    {
        printf("0\n");
        return;
    }
    if(s[n-1]=='#')
    {
        printf("-1\n");
        return;
    }
    int box=0;
    int len=0;
    int can=0;
    int spare=0;
    bool found=0;
    ll ans=0;
    for(int i=pos;i<n;i++)
    {
        // pause;
        if(s[i]=='.')
            if(!found)len++;
            else can++;
        if(s[i]=='#')
        {
            found=1;
            box++;
            spare+=can;
        }
        s[i]='.';
        if(can>=box && box>=1)
        {
            len--;
            ans+=(box*(len+box))-spare;
            // debug(ans);
            len=len+1+box;
            box=0;
            can=0;
            spare=0;
            found=0;
            continue;
        }
        // debug(i);
        // printf("%d %d %d %d %d\n",box,len,can,spare,found? 1:0);
    }
    if(can<box)
    {
        printf("-1\n");
        return ;
    }
    printf("%lld\n",ans);
}
int main()
{
    sint(t);
    while(t--)_main();
}
/*

*/
