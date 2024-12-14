class Solution {
public:
    int minOperations(vector<int>& nums, int a) {
        long sum=0;
        for (int i=0; i!=nums.size(); i++) sum+=nums[i];
        if (sum<a) return -1;
        vector<int> arr(33, 0), tarr=arr;
        int t=a, l=0;
        while (t>=1)
        {
            if (t%2==1) tarr[l]++;
            t/=2;
            l++;
        }
        for (int i=0; i!=nums.size(); i++)
        {
            t=nums[i];
            int b=0;
            while (t>1)
            {
                t/=2;
                b++;
            }
            arr[b]++;
        }
        //return arr[5];
        //return 10000*arr[0]+1000*arr[1]+100*arr[2]+10*arr[3]+1*arr[4];
        //return 1000*tarr[0]+100*tarr[1]+10*tarr[2];
        int ans=0;
        for (int i=0; i<arr.size()-1; i++)
        {
            while(arr[i]<tarr[i]||arr[i]<0)
            {
                arr[i]+=2;
                arr[i+1]--;
                ans++;
            }
            while (arr[i]>tarr[i]+1)
            {
                arr[i]-=2;
                arr[i+1]++;
            }
        }
        return ans;
    }
};