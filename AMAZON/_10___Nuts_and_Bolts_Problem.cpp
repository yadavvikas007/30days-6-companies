// Nuts and Bolts Problem

// My Profiles--------------------------------------------------------------------
// GFG : https://auth.geeksforgeeks.org/user/vy9690703/profile
// Leetcode : https://leetcode.com/xmenvikas07/
// Codeforces : https://codeforces.com/profile/xmenvikas07
// Codechef : https://www.codechef.com/users/vikas_009

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
    int partition(char array[], int low, int high, char pivot)
    {
        int i = low;
        for (int j = low; j < high; j++)
        {
            if (array[j] < pivot)
                swap(array[i++], array[j]);
            else if (array[j] == pivot)
                swap(array[j--], array[high]);
        }
        swap(array[i], array[high]);
        return i;
    }

    void quicksort(char nuts[], char bolts[], int l, int h)
    {
        if (l >= h)
            return;
        int pos = partition(nuts, l, h, bolts[h]);
        partition(bolts, l, h, nuts[pos]);
        quicksort(nuts, bolts, l, pos - 1);
        quicksort(nuts, bolts, pos + 1, h);
    }

public:
    void matchPairs(char nuts[], char bolts[], int n)
    {
        quicksort(nuts, bolts, 0, n - 1);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++)
        {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++)
        {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends