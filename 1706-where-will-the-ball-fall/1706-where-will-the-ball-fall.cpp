class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<n;i++){
            int row=0,l=i;
            while(row<m){
                if(grid[row][l]==1 && l<n-1 && grid[row][l+1]==1){
                    l++;
                }
                else if(grid[row][l]==-1 && l>0 && grid[row][l-1]==-1){
                    l--;
                }
                else{
                    ans.push_back(-1);
                    break;
                }
                row++;
                if(row==m){
                    ans.push_back(l);
                    break;
                }
            }
        }
        return ans;
    }
};