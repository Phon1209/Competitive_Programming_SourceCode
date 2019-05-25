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

int a[1005];

vector<pair<ll,int>> v;
int main()
{
    sint2(n,m);
    for(int i=0;i<n;i++)
    {
        int1(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        ll sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            v.pb(mkp(sum,j-i+1));
        }
    }
    sort(all(v));
    int mx=0;
    for(int i=0;i<v.size();i++)
    {
        mx=max(mx,v[i].S);
        v[i].S=mx;
    }
    vector<pair<ll,int> >::iterator it;
    while(m--)
    {
        slong(tmp);
        it=upper_bound(all(v),mkp(tmp,n+1));
        if(it==v.begin())
        {
            printf("0\n");
            continue;
        }
        it--;
        printf("%d\n",it->S);
    }
}
/*

*/
