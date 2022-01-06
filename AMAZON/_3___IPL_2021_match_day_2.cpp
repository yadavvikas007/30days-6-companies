// IPL 2021 - Match Day 2

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
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        vector<int> ans;
        deque<int> dq;
        int i = 0;
        while (i < n)
        {
            while (!dq.empty() and dq.front() == i - k)
                dq.pop_front();

            while (!dq.empty() and arr[dq.back()] < arr[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1)
                ans.push_back(arr[dq.front()]);

            i++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends