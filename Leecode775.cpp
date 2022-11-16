/*
 * @Author: 快出来了哦
 * @Date: 2022-11-16 01:20:34
 * @LastEditors: 快出来了哦
 * @LastEditTime: 2022-11-16 02:09:10
 * @FilePath: /c++/algorithm/Leecode/Leecode775.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        return func_findnext(nums);
    }
    /**
     * @description: 暴力超时
     * @return {*}
     */    
    bool func_violence(vector<int>& nums)
    {
        int n=nums.size();
        if(n<=1)return true;
        int lcnt=0;
        int rcnt=0;
        for(int i=1;i<n;++i)/*判断局部*/
        {
            if(nums[i]<nums[i-1])lcnt++;
        }
        for(int i=0;i<n;++i)/*判断全局*/
        {
            for(int j=i+1;j<n;++j)
            {
                if(nums[i]>nums[j])rcnt++;

            }
        }
        return lcnt==rcnt;
    }
    /**
     * @description: 一个局部倒置一定是一个全局倒置，因此要判断数组中局部倒置的数量是否与全局倒置的数量相等，只需要检查有没有非局部倒置就可以了。
     * @return {*}
     */    
    bool func_findnext(vector<int>& nums)
    {
        int n=nums.size();
        int mindiff=nums[n-1];
        for(int i=n-3;i>=0;--i)
        {
            if(nums[i]>mindiff)return false;
            mindiff=min(mindiff,nums[i+1]);
        }
        return true;
    }
};
int main()
{
    vector<int>nums={1,2,0};
    cout<<Solution().isIdealPermutation(nums)<<endl;

    return 0;
}