class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        vector<int> ans(s.size()+1, 17);
        if (s[0]=='0') return -1;
        else
        {
            ans[1]=1;
            ans[0]=0;
        }
        vector<string> arr{"1", "101", "11001", "1111101", "1001110001", "110000110101", "11110100001001"};
        for (int i=1; i<ans.size(); i++)
        {
                string t;
                for (int j=i; j<ans.size(); j++)
                {
                    t+=s[j-1];
                    bool isit=0;
                    for (int k=0; k!=arr.size(); k++)
                    {
                        if (t==arr[k])
                        {
                            isit=1;
                            break;
                        }
                    }
                    if (isit==1)
                    {
                        ans[j]=min(ans[j], ans[i-1]+1);
                    }
                }
        }
        if (ans[ans.size()-1]!=17) return ans[ans.size()-1];
        else return -1;
    }
};