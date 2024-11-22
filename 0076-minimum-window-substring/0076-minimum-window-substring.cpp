class Solution {
public:
    string minWindow(string s, string t) {
        string ans(100001, 'z'), ansb=ans;
        int l=t.size(), r=s.size(), m;
        if (l>r) return "";
        vector<int> arr(52, 0);
        for (int i=0; i!=t.size(); i++)
        {
            if (t[i]>='a'&&t[i]<='z') arr[t[i]-'a']++;
            else arr[t[i]-'A'+26]++;
        }
        while (l<=r)
        {
            m=(l+r)/2;
            vector<int> arr2(52, 0);
            for (int i=0; i!=m; i++)
            {
                if (s[i]>='a'&&s[i]<='z') arr2[s[i]-'a']++;
                else arr2[s[i]-'A'+26]++;
            }
            bool isit=1;
            for (int i=0; i!=52; i++)
            {
                if (arr2[i]<arr[i])
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1&&m<ans.size()) ans=s.substr(0, m);
            //if (isit==0)
            {
                for (int i=m; i<s.size(); i++)
                {
                    isit=1;
                    if (s[i]>='a'&&s[i]<='z') arr2[s[i]-'a']++;
                    else arr2[s[i]-'A'+26]++;
                    if (s[i-m]>='a'&&s[i-m]<='z') arr2[s[i-m]-'a']--;
                    else arr2[s[i-m]-'A'+26]--;
                    for (int i=0; i!=52; i++)
                    {
                        if (arr2[i]<arr[i])
                        {
                            isit=0;
                            break;
                        }
                    }
                    if (isit==1&&m<ans.size())
                    {
                        ans=s.substr(i-m+1, m);
                        break;
                    }
                }
            }
            if (ans.size()>m) l=m+1;
            else r=m-1;
        }
        if (ans==ansb) return "";
        else return ans;
    }
};