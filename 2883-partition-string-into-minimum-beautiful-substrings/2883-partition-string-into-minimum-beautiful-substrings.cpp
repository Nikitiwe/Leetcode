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
                    if (t.size()==1&&t==arr[0]) isit=1;
                    else if (t.size()==3&&t==arr[1]) isit=1;
                    else if (t.size()==5&&t==arr[2]) isit=1;
                    else if (t.size()==7&&t==arr[3]) isit=1;
                    else if (t.size()==10&&t==arr[4]) isit=1;
                    else if (t.size()==12&&t==arr[5]) isit=1;
                    else if (t.size()==14&&t==arr[6]) isit=1;
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