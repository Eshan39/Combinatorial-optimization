#include<iostream>
#include<queue>

using namespace std;

void push(int i)
{
    r++;
    e++;
    if(r>=MAX)
    {
        r=1;
    }
    que[r]=1;
}
int pop()
{
    e--;
    int i=que[f];
    f++;
    if(f>=MAX)
    {
        f=1;
    }

    return i;
}

int main(void)
{
    int N,m;
    int que[MAX];
    int f,r,e;


    while(1)
    {
        cin>>N;
        if(N==0) break;
        queue <int> regionQ;
        for(int i=1;i<=N;i++)
        {
            que[i]=i;
            push(i);
            int k= (i+N)%N;

        }


    }


    return 0;
