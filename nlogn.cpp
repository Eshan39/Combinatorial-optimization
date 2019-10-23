#include<iostream>

using namespace std;

int main()
{
    int arr[]={1,6,8,5,4};
    int you[]={7,8,6,3,2};
    int test,cnt=0;
    cin>>test;

    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        for(int j=0;j<sizeof(you)/sizeof(you[0]);j++){
            if(arr[i]+you[j]==test){
              cnt++;
            }
            //else
                //cout<<"not found"<<endl;
        }
    }

    if(cnt!=0) cout<<"matched"<<endl;


    return 0;
}
