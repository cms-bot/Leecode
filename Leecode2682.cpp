/*
 * @Author: 快出来了哦
 * @Date: 2023-08-16 19:21:51
 * @LastEditors: 快出来了哦
 * @LastEditTime: 2023-08-16 19:47:32
 * @FilePath: /Leecode/Leecode2682.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
   static vector<int> circularGameLosers(int n, int k) {
        vector<int>ans;
        set<int> uset;
        int index = 0;
        int step = 0;
        while (true)
        {
            index = (index+(step*k))%n;
            step++;
            if(!uset.count(index))
            {
                uset.emplace(index);
            }else{
                break;
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            if(!uset.count(i-1))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
int main()
{
    int m;
    int n;
    cin>>m>>n;
    vector<int> ans = Solution::circularGameLosers(m,n);
    for(auto num: ans)
    {
        cout<< num <<" ";
    }
    return 0;
}