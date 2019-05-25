#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf 1e9
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
char a[1005][505];
unsigned long long h[1005];
int mk=11;
set<unsigned long long> s;
int f(char c)
{
	if(c=='A') return 0;
	if(c=='T') return 1;
	if(c=='G') return 2;
	if(c=='C') return 3;
}
int main()
{
//	freopen("cownomics.in","r",stdin);
//	freopen("cownomics.out","w",stdout);
	sint2(n,m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	for(int i=n;i<2*n;i++)
	{
		scanf("%s",a[i]);
	}
	int ans=m;
	int mx=m,mn=0,md;
	while(1)
	{
		queue<int> q[1005];
		if(mn>mx)break;
		md=(mx+mn)/2;
		bool chk=false;
//		printf("%d %d %d\n",md,mn,mx);
		unsigned long long p=1;
		for(int i=0;i<1000;i++)
			h[i]=0;
		for(int i=0;i<md;i++)
			p*=mk;
		for(int i=0;i<m;i++)
		{
			bool ok=true;
			for(int j=0;j<n;j++)
			{
				q[j].push(f(a[j][i]));
				h[j]*=mk;
				h[j]+=f(a[j][i]);
				while(q[j].size()>md)
				{
					h[j]-=(q[j].front()*p);
					q[j].pop();
				}
				if(q[j].size()==md)
				{
//					printf("%llu\n",h[j]);
					s.insert(h[j]);
				}
			}
//			printf(">>%d\n",i);
			for(int j=n;j<2*n;j++)
			{
//				printf("A\n");
				q[j].push(f(a[j][i]));
				h[j]*=mk;
				h[j]+=f(a[j][i]);
				while(q[j].size()>md)
				{
					h[j]-=(q[j].front()*p);
					q[j].pop();
				}
//				printf(">%d\n",q[j].size());
				if(q[j].size()==md)
				{
//					printf("%llu\n",h[j]);
					if(s.find(h[j])!=s.end())
					{
						ok=false;
//						printf("a\n");
					}
				}
				else
				{
//					printf("b\n");
					ok=false;
				}
			}
			s.clear();
			if(ok)
			{
//				printf("%d\n",i);
				chk=true;
			}
		}
		if(chk)
		{
			ans=min(md,ans);
			mx=md-1;
		}
		else
		{
			mn=md+1;
		}
	}
	printf("%d\n",ans);
}

