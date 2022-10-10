class Solution {
public:
    static const int MOD = 1e9 + 7;
    int maxProfit(vector<int>& inventory, int orders){
        unordered_map<int, int> mp;
        
        priority_queue<int> pq;
        for(int i = 0; i < inventory.size(); ++i){
            if(mp.find(inventory[i]) == mp.end())
                pq.push(inventory[i]);
            ++mp[inventory[i]];
        }
        
        int64_t cost = 0;
        while(orders > 0){
            int max_cost = pq.top();        pq.pop();
            int counter = mp[max_cost];
            
            mp[max_cost] = 0;   
            if(!pq.empty()){
                mp[pq.top()] += counter;
            }
            
            int64_t balls = (!pq.empty())?max_cost - pq.top(): max_cost;
            int64_t total_ball = counter * balls;

            if(total_ball >= orders){
                int64_t complete = (orders / counter);
                int64_t start = max_cost - complete + 1;


                int64_t a = complete;
                int64_t b = (max_cost + start);
                int64_t current_cost = ((a * b)/2)% MOD;
                
                current_cost = (current_cost * counter)% MOD;
                
                orders = orders - (complete * counter);
                --start;
                for(int i = 0; i < orders; ++i){
                    current_cost = (current_cost + start) % MOD;
                }

                cost = (cost + current_cost) % MOD;
                orders = 0;
            } else{
                int64_t s = (!pq.empty())? pq.top(): 0;

                int64_t a = balls;
                int64_t b = (max_cost + s + 1);

                int64_t current_cost = ((a * b)/2) % MOD;
                current_cost = (current_cost * counter) % MOD;

                cost = (cost + current_cost) % MOD;
                orders -= total_ball;
            }
        }
        return cost;
    }
};