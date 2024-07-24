class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string ans;
        int f=0, l, i=0, temp;
        while (i<s.size())
        {
            temp=ans.size();
            for (int j=0; j!=indices.size(); j++)
            {
                if (i==indices[j])
                {
                        f=0;
                        l=0;
                        while (i+l<s.size()&&l<sources[j].size())
                        {
                            if (s[i+l]==sources[j][l]) f++;
                            else break;
                            l++;
                        }
                        if (f==sources[j].size()) {ans+=targets[j]; i=i+sources[j].size(); break;}
                }
            }
            if (temp==ans.size())
            {
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};