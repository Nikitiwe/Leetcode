class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0, ans=0;
        for (int i=0; i!=k; i++)
        {
            sum+=cardPoints[i];
        }
        ans=sum;
        for (int i=0; i!=k; i++)
        {
            sum-=cardPoints[k-1-i];
            sum+=cardPoints[cardPoints.size()-1-i];
            ans=max(ans, sum);
        }
        return ans;
    }
};