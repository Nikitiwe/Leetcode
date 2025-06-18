class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<vector<int>> arr(3, vector<int>(nums.size(), 0));
        vector<vector<vector<int>>> id(3, vector<vector<int>>(nums.size(), vector<int>()));
        //vector<vector<int>> p(3, vector<int>(nums.size(), -1));
        
        int sum = 0;
        for (int j=0; j<nums.size(); j++)
        {
            sum += nums[j];
            if (j >= k) sum -= nums[j-k];
            if (j >= k-1)
            {
                arr[0][j] = sum;
                id[0][j].push_back(j+1-k);
            }
            if (j >= k)
            {
                if (arr[0][j-1] >= arr[0][j])
                {
                    arr[0][j] = arr[0][j-1];
                    id[0][j] = id[0][j-1];
                }
            }
        }
        for (int i=1; i<3; i++)
        {
            int sum = 0;
            int total = 0;
            for (int j=i*k; j<nums.size(); j++)
            {
                id[i][j] = id[i-1][j-k];
                sum += nums[j];
                if (j >= (i+1)*k) sum -= nums[j-k];
                if (j >= (i+1)*k-1)
                {
                    total = sum + arr[i-1][j-k];
                    arr[i][j] = total;
                    id[i][j].push_back(j+1-k);
                }
                if (j >= (i+1)*k)
                {
                    if (arr[i][j-1] >= arr[i][j])
                    {
                        arr[i][j] = arr[i][j-1];
                        id[i][j] = id[i][j-1];
                    }
                }
            }
        }
        return {id[2][nums.size()-1]};
    }
};