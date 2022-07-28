// class node{
//     public:
//     int val;
//     node* next;
//     node(int val){
//         this->val = val;
//         next = NULL;
//     }
// }


// class MyLinkedList {
// public:
//     node* head = new node(0);
//     int size =0;
    
//     MyLinkedList() {
        
//     }
    
//     int get(int index) {
//         if(index>size)
//             return -1;
//         node*temp = head;
//         while(index>=0){
//             temp = temp->next;
//             index--;
//         }
//         return temp->val;
//     }
    
//     void addAtHead(int val) {
//         node*temp = head;
//         node*nnode= new node(val);
//         if(temp->next==NULL){
//             temp->next=nnode;
//             size++;
//         }
//         else{
//             temp= temp->next;
//             head->next =nnode;
//             nnode->next = temp;
//             size++;
//         }
        
//     }
    
//     void addAtTail(int val) {
//         node*temp = head;
//         node*nnode= new node(val);
//         while(temp->next != NULL){
//             temp= temp->next;
//         }
//         temp->next= nnode;
//         size++;
//     }
    
//     void addAtIndex(int index, int val) {
//         node*temp = head;
//         node*nnode = new node(val);
//         if(index>size)
//             return ;
//         else if(index=0)
//             addAtHead(val);
//         else if(index==size)
//             addAtTail(val);
//         else{
//             while(index>0){
//                 temp = temp->next;
//             }
//             node*temp2 = temp->next;
//             temp->next = nnode;
//             nnode->next = temp2;
//             size++;
//         }
//     }
    
//     void deleteAtIndex(int index) {
//         node*temp = head;
//         if(index>size)
//             return;
//         else if(index==1){
//             if(size==1){
//                 temp->next;
//                 delete(temp);
//             }
//             else{
//                 node* temp2 = temp->next;
//                 temp = temp->next->next;
//                 head->next=temp2;
//                 delete(temp2);
//             }
//         }
//     }
// };

// /**
//  * Your MyLinkedList object will be instantiated and called as such:
//  * MyLinkedList* obj = new MyLinkedList();
//  * int param_1 = obj->get(index);
//  * obj->addAtHead(val);
//  * obj->addAtTail(val);
//  * obj->addAtIndex(index,val);
//  * obj->deleteAtIndex(index);
//  */

class Node {
    public: 
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};
class MyLinkedList {
public:
    int size = 0;
    Node* head = NULL;
    Node* tail = NULL;
    MyLinkedList() {
        
    }
    // void display() {
    //     Node* temp = head;
    //     while(temp!=NULL) {
    //         cout<<temp->val<<" ";
    //         temp=temp->next;
    //     }
    //     cout<<endl;
    // }
    int get(int index) {
        if(index >= size)
            return -1;
        Node* temp = head;
        for(int i=0; i<index; ++i)
            temp = temp->next;
        
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* nnode = new Node(val);
        nnode->next = head;
        head = nnode;
        if(size==0)
            tail = nnode;
        // cout<<"Added at head "<< val<<endl;
        // display();
        size++;
    }
    
    void addAtTail(int val) {
        if(size ==0) {
            addAtHead(val);
            return;
        }
        Node* nnode = new Node(val);
        tail->next = nnode;
        tail = nnode;
        // cout<<"Added at Tail "<< val<<endl;
        // display();
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size)
            return;
        else if(index == size)
            addAtTail(val);
        else if(index==0)
            addAtHead(val);
        else {
            Node* temp =head;
            Node* nnode = new Node(val);
            for(int i=0; i<index-1; ++i) {
                temp = temp->next;
            }
            nnode->next = temp->next;
            temp->next = nnode;
            // cout<<"Added at index "<< index<<" val "<<val<<endl;
            // display();
            
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index>=size)
            return;
        else if(index == size-1) {
           
            if(index==0){
                head==NULL;
                tail==NULL;
            }
            else {
                Node* temp = head;
                while(temp->next!=tail) {
                    temp= temp->next;
                }
                tail = temp;
                temp->next = NULL;
            }
           
        }
        else if(index==0) {
            Node* temp = head;
            head = head->next;
            temp =NULL;
        }
        else {
            Node* temp = head;
            for(int i=0; i<index-1;++i) {
                temp = temp->next;
            }
            Node* t = temp->next;
            temp->next = temp->next->next;
            t->next = NULL;
            
        }
        // cout<<"Deleted at index "<< index<<endl;
        // display();
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */