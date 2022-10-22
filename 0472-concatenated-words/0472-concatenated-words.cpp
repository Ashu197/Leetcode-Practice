	class Solution {
	public:
	
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<string> ans;
		unordered_set<string>dict(words.begin(),words.end());
			
		for(auto w : words){
			int n = w.size();
			if(n == 0) continue;
			bool dp[n+1];
			memset(dp,false,sizeof(dp));
			dp[0] = true;
		
			for(int i=0; i<n; i++){
				if(dp[i] == false) continue;
				string generate="";
			
				for(int j=i; j<n; j++){
					generate += w[j];
					if(dp[j+1])continue;
					if(i==0 && j==n-1)continue;
					if(dict.find(generate) != dict.end())
						dp[j+1]=true;
				}
				
				if(dp[n]){
					ans.push_back(w);
					break;
				}
			}    
		}
				
		return ans;
	}
};