// Overlapping rectangles

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
    int doOverlap(int L1[], int R1[], int L2[], int R2[])
    {
        if (L1[0] > R2[0] or L2[0] > R1[0])
            return false;
        if (R1[1] > L2[1] or R2[1] > L1[1])
            return false;
        return true;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}