class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k>=arr.size()-1) return *max_element(arr.begin(), arr.end());
        int l=0, c=0, t=arr[0];
        while (1)
        {
            l++;
            if (arr[l%arr.size()]<t)
            {
                c++;
            }
            else
            {
                c=1;
                t=arr[l%arr.size()];
            }
            if (c==k) return t;
        }
        return -1;
    }
};