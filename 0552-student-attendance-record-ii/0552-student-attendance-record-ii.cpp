class Solution {
public:
    int mod = 1e9+7;
    int dp[100001][2][3];
    int solve(int idx,int s,int ab,int l)
    {
        if(idx>=s)
        return 1;
        if(dp[idx][ab][l]!=-1)
        return dp[idx][ab][l];
        if(ab>0)
        {
            if(l>0)
            {
                long long takeL = solve(idx+1,s,ab,l-1);
                long long takeAb = solve(idx+1,s,ab-1,2);
                long long notTake = solve(idx+1,s,ab,2);
                return dp[idx][ab][l]=(takeL+takeAb+notTake)%mod;
            }
            else 
            {
                long long takeAb = solve(idx+1,s,ab-1,2);
                long long notTake = solve(idx+1,s,ab,2);
                return dp[idx][ab][l]=(takeAb+notTake)%mod;
            }
        }
        else if(l>0)
        {
            long long takeL = solve(idx+1,s,ab,l-1);
            long long notTake = solve(idx+1,s,ab,2);
            return dp[idx][ab][l]=(takeL+notTake)%mod;
        }
        else
        {
            long long notTake = solve(idx+1,s,ab,2);
            return dp[idx][ab][l] = notTake;
        }
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n,1,2);
    }
};