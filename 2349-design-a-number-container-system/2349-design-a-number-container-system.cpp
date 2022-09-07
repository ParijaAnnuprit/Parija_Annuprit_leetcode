


class NumberContainers {
public:
    unordered_map<int,priority_queue<int,vector<int>, greater<int>>>mnum;
    unordered_map<int,int>mind;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        mind[index]=number;
        mnum[number].push(index);
    }
    
    int find(int number) {
        while(mnum[number].size()){
            if(mind[mnum[number].top()]==number) return mnum[number].top();
            else mnum[number].pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */