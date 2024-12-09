class Solution {
public:
    int maximizeWin(vector<int>& nums, int kk) {
        long k=kk;
        unordered_set<int> n(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for (int i=0; i!=nums.size(); i++)
        {
            n.insert(nums[i]+k);
            m[nums[i]]++;
        }
        vector<long> arr(n.size(), 0), id=arr;
        int j=0;
        for (auto i=n.begin(); i!=n.end(); i++)
        {
            id[j]=*i;
            j++;
        }
        sort(id.begin(), id.end());
        int l=0, c=0;
        for (int i=0; i!=arr.size(); i++)
        {
            if (m.count(id[i])>0) c+=m[id[i]];
            while (id[l]+k<id[i])
            {
                if (m.count(id[l])>0) c-=m[id[l]];
                l++;
            }
            arr[i]=c;
        }
        long ans=0, ma1=arr[0];
        l=0;
        for (int i=0; i!=arr.size(); i++)
        {
            while (l+1<arr.size()&&id[l+1]+k<id[i])
            {
                l++;
                ma1=max(ma1, arr[l]);
            }
            if (id[l]+k<id[i]) ans=max(ans, arr[i]+ma1);
        }
        if (ans>0) return ans;
        else return nums.size();
    }
};