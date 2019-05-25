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
map<int,int> mp;
map<int,int>::iterator it;
int main()
{
	sint2(n,m);
	for(int i=0;i<n;i++)
	{
		sint(a);
		mp[a]++;
	}
	while(m--)
	{
		sint(a);
		it=mp.begin();
		bool chk=true;
		while(it!=mp.end())
		{
			int tmp;
			tmp=a-(*it).first;
			if(tmp<(*it).first)
				break;
			if(mp.find(tmp)!=mp.end())
			{
				if(tmp==(*it).first)
				{
					if((*it).second>=2)
					{
						printf("%d + %d = %d\n",(*it).first,tmp,a);
						chk=false;
						break;
					}
					else
					{
						break;
					}
				}
				printf("%d + %d = %d\n",(*it).first,tmp,a);
				chk=false;
				break;
			}
			it++;
		}
		if(chk)
			printf("Not Have\n");
	}
}

