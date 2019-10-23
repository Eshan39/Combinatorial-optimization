#include <bits/stdc++.h>

using namespace std;
#define MAX 1110000

int node , edge;
int color[MAX];
vector <long> graph[MAX];
vector <long> dipto;
int num ;

void dfs_visit(int u)
{
    int i,j;
    color[u] = true;
    for(i=0;i<graph[u].size();i++)
    {
        int v = graph[u][i];
        if(color[v]==0)
        {
            dfs_visit(v);
        }
    }
    dipto.push_back(u);
}

void dfs()
{
    int i,j;
    memset(color , 0 , sizeof(color));
    for(i=1;i<=node;i++)
    {
        if(color[i]==0)
        {
            dfs_visit(i);
        }
    }
}

void dfs2()
{
    //dipto.clear();
    memset(color,0,sizeof(color));
    int i , j;
    j = dipto.size()-1;
    for(i=j;i>=0;i--)
    {
        if(color[dipto[i]]==0)
        {
            dfs_visit(dipto[i]);
            num++;
        }

    }
}

int main()
{
    int n,i,j,k,l,a,b,c,d;
    scanf("%d",&n);
    while(n--)
    {
        num = 0;
        scanf("%d %d",&node,&edge);
        for(i=1;i<=edge;i++)
        {
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
        }

        dfs();
        dfs2();

        printf("%d\n",num);

        dipto.clear();
        for(j=0;j<MAX;j++)
        {
            graph[j].clear();
        }
    }
}
