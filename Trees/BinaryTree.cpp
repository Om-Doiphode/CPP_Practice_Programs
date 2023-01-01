#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
Node *create()
{
    Node *p;
    Node *t;
    int x;
    queue<Node *> q;

    Node *root = new Node;
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
    return root;
}
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}
void iterativePreOrder(Node *root)
{
    stack<Node *> st;
    while (root != NULL || !st.empty())
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            st.push(root);
            root = root->lchild;
        }
        else
        {
            root = st.top();
            st.pop();
            root = root->rchild;
        }
    }
}
void postOrder(Node *root)
{
    if (root != NULL)
    {
        preOrder(root->lchild);
        preOrder(root->rchild);
        cout << root->data << " ";
    }
}
void inOrder(Node *root)
{
    if (root != NULL)
    {
        preOrder(root->lchild);
        cout << root->data << " ";
        preOrder(root->rchild);
    }
}
void iterativeInOrder(Node *root)
{
    stack<Node *> st;
    while (root != NULL || !st.empty())
    {
        if (root != NULL)
        {
            st.push(root);
            root = root->lchild;
        }
        else
        {
            root = st.top();
            st.pop();
            cout << root->data << " ";
            root = root->rchild;
        }
    }
}
void LevelOrder(Node *root)
{
    queue<Node *> q;
    cout << root->data << " ";
    q.emplace(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        if (root->lchild)
        {
            cout << root->lchild->data << " ";
            q.emplace(root->lchild);
        }
        if (root->rchild)
        {
            cout << root->rchild->data << " ";
            q.emplace(root->rchild);
        }
    }
}
int countLeafNodes(Node *root)
{
    if (root != NULL)
    {
        if (root->lchild == NULL && root->rchild == NULL)
            return countLeafNodes(root->lchild) + countLeafNodes(root->rchild) + 1;
        else
            return countLeafNodes(root->lchild) + countLeafNodes(root->rchild);
    }
    return 0;
}
int countDeg2Nodes(Node *root)
{
    if (root != NULL)
    {
        if (root->lchild != NULL && root->rchild != NULL)
            return countDeg2Nodes(root->lchild) + countDeg2Nodes(root->rchild) + 1;
        else
            return countDeg2Nodes(root->lchild) + countDeg2Nodes(root->rchild);
    }
    return 0;
}
int countDeg1Nodes(Node *root)
{
    if (root != NULL)
    {
        if (root->lchild != NULL ^ root->rchild != NULL)
            return countDeg1Nodes(root->lchild) + countDeg1Nodes(root->rchild) + 1;
        else
            return countDeg1Nodes(root->lchild) + countDeg1Nodes(root->rchild);
    }
    return 0;
}
int main()
{
    Node *root = create();
    preOrder(root);
    cout << endl;
    LevelOrder(root);
    cout << "\nPreOrder: " << endl;
    iterativePreOrder(root);
    cout << "Leaf Nodes count: " << countLeafNodes(root) << endl;
    cout << "Deg 2 Nodes count: " << countDeg2Nodes(root) << endl;
    cout << "Deg 1 Nodes count: " << countDeg1Nodes(root) << endl;
}