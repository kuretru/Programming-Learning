#include <map>

class Solution {
  public:
    Solution(int capacity) {
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
        node(): {}
        node(node* prev, node* next, int key, int value):
            prev(prev), next(next), key(key), value(value) {}
    };

    map<int, node*>data;
    int capacity;
    int count;
    node* head;
    node* tail;

    void use(node* record) {
        record->prev->next = record->next;
        record->next->prev = record->prev;
        record->next = this->head->next;
        record->prev = this->head;
        record->next->prev = record;
        this->head->next = record;
    }

    void insert(int key, int value) {
        node* record = new node(this->head, this->head->next, key, value);
        this->data[key] = record;
        this->head->next->prev = record;
        this->head->next = record;
        this->count++;
        while (this->count > this->capacity) {
            erase();
        }
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

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* solution = new Solution(capacity);
 * int output = solution->get(key);
 * solution->set(key,value);
 */
