class Solution {
public:
    bool isValid(string s) {
        int n = s.size(),i=0;
        stack<char>st;
        while(i < n){
            char current = s[i];
            if(current == '(' || current == '[' || current == '{')st.push(current);
            else{
                if(st.empty())return false;
                char topchar = st.top();
                if((topchar == '(' && current != ')') || 
                    (topchar == '[' && current != ']') ||
                    (topchar == '{' && current != '}')){
                        return false;
                }
                st.pop();
            }
            i++;
        }
        return st.empty();
    }
};
