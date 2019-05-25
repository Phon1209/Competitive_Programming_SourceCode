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

ii sum(ii a,ii b)
{
    b.F*=a.S;
    b.S*=a.S;
    a.F+=b.F;
    a.S*=2;
    int u=__gcd(a.F,a.S);
    if(u)
    {
        a.F/=u;
        a.S/=u;
    }
    return a;
}
bool lessthan(ii a,ii b)
{
    int x,y;
    x=a.F*b.S;
    y=a.S*b.F;
    // debug(x);
    // debug(y);
    return x<y;
}
bool equal(ii a,ii b)
{
    int u=__gcd(a.F,a.S);
    a.F/=u;
    a.S/=u;
    u=__gcd(b.F,b.S);
    if(u!=0)
    {
        b.F/=u;
        b.S/=u;
    }
    return (a==b);
}
int conv(string s)
{
    int ret;
    stringstream ss;
    ss<<s;
    ss>>ret;
    return ret;
}
int main()
{
    sint(t);
    while(t--)
    {
        int use=0;
        ii want;
        sstring(s);
        string tmp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='/')
            {
                want.F=conv(tmp);
                tmp="";
                continue;
            }
            tmp+=s[i];
        }
        want.S=conv(tmp);
        if(want.S%2)
        {
            printf("NO\n");
            continue;
        }
        ii now=mkp(1,1);
        int No=40;
        while(No--)
        {
            // printf("now = %d/%d\n",now.F,now.S);
            if(equal(now,want))
            {
                break;
            }
            if(lessthan(now,want))
            {
                // use++;
                now=sum(now,mkp(1,1));
            }
            else
            {
                now=sum(now,mkp(0,1));
                use++;
            }
        }
        printf("%d\n",use);
    }
}
/*

*/
