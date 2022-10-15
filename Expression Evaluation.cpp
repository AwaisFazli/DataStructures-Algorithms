#include <iostream>
using namespace std;

char stack[20];
char postfix[20];
int top = -1;

bool isOperator(char alpha)
{
    if (alpha == '+' || alpha == '-' || alpha == '^' || alpha == '%' || alpha == '/' || alpha == '*')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int precedece(char alpha)
{
    if (alpha == '+' || alpha == '-')
    {
        return 1;
    }
    else if (alpha == '*' || alpha == '/')
    {
        return 2;
    }
    else if (alpha == '%')
    {
        return 3;
    }
    else if (alpha == '^')
    {
        return 4;
    }
}

bool is_emp()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(char value)
{
    top++;
    stack[top] = value;
}

void pop() { top--; }
char peek() { return stack[top]; }

int main()
{
    cout << "Hello World";

    return 0;
}
