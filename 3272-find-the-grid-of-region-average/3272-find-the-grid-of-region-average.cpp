class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        vector<vector<int>> arr(image.size(), vector<int> (image[0].size(), -2));
        for (int i=0; i<image.size(); i++)
        {
            for (int j=0; j<image[0].size(); j++)
            {
                if (j+1<image[0].size()&&abs(image[i][j]-image[i][j+1])>threshold)
                {
                    if (i>0) {arr[i-1][j]=-1; arr[i-1][j+1]=-1;}
                             {arr[i][j]=-1; arr[i][j+1]=-1;}
                    if (i+1<image.size()) {arr[i+1][j]=-1; arr[i+1][j+1]=-1;}
                }
                if (i+1<image.size()&&abs(image[i][j]-image[i+1][j])>threshold)
                {
                    if (j>0) {arr[i][j-1]=-1; arr[i+1][j-1]=-1;}
                             {arr[i][j]=-1; arr[i+1][j]=-1;}
                    if (j+1<image[0].size()) {arr[i][j+1]=-1; arr[i+1][j+1]=-1;}
                }
            }
        }
        for (int i=0; i<image.size(); i++) {arr[i][0]=-1; arr[i][image[0].size()-1]=-1;}
        for (int j=0; j<image[0].size(); j++) {arr[0][0]=-1; arr[image.size()-1][j]=-1;}
        //vector<vector<int>> ans=image;
        for (int i=1; i<image.size()-1; i++)
        {
            for (int j=1; j<image[0].size()-1; j++)
            {
                if (arr[i][j]!=-1)
                {
                    arr[i][j]=(image[i][j]+image[i][j-1]+image[i][j+1]+
                               image[i-1][j]+image[i-1][j-1]+image[i-1][j+1]+
                               image[i+1][j]+image[i+1][j-1]+image[i+1][j+1])/9;
                }
            }
        }
        int temp, count;
        for (int i=0; i<image.size(); i++)
        {
            for (int j=0; j<image[0].size(); j++)
            {
                temp=0; count=0;
                if (i>0&&j>0&&arr[i-1][j-1]>=0) {temp+=arr[i-1][j-1]; count++;}
                if (i>0&&arr[i-1][j]>=0) {temp+=arr[i-1][j]; count++;}
                if (i>0&&j+1<image[0].size()&&arr[i-1][j+1]>=0) {temp+=arr[i-1][j+1]; count++;}
                if (j>0&&arr[i][j-1]>=0) {temp+=arr[i][j-1]; count++;}
                if (arr[i][j]>=0) {temp+=arr[i][j]; count++;}
                if (j+1<image[0].size()&&arr[i][j+1]>=0) {temp+=arr[i][j+1]; count++;}
                if (i+1<image.size()&&j>0&&arr[i+1][j-1]>=0) {temp+=arr[i+1][j-1]; count++;}
                if (i+1<image.size()&&arr[i+1][j]>=0) {temp+=arr[i+1][j]; count++;}
                if (i+1<image.size()&&j+1<image[0].size()&&arr[i+1][j+1]>=0) {temp+=arr[i+1][j+1]; count++;}
                if (count>0) image[i][j]=temp/count;
            }
        }
        return image;
    }
};