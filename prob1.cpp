#include<iostream>
#include<stack>
#include<string>

using namespace std;
int IsOpeningParentheses(char stackSymbol)
{
    if(stackSymbol=='(') return stackSymbol;
    else return -1;
}

bool lowerPrecedence(char infixSymbol, char stackSymbol)
{
	if((infixSymbol=='/'|| infixSymbol=='*')&&(stackSymbol=='+'||stackSymbol=='-')) return true;
	else return false;
}
int main(void)
{
    int test;
    cin>>test;
    stack<char> mS;
    string expression,result;

    for(int t=1;t<=test;t++)
    {
        cin>>expression;
        for(int i=0;i<expression.length();i++)
        {

            if( expression[i]!='+' && expression[i]!='-' && expression[i]!='*' && expression[i]!='/' && expression[i]!='(' && expression[i]!=')')
            {
                result=result+expression[i];
            }
            /*
            else if(expression[i]=='+' || expression[i]=='-' && expression[i]=='*' && expression[i]=='/')
            {
                while(!mS.empty()&& !IsOpeningParentheses(mS.top()) && !lowerPrecedence(expression[i],mS.top()))
                {
                    result=result+mS.top();
                    mS.pop();
                }
                mS.push(expression[i]);
            }
            */
            else if(expression[i]=='(') mS.push(expression[i]);

            else if(expression[i]==')')
            {
                while(!mS.empty()&& mS.top()!='(')
                {
                    result=result+mS.top();
                    mS.pop();
                }
                mS.pop();
            }

        }
        cout<<result<<endl;
    }



    return 0;
}
