class Solution {
public:
    int mod=1e9+7;
    int getNumberOfBacklogOrders(vector<vector<int>>& nums) {
        priority_queue<pair<int,long long int>>buy;
        priority_queue<pair<int,long long int>,vector<pair<int,long long int>>,greater<pair<int,long long int>>>sell;
        int maxi1=0,maxi2=0;
        
        
        for(int i=0;i<nums.size();i++){
            if(nums[i][2]==0){//buy
                bool b=false;
                
                while(!sell.empty() and sell.top().first<=nums[i][0] and nums[i][1]>0){
                    pair<int,long long int>p=sell.top();
                    sell.pop();
                    if(p.second>nums[i][1]){
                        b=true;
                        sell.push({p.first,p.second-nums[i][1]});
                            break;
                    }
                    nums[i][1]=abs(p.second - nums[i][1]);
                }
                if(b){continue;}
                
                if(nums[i][1]>0 ){
                    maxi1=nums[i][1];
                    buy.push({nums[i][0],nums[i][1]});
                }
            }
            else{//sell
                bool b=false;
                
                while(!buy.empty() and buy.top().first>=nums[i][0] and nums[i][1]>0){
                    pair<int,long long int>p=buy.top();
                    buy.pop();
                    if(p.second>nums[i][1]){
                        b=true;
                        buy.push({p.first,p.second-nums[i][1]});
                            break;
                    }
                    nums[i][1]=abs(p.second - nums[i][1]);
                }
                if(b){continue;}
                
                if(nums[i][1]>0 ){
                    maxi2=nums[i][1];
                    sell.push({nums[i][0],nums[i][1]});
                }
                
            }
        }
        
        int cnt=0;
        while(!sell.empty()){
            cnt=(cnt+((sell.top().second % mod)))%mod;
            sell.pop();
        }
        while(!buy.empty()){
            cnt=(cnt+((buy.top().second % mod)))%mod;
            buy.pop();
        }
        return cnt;
        
    }
};