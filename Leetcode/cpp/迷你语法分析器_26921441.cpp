/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
// 思路就是递归求解，在单个片段内部不断调用分析器，生成NestedInteger
// 之前的版本用了自己写的数值转换不如直接用stoi，而且一次遍历就够了，不用再搞一个vector出来存分开的字符串……
// 之后看一下用栈实现的非递归版本
private:
    
    inline bool isComma(const char &c){
        return c == ',';
    }
    
    inline bool isL(const char &c){
        return c == '[';
    }
    
    inline bool isR(const char &c){
        return c == ']';
    }
    
    inline int char2num(const char &c){
        return c-'0';
    }
    
public:
    NestedInteger deserialize(string s) {
        NestedInteger ans;
        if(!isL(s[0])){
             ans.setInteger(stoi(s));
             return ans;
        }else if(s=="[]"){
             return ans;
        }else{
             int inside = 0;
             int start = 1, len = 0;
             for(int i=1;i<s.length()-1;i++){
                 if(isComma(s[i]) && inside==0){
                    string ss = s.substr(start,len);
                    ans.add(deserialize(ss));
                    start = i+1;
                    len = 0;
                 } else {
                     len++;
                     if(isL(s[i])){
                         inside++;
                     }else if(isR(s[i])){
                         inside--;
                     }
                 }
             }
             len = s.length()-1-start;
             string ss = s.substr(start,len);
             ans.add(deserialize(ss));
             return ans;
        }
    }
};