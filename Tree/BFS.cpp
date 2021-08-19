#include <iostream>
#include <algorithm>
#include <queue>
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

void BFS(Node *root)
{

    if (root == NULL)
        return;

    else
    {

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            cout << current->data << " ";
            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
            q.pop();
        }
    }
}

bool isBSTUtil(Node *root, int minVal, int maxVal)
{

    if (root == NULL)
        return true;

    if (root->data > minVal && root->data < maxVal && isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal))
        return true;

    else
        return false;
}

bool IsBST(Node *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

Node *Min(Node *root)
{

    if (root == NULL)
        return 0;

    else
    {

        if (root->right == NULL)
            return root;

        else
        {
            return Min(root->right);
        }
    }

    // while(root->left!=NULL){
    //     root=root->left;
    // }
    // return root->data;
}

void PreOrder(Node *root)
{
    if (root == NULL)
        return;

    else
    {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(Node *root)
{
    if (root == NULL)
        return;

    else
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

void PostOrder(Node *root)
{
    if (root == NULL)
        return;

    else
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }
}

Node *Delete(Node *root, int data)
{
    if (root == NULL)
        return root;

    else if (root->data > data)
        root->left = Delete(root->left, data);

    else if (root->data < data)
        root->right = Delete(root->right, data);

    else
    {
        //No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        //One child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }

        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }

        //2 children
        else
        {
            Node *temp = Min(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }

        return root;
    }
}

int main()
{
    Node *root = NULL;
    root = InsertNode(root, 12);
    root = InsertNode(root, 5);
    root = InsertNode(root, 15);
    root = InsertNode(root, 3);
    root = InsertNode(root, 7);
    root = InsertNode(root, 1);
    root = InsertNode(root, 9);
    root = InsertNode(root, 13);
    root = InsertNode(root, 17);

    // BFS(root);
    // cout << endl;
    // PreOrder(root);
    // cout << endl;
    // InOrder(root);
    // cout << endl;
    // PostOrder(root);
    // cout << endl;

    Delete(root, 15);
    BFS(root);
    cout << endl;
    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);

    cout << endl;

    cout << IsBST(root);
}