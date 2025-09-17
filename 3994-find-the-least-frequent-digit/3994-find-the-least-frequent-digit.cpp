class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> arr(10, 0);
        vector<bool> brr(10, 0);
        int ans = n%10;
        while(n > 0)
        {
            ans = min(ans, n%10);
            arr[n%10]++;
            brr[n%10] = 1;
            n /= 10;
        }
        for (int i=0; i!=arr.size(); i++)
        {
            if (brr[i] == 1 && arr[i] < arr[ans]) ans = i;
        }
        return ans;
    }
};