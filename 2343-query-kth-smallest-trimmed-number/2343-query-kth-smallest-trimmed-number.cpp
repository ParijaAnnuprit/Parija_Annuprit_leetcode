class Solution {
public:
    int solve(int trim , int k ,vector<string> & nums){
	priority_queue<pair<string,int>> pq;
	int n = nums.size();
	for(int i = 0 ; i < n ; i++){
		string s = nums[i];
		if(trim < s.size()) {
			s = s.substr(s.size() - trim);
		}
		
		pq.push(make_pair(s,i));
	}
	while(pq.size() > k) pq.pop();
	return pq.top().second;
}

vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
    vector<int> ans;
    for(int i = 0 ; i < queries.size() ; i++){
    	int trim = queries[i][1];
    	int k = queries[i][0];
    	int t = solve(trim,k,nums);
    	ans.push_back(t);
    }
    return ans;
}
};