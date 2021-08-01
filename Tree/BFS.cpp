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

// bool IsBST(Node *root){

//     if(root==NULL) return false;

//     else{

//         if()
//     }
// }

Node *Delete(Node *root, int data){
    
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

int main()
{
    Node *root = NULL;
    root = InsertNode(root, 15);
    root = InsertNode(root, 10);
    root = InsertNode(root, 20);
    root = InsertNode(root, 12);
    root = InsertNode(root, 8);
    root = InsertNode(root, 17);
    root = InsertNode(root, 25);
    root = InsertNode(root, 13);
    root = InsertNode(root, 16);

    BFS(root);
    cout << endl;
    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
}