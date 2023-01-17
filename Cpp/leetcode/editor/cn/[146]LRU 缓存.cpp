//
// 请你设计并实现一个满足 
// LRU (最近最少使用) 缓存 约束的数据结构。
// 
//
// 
// 实现 
// LRUCache 类：
// 
//
// 
// 
// 
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 
//key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。 
// 
// 
// 
//
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10000 
// 0 <= value <= 10⁵ 
// 最多调用 2 * 10⁵ 次 get 和 put 
// 
//
// Related Topics 设计 哈希表 链表 双向链表 👍 2518 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
    // lru算法使用一个unordered_map存储key,value.再使用一个双链表标记使用的时间。最近使用则在双链表头部，最不常使用的则在双链表的尾部
public:
    struct Node {
        int key, val;
        Node *left, *right;

        Node(int _val, int _key) : val(_val), key(_key), left(nullptr), right(nullptr) {}
    } *l, *r;

    unordered_map<int, Node *> hash;

    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        l = new Node(-1, -1), r = new Node(-1, -1);
        l->right = r;
        r->left = l;
    }

    int get(int key) {
        if (hash.count(key)) {
            auto p = hash[key];
            remove(p);
            insert(p);
            return p->val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (hash.count(key)) {
            auto p = hash[key];
            p->val = value;
            remove(p);
            insert(p);
        } else {
            if (hash.size() == cap) {
                auto p = r->left;
                remove(p);
                hash.erase(p->key);
                delete p;
            }
            auto p = new Node(value, key);
            hash[key] = p;
            insert(p);
        }
    }

    void remove(const Node *node) {
        node->left->right = node->right;
        node->right->left = node->left;
    }

    void insert(Node *node) {
        node->right = l->right;
        node->left = l;
        l->right->left = node;
        l->right = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
