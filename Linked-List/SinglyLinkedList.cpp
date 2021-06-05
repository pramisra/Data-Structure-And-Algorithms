//Singly Linked List

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *link;

    node(int val)
    {
        data = val;
        link = NULL;
    }
};

node *head = NULL;

void insertAthead(int val, node *&head)
{
    node *n;
    n = new node(val);
    if (n == NULL)
    {
        cout << "Unable to allocate memory!!!!Sorry" << endl;
        return;
    }

    else
    {
        if (head == NULL)
        {
            head = n;
            return;
        }

        else
        {
            node *temp;
            temp = head;
            n->link = temp;
            head = n;
        }
    }
}

void insertAttail(int val, node *&head)
{
    node *n;
    n = new node(val);
    if (n == NULL)
    {
        cout << "Unable to allocate memory!!!!Sorry" << endl;
        return;
    }

    else
    {
        if (head == NULL)
        {
            head = n;
            return;
        }

        else
        {
            node *temp;
            temp = head;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = n;
        }
    }
}

void insertAtafterPos(int val, node *&head, int pos)
{
    node *n;
    n = new node(val);
    if (n == NULL)
    {
        cout << "Unable to allocate memory!!!!Sorry" << endl;
        return;
    }
    else
    {
        if (head == NULL)
        {
            head == n;
            return;
        }

        else
        {
            node *temp;
            temp = head;
            while (temp != NULL)
            {
                if (temp->data == pos)
                {
                    n->link = temp->link;
                    temp->link = n;
                }
                temp = temp->link;
            }
        }
    }
}

void display(node *&head)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
    }
    node *temp;
    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " => ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

void insertbeforePos(int val, node *&head, int pos)
{
    node *n;
    n = new node(val);
    if (n == NULL)
    {
        cout << "Unable to Allocate the Memory!!!Sorry" << endl;
    }

    else
    {
        if (head == NULL)
        {
            head = n;
            return;
        }

        else
        {
            node *temp, *ptr;
            temp = head;
            while (temp != NULL)
            {
                if (temp->data == pos)
                {
                    n->link = temp;
                    ptr->link = n;
                }
                ptr = temp;
                temp = temp->link;
            }
        }
    }
}

void isEmpty(node *&head)
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

void sizeOflist(node *&head)
{
    if (head == NULL)
    {
        cout << "UnderFlow" << endl;
        return;
    }
    node *temp;
    temp = head;
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->link;
    }
    cout << "Size of List is :: " << c << endl;
}

void deleteAthead(node *&head)
{
    if (head == NULL)
    {
        cout << "UnderFlow" << endl;
    }

    else
    {
        node *temp;
        temp = head;
        head = temp->link;
        free(temp);
    }
}

void deleteAttail(node *&head)
{
    if (head == NULL)
    {
        cout << "UnderFlow" << endl;
        return;
    }
    else
    {
        node *temp, *ptr;
        temp = head;
        while (temp->link != NULL)
        {
            ptr = temp;
            temp = temp->link;
        }
        ptr->link = NULL;
        // free(ptr);
    }
}

void deleteGivenPos(int pos, node *&head)
{
    if (head == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    node *temp;
    temp = head;

    if (pos == 0)
    {
        head = temp->link;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->link;
    }
    if (temp == NULL || temp->link == NULL)
    {
        return;
    }
    node *next;
    next = temp->link->link;
    free(temp->link);
    temp->link = next;
}

void deleteBeforePos(int pos, node *&head)
{
    if (head == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    node *temp;
    temp = head;
    if (pos >= 1)
    {
        if (pos == 1)
        {
            head = temp->link;
            free(temp);
            return;
        }
        else
        {
            deleteGivenPos(pos - 1, head);
            // return;
        }
    }
    else
    {
        cout << "No Element Before First Element" << endl;
    }
}

node *reverseList(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->link;
        currptr->link = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

void reverseLinked()
{
    node *newhead = reverseList(head);
    display(newhead);
    return;
}

int main()
{
    int ch;
    while (1)
    {
        cout << "--------LINKED LIST--------" << endl;
        cout << "1:Insertion at Head" << endl;
        cout << "2:Insertion at Tail" << endl;
        cout << "3:Insertion After at Given Position" << endl;
        cout << "4:Insertion Before at Given Position" << endl;
        cout << "5:Deletion at Head" << endl;
        cout << "6:Deletion at Tail" << endl;
        cout << "7:Deletion Given Position" << endl;
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
            int c, pos;
            cin >> c >> pos;
            insertAtafterPos(c, head, pos);
            break;
        case 4:
            int d, ps;
            cin >> d >> ps;
            insertbeforePos(d, head, ps);
            break;
        case 5:
            deleteAthead(head);
            break;
        case 6:
            deleteAttail(head);
            break;
        case 7:
            int posi;
            cin >> posi;
            deleteGivenPos(posi, head);
            break;
        case 8:
            int pp;
            cin >> pp;
            deleteBeforePos(pp, head);
            break;
        case 9:
            isEmpty(head);
            break;
        case 10:
            sizeOflist(head);
            break;
        case 11:
            display(head);
            break;
        case 12:
            reverseLinked();
            break;
        case 13:
            exit(0);
            break;
        }
    }
    return 0;
}