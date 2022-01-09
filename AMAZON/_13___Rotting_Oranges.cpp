// Rotting Oranges

// My Profiles--------------------------------------------------------------------
// GFG : https://auth.geeksforgeeks.org/user/vy9690703/profile
// Leetcode : https://leetcode.com/xmenvikas07/
// Codeforces : https://codeforces.com/profile/xmenvikas07
// Codechef : https://www.codechef.com/users/vikas_009

#include <bits/stdc++.h>
using namespace std;

class RottenOrange
{
public:
    int x;
    int y;
    int time;
    RottenOrange(int x, int y, int time)
    {
        this->x = x;
        this->y = y;
        this->time = time;
    }
};

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return -1;

        int rows = grid.size();
        int columns = grid[0].size();

        queue<RottenOrange> rotten_oranges;

        // enque all rotten oranges
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (grid[i][j] == 2)
                {
                    RottenOrange orange(i, j, 0);
                    rotten_oranges.push(orange);
                }
            }
        }

        int time = 0;
        vector<vector<int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        // BFS on all rotten oranges sources
        while (!rotten_oranges.empty())
        {
            RottenOrange orange = rotten_oranges.front();
            rotten_oranges.pop();

            int x = orange.x;
            int y = orange.y;
            time = orange.time;

            for (auto &dir : directions)
            {
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                if (new_x < 0 || new_x >= rows || new_y < 0 || new_y >= columns)
                    continue;
                if (grid[new_x][new_y] != 1)
                    continue;
                grid[new_x][new_y] = 2;
                RottenOrange orange(new_x, new_y, time + 1);
                rotten_oranges.push(orange);
            }
        }

        // check for any remaining fresh orange
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (grid[i][j] == 1)
                    return -1;

        return time;
    }
};