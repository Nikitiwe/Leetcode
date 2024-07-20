class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> arr(high+1, 0);
        arr[0]=1;
        for (int i=0; i!=arr.size(); i++)
        {
            if (i+zero<arr.size()) {arr[i+zero]+=arr[i]; arr[i+zero]%=1000000007;}
            if (i+one<arr.size()) {arr[i+one]+=arr[i]; arr[i+one]%=1000000007;}
        }
        int ans=0;
        for (int i=low; i<=high; i++)
        {
            ans+=arr[i];
            ans%=1000000007;
        }
        return ans;
    }
};