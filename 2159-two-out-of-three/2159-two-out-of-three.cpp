class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> n1, n2, n3;
        for (int i=0; i!=nums1.size(); i++) n1.insert(nums1[i]);
        for (int i=0; i!=nums2.size(); i++) n2.insert(nums2[i]);
        for (int i=0; i!=nums3.size(); i++) n3.insert(nums3[i]);
        unordered_map<int, int> m;
        for (auto i=n1.begin(); i!=n1.end(); i++) m[*i]++;
        for (auto i=n2.begin(); i!=n2.end(); i++) m[*i]+=2;
        for (auto i=n3.begin(); i!=n3.end(); i++) m[*i]+=4;
        vector<int> ans;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second==3||i->second>=5) ans.push_back(i->first);
        }
        return ans;
    }
};