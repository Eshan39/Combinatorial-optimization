#include<iostream>
#include<algorithm>

using namespace std;

int a[1000];
int b[100];

int knapSack(int m, int mid){
    for(int i = 0; i<= mid; i++){
        a[i] = 0;;
    }

    for(int i = 1; i<= m; i++)
        for(int j = mid; j>0; j--){
            if(b[i]<= j) a[j] = max(a[j], b[i] + a[j - b[i]]);
        }
   return a[mid];
}

int main()
{
    int test;
    int sum=0;

    while(test--)
    {
        int m;
        cin>>m;
        int arr[m];
        for(int i=0;i<m;i++){
            //int n;
            //cin>>n;
            cin>>b[i];
            sum+=b[i];

        }
        int mid=sum/2;

        //cout<<mid<<endl;
        knapSack(m, sum/2);

        int mn=2*knapSack(m, sum/2);
        int difference=sum-mn;
        cout<<difference<<endl;

    }

    return 0;
}
