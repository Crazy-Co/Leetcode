class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n%2!=0) return false;
        stack<char> st;
        for(int i =0;i<n;i++){
            char ch =s[i];
            if(ch=='('|| ch=='{' ||ch=='['){
                    st.push(ch);
            }else{
                if(!st.empty()){
                        if(st.top()=='{' && ch=='}') st.pop();
                        else if(st.top()=='(' && ch==')') st.pop();
                        else if(st.top()=='[' && ch==']') st.pop();
                        else return false;
                }else{
                    return false;
                }
            }
        }
        return !st.size();
    }
};