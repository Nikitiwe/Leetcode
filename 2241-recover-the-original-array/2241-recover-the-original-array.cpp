class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        unordered_map<int, int> m, arr, arr1;
        sort(nums.begin(), nums.end());
        for (int i=0; i!=nums.size(); i++) arr[nums[i]]++;
        arr1=arr;
        vector<int> ans;
        for (int i=0; i!=1; i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                if (nums[j]-nums[i]>0&&(nums[j]-nums[i])%2==0) m[(nums[j]-nums[i])/2]++;
            }
        }
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            int k=i->first;
            if (arr1.count(nums[nums.size()-1]-2*k)>0)
            {
                ans.clear();
                arr=arr1;
                for (int j=0; j!=nums.size(); j++)
                {
                    if (arr.count(nums[j])>0&&arr.count(nums[j]+2*k)>0)
                    {
                        ans.push_back(nums[j]+k);
                        arr[nums[j]]--;
                        if (arr[nums[j]]==0) arr.erase(nums[j]);
                        arr[nums[j]+2*k]--;
                        if (arr[nums[j]+2*k]==0) arr.erase(nums[j]+2*k);
                    }
                    //else break;
                }
                if (ans.size()==nums.size()/2) return ans;
            }
        }
        return ans;
    }
};