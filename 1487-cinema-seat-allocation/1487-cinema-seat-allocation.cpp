class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& nums) {
        int ans=n*2;
        sort(nums.begin(), nums.end());
        int l=nums[0][0];
        nums.push_back({1000000001, 0});
        vector<int> arr(11, 0), zero=arr;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i][0]==l)
            {
                arr[nums[i][1]]=1;
            }
            else
            {
                if (arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7]+arr[8]+arr[9]==0) ;
                else if (arr[2]+arr[3]+arr[4]+arr[5]==0||arr[4]+arr[5]+arr[6]+arr[7]==0||arr[6]+arr[7]+arr[8]+arr[9]==0) ans--;
                else ans-=2;
                arr=zero;
                l=nums[i][0];
                arr[nums[i][1]]=1;
            }
        }
        return ans;
    }
};