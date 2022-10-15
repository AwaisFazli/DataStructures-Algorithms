#include <iostream>
using namespace std;

int size = 20;
char stack[50];
char bstack[20];
char btop = -1;
int top = -1;
string expression = "a+[b*{c^d%(e/f*g)-h}]";
char postfix[40];
int postop = -1;
char validation[50];
int validtop = -1;

char evalstack[50];
int evaltop = -1;

void pusheval(char x)
{
    evaltop++;
    evalstack[evaltop] = x;
}

char popeval()
{
    char temp = evalstack[evaltop];
    evaltop--;
    return temp;
}

void evaluate(char ope)
{
    if (ope == '+')
    {
        char val1 = popeval();
        int val3 = val1 - '0';
        char val2 = popeval();
        int val4 = val2 - '0';
        int res = val3 + val4;
        char res1 = res + 48;
        pusheval(res1);
    }
    else if (ope == '-')
    {
        char val1 = popeval();
        // cout<<"val1 = "<<val1<<endl;
        int val3 = val1 - '0';
        // cout<<"val3 = "<<val3<<endl;
        char val2 = popeval();
        // cout<<"val2 = "<<val2<<endl;
        int val4 = val2 - '0';
        // cout<<"val4 = "<<val4<<endl;
        int res = val3 - val4;
        // cout<<"res = "<<res<<endl;
        char res1 = res + 48;
        // cout<<"res` = "<<res1<<endl;
        pusheval(res1);
    }
    else if (ope == '/')
    {
        char val1 = popeval();
        int val3 = val1 - '0';
        char val2 = popeval();
        int val4 = val2 - '0';
        int res = val3 / val4;
        char res1 = res + 48;
        pusheval(res1);
    }
    else if (ope == '%')
    {
        char val1 = popeval();
        int val3 = val1 - '0';
        char val2 = popeval();
        int val4 = val2 - '0';
        int res = val3 % val4;
        char res1 = res + 48;
        pusheval(res1);
    }
    else if (ope == '^')
    {
        char val1 = popeval();
        int val3 = val1 - '0';
        char val2 = popeval();
        int val4 = val2 - '0';
        int res = val3 ^ val4;
        char res1 = res + 48;
        pusheval(res1);
    }
    else if (ope == '+')
    {
        char val1 = popeval();
        int val3 = val1 - '0';
        char val2 = popeval();
        int val4 = val2 - '0';
        int res = val3 + val4;
        char res1 = res + 48;
        pusheval(res1);
    }
}

void pushValid(char x)
{
    validtop++;
    validation[validtop] = x;
}

int priority(char x)
{

    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else
    {
        // (x == "^" ||  x == "%")
        return 3;
    }
}

int bpriority(char x)
{
    if (x == '[' || x == ']')
    {
        return 1;
    }
    else if (x == '{' || x == '}')
    {
        return 2;
    }
    else
    {
        // (x == '(' ||  x == ')')
        return 3;
    }
}

int isNonAlpha(char x)
{
    if (x == '{' || x == '}' || x == '(' || x == ')' || x == '[' || x == ']' || x == '+' || x == '-' || x == '/' || x == '*' || x == '%' || x == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isBracket(char x)
{
    if (x == '{' || x == '}' || x == '(' || x == ')' || x == '[' || x == ']')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOperator(char x)
{
    if (x == '+' || x == '-' || x == '/' || x == '*' || x == '%' || x == '^')
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

void bpush(char x)
{
    btop++;
    bstack[btop] = x;
}

char bpop()
{
    char temp = bstack[top];
    btop--;
    return temp;
}
void pushpost(char x)
{
    postop++;
    postfix[postop] = x;
}

char pop()
{

    char temp = stack[top];
    top--;
    return temp;
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

int isbEmpty()
{
    if (btop == -1)
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
    int b_len = sizeof(bstack) / sizeof(bstack[0]) - 1;

    // VALIDATION OF EXPRESSION

    int error = 0;
    for (int i = 0; i < exp_len; i++)
    {

        if (!isNonAlpha(expression[i]))
        {
            pushValid(expression[i]);
        }
        else if (isOperator(expression[i]))
        {
            if (!isNonAlpha(validation[validtop]))
            {
                pushValid(expression[i]);
            }
            else
            {
                // cout << "Dual operator"<< endl;
                error++;
            }
        }

        else if (isBracket(expression[i]))
        {

            if (isClosing(expression[i]) && isbEmpty())
            {
                // cout << "Closing first"<<endl;
                error++;
            }

            else if (isClosing(expression[i]))
            {
                if (bpriority(expression[i]) == bpriority(bstack[btop]))
                {
                    bpop();
                }
                else if (bpriority(expression[i]) != bpriority(bstack[btop]))
                {
                    // cout << "braceket doesnt match" <<endl;
                    error++;
                }
            }

            else if (isbEmpty())
            {
                pushValid(expression[i]);
                bpush(expression[i]);
            }
            else if (!isbEmpty())
            {

                if (bpriority(expression[i]) > bpriority(bstack[btop]))
                {
                    pushValid(expression[i]);
                    bpush(expression[i]);
                }
                else
                {
                    // cout << "lesser priority first"<<endl;
                    error++;
                }
            }
        }
    }

    string check = "NONE";
    if (error > 0)
    {
        check = "INVALID";
    }
    else
    {
        cout << "The expression is valid" << endl;
        check = "VALID";
    }

    // CONVERSION TO POSTFIX

    if (check == "VALID")
    {

        for (int i = 0; i < exp_len; i++)
        {
            if (!isNonAlpha(expression[i]))
            {
                pushpost(expression[i]);
            }
            else if (isNonAlpha(expression[i]))
            {
                if (isEmpty())
                {
                    push(expression[i]);
                }
                else if (!isEmpty())
                {
                    if (isOperator(expression[i]))
                    {
                        if (isBracket(stack[top]))
                        {
                            push(expression[i]);
                        }
                        else
                        {
                            if (priority(stack[top]) < priority(expression[i]))
                            {
                                push(expression[i]);
                            }
                            else
                            {
                                pushpost(pop());
                                i--;
                            }
                        }
                    }
                    else if (isBracket(expression[i]))
                    {
                        if (!isClosing(expression[i]))
                        {
                            push(expression[i]);
                        }
                        else if (isClosing(expression[i]))
                        {

                            int j = top;
                            while (j > 0)
                            {

                                char temp = stack[j];

                                if (!isBracket(temp))
                                {
                                    pushpost(pop());
                                }
                                else
                                {
                                    pop();
                                    break;
                                }
                                j--;
                            }
                        }
                    }
                }
            }
            cout << endl;
            cout << postfix << endl;
        }
    }
    else
    {
        cout << "Please Enter Valid Expression For Further Processing" << endl;
    }
    if (top != -1)
    {
        int temp = top;
        while (temp != -1)
        {
            pushpost(pop());
            temp--;
        }
    }
    cout << endl;
    cout << "Final Result is: " << postfix << endl;

    // EVALUATION

    string test = "24-4+16+-";
    int test_len = test.length();

    for (int i = 0; i < test_len; i++)
    {
        if (!isOperator(test[i]))
        {
            pusheval(test[i]);
        }
        else if (isOperator(test[i]))
        {
            evaluate(test[i]);
        }
        for (int k = 0; k <= evaltop; k++)
        {
            cout << evalstack[k];
        }
        cout << endl;
    }
    cout << "The Evaluated Result is: " << evalstack[0] << endl;
}