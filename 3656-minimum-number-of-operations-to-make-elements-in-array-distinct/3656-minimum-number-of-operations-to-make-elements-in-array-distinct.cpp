class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0, l=0;
        while (1)
        {
            vector<int> arr(101, 0);
            bool isit=0;
            if (l<nums.size())
            {
                for (int i=l; i<nums.size(); i++)
            {
                arr[nums[i]]++;
                if (arr[nums[i]]>1) isit=1;
            }
            if (isit==1)
            {
                ans++;
                l+=3;
            }
            else return ans;
            }
            else return ans;
        }
        return ans;
    }
};