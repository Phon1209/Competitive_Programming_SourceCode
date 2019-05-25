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
#define inf 1e9
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
int a[500][500],T;
vector<int> v[500];
vector<int>::iterator it,it2;
void upt(int idx,int val)
{
	int x,y;
	x=idx/T;
	y=idx%T;
	int tmp;
	tmp=a[x][y];
	a[x][y]=val;
	it=lower_bound(all(v[x]),tmp);
	v[x][it-v[x].begin()]=val;
	sort(all(v[x]));
}
int ret(int l,int r,int x,int y)
{
	int cnt=0;
//	printf("ok %d\n",T);
	for(int i=0;i<T;i++)
	{
		int L,R;
		L=i*T;
		R=(i*T)+T-1;
//		printf("T\n");
//		printf("%d %d %d %d\n",l,r,L,R);
		if(r<L || l>R) continue;
		if(l<=L && R<=r)
		{
//			printf("L\n");
			it2=upper_bound(all(v[i]),y);
			it=lower_bound(all(v[i]),x);
			cnt+=(it2-it);
			continue;
		}
		if(l<=L && R>r)
		{
//			printf("A : ");
			for(int j=0;j<=r%T;j++)
			{
//				printf("%d %d %d\n",a[i][j],x,y);
				if(a[i][j]>=x && a[i][j]<=y)
					cnt++;
			}
//			printf("%d\n",cnt);
		}
		if(l>L && R<=r)
		{
//			printf("B : ");
			for(int j=l%T;j<T;j++)
			{
//				printf("%d %d %d\n",a[i][j],x,y);
//				if(i*T+j<l || i*T+j>r) continue;
				if(a[i][j]>=x && a[i][j]<=y)
					cnt++;
			}
//			printf("%d \n",cnt);
		}
		if(L<l && r<R)
		{
			for(int j=l%T;j<=r%T;j++)
			{
				if(a[i][j]>=x && a[i][j]<=y)
					cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	sint2(n,m);
	T=sqrt(n)+1;
	for(int i=0;i<n;i++)
	{
		int x,y;
		x=i/T;
		y=i%T;
		scanf("%d",&a[x][y]);
		v[x].pb(a[x][y]);
	}
	for(int i=0;i<T;i++)
	{
		sort(all(v[i]));
	}
	while(m--)
	{
		char c[5];
		/*
		for(int i=0;i<T;i++)
		{
			for(int j=0;j<v[i].size();j++)
			{
				printf("%d ",v[i][j]);
			}
			printf("| ");
			for(int j=0;j<T;j++)
			{
				printf("%d ",a[i][j]);
			}
			endl;
		}
		//*/
		scanf("%s",c);
		if(c[0]=='q')
		{
			sint2(l,r);
			sint2(x,y);
			printf("%d\n",ret(l-1,r-1,x,y));
		}
		else if(c[0]=='c')
		{
			sint2(idx,val);
			upt(idx-1,val);
		}
	}
}

