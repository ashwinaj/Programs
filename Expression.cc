#include<cstdio>
#include<cstdlib>
#include<stack>
#include<string>
#include<iostream>

using namespace std;

typedef enum
{
    INFIX =0,
    PREFIX,
    POSTFIX
}type_t;

class Expression
{
    public:
            Expression(){}
            Expression(std::string aInExpression, type_t t)
            {
                this->str = aInExpression;
                this->t = t;
            }

            virtual ~Expression(){} 

            void EvaluatePostfix();
            void EvaluateInfix();
            int precedence(char aInCh);

    private:

            std::string str;
            type_t t;
            bool isOperand(char ch);

};

int Expression::precedence(char aInCh)
{
    switch(aInCh)
    {
        case '+':
        case '-':
                    return 1;
        case '*':
        case '/':

                    return 2;
        case '^':
                    return 2; 
    
    }
}

bool Expression::isOperand(char ch)
{
    if(ch == '^' ||ch == '*' ||ch == '/' ||ch == '+' ||ch == '-')
        return false;
    else
        return true;

}

void Expression::EvaluatePostfix()
{
    if(t != POSTFIX)
        return;

    stack<char> st;
    int lResult;

    for(int i=0;i<str.length();i++)
    {
        if(isOperand(str[i]))
            st.push(str[i]);
        else
        {
            if(st.empty())
                return;

            char lB = st.top();
            st.pop();

            if(st.empty())
                return;

            char lA = st.top();
            st.pop();  

            lResult = 0;

            switch(str[i])
            {
                case '^':
                            lResult = (lA - '0')^(lB - '0');
                            break;
                case '*':
                            lResult = (lA - '0') * (lB - '0');
                            break;
                case '/':
                            lResult = (lA - '0')/(lB - '0');
                            break;
                case '+':
                            lResult = (lA - '0') + (lB - '0');
                            break;
                case '-':
                            lResult = (lA - '0') - (lB - '0');
                            break;

            }

            st.push(lResult+'0');

        }
        
    }
    
    lResult = st.top()-'0';
    cout<<endl<<lResult<<endl;
    st.pop();
}

void Expression::EvaluateInfix()
{
    stack<char> st;
    cout<<endl;

    for(int i=0;i<str.length();i++)
    {
        if(isOperand(str[i]))
            cout<<str[i]<<" ";
        else
        {
            if(!st.empty())
            {
                  char top = st.top();
                  if(precedence(str[i]) <= precedence(top) && str[i] != '^')
                  {
                      cout<<top;
                      st.pop();
                      st.push(str[i]);
                  }
                  else
                  {
                      st.push(str[i]);
                  }
            
            }
            else
                st.push(str[i]);
        }
    }

    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }

    cout<<endl;

 return;
}

int main()
{
    Expression e("345+*", POSTFIX);
    Expression f("3+4*5^7+2-8*7+3", INFIX);

    e.EvaluatePostfix();
    f.EvaluateInfix();

    return 0;
}
