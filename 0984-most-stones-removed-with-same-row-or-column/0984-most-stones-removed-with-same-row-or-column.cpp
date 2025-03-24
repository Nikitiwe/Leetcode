class Solution {
public:
    int removeStones(vector<vector<int>>& nums) {
        // из каждой компоненты связности останется один камень
        vector<int> isit(nums.size(), 1);
        int count = 0;
        int ans = nums.size();
        while (count < nums.size())
        {
            unordered_set<int> x, y;
            queue<int> q;
            for (int i=0; i!=nums.size(); i++)
            {
                if (isit[i] == 1)
                {
                    isit[i] = 0;
                    count++;
                    q.push(i);
                    x.insert(nums[i][0]);
                    y.insert(nums[i][1]);
                    break;
                }
            }
            while(1)
            {
                int c = q.size();
                for (int i=0; i!=nums.size(); i++)
                {
                    if (isit[i] == 1 && (x.count(nums[i][0]) == 1 || y.count(nums[i][1]) == 1) )
                    {
                        isit[i] = 0;
                        count++;
                        q.push(i);
                        x.insert(nums[i][0]);
                        y.insert(nums[i][1]);
                    }
                }
                if (c == q.size()) break;
            }
            ans--;
        }
        return ans;
    }
};