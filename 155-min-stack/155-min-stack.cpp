// class MinStack {
// public:
//     int mini = INT_MAX;
//     vector<int>st;
//     MinStack() {
//     }
    
//     void push(int val) {
//         mini = min(mini,val);
//         st.push_back(mini);
//         st.push_back(val);
//     }
    
//     void pop() {
//         st.pop_back();
//         st.pop_back();
//     }
    
//     int top() {
//         int n = st[st.size()-1];
//         return n;
//     }
    
//     int getMin() {
//         return st[st.size()-2];
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


class MinStack {
public:
    
    // pair<current added value, current minimum value>
    stack<pair<int, int>> record;
    
    MinStack(){
        
    }
    
    void push(int val){
      //there is no minimum in the stack
      if(record.empty())
        record.push({val, val});
      else{
        int mini=min(val, record.top().second);
        record.push({val, mini});
      }
    }
    
    void pop(){
      record.pop();
    }
    
    int top(){
      return record.top().first;
    }
    
    int getMin(){
      return record.top().second;
    }
};