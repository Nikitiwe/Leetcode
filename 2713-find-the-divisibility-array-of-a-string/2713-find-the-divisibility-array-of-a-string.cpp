class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long a=0;
        vector<int> ans;
        for (int i=0; i!=word.size(); i++)
        {
            a=(a*10+word[i]-'0')%m;
            if (a==0) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};