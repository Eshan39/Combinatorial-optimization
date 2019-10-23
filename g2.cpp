#include<iostream>

using namespace std;

int main()
{

    int test;
    cin>>test;

    while(test--)
    {
        int X,i;
        cin>>X;

        int coins[X];
        for( i=0;i<X;i++){

            cin>>coins[i];
        }
        int sum=coins[0];
        int answer=1;
        for( i=1;i<X-1;i++){
			if(coins[i]+sum<coins[i+1]){
                    sum+=coins[i];
                    answer++;
            }
		}

        cout<<answer+1<<endl;;
    }



}
