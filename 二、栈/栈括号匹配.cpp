//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//1、左括号必须用相同类型的右括号闭合。
//2、左括号必须以正确的顺序闭合。
//3、每个右括号都有一个对应的相同类型的左括号。



#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool is_valid(string s) {
        //设定一个函数判断字符串是否合法,如果
        if (s.length()%2!=0){
            return false;
        }

        stack<char> st;

        for (char ch : s) {
            if (ch =='(' || ch == '{' || ch == '[') //遇到左括号，压栈。
                st.push(ch);

            else {
                if (st.empty()) {
                    return false; //如果遇到右括号，但是栈内已经没有元素，即没有对应的左括号，就不符合。
                }

                char top = st.top();
                st.pop(); //如果栈非空，则弹出栈顶元素

                if (ch == ')' && top != '(') {
                    return false;
                }
                if (ch == '}' && top != '{') {
                    return false;
                }
                if (ch == ']' && top != '[') {
                    return false;  //如果左右括号不匹配，则返回false。
                }
            }
        }
        return st.empty(); //如果成功，最后应该栈空，于是st.empty()应该是true
    }
};
