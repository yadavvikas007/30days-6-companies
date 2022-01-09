// Delete N nodes after M nodes of a linked list

// My Profiles--------------------------------------------------------------------
// GFG : https://auth.geeksforgeeks.org/user/vy9690703/profile
// Leetcode : https://leetcode.com/xmenvikas07/
// Codeforces : https://codeforces.com/profile/xmenvikas07
// Codechef : https://www.codechef.com/users/vikas_009

#include <iostream>
using namespace std;
/* A linked list node */

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

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void insert(int n1)
{
    int n, value;
    n = n1;
    struct Node *temp;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

class Solution
{
public:
    void linkdelete(struct Node *head, int M, int N)
    {
        Node *cur = head;
        while (cur)
        {
            // skipping M nodes
            for (int i = 1; i < M && cur; i++)
                cur = cur->next;
            if (!cur)
                return;
            Node *temp = cur;

            // deleting N nodes
            for (int i = 0; i <= N && temp; i++)
            {
                Node *next = temp->next;
                if (temp != cur)
                    delete (temp);
                temp = next;
            }

            cur->next = temp;
            cur = temp;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t, n1;
    cin >> t;
    while (t--)
    {
        cin >> n1;
        int m, n;
        cin >> m;
        cin >> n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start, m, n);
        printList(start);
    }

    return 0;
}
// } Driver Code Ends