
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
    int N;

    while(cin>>N && N)
    {
     int input,output=0;
     priority_queue<int> tQ;
     for(int i=0;i<N;i++)
     {
         cin>>input;
         tQ.push(-input);

     }
     for(int i=0;i<N-1;i++)
     {
         int a=-tQ.top();
         tQ.pop();
         int b=-tQ.top();
         tQ.pop();
         int total=a+b;
         output+=total;
         tQ.push(-total);


     }

    cout<<output<<endl;


    }


    return 0;
}
