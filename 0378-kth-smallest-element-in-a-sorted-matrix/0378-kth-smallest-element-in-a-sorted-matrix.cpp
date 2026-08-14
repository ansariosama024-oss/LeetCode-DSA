class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low=matrix[0][0];
        int high = matrix.back().back();
        while(low<high){
            int mid=low+(high-low)/2;
            int count=0;
            for(auto &row : matrix){
                count+=upper_bound(row.begin(),row.end(),mid)-row.begin();
            }
            if(count<k){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};