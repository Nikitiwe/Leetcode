class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> arr(nums.size(), vector<int> (3, 0));
        if (nums[0]==1)
        {
            arr[0][0]=0;
            arr[0][1]=1;
            arr[0][2]=1;
        }
        else if (nums[0]==2)
        {
            arr[0][0]=1;
            arr[0][1]=0;
            arr[0][2]=1;
        }
        else if (nums[0]==3)
        {
            arr[0][0]=1;
            arr[0][1]=1;
            arr[0][2]=0;
        }
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]==1)
            {
                arr[i][0]=arr[i-1][0];
                arr[i][1]=min(arr[i-1][0], arr[i-1][1])+1;
                arr[i][2]=min({arr[i-1][0], arr[i-1][1], arr[i-1][2]})+1;
            }
            else if (nums[i]==2)
            {
                arr[i][0]=arr[i-1][0]+1;
                arr[i][1]=min(arr[i-1][0], arr[i-1][1]);
                arr[i][2]=min({arr[i-1][0], arr[i-1][1], arr[i-1][2]})+1;
            }
            else if (nums[i]==3)
            {
                arr[i][0]=arr[i-1][0]+1;
                arr[i][1]=min(arr[i-1][0], arr[i-1][1])+1;
                arr[i][2]=min({arr[i-1][0], arr[i-1][1], arr[i-1][2]});
            }
        }
        return min({arr[nums.size()-1][0], arr[nums.size()-1][1], arr[nums.size()-1][2]});
    }
};