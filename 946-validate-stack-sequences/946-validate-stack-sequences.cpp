// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         stack<int>st;
//         int k=0;
//         int n = popped.size();
//         for(int i= 0;i<pushed.size();i++){
//             st.push(pushed[i]);
//             if(st.top()==popped[k] && st.size()>0){
//                 st.pop();
//                 k++;
//             }
//         }
//         if(st.size()==0)
//             return true;
//         return false;
//     }
// };

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st; // Create a stack
        
        int j = 0; // Intialise one pointer pointing on popped array
        
        for(auto val : pushed){
            st.push(val); // insert the values in stack
            while(st.size() > 0 && st.top() == popped[j]){ // if st.peek() values equal to popped[j];
                st.pop(); // then pop out
                j++; // increment j
            }
        }
        return st.size() == 0; // check if stack is empty return true else false
    }
};