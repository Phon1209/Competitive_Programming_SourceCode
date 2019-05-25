#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define mp make_pair
#define pb push_back
#define inf 1e9
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define PER(a) int _a=a; while(_a--)
#define pd(n) printf("%d\n",n);
#define pl(x) printf("%lld\n",x);
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int f(char c)
{
	if(c>='a' && c<='z')
	{
		return c-'a';
	}
	else if(c>='A' && c<='Z')
	{
		return c-'A'+26;
	}
	else if(c>='0' && c<='9')
	{
		return c-'0'+52;
	}
}
int _main()
{
	char c[100005],s[100005];
	scanf("%s %s",c,s);
	unsigned long long chk=0,mn=1;
	int n=0;
	for(int i=0;c[i];i++)
	{
		chk*=101;
		chk+=f(c[i]);
		n++;
		mn*=101;
	}
	queue<int> q;
	unsigned long long cnt=0;
	int ck=0;
//	printf("%lld\n",chk);
	for(int i=0;s[i];i++)
	{
		q.push(f(s[i]));
		cnt*=101;
		cnt+=f(s[i]);
		while(q.size()>n)
		{
			cnt-=(q.front()*mn);
			q.pop();
		}
		if(cnt==chk)
		{
			ck++;
		}
	}
	c[0]=0;
	s[0]=0;
	printf("%d\n",ck);
}
int main()
{
	sint(t);
	while(t--)
	{
		_main();
	}
}


