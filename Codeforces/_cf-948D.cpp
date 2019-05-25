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
int a[300005];
int pt=1;
struct Node
{
    int l,r,val;
}S[20000005];
int get(int val,int lv=29,int p=1)
{
    if(p==0)p=++pt;
    if(lv==-1)
    {
        S[p].val++;
        S[p].l=val;
        return p;
    }
    if(val & (1<<lv)) S[p].l = get(val,--lv,S[p].l);
	else S[p].r=get(val,--lv,S[p].r);
	return p;
}
bool find(int &val,int lv=29,int p=1) {
	if(lv == -1) {
		S[p].val--;
		return (S[p].val==0);
	}
	bool st1 = false, st2 = false;
	if(val&(1<<lv)) {
		if(S[p].l) {
			val ^= (1 << lv);
			st1 = find(val,--lv,S[p].l);
		}else st2 = find(val, lv-1, S[p].r);
	} else {
		if(S[p].r) st2 = find(val, lv-1, S[p].r);
		else {
			val ^= (1<<lv);
			st1 = find(val, lv-1, S[p].l);
		}
	}
	bool st = false;
	if(st1) S[p].l = 0, st = true;
	if(st2) S[p].r = 0, st = true;
	if(S[p].l) st = false; if(S[p].r) st = false;
	return st;
}
int main()
{
    sint(n);
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        get(tmp);
    }
    for(int i=1;i<=n;i++)
    {
        find(a[i]);
        printf("%d ",a[i]);
    }
    endl;
}
/*

*/
