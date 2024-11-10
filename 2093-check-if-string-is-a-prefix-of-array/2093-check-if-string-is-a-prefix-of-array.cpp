class Solution {
public:
    bool isPrefixString(string s, vector<string>& w) {
        int l=0, sum=0;
        bool isit;
        for (int i=0; i!=s.size(); i++)
        {
            isit=0;
            if (l==w.size()||s[i]!=w[l][i-sum]) return 0;
            if (i-sum==w[l].size()-1)
            {
                sum+=w[l].size();
                l++;
                isit=1;
            }
        }
        if (isit==1) return 1;
        else return 0;
    }
};