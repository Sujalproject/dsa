class Solution {
public:
    void fun(int open,int close,int n,string &temp,vector<string> &ans){
        if(open==n && close==n){
            ans.push_back(temp);
            return;
        }
        //open
        if(open<n){
            temp.push_back('(');
            fun(open+1,close,n,temp,ans);
            temp.pop_back();
        }
        //close
        if(close<open){
            temp.push_back(')');
            fun(open,close+1,n,temp,ans);
            temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
       int open = 0;
       int close = 0;
       string temp = "";
       vector<string> ans;
       fun(open,close,n,temp,ans);
       return ans;
    }
};