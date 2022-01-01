// Array Pair Sum Divisibility Problem

// My Profiles--------------------------------------------------------------------
// GFG : https://auth.geeksforgeeks.org/user/vy9690703/profile
// Leetcode : https://leetcode.com/xmenvikas07/
// Codeforces : https://codeforces.com/profile/xmenvikas07
// Codechef : https://www.codechef.com/users/vikas_009

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool canPair(vector<int> a, int k)
    {
        int n = a.size();
        if (n & 1)
            return false;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[a[i] % k]++;
        }
        for (int i = 0; i < n; i++)
        {
            int r = a[i] % k;
            if (r == 0)
            {
                if (mp[0] & 1)
                    return 0;
            }
            else if (mp[r] != mp[k - r])
                return 0;
        }
        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
} // } Driver Code Ends