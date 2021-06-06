#include <bits/stdc++.h>
using namespace std;

class scnode
{
public:
    int data;
    scnode *link;

    scnode(int val)
    {
        data = val;
        link = NULL;
    }
};

scnode *head = NULL;

void insertAthead(int val, scnode *&head)
{
    scnode *n;
    n = new scnode(val);
    if (head == NULL)
    {
        n->link = n;
        head = n;
        return;
    }
    scnode *temp;
    temp = head;
    while (temp->link != head)
    {
        temp = temp->link;
    }
    temp->link = n;
    n->link = head;
    head = n;
}

void insertAttail(int val, scnode *&head)
{
    scnode *n;
    n = new scnode(val);
    if (head == NULL)
    {
        insertAthead(val, head);
        return;
    }
    else
    {
        scnode *temp;
        temp = head;
        while (temp->link != head)
        {
            temp = temp->link;
        }
        temp->link = n;
        n->link = head;
    }
}

void display(scnode *&head)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    else
    {
        scnode *temp;
        temp = head;
        do
        {
            cout << temp->data << " => ";
            temp = temp->link;
        } while (temp != head);
        cout << "NULL" << endl;
    }
}

void insertAfterPos(int val, scnode *&head, int pos)
{
    scnode *n;
    n = new scnode(val);
    if (head == NULL)
    {
        n->link = n;
        head = n;
        return;
    }
    else
    {
        scnode *temp;
        temp = head;
        int i = 0;
        do
        {
            temp = temp->link;
            i++;
        } while (temp != head && i <= pos - 1);
        n->link = temp->link;
        temp->link = n;
    }
}

void insertBeforePos(int val, scnode *&head, int pos)
{
    scnode *n = new scnode(val);
    if (head == NULL)
    {
        n->link = n;
        head = n;
        return;
    }
    else
    {
        scnode *temp;
        temp = head;
        int i = 0;
        do
        {
            temp = temp->link;
            i++;
        } while (temp != head && i < pos - 1);
        n->link = temp->link;
        temp->link = n;
    }
}

void isEmpty(scnode *&head)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    else
    {
        cout << "List is not Empty" << endl;
        return;
    }
}

void sizeOfList(scnode *&head)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    scnode *temp;
    temp = head;
    int c = 0;
    do
    {
        c++;
        temp = temp->link;
    } while (temp != head);
    cout << c << endl;
}

void deleteAthead(scnode *&head)
{
    if (head == NULL)
    {
        cout << "UnderFlow" << endl;
        return;
    }
    else
    {
        scnode *temp;
        temp = head;
        scnode *p;
        p = head;
        do
        {
            p = p->link;
        } while (p->link != head);
        p->link = temp->link;
        head = temp->link;
        temp->link = NULL;
    }
}

void deleteAttail(scnode *&head, int pos)
{
    if (head == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        scnode *temp;
        temp = head;
        int c = 1;
        while (c != pos - 1)
        {
            temp = temp->link;
            c++;
        }
        scnode *newnode;
        newnode = temp->link;
        temp->link = temp->link->link;
    }
}

void deleteAfterPos(scnode *&head, int pos)
{
    if (head == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        deleteAttail(head, pos + 1);
        return;
    }
}

void deleteBeforePos(scnode *&head, int pos)
{
    if (head == NULL)
    {
        cout << "UnderFlow" << endl;
        return;
    }
    else
    {
        deleteAttail(head, pos);
        return;
    }
}

scnode *reverseCircular(scnode *&head)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        // return;
    }
    else
    {
        scnode *prevptr = NULL;
        scnode *currptr = head;
        scnode *nextptr;

        do
        {
            nextptr = currptr->link;
            currptr->link = prevptr;

            prevptr = currptr;
            currptr = nextptr;
        } while (currptr != head);
        head->link = prevptr;
        head = prevptr;
        return prevptr;
    }
}

void reverseList()
{
    scnode *newnode = reverseCircular(head);
    display(newnode);
}

int main()
{
    int ch;
    while (1)
    {
        cout << "--------SINGLY-CIRCULAR LINKED LIST--------" << endl;
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
            insertAthead(a, head);
            break;
        case 2:
            int b;
            cin >> b;
            insertAttail(b, head);
            break;
        case 3:
            int c, p;
            cin >> c >> p;
            insertAfterPos(c, head, p);
            break;
        case 4:
            int d, po;
            cin >> d >> po;
            insertBeforePos(d, head, po);
            break;
        case 5:
            deleteAthead(head);
            break;
        case 6:
            int pi;
            cin >> pi;
            deleteAttail(head, pi);
            break;
        case 7:
            int x;
            cin >> x;
            deleteAfterPos(head, x);
            break;
        case 8:
            int y;
            cin >> y;
            deleteBeforePos(head, y);
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
            reverseList();
            break;
        case 13:
            exit(0);
            break;
        default:
            cout << "Please enter the Correct Choice!!!" << endl;
            break;
        }
    }
    return 0;
}