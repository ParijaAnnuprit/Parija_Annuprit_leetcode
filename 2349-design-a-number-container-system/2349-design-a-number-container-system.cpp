// unordered_map<int,set<int>>mnum;
// unordered_map<int,int>mind;

// class NumberContainers {
// public:
//     NumberContainers() {
        
//     }
    
//     void change(int index, int number) {
//         if(mind.find(index)==mind.end()){
//             mind[index]=number;
//             mnum[number].insert(index);
//         }
//         else if(mind.find(index)!=mind.end()){
//             int x = mind[index];
//             mnum[x].erase(index);
//             mind[index]=number;
//             mnum[number].insert(index);
//         }
//     }
    
//     int find(int number) {
//         if(mnum.find(number)==mnum.end())
//             return -1;
//         return *mnum[number].begin();
//     }
// };

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */


class NumberContainers {
public:
    unordered_map<int,set<int>>map_nums; //(number,{index}) (used set in place of unordered set to get minimum quickly )
    unordered_map<int,int>map_index;// (index,number)
    NumberContainers() {
        
    }
    void change(int index, int number) {
         //if index already exists we have to change the map_index at given "index"
         if(map_index.find(index)!=map_index.end())
         {
             int num=map_index[index];  
             if(map_nums[num].size()) map_nums[num].erase(index);
             if(map_nums[num].size()==0)
                 map_nums.erase(num);
         }
          map_index[index]=number;
            map_nums[number].insert(index);    
    }
    
    int find(int number) {
        if(map_nums.find(number)==map_nums.end())
            return -1;
        return *map_nums[number].begin();
    }
};
