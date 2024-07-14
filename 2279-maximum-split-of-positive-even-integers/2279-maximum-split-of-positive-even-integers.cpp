class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum%2==1) return {};
        vector<long long> ans;
        int i=2;
        while (2*i+2<=finalSum)
        {
            ans.push_back(i);
            finalSum-=i;
            i=i+2;
        }
        ans.push_back(finalSum);
        return ans;
    }
};