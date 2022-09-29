// class StockPrice {
// public:
//     set<int>s;
//     priority_queue<int>time;
//     unordered_map<int,int>cost;
//     StockPrice() {
        
//     }
    
//     void update(int timestamp, int price) {
//         if(s.find(cost[timestamp])!=s.end()){
//             s.erase(cost[timestamp]);
//             cost[timestamp] = price;
//             time.push(timestamp);
//             s.insert(cost[timestamp]);
//         }
//         else{
//             time.push(timestamp);
//             s.insert(cost[timestamp]);
//             cost[timestamp] = price;
//         }
//     }
    
//     int current() {
//         return cost[time.top()];
//     }
    
//     int maximum() {
//         return *(--s.end());
//     }
    
//     int minimum() {
//         return *(s.begin());
//     }
// };

// /**
//  * Your StockPrice object will be instantiated and called as such:
//  * StockPrice* obj = new StockPrice();
//  * obj->update(timestamp,price);
//  * int param_2 = obj->current();
//  * int param_3 = obj->maximum();
//  * int param_4 = obj->minimum();
//  */



class StockPrice {
    unordered_map<int, int> mp; 
    priority_queue<pair<int, int>> maxp; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minp; 
    int latest = 0; 
    
public:
    StockPrice() {}
    
    void update(int timestamp, int price) {
        mp[timestamp] = price; 
        if (latest < timestamp) latest = timestamp; 
        maxp.emplace(price, timestamp); 
        minp.emplace(price, timestamp); 
    }
    
    int current() {
        return mp[latest]; 
    }
    
    int maximum() {
        while (mp[maxp.top().second] != maxp.top().first) maxp.pop(); 
        return maxp.top().first; 
    }
    
    int minimum() {
        while (mp[minp.top().second] != minp.top().first) minp.pop(); 
        return minp.top().first; 
    }
};