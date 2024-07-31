class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, long long> m;
        long long ans=0, temp;
        string s;
        for (int i=0; i!=nums.size(); i++)
        {
            s=to_string(nums[i]);
            reverse(s.begin(), s.end());
            temp=nums[i]-stoi(s);
            if (m.count(temp)==0) m.insert({temp, 1});
            else {m[temp]++; ans+=m[temp]-1;}
            ans%=1000000007;
        }
        /*for (auto it=m.begin(); it!=m.end(); it++)
        {
            temp=it->second;
            ans+=temp*(temp-1)/2;
            ans%=1000000007;
        }*/
        return ans;
    }
};