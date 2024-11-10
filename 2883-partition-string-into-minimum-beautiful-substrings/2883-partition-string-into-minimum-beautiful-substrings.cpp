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
        for (int i=2; i<ans.size(); i++)
        {
            for (int k=1; k<=i; k++)
            {
                string t;
                for (int j=k; j<=i; j++)
                {
                    t+=s[j-1];
                }
                bool isit=0;
                for (int j=0; j!=arr.size(); j++)
                {
                    if (t==arr[j])
                    {
                        isit=1;
                        break;
                    }
                }
                if (isit==1)
                {
                    ans[i]=min(ans[i], ans[k-1]+1);
                }
            }
        }
        if (ans[ans.size()-1]!=17) return ans[ans.size()-1];
        else return -1;
    }
};