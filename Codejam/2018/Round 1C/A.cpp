#include<bits/stdc++.h>
using namespace std;
#define SEND freopen("output.txt","w",stdout)
char a[2005][15];
int hsh[2005][1005];
set<int> s[2005];
int f(char c)
{
    return (c-'A');
}
int _main()
{
    for(int i=0;i<=2000;i++)s[i].clear();
    memset(a,0,sizeof(a));
    memset(hsh,0,sizeof(hsh));


    int n,l;
    scanf("%d %d",&n,&l);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        for(int j=1;j<l;j++)
        {
            int u=f(a[i][j-1])*29+f(a[i][j]);
            hsh[j][u]=1;
        }
        for(int j=0;j<l;j++)
        {
            s[j].insert(f(a[i][j]));
        }
    }
    for(int i=1;i<l;i++)
    {
        for(auto it=s[i-1].begin();it!=s[i-1].end();it++)
        {
            for(auto it2=s[i].begin();it2!=s[i].end();it2++)
            {
                int u=(*it)*29+(*it2);
                if(!hsh[i][u])
                {
                    for(int j=0;j<i-1;j++)printf("%c",(*(s[j].begin())+'A'));
                    printf("%c%c",(*it)+'A',(*it2)+'A');
                    for(int j=i+1;j<l;j++)printf("%c",(*(s[j].begin())+'A'));
                    return 0;
                }
            }
        }
    }
    printf("-");
    return 0;
}
int main()
{
    // SEND;
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        _main();
        if(i!=t)printf("\n");
    }
}
/*

*/
