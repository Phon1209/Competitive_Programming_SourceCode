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
int a[1005][1005];
int main()
{
	int t;
	scanf("%d",&t);
	char g[100];
	gets(g);
	while(t--)
	{
		char c[1005];
		gets(c);
		string s,rev;
		rev=s=c;
		reverse(all(rev));
		memset(a,0,sizeof(a));
		for(int i=1;i<=s.size();i++)
		{
			for(int j=1;j<=rev.size();j++)
			{
				if(s[i-1]==rev[j-1])
				{
					a[i][j]=a[i-1][j-1]+1;
				}
				else
				{
					a[i][j]=max(a[i-1][j],a[i][j-1]);
				}
			}
		}
		queue<ii> q;
		int n=s.size();
		/*
		q.push(mkp(n,n));
		while(!q.empty())
		{
			int x,y;
			x=q.front().F;
			y=q.front().S;
			q.pop();
			if(x==0 || y==0)
				break;
			if(s[x-1]==rev[y-1])
			{
//				printf("%c",s[x-1]);
				q.push(mkp(x-1,y-1));
			}
			else
			{
				if(a[x][y-1]>a[x-1][y])
				{
					q.push(mkp(x,y-1));
				}
				else
				{
					q.push(mkp(x-1,y));
				}
			}
		}
		*/
		/*
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		*/
		printf("%d\n",a[n][n]);
	}
}

