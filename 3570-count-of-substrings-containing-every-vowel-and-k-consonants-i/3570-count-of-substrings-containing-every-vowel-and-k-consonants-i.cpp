class Solution {
public:
    int countOfSubstrings(string s, int k) {
        vector<int> t(6, 0), zero=t;
        int ans=0;
        for (int i=0; i!=s.size(); i++)
        {
            t=zero;
            for (int j=i; j<s.size(); j++)
            {
                if (s[j]=='a') t[0]++;
                else if (s[j]=='e') t[1]++;
                else if (s[j]=='i') t[2]++;
                else if (s[j]=='o') t[3]++;
                else if (s[j]=='u') t[4]++;
                else t[5]++;

                if (t[5]>k) break;
                if (t[5]==k&&t[0]>0&&t[1]>0&&t[2]>0&&t[3]>0&&t[4]>0) ans++;
            }
        }
        return ans;
    }
};