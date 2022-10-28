#include <iostream>

using namespace std;

struct node
{
    int val;
    node *prev;
    node *next;
};

class llist
{
    node *head;

public:
    llist()
    {
        head = NULL;
    }

    void insert()
    {
        node *temp = new node;
        cout << "Enter Value ";
        cin >> temp->val;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *i = head;
            for (i; i->next != NULL && temp->val > i->val; i = i->next)
            {
                ;
            }

            if (i == head)
            {

                if (temp->val > i->val)
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
                    if (temp->val > i->val)
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

    void del()
    {
        int req;
        cout << "Which Val to be deleted ";
        cin >> req;
        node *j = head;
        node *i;
        for (i = head; i != NULL; i = i->next)
        {

            if (req == head->val)
            {
                node *temp = head;
                cout << temp->val << " Deleted" << endl;
                head = head->next;
                head->prev = NULL;
                break;
            }
            else if (req == i->val)
            {
                // j->next = i->next;
                // cout << req << " Deleted" << endl;

                if (i->next == NULL)
                {
                    i->prev->next = i->next;
                    cout << req << " Deleted" << endl;
                    break;
                }
                else
                {
                    i->prev->next = i->next;
                    i->next->prev = i->prev;
                    cout << req << " Deleted" << endl;
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
            cout << s->val << endl;
            s = s->next;
        }
    }
};

int main()
{
    llist l1;
    l1.insert();
    l1.insert();
    l1.insert();
    l1.insert();
    l1.del();
    l1.show();

    return 0;
}