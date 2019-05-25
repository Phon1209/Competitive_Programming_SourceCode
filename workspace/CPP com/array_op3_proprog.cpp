#include<bits/stdc++.h>
int a[100005];
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int mn=0,mx=0;
        int cnt=0;
        bool chk=true;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i==1 || (a[i]>mx && i!=0))
            {
                mx=a[i];
                if(mx-mn>cnt)
                	cnt=mx-mn,chk=false;
            }
            if(i==0 || a[i]<mn)
            {
            	mn=a[i];
				mx=0;
			}
//			printf("%d %d %d\n",mx,mn,cnt);
        }
//        printf("%d %d\n",mn,mx);
        if(chk && n!=0)
            printf("UNFIT\n");
        else
            printf("%d\n",cnt);
    }
}

