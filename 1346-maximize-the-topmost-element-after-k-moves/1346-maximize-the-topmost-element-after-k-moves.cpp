class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (k==0) return nums[0];
        if (k%2==1&&nums.size()==1) return -1;
        if (k==1) return nums[1];
        priority_queue<int> q;
        int id=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (k==1)
            {
                id=i;
                break;
            }
            else
            {
                q.push(nums[i]);
            }
            k--;
        }
        if (id<nums.size()-1) return max(q.top(), nums[id+1]);
        else return q.top();
    }
};