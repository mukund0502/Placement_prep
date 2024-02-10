#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;

    priority_queue<pair<int, int>> pp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i < k - 1)
        {
            pair<int, int> p = {nums[i], i};
            pp.push(p);
        }
        else
        {
            pair<int, int> p = {nums[i], i};
            pp.push(p);
            while (1 || !(pp.empty()))
            {
                if (pp.top().second > i - k)
                {
                    break;
                }
                pp.pop();
            }
            ans.push_back(pp.top().first);
        }
    }
    return ans;
}