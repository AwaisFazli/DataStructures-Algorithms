#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class queue
{
    node *rear, *front;

public:
    queue()
    {
        rear = NULL;
        front = NULL;
    }

    void qinsert()
    {
        node *temp;
        temp = new node;
        cout << "Value: ";
        cin >> temp->data;
        temp->next = NULL;

        if (rear == NULL)
        {
            rear = temp;
            front = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    void qdelete()
    {
        if (front != NULL)
        {
            node *temp = front;
            cout << temp->data << endl;
            front = front->next;

            if (front == NULL)
            {
                rear = NULL;
            }
        }
        else
        {
            cout << "QUEUE is EMPTY" << endl;
        }
    }

    void peek()
    {
        cout << front->data << endl;
    }
};

int main()
{
    queue q;
    q.qinsert();
    // q.qinsert();
    q.qdelete();
    q.qdelete();

    return 0;
}
