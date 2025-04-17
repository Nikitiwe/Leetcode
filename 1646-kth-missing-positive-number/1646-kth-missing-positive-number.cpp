class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int c = 0, l = 0;
        for (int i=1; i!=3000; i++)
        {
            if (l >= arr.size() || arr[l] != i)
            {
                c++;
                if (c == k) return i;
            }
            else l++;
        }
        return -1;
    }
};