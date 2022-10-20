#include <iostream>

using namespace std;

struct node
{
    int val;
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

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *i = head;
            node *j;
            for (i; i->next != NULL && temp->val > i->val; i = i->next)
            {
                j = i;
            }

            if (i == head)
            {
                if (temp->val > i->val)
                {
                    temp->next = i->next;
                    i->next = temp;
                }
                else
                {
                    temp->next = head;
                    head = temp;
                }
            }
            else
            {
                if (i->next != NULL)
                {
                    j->next = temp;
                    temp->next = i;
                }
                else
                {
                    if (temp->val > i->val)
                    {
                        i->next = temp;
                    }
                    else
                    {
                        j->next = temp;
                        temp->next = i;
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
                break;
            }
            else if (req == i->val)
            {
                j->next = i->next;
                cout << req << " Deleted" << endl;
                break;
            }
            else
            {
                cout << "Val not Found" << endl;
            }
            j = i;
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
    l1.del();
    l1.show();

    return 0;
}