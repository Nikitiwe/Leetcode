bool ssort(vector<int> a, vector<int> b)
{
    return a[0]<b[0];
}

class Solution {
public:
    vector<int> sortJumbled(vector<int>& m, vector<int>& nums) {
        vector<vector<int>> arr(nums.size(), vector<int> (2, 0));
        for (int i=0; i!=nums.size(); i++)
        {
            arr[i][1]=nums[i];
            int t=0;
            string s=to_string(nums[i]);
            for (int j=0; j!=s.size(); j++)
            {
                t*=10;
                t+=m[s[j]-'0'];
            }
            arr[i][0]=t;
        }
        stable_sort(arr.begin(), arr.end(), ssort);
        for (int i=0; i!=nums.size(); i++) nums[i]=arr[i][1];
        return nums;
    }
};