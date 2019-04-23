struct Node{
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(){}
    Node(int k, int v){
        key = k;
        value = v;
    }
};

class LRUCache {
public:
    map<int, Node *>mp;
    map<int, Node *>::iterator it;
    int size;
    Node *head;
    Node *tail;

    LRUCache(int capacity) {
        size = capacity;
        head = (Node *)malloc(sizeof(Node));
        tail = (Node *)malloc(sizeof(Node));
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        it = mp.find(key);
        if (it != mp.end()){
             Node *node = (it->second);
             mp.erase(key);

            node->prev->next = node->next;
            node->next->prev = node->prev;

            appendTail(node);
            mp[key] = node;
        }

        int value = it == mp.end() ? -1 : it->second->value;
        
        return value;
    }
    
    void put(int key, int value) {
        it = mp.find(key);
        Node *node;
        if (it != mp.end()){
            mp.erase(key);
            node = it->second;
            
            node->prev->next = node->next;
            node->next->prev = node->prev;
            
            node->value = value;
        }else if (mp.size() == size){
            Node *tmp = head->next;
            mp.erase(tmp->key);
            
            head->next = tmp->next;
            tmp->next->prev = head;
            
            free(tmp);
        }
        
        if (it == mp.end()){
            node = (Node *)malloc(sizeof(Node));
            node->key = key;
            node->value = value;
        }
        appendTail(node);
        mp[key] = node;
    }
    
    void appendTail(Node *node){
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
