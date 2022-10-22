class Solution {
public:
   
    int helper(string s,string t,int i,int j,vector<vector<int>>& dp){
        
        if(j>=t.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        char c=t[j];//this is the current character of t which needs to be macthed
    
        //and we are at the ith postion currently
        int k=i,cct=0;
		//cct means clowise count fro clockwise rotation
        int p=i,act=0;
      //act means anitclockwise count fot anticlockwise rotation
        while(true){
            if(s[k]==c){
                break;
            }
            k++;
            cct++;
            if(k==s.size()){
                k=0;
            }
        }
        while(true){
            if(s[p]==c){
                break;
            }
            p--;
            act++;
            if(p<0){
                p=s.size()-1;
            }
        }
        
        return dp[i][j]=min(cct+1+helper(s,t,k,j+1,dp),act+1+helper(s,t,p,j+1,dp));
        
        
        
        
    }
    int findRotateSteps(string ring, string key) {
        //the only thing is you can rotate in two ways
        //either clockwise or anticlockwise AT EACH STEP
        //so do both and take the minimum 
        //knapscak types although not that similar
        vector<vector<int>> dp(ring.size()+1,vector<int>(key.size()+1,-1));
        return helper(ring,key,0,0,dp);
    }
};