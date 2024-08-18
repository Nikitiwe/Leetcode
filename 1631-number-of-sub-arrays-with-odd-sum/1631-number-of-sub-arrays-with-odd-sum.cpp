class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int> sum(arr.size()+1, 0);
        int countodd=0, counteven=1;
        for (int i=0; i!=arr.size(); i++)
        {
            sum[i+1]=sum[i]+arr[i];
            if (sum[i+1]%2==0) counteven++;
            else countodd++;
        }
        return ((long)countodd*(long)counteven)%1000000007;
    }
};