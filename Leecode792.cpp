/*
 * @Author: 快出来了哦
 * @Date: 2022-11-17 00:50:56
 * @LastEditors: 快出来了哦
 * @LastEditTime: 2022-11-17 01:37:27
 * @FilePath: /c++/algorithm/Leecode/Leecode792.cpp
 * @Description: 
 */
/*
给定字符串 s 和字符串数组 words, 返回  words[i] 中是s的子序列的单词个数 。

字符串的 子序列 是从原始字符串中生成的新字符串，可以从中删去一些字符(可以是none)，而不改变其余字符的相对顺序。

例如， “ace” 是 “abcde” 的子序列。
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt = 0;
        for(auto word: words)
        {
            if(isSubsequence(word,s))cnt++;
        }
        return cnt;

    }
    /**
     * @description: 判断s是否为t子串
     * @param {string} s
     * @param {string} t
     * @return {*}
     */    
    bool isSubsequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        int i= 0;
        int j= 0;
        while(i < n && j < m)
        {
            if(s[i] == t[j])i++;
            j++;
        }
        return i == n;
    }
};
int main()
{
    return 0;
}