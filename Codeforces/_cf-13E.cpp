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

int sq;
int a[100005];
int cnt[100006];
int jmp[100006];
void upt(int idx)
{
    for(int i=sq-1;i>=0;i--)
    {
        int pos=idx*sq+i;
        if(a[pos]<=0)continue;
        if(pos+a[pos]>=sq)
        {
            cnt[pos]=1;
            jmp[pos]=pos+a[pos];
        }
        else
        {
            cnt[pos]=cnt[pos+a[i]]+1;
            jmp[pos]=jmp[pos+a[i]];
        }
    }
}
int main()
{
    memset(a,-1,sizeof(a));
    sint2(n,m);
    sq=sqrt(n)+1;
    for(int i=0;i<n;i++)
    {
        int1(a[i]);
    }
    for(int i=0;i<=sq;i++)
    {
        upt(i);
    }
    while(m--)
    {
        sint(cmd);
        sint(pos);
        pos--;
        if(cmd==0)
        {
            sint(val);
            //update
            a[pos]=val;
            upt(pos/sq);
        }
        if(cmd==1)
        {
            int ans=0;
            int tmp=0;
            while(pos<n)
            {
                ans+=cnt[pos];
                tmp=pos;
                pos=jmp[pos];
            }
            printf("%d %d\n",tmp+1,ans);
            //process
        }
    }
}
/*

*/
