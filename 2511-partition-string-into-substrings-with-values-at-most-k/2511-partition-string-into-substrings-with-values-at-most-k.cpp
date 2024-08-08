class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans=0;
        long temp=0;
        for (int i=0; i!=s.size(); i++)
        {
            temp*=10;
            temp+=s[i]-'0';
            if (temp>k)
            {
                ans++;
                temp=s[i]-'0';
                if (temp>k) return -1;
            }
        }
        ans++;
        return ans;
    }
};