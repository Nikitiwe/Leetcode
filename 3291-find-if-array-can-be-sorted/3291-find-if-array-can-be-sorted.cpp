class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<vector<int>> arr(nums.size(), vector<int> (2, 0));
        for (int i=0; i!=nums.size(); i++)
        {
            arr[i][0]=nums[i];
            int t=nums[i];
            int s=0;
            while (t>0)
            {
                s+=t%2;
                t/=2;
            }
            arr[i][1]=s;
        }
        vector<int> k, m;
        int l=0, ma=arr[l][0], mi=ma;
        for (int i=1; i<nums.size(); i++)
        {
            if (arr[i][1]==arr[l][1])
            {
                ma=max(arr[i][0], ma);
                mi=min(arr[i][0], mi);
            }
            else
            {
                k.push_back(ma);
                m.push_back(mi);
                l=i;
                ma=arr[l][0];
                mi=arr[l][0];
            }
        }
        k.push_back(ma);
        m.push_back(mi);
        for (int i=0; i<k.size()-1; i++) if (k[i]>m[i+1]) return 0;
        return 1;
    }
}; // чот не так пошло ну и пох