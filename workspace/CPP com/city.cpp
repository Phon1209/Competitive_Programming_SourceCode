#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,pair<int,int> > > v;
vector<int> ans;
class UnionFind
{
	private : vector<int> rk,p;
	public :
		UnionFind(int n)
		{
			rk.assign(n+1,0);
			p.assign(n+1,0);
			for(int i=1;i<=n;i++)
			{
				p[i]=i;
			}
		}
		int fs(int i)
		{
			return (p[i]==i)? i : (p[i]=fs(p[i]));
		}
		bool iss(int i,int j)
		{
			return fs(i)==fs(j);
		}
		void us(int i,int j)
		{
			if(!iss(i,j))
			{
				int x=fs(i),y=fs(j);
				if(rk[x]>rk[y])
				{
					p[y]=x;
				}
				else
				{
					p[x]=y;
					if(rk[x]==rk[y])
					{
						rk[y]++;
					}
				}
			}
		}
};
int main()
{
	int n,m;
	int s,t,w;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&s,&t,&w);
		v.push_back(make_pair(make_pair(w,s),make_pair(t,i)));
	}
	sort(v.begin(),v.end());
	UnionFind uf(n); 
	for(int i=0;i<v.size();i++)
	{
		if(!uf.iss(v[i].first.second,v[i].second.first))
		{
			ans.push_back(v[i].second.second);
			uf.us(v[i].first.second,v[i].second.first);
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d\n",ans[i]);
	}
}
