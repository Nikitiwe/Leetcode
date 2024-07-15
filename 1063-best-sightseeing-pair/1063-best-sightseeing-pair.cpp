class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=0, val=values[0];
        for (int i=1; i!=values.size(); i++)
        {
            val--;
            ans=max(ans, (val+values[i]));
            val=max(val, values[i]);
        }
        return ans;
    }
};