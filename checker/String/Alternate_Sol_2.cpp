#include<bits/stdc++.h>
using namespace std;
/*
Problem : Brute Force
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
#define MOD 1000000007

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
vii v;
int n,m,k;
int a[100];
int cnt=0;
void find(int lv)
{
    if(lv==n+1)
    {
        bool ok=true;
        for(int i=0;i<v.size();i++)
        {
            int x,y;
            x=v[i].F;
            y=v[i].S;
            while(x<=y)
            {
                if(a[x++]!=a[y--])
                {
                    ok=false;
                }
            }
            if(!ok)break;
        }
        /*
        for(int i=1;i<=n;i++)
        {
            printf("%d ",a[i]);
        }
        endl;
        */
        if(ok)
        {
            printf("ok\n");
            cnt++;
        }
        return;
    }
    a[lv]=0;
    find(lv+1);
    a[lv]=1;
    find(lv+1);
}
int main()
{
    int3(n,k,m);
    if(k==1)
    {
        printf("1\n");
        return 0;
    }
    while(m--)
    {
        sint2(x,y);
        if(x>y)swap(x,y);
        v.pb(mkp(x,y));
    }
    cnt=0;
    find(1);
    printf("%d\n",cnt);
}
/*

*/
