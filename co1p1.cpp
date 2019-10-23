#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void)
{
    int test,y=1;
    while(cin>>test && test)
    {

        int x;
        int output=0;
        queue<int> pQ;
        vector<int>myVec;

        string myString;
        for(int i=0; i<test; i++)
        {
            int N;
            cin>> N;
            for(int j = 0; j<N; j++)
            {
                int x;
                cin>> x;
                pQ.push(x);
                myVec.push_back(x);
            }
        }
        cout<<"Scenario #"<<y<<endl;
        while(cin>>myString)
        {
            if(myString=="STOP") break;
            else if(myString=="ENQUEUE")
            {
               int temp, flag = 1;
               cin>>temp;

                for(int i=0; i<myVec.size(); i++)
                {
                    if(temp == myVec[i])
                    flag = 0;
                }
                if(flag)
                {
                    pQ.push(temp);
                    myVec.push_back(temp);
                }
            }
            else if(myString=="DEQUEUE")
            {
                cout<<pQ.front()<<endl;
                pQ.pop();
            }
        }

        y++;
    }


    return 0;
}
