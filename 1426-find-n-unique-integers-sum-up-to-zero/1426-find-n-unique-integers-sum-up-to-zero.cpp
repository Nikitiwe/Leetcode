class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n, 0);
        for (int i=1; i<ans.size(); i++) ans[i]=i;
        ans[0]=-n*(n-1)/2;
        return ans;
    }
};