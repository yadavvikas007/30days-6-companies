//  Given two strings str1 and str2. We say that str2 divides str1 if it's possible
//  to concatenate multiple str2 to get str1.For example, ab divides abab. if str2 does not divide str1,
//  return -1. Otherwise, return the smallest string str3 such that str3 divides both str1 and str2.

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
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 == str2 + str1)
            return str1.substr(0, __gcd(str1.size(), str2.size()));
        return "";
    }
};