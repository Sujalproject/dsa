class Solution {
public:
    bool isballon(unordered_map<char,int> &mp){
        string ransomNote = "balloon";
        for(int i=0;i<ransomNote.size();i++){
            if(mp.find(ransomNote[i])==mp.end()){
                return false;
            }
            if(mp[ransomNote[i]]){
                mp[ransomNote[i]]--;
                if(mp[ransomNote[i]]==0) mp.erase(ransomNote[i]);
                continue;
            }
        }
        return true;
    }
    int maxNumberOfBalloons(string text) {
         unordered_map<char,int> mp;
         int ans =0;
         for(int i=0;i<text.size();i++){
            mp[text[i]]++;
        }
            while(isballon(mp)){
                ans++;
         }
        return ans;
    }
};