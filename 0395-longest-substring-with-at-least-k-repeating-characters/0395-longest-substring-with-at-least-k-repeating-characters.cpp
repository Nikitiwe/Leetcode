class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<vector<int>> arr(1, vector<int>(26, 0));
        vector<int> t(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            t[s[i]-'a']++;
            arr.push_back(t);
        }
        int ans=0, l=k-1;
        for (int i=0; i!=s.size(); i++)
        {
            for (int a=l; a<s.size(); a++)
            {
                bool isit=1;
                for (int j=0; j!=26; j++)
                {
                    if (arr[a+1][j]-arr[i][j]>0&&arr[a+1][j]-arr[i][j]<k)
                    {
                        isit=0;
                        break;
                    }
                }
                if (isit==1)
                {
                    ans=max(ans, a-i+1);
                    l=a;
                }
            }
        }
        return ans;
    }
};