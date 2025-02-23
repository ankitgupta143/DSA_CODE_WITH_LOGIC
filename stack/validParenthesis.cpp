/*
 * Problem: Valid Parenthesis
 * 
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid. 
 * 
 * A string is valid if:
 *  - Open brackets must be closed by the same type of brackets.
 *  - Open brackets must be closed in the correct order.
 *  - Every closing bracket has a corresponding opening bracket of the same type.
 * 
 * Link: https://leetcode.com/problems/valid-parentheses/
 *
 * Approach:
 * - Use a stack to track opening brackets.
 * - When encountering an opening bracket, push the corresponding closing bracket onto the stack.
 * - When encountering a closing bracket, check if it matches the top of the stack.
 * - If it does, pop the stack. Otherwise, return false.
 * - At the end, if the stack is empty, the string is valid.
 *
 * Time Complexity: O(n) - Each character is processed once.
 * Space Complexity: O(n) - In the worst case, all opening brackets are stored in the stack.
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 class Solution {
   public:
     bool isBalanced(string& s) {
         int n = s.length();
         stack<char> st;
         
         for(char ch : s){
             if(ch == '['){
                 st.push(']');
             }
             else if(ch == '{'){
                 st.push('}');
             }
             else if(ch == '('){
                 st.push(')');
             }
             else if(!st.empty() && st.top() == ch){
                 st.pop();
             }
             else{
                 return false;
             }
         }
         
         return st.empty();
     }
 };
 
 // Driver Code
 int main() {
     Solution sol;
     string s = "{[()]}";  // Example Input
 
     if(sol.isBalanced(s)) 
         cout << "Valid Parentheses" << endl;
     else 
         cout << "Invalid Parentheses" << endl;
 
     return 0;
 }
 