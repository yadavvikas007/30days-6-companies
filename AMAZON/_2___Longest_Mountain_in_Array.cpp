// Longest Mountain in Array

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
    int longestMountain(vector<int> &arr)
    {
        int len = 0, n = arr.size(), i = 1;
        while (i < n)
        {
            // climb up
            if (arr[i] > arr[i - 1])
            {
                int climb_up = 1, climb_down = 0;
                while (i < n && arr[i] > arr[i - 1])
                    i++, climb_up++;
                while (i < n && arr[i] < arr[i - 1])
                    i++, climb_down++;

                // validate mountain
                if (climb_up >= 1 && climb_down >= 1)
                    len = max(len, climb_up + climb_down);
            }
            else
                i++;
        }
        return len;
    }
};