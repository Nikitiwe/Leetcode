class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> arr(121, 0);
        int ans=0;
        for (int i=0; i!=ages.size(); i++) arr[ages[i]]++;
        for (int i=1; i<=120; i++)
        {
            for (int j=1; j<=120; j++)
            {
                if (j<=i/2+7||j>i||(j>100&&i<100)) continue;
                else if (i!=j) ans+=arr[i]*arr[j];
                else ans+=arr[i]*(arr[j]-1);
            }
        }
        return ans;
    }
};