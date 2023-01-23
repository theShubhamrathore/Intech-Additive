#include <stdio.h>
#include<bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node *head, int n);
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, k;
    cin >> T;
    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;
        cin >> n >> k;
        int firstdata;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }


        cout << getNthFromLast(head, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node *slow = head;
    Node *fast = head;
    int i = 1, odd = 0;
    while (fast != NULL && fast->next != NULL)
    {
        if (!fast->next)
        {
            odd = 0;
            break;
        }
        if (!fast->next->next)
        {
            odd = 1;
            break;
        }
        i++;
        if (slow->next)
            slow = slow->next;
        if (fast->next->next)
            fast = fast->next->next;
    }
    int t;
    if (odd == 0)
    {
        t = i * 2 - 1;
    }
    else
        t = i * 2;
    if (t < n)
        return -1;
    int x = t - n + 1;
    if (x >= i)
    {
        x -= i;
        while (x--)
        {
            slow = slow->next;
        }
    }
    else
    {
        slow = head;
        x -= 1;
        while (x--)
        {
            slow = slow->next;
        }
    }
    return slow->data;
}
