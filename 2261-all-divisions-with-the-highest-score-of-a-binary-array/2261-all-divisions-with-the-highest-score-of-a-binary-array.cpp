class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> scores, ans;
        int co=0, cz=0;
        for (int i=0; i!=nums.size(); i++)
        {
            co+=nums[i];
        }
        scores.push_back(co);
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]==0) cz++;
            else co--;
            scores.push_back(co+cz);
        }
        int m=*max_element(scores.begin(), scores.end());
        for (int i=0; i!=scores.size(); i++)
        {
            if (scores[i]==m) ans.push_back(i);
        }
        return ans;
    }
};