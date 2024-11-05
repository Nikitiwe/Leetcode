class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k>=arr.size()-1) return *max_element(arr.begin(), arr.end());
        int l=0, c=0, t=arr[0];
        while (1)
        {
            if (arr[(l+1)%arr.size()]<t)
            {
                c++;
            }
            else
            {
                c=1;
                t=arr[(l+1)%arr.size()];
            }
            if (c==k) return t;
            l++;
        }
        return -1;
    }
};