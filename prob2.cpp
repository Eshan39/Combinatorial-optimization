#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

int lowerPrecedence(char symbol)
{
    if(symbol=='+'||symbol=='-') return 1;
    else if (symbol=='*'||symbol=='/') return 2;
    else if (symbol=='^') return 3;
}
int main(void)
{
    int test;
    cin>>test;
    stack<char> mS;
    vector<char> output;
    string expression;

    for(int t=1;t<=test;t++)
    {
        cin>>expression;
        for(int i=0;i<expression.length();i++)
        {

            if( expression[i]=='+' || expression[i]=='-' || expression[i]=='*' || expression[i]=='/' || expression[i]!='^')
            {
               while( !mS.empty() && lowerPrecedence(mS.top()) >= lowerPrecedence(expression[i]) ){
                    output.push_back(mS.top());
                    mS.pop();
                }
                mS.push(expression[i]);
            }

            else if(expression[i]=='(') mS.push(expression[i]);

            else if(expression[i]==')')
            {
                while(mS.top()!='(')
                {
                    output.push_back(mS.top());
                    mS.pop();
                }
                mS.pop();
            }
            else mS.push(expression[i]);

        }
        while(!mS.empty()){
            output.push_back(mS.top());
            mS.pop();
        }

        for(int i=0;i<output.size();i++){
            cout<<output[i];
        }
        cout<<endl;
        while(!output.empty()){
            output.pop_back();
        }

    }



    return 0;
}
