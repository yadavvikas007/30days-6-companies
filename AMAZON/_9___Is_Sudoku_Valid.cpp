// Is Sudoku Valid

// My Profiles--------------------------------------------------------------------
// GFG : https://auth.geeksforgeeks.org/user/vy9690703/profile
// Leetcode : https://leetcode.com/xmenvikas07/
// Codeforces : https://codeforces.com/profile/xmenvikas07
// Codechef : https://www.codechef.com/users/vikas_009

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isValid(vector<vector<int>> mat)
    {
        bool row[10][10] = {false};  // row[i][j] => in i'th row is 'j' present or not
        bool col[10][10] = {false};  // col[i][j] => in i'th col is 'j' present or not
        bool grid[10][10] = {false}; // grid[i][j] => in i'th grid is 'j' present or not

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                int num = mat[i][j];
                if (num == 0)
                    continue;

                int grid_idx = (i / 3) * 3 + (j / 3);
                if (row[i][num] || col[j][num] || grid[grid_idx][num])
                    return 0;
                row[i][num] = col[j][num] = grid[grid_idx][num] = true;
            }
        }
        return 1;
    }
};
// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for (int i = 0; i < 81; i++)
            cin >> mat[i / 9][i % 9];

        Solution ob;
        cout << ob.isValid(mat) << "\n";
    }
    return 0;
} // } Driver Code Ends
