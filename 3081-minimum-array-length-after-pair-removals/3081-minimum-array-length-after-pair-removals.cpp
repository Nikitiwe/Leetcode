class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i=0; i!=nums.size(); i++) m[nums[i]]++;
        int ma=0;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            ma=max(ma, i->second);
        }
        if (ma<=nums.size()/2)
        {
            if (nums.size()%2==0) return 0;
            else return 1;
        }
        else
        {
            return 2*ma-nums.size();
        }
        return -1;
        
    }
};