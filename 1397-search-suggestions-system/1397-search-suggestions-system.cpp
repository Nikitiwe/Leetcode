class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& s, string w) {
        sort(s.begin(), s.end());
        vector<vector<string>> ans;
        string t;
        int r=0, x=0;
        for (int i=0; i!=w.size(); i++)
        {
            t+=w[i];
            vector<string> arr;
            for (int j=r; j<s.size(); j++)
            {
                int l=0;
                while (l<s[j].size()&&l<t.size()&&s[j][l]==t[l]) l++;
                if (l>x)
                {
                    x=l;
                    r=j;
                }
                if (l==t.size()) arr.push_back(s[j]);
                else if (arr.size()>0)
                {
                    ans.push_back(arr);
                    break;
                }
                if (arr.size()==3)
                {
                    ans.push_back(arr);
                    break;
                }
                else if (j==s.size()-1) ans.push_back(arr);
            }
        }
        return ans;
    }
};