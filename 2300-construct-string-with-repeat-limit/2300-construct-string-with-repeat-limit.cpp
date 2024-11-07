class Solution {
public:
    string repeatLimitedString(string s, int l) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++) arr[s[i]-'a']++;
        string ans;
        for (int i=25; i>=0; i--)
        {
            while (arr[i]>0)
            {
                if (arr[i]<=l)
                {
                    for (int j=0; j<arr[i]; j++) ans+='a'+i;
                    arr[i]=0;
                }
                else
                {
                    for (int j=0; j<l; j++) ans+='a'+i;
                    arr[i]-=l;
                    int k=i-1;
                    while (k>=0&&arr[k]==0) k--;
                    if (k<0) break;
                    else
                    {
                        ans+='a'+k;
                        arr[k]--;
                    }
                }
            }
        }
        return ans;
    }
};