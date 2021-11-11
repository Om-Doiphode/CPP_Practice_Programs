#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
    }
};
void insertatHead(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void inseratatTail(Node *&head, int val)
{
    if (head == NULL)
    {
        insertatHead(head, val);
        return;
    }
    Node *n = new Node(val);
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void deleteatHead(Node *&head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}
void deletion(Node *&head, int pos)
{
    if (pos == 1)
    {
        deleteatHead(head);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
void display(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head = NULL;
    inseratatTail(head, 1);
    inseratatTail(head, 2);
    inseratatTail(head, 3);
    display(head);
    deletion(head, 1);
    display(head);
    return 0;
}