class Solution {
public:
    int magicalString(int n) {
        vector<int> arr{1,2,2};
        int l = 2;
        int ans = 0;
        while (arr.size() < n)
        {
            if (arr[l] == 2)
            {
                arr.push_back(3 - arr.back());
                arr.push_back(arr.back());
            }
            else
            {
                arr.push_back(3 - arr.back());
            }
            l++;
        }
        for (int i=0; i<n; i++) if (arr[i] == 1) ans++;
        return ans;
    }
};