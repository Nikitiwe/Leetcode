class Solution {
public:
    int countTexts(string pressedKeys) {
        long long ans=1, temp=1;
        pressedKeys+='0';
        for (int i=1; i!=pressedKeys.size(); i++)
        {
            if (pressedKeys[i]==pressedKeys[i-1]) temp++;
            else if (pressedKeys[i-1]=='7'||pressedKeys[i-1]=='9')
            {
                vector<long long> arr(temp+1, 0);
                arr[0]=1;
                for (int j=1; j!=temp+1; j++)
                {
                    arr[j]+=arr[j-1];
                    if (j>1) arr[j]+=arr[j-2];
                    if (j>2) arr[j]+=arr[j-3];
                    if (j>3) arr[j]+=arr[j-4];
                    arr[j]%=1000000007;
                }
                ans*=arr[temp];
                ans%=1000000007;
                temp=1;
            }
            else
            {
                vector<long long> arr(temp+1, 0);
                arr[0]=1;
                for (int j=1; j!=temp+1; j++)
                {
                    arr[j]+=arr[j-1];
                    if (j>1) arr[j]+=arr[j-2];
                    if (j>2) arr[j]+=arr[j-3];
                    arr[j]%=1000000007;
                }
                ans*=arr[temp];
                ans%=1000000007;
                temp=1;
            }
        }
        return ans;
    }
};