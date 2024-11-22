class Solution {
public:
    int minimumDeletions(string w, int k) {
        vector<int> arr(26, 0);
        for (int i=0; i!=w.size(); i++) arr[w[i]-'a']++;
        sort(arr.begin(), arr.end());
        int ans=1000000, s=0;
        for (int i=0; i!=arr.size(); i++)
        {
            int sum=0;
            for (int j=i+1; j<arr.size(); j++)
            {
                if (arr[j]>arr[i]+k) sum+=arr[j]-arr[i]-k;
            }
            ans=min(ans, sum+s);
            s+=arr[i];
        }
        return ans;
    }
};