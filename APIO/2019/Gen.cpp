#include<bits/stdc++.h>
#include"aquagenlib.h"
using namespace std;
#define mkp make_pair
#define mkt make_tuple
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define endl printf("\n")
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define SEND freopen("output.txt","w",stdout)
typedef long long ll;
void Wl(int x)
{
    printf("%d\n",x);
}
void Wl(double x)
{
    printf("%lf\n",x);
}
void Wl(string x)
{
    printf("%s\n",x.c_str());
}
void Wl(ll x)
{
    printf("%lld\n",x);
}
void W(int x)
{
    printf("%d ",x);
}
void W(double x)
{
    printf("%lf ",x);
}
void W(string x)
{
    printf("%s ",x.c_str());
}
void W(ll x)
{
    printf("%lld ",x);
}
int main(int argc,char* argv[])
{
    SEND;
    ll mx=(1000000LL);
    registerGen(argc,argv,1);
    int n=atoi(argv[1]);
    ll x=atoi(argv[2]);
    ll y=atoi(argv[3]);
    W(n),W(x),Wl(y);
    // Wl(mx);
    for(int i=0;i<n;i++)
    {
        ll a=rnd.next(0ll,mx),b=rnd.next(0ll,mx);
        if(a>b)swap(a,b);
        W(a);
        Wl(b);
    }
}
