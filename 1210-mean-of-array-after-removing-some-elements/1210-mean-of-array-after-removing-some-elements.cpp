class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        double ans=0;
        for (int i=arr.size()/20; i<arr.size()*19/20; i++) ans+=arr[i];
        return (ans/(double)arr.size())*((double)10/9);
    }
};