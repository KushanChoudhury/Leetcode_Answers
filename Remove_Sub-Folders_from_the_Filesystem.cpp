class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        for(auto s : folder){
            if(ans.empty()||ans.back().compare(0,ans.back().size(),s,0,ans.back().size())||s[ans.back().size()]!='/')
                ans.push_back(s);
        }
        return ans;
    }
};