class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        vector<string> ans;
        string temp;
        if (s.size()<10) return ans;
        for (int i=0; i!=s.size()-9; i++)
        {
            temp=s.substr(i,10);
            if (m.count(temp)==0) m.insert({temp, 1});
            else {if (m[temp]==1) ans.push_back(temp); m[temp]++;}
        }
        return ans;
    }
};