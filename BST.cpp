#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
int max(int a, int b)
{
    return a > b ? a : b;
}
int height(Node *root)
{
    if (root == NULL)
        return 0;
    return (1 + max(height(root->left), height(root->right)));
}
int getBalancedFactor(Node *root)
{
    return height(root->left) - height(root->right);
}
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    x->right = T2;
    y->left = x;

    return y;
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        Node *t = new Node;
        t->data = key;
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    int bf = getBalancedFactor(root);

    // LL Rotation
    if (bf > 1 && key < root->left->data)
    {
        return rightRotate(root);
    }

    // RR rotation
    if (bf < -1 && key > root->right->data)
    {
        return leftRotate(root);
    }

    // LR Rotation
    if (bf > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Rotation
    if (bf < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node *root)
{
    if (root != NULL)
    {
        preOrder(root->left);
        cout << root->data << " ";
        preOrder(root->right);
    }
}
Node *search(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else if (key > root->data)
        return search(root->right, key);
}
Node *inOrderPredecessor(Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
Node *inOrderSuccessor(Node *root)
{
    root = root->right;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else
    {
        Node *iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}
Node *deleteAVLNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (!root->left && !root->right)
    {
        delete root;
        return NULL;
    }
    if (key < root->data)
        root->left = deleteAVLNode(root->left, key);
    else if (key > root->data)
        root->right = deleteAVLNode(root->right, key);
    else
    {
        Node *iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteAVLNode(root->left, key);
    }
    int bf = getBalancedFactor(root);

    // LL Rotation
    if (bf > 1 && key < root->left->data)
    {
        return rightRotate(root);
    }

    // RR rotation
    if (bf < -1 && key > root->right->data)
    {
        return leftRotate(root);
    }

    // LR Rotation
    if (bf > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Rotation
    if (bf < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
bool isBst(Node *root)
{
    if (root == NULL)
        return false;
    // In a BST, the maximum of left subtree is smaller than the root node
    if (inOrderPredecessor(root)->data > root->data)
        return false;
    // In a BST, the minimum of right subtree is greater than the root node
    if (inOrderSuccessor(root)->data < root->data)
        return false;
    return true;
}
int main()
{
    Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    cout << "PreOrder: ";
    preOrder(root);
    cout << "\nInOrder: ";
    inOrder(root);
    root = deleteAVLNode(root, 4);
    cout << "\nPreOrder: ";
    preOrder(root);
    cout << "\n InOrder: ";
    inOrder(root);
}