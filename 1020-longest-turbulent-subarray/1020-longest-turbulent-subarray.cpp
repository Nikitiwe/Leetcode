class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> arrd(arr.size()-1);
        int temp=0, ans=1;
        for (int i=0; i!=arr.size()-1; i++)
        {
            arrd[i]=arr[i+1]-arr[i];
            if (arrd[i]>0) {arrd[i]=1; ans=2;}
            else if (arrd[i]<0) {arrd[i]=-1; ans=2;}
        }
        for (int i=1; i<arr.size()-1; i++)
        {
            if (arrd[i]*arrd[i-1]>=0) temp=0;
            else {temp++; ans=max(ans, temp+2);}
        }
        return ans;
    }
};