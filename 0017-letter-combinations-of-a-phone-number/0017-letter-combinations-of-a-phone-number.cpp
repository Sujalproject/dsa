class Solution {
public:
    unordered_map<char, string> mp;

    Solution() {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
    }
    void com(string &digit,int idx,int n,string &temp,vector<string> &ans){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        string choice = mp[digit[idx]];
        for(int i=0;i<choice.size();i++){
            temp.push_back(choice[i]);
            com(digit,idx+1,n,temp,ans);
            temp.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        string temp = "";
        vector<string> ans;
        int idx = 0;
        com(digits,idx,digits.size(),temp,ans);
        return ans;
    }
};