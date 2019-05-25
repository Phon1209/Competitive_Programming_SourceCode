#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		int ans=0,cnt=2;
		for(int i=1;i<n;i++)
		{
			if(v[i]-v[i-1]==1)
			{
//				printf("A\n");
				cnt++;
			}
			else
			{
//				printf("B\n");
				ans+=(cnt/2);
				cnt=2;
			}
		}
		ans+=(cnt/2);
		printf("%d\n",ans);
		v.clear();
	}
}
