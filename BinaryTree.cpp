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

    int leftSuccessor()
    {
        node *temp;
        for (node *i = root->left; i != NULL; i = i->right)
        {
            temp = i;
        }
        return temp->data;
    }

    int rightSuccessor()
    {
        node *temp;
        for (node *i = root->right; i != NULL; i = i->left)
        {
            temp = i;
        }
        return temp->data;
    }

    void deletion(int key)
    {
        node *temp = root;
        node *prev = root;
        while (key != temp->data)
        {
            prev = temp;
            if (key < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }

            if (temp->left == NULL && temp->right == NULL && temp->data != key)
            {
                cout << key << " Key Not Found" << endl;
                break;
            }
        }

        // If Node to be deleted has no child (Leaf Node)
        if (temp->left == NULL && temp->right == NULL)
        {
            if (prev->left->data == key)
            {
                prev->left = NULL;
            }
            else
            {
                prev->right = NULL;
            }
        }

        // If Node to be deleted has only one child
        else if (temp->left != NULL && temp->right == NULL)
        {
            if (prev->left->data == key)
            {
                prev->left = temp->left;
            }
            else
            {
                prev->right = temp->left;
            }
        }
        else if (temp->left == NULL && temp->right != NULL)
        {
            if (prev->left->data == key)
            {
                prev->left = temp->right;
            }
            else
            {
                prev->right = temp->right;
            }
        }

        // If Node to be deleted has two children
        else
        {
            node *prev2;
            for (node *l = temp->left; l != NULL; l = l->right)
            {
                prev2 = l;
                temp->data = l->data;
            }
            if (prev2->left->data == temp->data)
            {
                prev2->left = NULL;
            }
            else
            {
                prev2->right = NULL;
            }
        }
    }
};

int main()
{
    BST b1;
    b1.insert(5);
    b1.insert(3);
    b1.insert(2);
    b1.insert(4);
    b1.insert(9);
    b1.insert(6);
    b1.insert(8);
    b1.insert(7);
    b1.insert(12);
    b1.deletion(9);
    b1.deletion(6);
    b1.deletion(7);
    cout << b1.leftSuccessor() << endl;
    cout << b1.rightSuccessor() << endl;

    /* Tree Structure
           5
         /   \
        3     9
      /  \   / \
     2   4  7   12
           / \
          6   8      */

    return 0;
}

// v1.0 = Created Tree and added Insertion Function
// v1.2 = Added Functions to find Successors
// v2.0 = Added Function to delete a member
// v2.1 = Fixed Some Bugs in Delete Function