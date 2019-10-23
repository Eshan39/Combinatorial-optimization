#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main(void)
{
    int buses,distance,bonusRate;

    while ( cin>>buses>>distance>>bonusRate&&buses&&distance&&bonusRate ) {

        int mornBuses [1000];
        int eveBuses [1000];

        for ( int i=0; i<buses;i++ ){
            cin>>mornBuses[i];
        }


        sort (mornBuses, mornBuses + buses);

        for ( int i=0; i<buses;i++ ){
            cin>>eveBuses[i];
        }

        sort (eveBuses, eveBuses+buses);

        int answer = 0;

        for ( int i=0; i<buses;i++ ){
            int tempDistance = mornBuses[i] + eveBuses [buses - i - 1];

            if (tempDistance>distance)
                answer+=(tempDistance-distance);
        }
        int result=answer*bonusRate;

        cout<<result;

    }

    return 0;
}
