class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0, SUM=mean*(rolls.size()+n);
        for (int i=0; i!=rolls.size(); i++)
        {
            sum+=rolls[i];
        }
        int suml=SUM-sum, temp=n;
        vector<int> ans(n, 1);
        if (suml<n||suml>n*6) return {};
        while (temp<suml)
        {
            ans[temp%n]++;
            temp++;
        }
        return ans;

    }
};