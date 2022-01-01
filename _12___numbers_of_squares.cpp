// Find total number of Squares in a N*N chessboard

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
    long long Number_of_squares(int n)
    {
        // ans = 1^2 + 2^2 + 3^2 + ... +n^2

        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += (i * i);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.Number_of_squares(8);
}