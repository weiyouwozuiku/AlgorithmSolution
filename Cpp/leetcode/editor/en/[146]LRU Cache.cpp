//Design a data structure that follows the constraints of a Least Recently Used 
//(LRU) cache. 
//
// Implement the LRUCache class: 
//
// 
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity. 
//
// int get(int key) Return the value of the key if the key exists, otherwise 
//return -1. 
// void put(int key, int value) Update the value of the key if the key exists. 
//Otherwise, add the key-value pair to the cache. If the number of keys exceeds 
//the capacity from this operation, evict the least recently used key. 
// 
//
// The functions get and put must each run in O(1) average time complexity. 
//
// 
// Example 1: 
//
// 
//Input
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//Output
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//Explanation
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // cache is {1=1}
//lRUCache.put(2, 2); // cache is {1=1, 2=2}
//lRUCache.get(1);    // return 1
//lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
//lRUCache.get(2);    // returns -1 (not found)
//lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
//lRUCache.get(1);    // return -1 (not found)
//lRUCache.get(3);    // return 3
//lRUCache.get(4);    // return 4
// 
//
// 
// Constraints: 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10⁴ 
// 0 <= value <= 10⁵ 
// At most 2 * 10⁵ calls will be made to get and put. 
// 
//
// Related Topics Hash Table Linked List Design Doubly-Linked List 👍 21028 👎 1
//070
#include <unordered_map>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
private:
    struct Node {
        int k, v;
        Node *pre, *next;

        Node(int _k, int _v): k(_k), v(_v), pre(nullptr), next(nullptr) {
        }
    } *l, *r;

    int cap;
    unordered_map<int, Node *> hash;

public:
    LRUCache(int capacity) {
        cap = capacity;
        l = new Node(-1, -1), r = new Node(-1, -1);
        l->next = r, r->pre = l;
    }

    int get(int key) {
        if (hash.count(key)) {
            auto p = hash[key];
            remove(p), insert(p);
            return p->v;
        }
        return -1;
    }

    void put(int key, int value) {
        if (hash.count(key)) {
            auto p = hash[key];
            p->v = value;
            remove(p), insert(p);
        } else {
            if (cap == hash.size()) {
                auto p = l->next;
                remove(p);
                hash.erase(p->k);
                delete p;
            }
            auto p = new Node(key, value);
            insert(p);
            hash[key] = p;
        }
    }

    void remove(Node *node) {
        auto p = node->pre, q = node->next;
        p->next = q, q->pre = p;
        node->next = nullptr, node->pre = nullptr;
    }

    void insert(Node *node) {
        auto p = r->pre;
        p->next = node, r->pre = node, node->pre = p, node->next = r;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
