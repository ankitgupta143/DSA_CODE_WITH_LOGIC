class Solution {
    public:
      int evaluate(vector<string>& arr) {
          int n = arr.size();
          
          stack<int> st;
          for(string s : arr){
              if (isdigit(s[0]) || (s.size() > 1 && isdigit(s[1]))) {  // Handling negative numbers
                  st.push(stoi(s));
              }
              else{
                  int a = st.top();
                  st.pop();
                  int b = st.top();
                  st.pop();
                  
                  if(s == "*"){
                      st.push(b * a);
                  }
                  else if(s == "+"){
                      st.push(b + a);
                  }
                  else if(s == "-"){
                      st.push(b - a);
                  }
                  else{
                      st.push(b / a);
                  }
              }
          }
          
          if(!st.empty()){
              return st.top();
          }
          
          return -1;
      }
  };