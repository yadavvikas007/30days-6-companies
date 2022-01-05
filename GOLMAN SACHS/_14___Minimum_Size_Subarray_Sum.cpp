// Decode string

// My Profiles--------------------------------------------------------------------
// GFG : https://auth.geeksforgeeks.org/user/vy9690703/profile
// Leetcode : https://leetcode.com/xmenvikas07/
// Codeforces : https://codeforces.com/profile/xmenvikas07
// Codechef : https://www.codechef.com/users/vikas_009

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=INT_MAX;
        int l=0,r=0,n=nums.size();
        long long sum=0;
        while(r<n){
            sum+=nums[r++];
            if(sum>=target){
                while(l<r && sum>=target){
                    sum-=nums[l++];
                }
                len=min(len,r-l+1);
            }
        }
        return (len==INT_MAX) ? 0 : len;
    }
};