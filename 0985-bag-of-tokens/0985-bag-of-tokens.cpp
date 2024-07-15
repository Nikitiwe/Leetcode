class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if (tokens.size()==0) return 0;
        sort(tokens.begin(), tokens.end());
        int l=0, r=tokens.size()-1, ans=0;
        if (tokens[l]>power) return 0;
        else
        {
            power-=tokens[l];
            l++;
            ans++;
        }
        while (l<r)
        {
            if (tokens[l]<=power)
            {
                power-=tokens[l];
                l++;
                ans++;
            }
            else
            {
                power+=tokens[r];
                ans--;
                r--;
            }
        }
        if (l<tokens.size()&&tokens[l]<=power)
        {
            power-=tokens[l];
            ans++;
        }
        return ans;
    }
};