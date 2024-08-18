class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int countodd=0, counteven=1;
        if (arr[0]%2==0) counteven++;
        else countodd++;
        for (int i=1; i!=arr.size(); i++)
        {
            arr[i]+=arr[i-1];
            if (arr[i]%2==0) counteven++;
            else countodd++;
        }
        return ((long)countodd*(long)counteven)%1000000007;
    }
};