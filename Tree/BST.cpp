#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *NewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *InsertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = NewNode(data);
    }

    else
    {
        if (root->data >= data)
        {
            root->left = InsertNode(root->left, data);
        }

        else
        {
            root->right = InsertNode(root->right, data);
        }
    }

    return root;
}

bool Search(Node *root, int data)
{
    if (root == NULL)
        return false;

    else if (root->data == data)
        return true;

    else if (root->data >= data)
        return Search(root->left, data);

    else
        return Search(root->right, data);
}

int Max(Node *root)
{
    if (root == NULL)
        return 0;

    else
    {

        if (root->right == NULL)
            return root->data;

        else
        {
            return Max(root->right);
        }
    }
}

int Min(Node *root)
{

    if (root == NULL)
        return 0;

    else
    {

        if (root->left == NULL)
            return root->data;

        else
        {
            return Min(root->left);
        }
    }

    // while(root->left!=NULL){
    //     root=root->left;
    // }
    // return root->data;
}

int FindHeight(Node *root)
{

    if (root == NULL)
        return -1;

    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    Node *root = NULL;
    root = InsertNode(root, 15);
    root = InsertNode(root, 10);
    root = InsertNode(root, 20);
    root = InsertNode(root, 12);
  //  root = InsertNode(root, 8);
    root = InsertNode(root, 17);
    root = InsertNode(root, 25);
    cout << Max(root) << endl;
    cout << Min(root) << endl;
    cout << Search(root, 35) << endl;
    cout << FindHeight(root) << endl;
}