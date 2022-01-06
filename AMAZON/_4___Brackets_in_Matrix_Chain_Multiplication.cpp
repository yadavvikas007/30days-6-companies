// Brackets in Matrix Chain Multiplication

// My Profiles--------------------------------------------------------------------
// GFG : https://auth.geeksforgeeks.org/user/vy9690703/profile
// Leetcode : https://leetcode.com/xmenvikas07/
// Codeforces : https://codeforces.com/profile/xmenvikas07
// Codechef : https://www.codechef.com/users/vikas_009

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    const static int MAX = 30;

    int dp[MAX][MAX];
    int bracket[MAX][MAX];

    int solve(int arr[], int i, int j)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int left, right;
            if (dp[i][k] != -1)
                left = dp[i][k];
            else
                left = solve(arr, i, k);
            if (dp[k + 1][j] != -1)
                right = dp[k + 1][j];
            else
                right = solve(arr, k + 1, j);
            int temp = left + right + arr[i - 1] * arr[k] * arr[j];
            if (temp < ans)
            {
                ans = temp;
                bracket[i][j] = k;
            }
        }
        return dp[i][j] = ans;
    }

    void printParenthesis(int i, int j, char &name, string &res)
    {
        if (i == j)
        {
            res.push_back(name++);
            return;
        }
        res.push_back('(');
        printParenthesis(i, bracket[i][j], name, res);
        printParenthesis(bracket[i][j] + 1, j, name, res);
        res.push_back(')');
    }

public:
    string matrixChainOrder(int p[], int n)
    {
        memset(dp, -1, sizeof(dp));
        solve(p, 1, n - 1);
        char ch = 'A';
        string res = "";
        printParenthesis(1, n - 1, ch, res);
        return res;
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
        int p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];

        Solution ob;
        cout << ob.matrixChainOrder(p, n) << "\n";
    }
    return 0;
} // } Driver Code Ends