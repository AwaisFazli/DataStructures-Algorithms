#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    int pwr;
    node *prev;
    node *next;
};

class llist
{

public:
    node *head;
    llist()
    {
        head = NULL;
    }

    void insert(int x, int y = 1)
    {
        node *temp = new node;
        temp->val = x;
        temp->pwr = y;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *i = head;
            for (i; i->next != NULL && temp->pwr > i->pwr; i = i->next)
            {
                ;
            }

            if (i == head)
            {

                if (temp->pwr > i->pwr)
                {
                    head->next = temp;
                    temp->prev = head;
                }
                else
                {
                    temp->next = i;
                    i->prev = temp;
                    head = temp;
                }
            }
            else
            {
                if (i->next != NULL)
                {
                    i->prev->next = temp;
                    temp->next = i;
                    i->prev = temp;
                }
                else
                {
                    if (temp->pwr > i->pwr)
                    {
                        i->next = temp;
                        temp->prev = i;
                    }
                    else
                    {
                        i->prev->next = temp;
                        temp->next = i;
                        i->prev = temp;
                    }
                }
            }
        }
    }

    void del(int cc, int pp)
    {

        node *j = head;
        node *i;
        for (i = head; i != NULL; i = i->next)
        {

            if (pp == head->pwr && cc == head->val)
            {
                node *temp = head;
                cout << cc << "x^" << pp << " Deleted" << endl;
                head = head->next;
                head->prev = NULL;
                break;
            }
            else if (pp == i->pwr && cc == head->val)
            {

                if (i->next == NULL)
                {
                    i->prev->next = i->next;
                    cout << cc << "x^" << pp << " Deleted" << endl;
                    break;
                }
                else
                {
                    i->prev->next = i->next;
                    i->next->prev = i->prev;
                    cout << cc << "x^" << pp << " Deleted" << endl;
                    break;
                }
            }
        }
    }

    void show()
    {
        node *s = head;
        while (s != NULL)
        {
            if (s->val >= 0)
            {
                cout << "+" << s->val << "x^" << s->pwr;
            }
            else
            {
                cout << s->val << "x^" << s->pwr;
            }

            s = s->next;
        }
    }
};

int isDigit(char x)
{
    if (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' || x == '9')
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
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int digitConv(char x)
{
    switch (x)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    }
}

llist tokenizer(string x)
{

    llist temp;

    string expp = x;
    int exp_len = expp.length();

    int prt1 = 0;
    int prt2 = 0;
    char sign = '+';
    int check;
    for (int i = 0; i < exp_len; i++)
    {

        for (prt2 = i; prt2 < exp_len; prt2++)
        {
            if (isOperator(expp[prt2]) || prt2 == exp_len - 1)
            {

                if (!isDigit(expp[prt2]) && prt2 == exp_len - 1)
                {
                    sign = expp[prt1 - 1];
                    if (sign == '-')
                    {
                        temp.insert(-digitConv(expp[prt1]));
                    }
                    else
                    {
                        temp.insert(+digitConv(expp[prt1]));
                    }
                }
                else if (isDigit(expp[prt2]) && prt2 == exp_len - 1)
                {
                    sign = expp[prt1 - 1];
                    if (sign == '-')
                    {
                        temp.insert(-digitConv(expp[prt1]));
                    }
                    else
                    {
                        temp.insert(+digitConv(expp[prt1]));
                    }
                }
                else if (isDigit(expp[prt1]) && isDigit(expp[prt2 - 1]))
                {
                    if (isOperator(expp[prt1 - 1]))
                    {
                        sign = expp[prt1 - 1];
                    }
                    if (sign == '-')
                    {
                        temp.insert(-digitConv(expp[prt1]), digitConv(expp[prt2 - 1]));
                    }
                    else
                    {
                        temp.insert(+digitConv(expp[prt1]), digitConv(expp[prt2 - 1]));
                    }
                }
                else if (isDigit(expp[prt1]) && isDigit(expp[prt2]))
                {
                    if (isOperator(expp[prt1 - 1]))
                    {
                        sign = expp[prt1 - 1];
                    }
                    if (sign == '-')
                    {
                        temp.insert(-digitConv(expp[prt1]), digitConv(expp[prt2]));
                    }
                    else
                    {
                        temp.insert(+digitConv(expp[prt1]), digitConv(expp[prt2]));
                    }
                }
                else if (isDigit(expp[prt1]) && !isDigit(expp[prt2]))
                {
                    sign = expp[prt1 - 1];
                    if (sign == '-')
                    {
                        temp.insert(-digitConv(expp[prt1]));
                    }
                    else
                    {
                        temp.insert(+digitConv(expp[prt1]));
                    }
                }
                prt1 = prt2 + 1;
            }
            check = prt2;
        }
        if (check == exp_len - 1)
        {
            break;
        }
    }

    return temp;
}

llist evaluate(string e1, string e2, int c)
{

    if (c == 1)
    {
        llist l1, l2;
        l1 = tokenizer(e1);
        l2 = tokenizer(e2);

        llist l3;
        node *n1 = l1.head;
        int ch = 0;
        while (n1 != NULL)
        {
            node *n2 = l2.head;
            while (n2 != NULL)
            {

                if (n1->pwr == n2->pwr)
                {
                    int v = ((n1->val) - (n2->val));
                    l3.insert(v, n2->pwr);
                    ch = 1;
                }
                n2 = n2->next;
            }
            if (ch == 0)
            {
                l3.insert(n1->val, n1->pwr);
            }
            ch = 0;
            n1 = n1->next;
        }
        return l3;
    }
    else if (c == 2)
    {
        llist l1, l2;
        l1 = tokenizer(e1);
        l2 = tokenizer(e2);

        llist l3;
        node *n1 = l1.head;
        int ch = 0;
        while (n1 != NULL)
        {
            node *n2 = l2.head;
            while (n2 != NULL)
            {

                if (n1->pwr == n2->pwr)
                {
                    int v = ((n1->val) + (n2->val));
                    l3.insert(v, n2->pwr);
                    ch = 1;
                }
                n2 = n2->next;
            }
            if (ch == 0)
            {
                l3.insert(n1->val, n1->pwr);
            }
            ch = 0;
            n1 = n1->next;
        }
        return l3;
    }
    else if (c == 3)
    {
        llist l1, l2;
        l1 = tokenizer(e1);
        l2 = tokenizer(e2);

        llist l3;
        node *n1 = l1.head;
        int ch = 0;
        while (n1 != NULL)
        {
            node *n2 = l2.head;
            while (n2 != NULL)
            {

                int v = ((n1->val) * (n2->val));
                int p = ((n1->pwr) + (n2->pwr));
                if (v >= 0)
                {
                    cout << "+" << v << "x^" << p;
                }
                else
                {
                    cout << v << "x^" << p;
                }

                n2 = n2->next;
            }

            ch = 0;
            n1 = n1->next;
        }
        cout << endl;
        return l3;
    }
}

int main()
{
    string expp1 = "4x^2+8x^5+3x^3-2x^4-7";
    string expp2 = "3x^2-4x^3-5x^4-4x^5-9";

    while (true)
    {
        int xx;
        cout << "Press 1 to Add an Element" << endl;
        cout << "Press 2 to Delete an Element" << endl;
        cout << "Press 3 to Add two Polynomials" << endl;
        cout << "Press 4 to Subtract two Polynomials" << endl;
        cout << "Press 5 to fing the Profduct of two Polynomials" << endl;
        cout << "Press 6 to Quit" << endl;
        cin >> xx;
        cout << endl;

        if (xx == 1)
        {
            string ex;
            llist jk;
            cout << "Enter Polynomial ";
            cin >> ex;
            int coef, pp;
            cout << "Enter Value For Coeffiecient ";
            cin >> coef;
            cout << "Enter Value for Exponent ";
            cin >> pp;

            jk = tokenizer(ex);
            jk.insert(coef, pp);
            jk.show();
            cout << endl
                 << endl
                 << endl;
        }
        else if (xx == 2)
        {
            string ex;
            llist jk;
            cout << "Enter Polynomial ";
            cin >> ex;
            int coef, pp;
            cout << "Enter Value For Coeffiecient to be deleted ";
            cin >> coef;
            cout << "Enter Value for Exponent to be deleted ";
            cin >> pp;

            jk = tokenizer(ex);
            jk.del(coef, pp);
            jk.show();
            cout << endl
                 << endl
                 << endl;
        }
        else if (xx == 3)
        {
            string ex1, ex2;
            llist jk;
            cout << "Enter Polynomial 1: ";
            cin >> ex1;
            cout << "Enter Polynomial 2: ";
            cin >> ex2;
            jk = evaluate(ex1, ex2, 2);
            jk.show();
            cout << endl
                 << endl
                 << endl;
        }
        else if (xx == 4)
        {
            string ex1, ex2;
            llist jk;
            cout << "Enter Polynomial 1: ";
            cin >> ex1;
            cout << "Enter Polynomial 2: ";
            cin >> ex2;
            jk = evaluate(ex1, ex2, 1);
            jk.show();
            cout << endl
                 << endl
                 << endl;
        }
        else if (xx == 5)
        {
            string ex1, ex2;
            llist jk;
            cout << "Enter Polynomial 1: ";
            cin >> ex1;
            cout << "Enter Polynomial 2: ";
            cin >> ex2;
            jk = evaluate(ex1, ex2, 3);
            jk.show();
            cout << endl
                 << endl
                 << endl;
        }
        else if (xx == 6)
        {
            break;
        }
    }

    return 0;
}