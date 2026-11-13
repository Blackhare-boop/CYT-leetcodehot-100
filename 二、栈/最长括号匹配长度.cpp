//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号 子串 的长度。
//左右括号匹配，即每个左括号都有对应的右括号将其闭合的字符串是格式正确的，比如 "(()())"。






#include <iostream>
#include <string>
#include <stack>
#include <algorithm> // 使用 max 函数需要包含这个头文件

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int max_length = 0;

        st.push(-1); // 关键技巧：栈底先放一个 -1，作为最初始的“边界”

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);  //如果遇到左括号，就下标压栈

            } else {

                st.pop();// 遇到右括号，先弹出栈顶

                if (st.empty()) {

                    st.push(i);// 如果栈空了，说明当前右括号多余了，把它作为新的边界压入

                } else {

                    max_length = max(max_length, i - st.top());// 如果栈没空，说明匹配成功，计算当前有效长度
                    // 长度 = 当前下标 - 栈顶的下标
                }
            }
        }

        return max_length;
    }
};


