#include <iostream>
using namespace std;

int size = 20;
char stack[50];
int top = -1;
string expression = "a+[b*{c^d%(e/f*g)-h}]";
char postfix[40];
int postop = -1;

int priority(char x)
{
    if (x == '[' || x == ']')
    {
        return 1;
    }
    else if (x == '{' || x == '}')
    {
        return 2;
    }
    else if (x == '(' || x == ')')
    {
        return 3;
    }

    else if (x == '+' || x == '-')
    {
        return 4;
    }
    else if (x == '*' || x == '/')
    {
        return 5;
    }
    else
    {
        // (x == "^" ||  x == "%")
        return 6;
    }
}

int isOperator(char x)
{
    if (x == '+' || x == '-' || x == '/' || x == '*' || x == '%' || x == '^' || x == '{' || x == '}' || x == '(' || x == ')' || x == '[' || x == ']')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char x)
{
    top++;
    stack[top] = x;
}

void pushpost(char x)
{
    postop++;
    postfix[top] = x;
}

void pop()
{
    cout << stack[top];
    top--;
}

void peek()
{
    cout << stack[top];
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isClosing(char x)
{
    if (x == ')' || x == '}' || x == ']')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    int exp_len = expression.length();
    int stk_len = sizeof(stack) / sizeof(stack[0]) - 1;

    for (int i = 0; i < exp_len; i++)
    {
        pushpost(expression[i]);
    }
    for (int i = 0; i < exp_len; i++)
    {
        cout << postfix[i];
    }
}