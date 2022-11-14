/*
 * @Author: 快出来了哦
 * @Date: 2022-11-14 01:19:22
 * @LastEditors: 快出来了哦
 * @LastEditTime: 2022-11-14 02:24:09
 * @FilePath: /c++/algorithm/Leecode/Leecode805.cpp
 * @Description: 
 */
/*
给定你一个整数数组 nums

我们要将 nums 数组中的每个元素移动到 A 数组 或者 B 数组中，使得 A 数组和 B 数组不为空，并且 average(A) == average(B) 。

如果可以完成则返回true ， 否则返回 false  。

注意：对于数组 arr ,  average(arr) 是 arr 的所有元素的和除以 arr 长度。

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    /**
     * @description: 位运算优化
     * @param {vector<int>} &nums
     * @return {*}
     */
    bool splitArraySameAverage(vector<int> &nums) {
        int n = nums.size(), m = n / 2;
        if (n == 1) {
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int &x : nums) {
            x = x * n - sum;
        }

        unordered_set<int> left;
        for (int i = 1; i < (1 << m); i++) {
            int tot = 0;
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    tot += nums[j];
                }
            }
            if (tot == 0) {
                return true;
            }
            left.emplace(tot);
        }

        int rsum = accumulate(nums.begin() + m, nums.end(), 0);
        for (int i = 1; i < (1 << (n - m)); i++) {
            int tot = 0;
            for (int j = m; j < n; j++) {
                if (i & (1 << (j - m))) {
                    tot += nums[j];
                }
            }
            if (tot == 0 || (rsum != tot && left.count(-tot))) {
                return true;
            }
        }
        return false;
    }
    /**
     * @description: 递归实现，超时
     * @param {int} depth
     * @param {double} avg
     * @param {bool&} ans
     * @return {*}
     */    
    void dfs(int depth,vector<int>vec,double avg,bool& ans,vector<int>& nums)
    {
        if(depth==nums.size())
        {
            return;
        }
        for(int i=depth;i<nums.size();++i)
        {
            long sum=accumulate(vec.begin(),vec.end(),0)+nums[i];
            double t=(sum)/(vec.size()+1);
            if(t==avg&&vec.size()+1<nums.size())
            {
                ans=true;
                return;
            }
            dfs(depth+1,vec,avg,ans,nums);
            vec.push_back(nums[i]);
            dfs(depth+1,vec,avg,ans,nums);
        }
    }

};
int main()
{
    vector<int>nums={3,1};
    cout<<Solution().splitArraySameAverage(nums)<<endl;
    return 0;
}
