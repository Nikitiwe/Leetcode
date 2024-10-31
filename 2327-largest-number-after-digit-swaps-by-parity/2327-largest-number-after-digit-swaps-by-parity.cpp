class Solution {
public:
    int largestInteger(int n) {
        string s=to_string(n);
        for (int i=0; i!=s.size(); i++)
        {
            for (int j=i+1; j<s.size(); j++)
            {
                if ((s[i]+s[j])%2==0&&s[j]>s[i]) swap(s[i], s[j]);
            }
        }
        return stoi(s);
    }
};