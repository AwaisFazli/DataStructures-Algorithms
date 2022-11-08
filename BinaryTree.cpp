#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class BST
{
public:
    node *root = NULL;

    void insert(int val)
    {
        node *temp = new node;
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;

        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            node *i = root;
            node *j = root;

            while (i != NULL)
            {
                j = i;
                if (temp->data < i->data)
                {
                    i = i->left;
                }
                else
                {
                    i = i->right;
                }
            }

            if (temp->data < j->data)
            {
                j->left = temp;
            }
            else
            {
                j->right = temp;
            }
        }
    }

    void leftSuccessor()
    {
        node *temp;
        for (node *i = root->left; i != NULL; i = i->right)
        {
            temp = i;
        }
        cout << temp->data << endl;
    }
    void rightSuccessor()
    {
        node *temp;
        for (node *i = root->right; i != NULL; i = i->left)
        {
            temp = i;
        }
        cout << temp->data << endl;
    }
};

int main()
{
    BST b1;
    b1.insert(5);
    b1.insert(3);
    b1.insert(2);
    b1.insert(4);
    b1.insert(7);
    b1.insert(6);
    b1.insert(8);

    b1.leftSuccessor();
    b1.rightSuccessor();

    /* Tree Structure
           5
         /   \
        3    7
      /  \  / \
     2   4 6   8  */

    return 0;
}
