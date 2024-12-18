class Solution {
public:
    bool hasGroupsSizeX(vector<int>& nums) {
        unordered_map<int, int> m;
        int mi=10000;
        for (int i=0; i!=nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            mi=min(mi, i->second);
        }
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            mi=gcd(mi, i->second);
        }
        if (mi==1) return 0;
        else return 1;
    }
};