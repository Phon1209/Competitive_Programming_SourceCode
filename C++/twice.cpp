#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : String
Source : Proprog
*/
#pragma GCC optimize ("Ofast")
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
char s[200005];
int n;
bitset<1000010> bt;
#define MOD 1000007
bool chk(int md)
{
    bt.reset();
    int lena,lenb,ha=0,hb=0,Mb=1,temp,i,j;
    lena=n;
    lenb=md;
    // debug(md);
    for(int i=0;i<lenb;i++)
    {
        ha=((ha*31)+(s[i]-48))%MOD;
    }
    for(i=0;i<lenb-1;i++)
    {
        Mb=(Mb*31)%MOD;
    }
    for(i=0;i<=lena-lenb;i++)
    {
        // debug(ha);
        if(bt[ha])return true;
        bt[ha]=1;
        if(i!=lena-lenb)
        {
            temp=((s[i]-48)*Mb)%MOD;
            if(ha<temp)
                ha+=MOD;
            ha=((ha-temp)*31+s[i+lenb]-48)%MOD;
        }
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    int mn=0;
    int mx=n;
    int ans=0;
    while(mn<=mx)
    {
        int md=(mn+mx)/2;
        if(chk(md))
        {
            ans=max(ans,md);
            mn=md+1;
        }
        else mx=md-1;
    }
    printf("%d\n",ans);
}
/*

*/
