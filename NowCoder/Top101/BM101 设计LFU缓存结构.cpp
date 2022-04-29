#include<map>

class LFUCache {
  public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->count = 0;
        this->head = new node();
        this->tail = new node();
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    int get(int key) {
        if (data.count(key)) {
            node* record = data[key];
            use(record);
            return record->value;
        }
        return -1;
    }

    void set(int key, int value) {
        if (data.count(key)) {
            node* record = data[key];
            record->value = value;
            use(record);
        } else {
            insert(key, value);
        }
    }

  private:
    struct node {
        node* prev = nullptr;
        node* next = nullptr;
        int key = 0;
        int value = 0;
        int visit_count = 0;
        node() {}
        node(node* prev, node* next, int key, int value):
            prev(prev), next(next), key(key), value(value) {}
    };

    map<int, node*>data;
    int capacity;
    int count;
    node* head;
    node* tail;

    void use(node* record) {
        record->visit_count++;
        node* root = record->prev;
        while (root != this->head && root->visit_count <= record->visit_count) {
            root = root->prev;
        }
        if (root == record->prev) {
            return;
        }

        record->prev->next = record->next;
        record->next->prev = record->prev;

        record->next = root->next;
        record->next->prev = record;
        root->next = record;
        record->prev = root;
    }

    void insert(int key, int value) {
        while (this->count >= this->capacity) {
            erase();
        }

        node* root = this->tail->prev;
        while (root != this->head && root->visit_count <= 0) {
            root = root->prev;
        }

        node* record = new node(root, root->next, key, value);
        this->data[key] = record;
        root->next->prev = record;
        root->next = record;
        this->count++;
    }

    void erase() {
        node* least_used = this->tail->prev;
        this->tail->prev = least_used->prev;
        least_used->prev->next = this->tail;
        this->data.erase(least_used->key);
        delete least_used;
        this->count--;
    }
};

class Solution {
  public:
    /**
     * lfu design
     * @param operators int整型vector<vector<>> ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LFU(vector<vector<int> >& operators, int k) {
        LFUCache lfu(k);
        vector<int>result;
        for (auto iter = operators.begin(); iter != operators.end(); iter++) {
            if ((*iter)[0] == 1) {
                lfu.set((*iter)[1], (*iter)[2]);
            } else {
                result.push_back(lfu.get((*iter)[1]));
            }
        }
        return result;
    }
};
