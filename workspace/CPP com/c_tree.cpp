#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
char a[5];

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int max=0;
	for(int i=0;i<m+n;i++)
	{
		scanf("%s",a);
		if(a[0]=='O')
		{
			printf("%d\n",pq.size());
		}
		if(a[0]=='T')
		{
			int s;
			scanf("%d",&s);
			while(!pq.empty())
			{
				if(-pq.top()<=s)
				{
//					printf("A\n");
					pq.pop();
				}
				else
				{
//					printf("B\n");
					break;
				}
			}
			pq.push(-s);
		}
	}
}
