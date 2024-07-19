class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0), arr(n, 0);
        if (n==1) return ans;
        int temp=0;
        for (int i=0; i!=queries.size(); i++)
        {
            if (queries[i][0]==0)
            {
                if (arr[0]==arr[1]&&arr[0]!=0) temp--;
                arr[0]=queries[i][1];
                if (arr[0]==arr[1]&&arr[0]!=0) temp++;
                ans[i]=temp;
            }
            else if (queries[i][0]==n-1)
            {
                if (arr[n-2]==arr[n-1]&&arr[n-1]!=0) temp--;
                arr[n-1]=queries[i][1];
                if (arr[n-2]==arr[n-1]&&arr[n-1]!=0) temp++;
                ans[i]=temp;
            }
            else
            {
                if (arr[queries[i][0]-1]==arr[queries[i][0]]&&arr[queries[i][0]]!=0) temp--;
                if (arr[queries[i][0]+1]==arr[queries[i][0]]&&arr[queries[i][0]]!=0) temp--;
                arr[queries[i][0]]=queries[i][1];
                if (arr[queries[i][0]-1]==arr[queries[i][0]]&&arr[queries[i][0]]!=0) temp++;
                if (arr[queries[i][0]+1]==arr[queries[i][0]]&&arr[queries[i][0]]!=0) temp++;
                ans[i]=temp;
            }
        }
        return ans;
    }
};