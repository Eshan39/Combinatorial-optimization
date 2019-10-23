 #include <iostream>

using namespace std;


int main()
{
    int  mways[30001];

    int change[] = {1, 5, 10, 25, 50};

    mways[0] = 1;

    for (int coin = 0; coin < 5; coin++)
    {
        for (int i = change[coin]; i < 30001; i++)
        {

            mways[i] += mways[i - change[coin]];

        }
    }

    int ncents;

    while (cin >> ncents)
    {
        if (mways[ncents] == 1){

            cout << "1 way " <<endl;
        }
        else
            cout  << mways[ncents] << " ways "<<endl;
    }


    return 0;
}
