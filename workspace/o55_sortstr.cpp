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
vector<string> v;
void Quick(int st,int ed)
{
    if(ed<=st) return;
    int k;
    k=rand()%(ed-st+1);
    swap(v[st],v[st+k]);
    string pivot=v[st];
    int cnt=st+1;
    for(int i=st+1;i<=ed;i++)
    {
        if(v[i]<=pivot)
        {
            swap(v[cnt],v[i]);
            cnt++;
        }
    }
    swap(v[st],v[cnt-1]);
    Quick(st,cnt-2);
    Quick(cnt,ed);
}
int main()
{
    srand(time(0));
    sint(n);
    for(int i=0;i<n;i++)
    {
        sstring(a,15);
        string tmp=a;
        a[0]=0;
        v.pb(tmp);
    }
    Quick(0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%s\n",v[i].c_str());
    }
}
