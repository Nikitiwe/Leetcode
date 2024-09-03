class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> arr(*max_element(nums.begin(), nums.end())+1, 0);
        for (int i=0; i!=nums.size(); i++) arr[nums[i]]++;
        for (int i=1; i!=arr.size(); i++) if (arr[i]>0) m[arr[i]]++;
        for (int i=nums.size()-1; i>=0; i--)
        {
            if (m.size()<=2)
            {
                int a=-1, b=-1, s1=-1, s2=-1;
                for (auto j=m.begin(); j!=m.end(); j++)
                {
                    if (a==-1) {a=j->first; s1=j->second;}
                    else {b=j->first; s2=j->second;}
                }
                if (b>a) {swap(a, b); swap(s1, s2);}
                if (b==-1&&(s1==1||a==1)) return i+1;
                else if (a==b+1&&s1==1) return i+1;
                else if (b==1&&s2==1) return i+1;
            }
            m[arr[nums[i]]]--;
            if (m[arr[nums[i]]]==0) m.erase(arr[nums[i]]);
            m[arr[nums[i]]-1]++;
            m.erase(0);
            arr[nums[i]]--;
        }
        return 1;
    }
};