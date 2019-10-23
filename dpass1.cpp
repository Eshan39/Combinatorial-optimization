#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;

    while(test--)
    {
        int m;
        cin>>m;
        int sales[31];
        int result=0;
        int price[31] ,weight[31];
        for(int i=0;i<m;i++){

            cin>>price[i]>>weight[i];

        }
        memset(sales, 0, sizeof (sales));
        for ( int j = 0; j < m; j++ ) {
            for ( int i = 30; i >= 0; i-- ) {
                if ( weight [j] <= i && sales [i] < sales [i - weight [j]] + price [j] )
                    sales [i] = sales [i - weight [j]] + price [j];
            }
        }
        int groupMembers;
        cin>>groupMembers;

        while(groupMembers--){
            int n;
            cin>>n;
            result=result+sales[n];
        }
        cout<<result<<endl;

    }



    return 0;
}
