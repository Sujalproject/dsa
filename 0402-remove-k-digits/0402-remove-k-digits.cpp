class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        int count = 0;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(num[i]);
                continue;
            }
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans = "";
        if(st.empty()){
            ans.push_back('0');
            return ans;
        }
        while(!st.empty()){
            char c = st.top();
            ans.push_back(c);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans.size() > 1 && ans[0] == '0'){
            ans.erase(0,1);
        }
        return ans;
    }
};