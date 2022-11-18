/*
 * @Author: 快出来了哦
 * @Date: 2022-11-18 01:10:27
 * @LastEditors: 快出来了哦
 * @LastEditTime: 2022-11-18 01:51:59
 * @FilePath: /c++/algorithm/Leecode/Leecode891.cpp
 * @Description: 
 */
/*
一个序列的 宽度 定义为该序列中最大元素和最小元素的差值。

给你一个整数数组 nums ，返回 nums 的所有非空 子序列 的 宽度之和 。由于答案可能非常大，请返回对 109 + 7 取余 后的结果。

子序列 定义为从一个数组里删除一些（或者不删除）元素，但不改变剩下元素的顺序得到的数组。例如，[3,6,2,7] 就是数组 [0,3,1,6,2,2,7] 的一个子序列。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        
    }
    /**
     * @description: 暴力超时
     * @return {*}
     */    
    int func_violence(vector<int>&nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n <= 1)return 0;
        long ans = 0;
        for(int i = 0; i < n;++i)
        {
            for(int j =i ; j < n; j++)
            {
                ans += (nums[j]-nums[i])*pow(2,j-i-1);
            }
        }
        return ans%mod;

    /**
     * @description: 用数学重构
     * @return {*}
     */
    }
    int func_math(vector<int>&nums)
    {
        /*
        优化：计算每个数的对结果的贡献。对于每一个数 nums[i] 来说，它可以做最大值也可以做最小值。

当 nums[i] 为子序列的最大值时，计算该子序列的宽度时，需要用 nums[i] 减去当前子序列的最小值。它一共可以当 2^i 个子序列中的最大值，所以它会被加上 2^i 次。

当 nums[i] 为子序列的最小值时，计算该子序列的宽度时，需要用子序列的最大值减去 nums[i]。它一共可以当 2^(n - 1 - i) 个子序列中的最小值，所以它会被减去 2^(n - 1 - i) 次。

所以 nums[i] 对结果的贡献为 (2^i - 2^(n - 1 - i)) * nums[i]。
        */
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // 先提前算好 2^i = pow2[i]
        vector<int> pow2(n); 
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = pow2[i - 1] * 2 % mod;
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            int cnt = (pow2[i] - pow2[n - 1 - i]) * 1ll * nums[i] % mod;
            res = (res + cnt) %mod;
        }
        
        return res;
    }
private:
    long mod = 1e9+7;
};
int main()
{
    vector<int>nums={2,1,3};
    cout<<Solution().sumSubseqWidths(nums)<<endl;
    return 0;
}
