class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;

            Node(int key, int val){
                this->key = key;
                this->val = val;
                // key = k;
                // val = v;
            }
    };

    int capacity;
    unordered_map<int,Node*> hashmap; // store key and Node pointer
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);


    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode){
        // head -> next
        //  \\     //
        //   newNode
        newNode->next = head->next;
        newNode->prev = head;

        head->next->prev = newNode;
        head->next = newNode;
    }

    void deleteNode(Node* delNode){
        //  ---------------->
        // prev -> curr -> next
        //  <----------------

        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }
    
    int get(int key) {
        if(hashmap.find(key) != hashmap.end()){
            // if key is found
            Node* resNode = hashmap[key];
            int ans = resNode->val;

            // updating Node
            deleteNode(resNode);
            addNode(resNode);

            hashmap[key] = head->next; // hashmap[key] = value // overwritten
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hashmap.find(key) != hashmap.end()){
            Node* curr = hashmap[key];
            hashmap.erase(key);
            deleteNode(curr);
        }

        if(hashmap.size() == capacity){
            hashmap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        hashmap[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */