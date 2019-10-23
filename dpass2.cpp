#include<bits/stdc++.h>
#include<math.h>

#define inf 10000
using namespace std;

int p;
int money[200][200],product[30][30];

int knapsack(int i,int m)
{
    if(m<0)
        return -inf;

    else if(i==p&&m>=0)
        return 0;

    else if(money[m][i]!=-1)
        return money[m][i];

    else
    {
        int val = -inf;
        //int j;
        for(int j=1;j<=product[i][0];j++){
            val= max(product[i][j]+knapsack(i+1,m-product[i][j]),val);
        }

        return money[m][i]=val;
    }
}



int main()
{
    int m,test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        cin>>m>>p;

        for(int i=0;i<=m;i++)
            for(int j=0;j<=p;j++)
                money[i][j]=-1;

        for(int i=0;i<p;i++)
        {
            cin>>product[i][0];
            for(int j=1;j<=product[i][0];j++)
                cin>>product[i][j];
        }
        int answer=knapsack(0,m);

        if(answer>0)
            cout<<answer<<endl;
        else
            cout<<"no solution"<<endl;
    }


    return 0;
}
