#include <bits/stdc++.h>
using namespace std;

class dnode
{
public:
    int data;
    dnode *left;
    dnode *right;

    dnode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

dnode *head = NULL;

void insertAtHead(int val, dnode *&head)
{
    dnode *n;
    n = new dnode(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    else
    {
        n->right = head;
        // n->left = NULL;
        head->left = n;
        head = n;
    }
}

void insertAtTail(int val, dnode *&head)
{
    dnode *n;
    n = new dnode(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    else
    {
        dnode *temp;
        temp = head;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = n;
        n->left = temp;
    }
}

void insertAfterPos(int val, int pos, dnode *&head)
{
    dnode *n;
    n = new dnode(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    else
    {
        dnode *temp;
        temp = head;
        for (int i = 0; temp != NULL && i <= pos - 1; i++)
        {
            temp = temp->right;
        }
        n->right = temp;
        n->left = temp->left;
        temp->left = n;
        temp->left->right = n;
    }
}

void insertBeforePos(int val, dnode *&head, int pos)
{
    dnode *n;
    n = new dnode(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    else
    {
        dnode *temp;
        temp = head;
        for (int i = 0; temp != NULL && i < pos - 1; i++)
        {
            temp = temp->right;
        }
        n->right = temp->right;
        temp->right->left = n;
        n->left = temp;
        temp->right = n;
    }
}

void display(dnode *&head)
{
    if (head == NULL)
    {
        cout << "No Element for Display for Reverse" << endl;
        return;
    }
    else
    {
        dnode *temp;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " => ";
            temp = temp->right;
        }
        cout << "NULL" << endl;
    }
}

void reverseList(dnode *&head)
{
    if (head == NULL)
    {
        cout << "No Element for Display for Reverse" << endl;
        return;
    }
    else
    {
        dnode *temp;
        temp = head;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        while (temp != NULL)
        {
            cout << temp->data << " => ";
            temp = temp->left;
        }
        cout << "NULL" << endl;
        // display(temp);
    }
}

void sizeOfList(dnode *&head)
{
    int c = 0;
    dnode *temp;
    temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->right;
    }
    cout << "Size of List :: " << c << endl;
}

void isEmpty(dnode *&head)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        cout << "List is not Empty" << endl;
    }
}

void deleteAthead(dnode *&head)
{
    if (head == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        dnode *temp;
        temp = head;
        head = temp->right;
        temp->right->left = NULL;
        temp->right = NULL;
    }
}

void deleteAttail(dnode *&head)
{
    if (head == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        dnode *temp;
        temp = head;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->left->right = NULL;
        temp->left = NULL;
    }
}

void deleteAfterGiven(int pos, dnode *&head)
{
    if (head == NULL)
    {
        cout << "UnderFlow" << endl;
    }
    else
    {
        dnode *temp;
        temp = head;
        for (int i = 0; temp != NULL && i <= pos; i++)
        {
            temp = temp->right;
        }
        temp->right->left = temp->left;
        temp->left->right = temp->right;
        temp->left = NULL;
        temp->right = NULL;
    }
}

void deleteBeforePos(int pos, dnode *&head)
{
    if (head == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        dnode *temp;
        temp = head;
        for (int i = 0; temp != NULL && i < pos - 1; i++)
        {
            temp = temp->right;
        }
        temp->right->left = temp->left;
        temp->left->right = temp->right;
        temp->left = NULL;
        temp->right = NULL;
    }
}

int main()
{
    int ch;
    while (1)
    {
        cout << "--------DOUBLY LINKED LIST--------" << endl;
        cout << "1:Insertion at Head" << endl;
        cout << "2:Insertion at Tail" << endl;
        cout << "3:Insertion After at Given Position" << endl;
        cout << "4:Insertion Before at Given Position" << endl;
        cout << "5:Deletion at Head" << endl;
        cout << "6:Deletion at Tail" << endl;
        cout << "7:Deletion After at Given Position" << endl;
        cout << "8:Deletion Before at Given Position" << endl;
        cout << "9:List is Empty" << endl;
        cout << "10:Size of List" << endl;
        cout << "11:Display the List" << endl;
        cout << "12:Reverse of Linked List" << endl;
        cout << "13:Exit" << endl;
        cout << "Enter the Following Option :: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            int a;
            cin >> a;
            insertAtHead(a, head);
            break;
        case 2:
            int b;
            cin >> b;
            insertAtTail(b, head);
            break;
        case 3:
            int c, p;
            cin >> c >> p;
            insertAfterPos(c, p, head);
            break;
        case 4:
            int d, pos;
            cin >> d >> pos;
            insertBeforePos(d, head, pos);
            break;
        case 5:
            deleteAthead(head);
            break;
        case 6:
            deleteAttail(head);
            break;
        case 7:
            int po;
            cin >> po;
            deleteAfterGiven(po, head);
            break;
        case 8:
            int pi;
            cin >> pi;
            deleteBeforePos(pi, head);
            break;
        case 9:
            isEmpty(head);
            break;
        case 10:
            sizeOfList(head);
            break;
        case 11:
            display(head);
            break;
        case 12:
            reverseList(head);
            break;
        case 13:
            exit(0);
            break;
        default:
            cout << "Please enter the correct Choice!!!!" << endl;
            break;
        }
    }
    return 0;
}