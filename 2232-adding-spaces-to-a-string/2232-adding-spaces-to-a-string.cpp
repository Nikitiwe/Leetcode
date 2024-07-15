class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int id=0, r=spaces[id];
        for (int i=0; i!=s.size(); i++)
        {
            if (i==r)
            {
                ans+=" ";
                if (spaces.size()>id+1) {id++; r=spaces[id];}
            }
            ans+=s[i];
        }
        return ans;
    }
};