#include<iostream>
#include<algorithm>
#include<map>


using namespace std;

int main()
{
    int length,gasStation;

    while(cin>>length>>gasStation &&(length&&gasStation)){

        int x,r;
        pair<int,int> Pair[100000];

        for(int i=0;i<gasStation;i++){
                cin>>x>>r;
                Pair[i]=make_pair(x-r,x+r);
        }
        sort(Pair,Pair + gasStation);

        int positionNow = 0,temp,i = 0,ans=gasStation;

        while(positionNow < length){
            temp = positionNow;

            while(i < gasStation && Pair[i].first <= positionNow)
                temp = max(temp,Pair[i++].second);

            if(temp == positionNow) break;

            positionNow = temp;
            ans--;
        }

        if(positionNow < length) cout<<"-1"<<endl;
        else cout<<ans<<endl;40 3


    }

}
