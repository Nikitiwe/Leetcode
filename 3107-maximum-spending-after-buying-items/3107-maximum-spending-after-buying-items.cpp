class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ans=0, it=0;
        vector<int> temp;

        for (int i=values[0].size()-1; i>=0; i--)
        {
            for (int j=0; j!=values.size(); j++)
            {
                temp.push_back(values[j][i]);
            }
        }
        sort(temp.begin(), temp.end());
        for (int j=0; j!=temp.size(); j++)
        {
            it++;
            ans+=temp[j]*it;
        }
        return ans;
    }
};