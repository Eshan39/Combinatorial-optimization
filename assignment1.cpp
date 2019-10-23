#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){

    stack<char>mS;
    string expression;
    int test;
    cin>>test;

    for(int t=1; t<=test; t++){
        cin>>expression;

        if(expression.length()%2==1)cout<<"NO"<<endl;

        else{

            for(int i=0; i<expression.length(); i++){
                if(expression[i]=='('||expression[i]=='['){
                   mS.push(expression[i]);
                }

                else if(expression[i]==')'){
                    if(!mS.empty() || mS.top()=='(') mS.pop();
                    else mS.push(expression[i]);
                }

                else if(expression[i]==']'){
                    if(!mS.empty() || mS.top()=='[') mS.pop();
                    else mS.push(expression[i]);
                }

            }

            if(mS.empty())cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

    }

    return 0;
}
