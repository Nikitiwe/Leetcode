class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x<=y) return y-x;
        vector<int> arr(x+11, 0);
        for (int i=x+1; i<arr.size(); i++) arr[i]=arr[i-1]+1;
        for (int i=x-1; i>=1; i--)
        {
            arr[i]=arr[i+1]+1;
            if (5*i<arr.size())
            {
                arr[i]=min(arr[i], arr[i*5]+1);
                for (int l=i+1; l<=i+5; l++) arr[l]=min(arr[l], arr[l-1]+1);
            }
            if (11*i<arr.size()) 
            {
                arr[i]=min(arr[i], arr[i*11]+1);
                for (int l=i+1; l<=i+11; l++) arr[l]=min(arr[l], arr[l-1]+1);
            }
        }
        for (int i=2; i<=y; i++)
        {
            arr[i]=min(arr[i], arr[i-1]+1);
        }
        return arr[y];

    }
};