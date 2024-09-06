class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> m;
        for (int i=0; i!=arr1.size(); i++)
        {
            int t=0;
            string s=to_string(arr1[i]);
            for (int j=0; j!=s.size(); j++)
            {
                t*=10;
                t+=s[j]-'0';
                m.insert(t);
            }
        }
        int ans=0;
        for (int i=0; i!=arr2.size(); i++)
        {
            int t=0;
            string s=to_string(arr2[i]);
            for (int j=0; j!=s.size(); j++)
            {
                t*=10;
                t+=s[j]-'0';
                if (m.count(t)>0) ans=max(ans, j+1);
            }
        }
        return ans;
    }
};