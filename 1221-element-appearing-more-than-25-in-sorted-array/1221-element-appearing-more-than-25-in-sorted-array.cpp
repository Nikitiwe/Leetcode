class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if (arr.size()<4) return arr[0];
        int c=1;
        for (int i=1; i<arr.size(); i++)
        {
            if (arr[i-1]==arr[i]) c++;
            else c=1;
            if (c>arr.size()/4) return arr[i];
        }
        return -1;
    }
};