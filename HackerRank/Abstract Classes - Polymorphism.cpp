#include <iostream>
#include <map>

using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
    Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

protected:
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : Cache {
public:
    LRUCache(int capacity) {
        cp = capacity;
        head = NULL;
        tail = NULL;
    }

    void set(int key, int value) {
        map<int, Node*>::iterator it = mp.find(key);
        if (it != mp.end()) {
            Node* node = it->second;
            node->value = value;
        }
        else {
            if (cp > 0) {
                if (mp.size() == cp) {
                    it = mp.find(tail->key);
                    if (head == tail) {
                        head = NULL;
                        tail = NULL;
                    }
                    else {
                        tail = tail->prev;
                        tail->next = NULL;
                    }
                    delete it->second;
                    mp.erase(it);
                }

                Node* node = new Node(key, value);
                mp[key] = node;

                if (head == NULL && tail == NULL) {
                    tail = node;
                }
                else {
                    head->prev = node;
                    node->next = head;
                }

                head = node;
            }
        }
    }

    int get(int key) {
        map<int, Node*>::iterator it = mp.find(key);
        if (it != mp.end()) {
            Node* node = it->second;
            if (node != head) {
                if (node != tail) {
                    node->next->prev = node->prev;
                    node->prev->next = node->next;
                }
                else {
                    tail = node->prev;
                    tail->next = NULL;
                }
                node->next = head;
                node->prev = NULL;
                head->prev = node;
                head = node;
            }
            return node->value;
        }
        else {
            return -1;
        }
    }
};


