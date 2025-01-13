class Solution {
public:
    int minimumLength(string s) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            arr[s[i]-'a']++;
        }
        int ans=0;
        for (int i=0; i!=26; i++)
        {
            if (arr[i]>2)
            {
                if (arr[i]%2==0) ans+=2;
                else ans+=1;
            }
            else ans+=arr[i];
        }
        return ans;
    }
};