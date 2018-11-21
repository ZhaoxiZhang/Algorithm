class LRUCache {
    class Node{
        Integer key;        
        Integer value;
        Node prev;
        Node next;

        public Node(Integer key, Integer value){
            this.key = key;
            this.value = value;
        }
    }

    private Map<Integer, Node>map;
    Node head;
    Node tail;
    int size;

    public LRUCache(int capacity) {
        size = capacity;
        map = new HashMap<>(capacity);
        head = new Node(null, null);
        tail = new Node(null, null);

        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        Node node = map.get(key);
        if (null != node){
            map.remove(node.key);

            node.prev.next = node.next;
            node.next.prev = node.prev;

            appendTail(node);
            map.put(key, node);
        }

        int value = null == node ? -1 : node.value;
        return value;
    }
    
    public void put(int key, int value) {
        Node node = map.get(key);
        if (null != node){
            map.remove(node.key);

            node.prev.next = node.next;
            node.next.prev = node.prev;

            node.value = value;
        }else if (map.size() == size){
            Node tmp = head.next;
            map.remove(tmp.key);

            head.next = tmp.next;
            tmp.next.prev = head;

            tmp = null;
        }

        if (null == node)   node = new Node(key, value);
        appendTail(node);
        map.put(key, node);
    }

    public void appendTail(Node node){
        tail.prev.next = node;
        node.prev = tail.prev;
        node.next = tail;
        tail.prev = node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */