#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class Stack
{
    node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push()
    {
        node *temp = new node;
        cout << "Value: ";
        cin >> temp->data;
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if (top != NULL)
        {
            node *temp = top;
            top = top->next;
            cout << temp->data;
            delete temp;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }

    void peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << top->data << endl;
        }
    }
};

int main()
{
    Stack st;
    st.push();
    st.push();
    st.pop();
    st.pop();
    st.pop();

    return 0;
}
