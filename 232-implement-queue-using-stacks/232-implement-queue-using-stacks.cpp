class MyQueue {
public:
//     amortized o(1)
    stack<int>st;
    stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            while(!st.empty()){
                int y = st.top();
                st.pop();
                st2.push(y);
            }
        }
        int x = st2.top();
        st2.pop();
        return x;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st.empty()){
                int y = st.top();
                st.pop();
                st2.push(y);
            }
        }
        int x = st2.top();
        return x;
    }
    
    bool empty() {
        return (st.empty() && st2.empty())? true: false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// stack<int> stackPush;
// stack<int> stackPop;
// MyQueue() {

// }

// void push(int x) {
//     stackPush.push(x);
// }

// int pop() {
//     int temp;
//     if (!stackPop.empty()) {
//          temp = stackPop.top();
//          stackPop.pop();
//         return temp;
//     }
//     else{
//         while (!stackPush.empty()){
//             temp = stackPush.top();
//             stackPush.pop();
//             stackPop.push(temp);
//         }
//         stackPop.pop();
//         return temp;
//     }
// }

// int peek() {
//     int temp;
//     if (!stackPop.empty()){
//         return stackPop.top();
//     }
//     else {
//         while (!stackPush.empty()){
//             temp = stackPush.top();
//             stackPush.pop();
//             stackPop.push(temp);
//         }
//         return temp;
//     }
// }

// bool empty() {
//     return (stackPush.empty() && stackPop.empty());
// }