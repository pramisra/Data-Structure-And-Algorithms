#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int Queue[MAX];
int front = -1, rear = -1;

void insertAtQueue(int val, int n)
{
    if (rear == n - 1)
    {
        cout << "Overflow" << endl;
        return;
    }
    if (front == -1 && rear == -1)
    {
        rear++;
        front++;
        Queue[rear] = val;
    }
    else
    {
        rear++;
        Queue[rear] = val;
    }
}

void deleteAtQueue(int n)
{
    if ((front == -1 && rear == -1) || (front == rear))
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        front++;
    }
}

void isFull(int n)
{
    if (rear == n - 1)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        cout << "Queue is Not Full" << endl;
    }
}

void isEmpty(int n)
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is Not Empty" << endl;
    }
}

void frontelement(int n)
{
    cout << Queue[front] << endl;
}

void rearelement(int n)
{
    cout << Queue[rear] << endl;
}

void display(int n)
{
    if (front == rear || (front == -1 && rear == -1))
    {
        cout << "No Element to Display" << endl;
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        if (i == rear)
        {
            cout << Queue[i];
            break;
        }
        cout << Queue[i] << " => ";
    }
    cout << endl;
}

int main()
{
    int ch;
    int n;
    cout << "Enter the Size of Queue :: ";
    cin >> n;
    while (1)
    {
        cout << "1:Insert in Queue" << endl;
        cout << "2:Delete in Queue" << endl;
        cout << "3:Queue is Full" << endl;
        cout << "4:Queue is Empty" << endl;
        cout << "5:Get the Front Value" << endl;
        cout << "6:Get the Rear Value" << endl;
        cout << "7:Display Queue" << endl;
        cout << "8:Exit" << endl;
        cout << "Enter the Choice :: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int a;
            cin >> a;
            insertAtQueue(a, n);
            break;
        case 2:
            deleteAtQueue(n);
            break;
        case 3:
            isFull(n);
            break;
        case 4:
            isEmpty(n);
            break;
        case 5:
            frontelement(n);
            break;
        case 6:
            rearelement(n);
            break;
        case 7:
            display(n);
            break;
        case 8:
            exit(0);
            break;
        default:
            cout << "Please Enter the Correct Choice!!!!" << endl;
            break;
        }
    }
    return 0;
}