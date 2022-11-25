/*
 * @Author: 快出来了哦
 * @Date: 2022-11-25 01:40:43
 * @LastEditors: 快出来了哦
 * @LastEditTime: 2022-11-25 02:02:49
 * @FilePath: /c++/algorithm/Leecode/Leecode809.cpp
 * @Description: 
 */
/*
有时候人们会用重复写一些字母来表示额外的感受，比如 "hello" -> "heeellooo", "hi" -> "hiii"。我们将相邻字母都相同的一串字符定义为相同字母组，例如："h", "eee", "ll", "ooo"。

对于一个给定的字符串 S ，如果另一个单词能够通过将一些字母组扩张从而使其和 S 相同，我们将这个单词定义为可扩张的（stretchy）。扩张操作定义如下：选择一个字母组（包含字母 c ），然后往其中添加相同的字母 c 使其长度达到 3 或以上。

例如，以 "hello" 为例，我们可以对字母组 "o" 扩张得到 "hellooo"，但是无法以同样的方法得到 "helloo" 因为字母组 "oo" 长度小于 3。此外，我们可以进行另一种扩张 "ll" -> "lllll" 以获得 "helllllooo"。如果 s = "helllllooo"，那么查询词 "hello" 是可扩张的，因为可以对它执行这两种扩张操作使得 query = "hello" -> "hellooo" -> "helllllooo" = s。

输入一组查询单词，输出其中可扩张的单词数量。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        for (string word : words) {
            if (check(s, word)) res++;
        } 
        return res;
    }
    
private:
    /**
     * @description: 双指针
     * @param {string} s
     * @param {string} word
     * @return {*}
     */
    bool check(string s, string word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] != word[j]) return false; 
            
            char c = s[i];
            
            int cnts = 0;
            while (i < s.size() && s[i] == c) {
                i++; 
                cnts++;
            }
            
            int cntw = 0;
            while (j < word.size() && word[j] == c) {
                j++; 
                cntw++;
            }
            
            if (cnts < cntw) return false;
            if (cnts > cntw && cnts < 3) return false; 
        }
        return i == s.size() && j == word.size();
    }
};
int main()
{
    return 0;
}
