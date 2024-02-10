#include <bits/stdc++.h>
using namespace std;

// this uses time complexity of O(1) because in this solution, hash map is used to store address of node corresponding to the key and doubly linkedlist is used to store and delete the node which consist of next, prev pointer, value and key::

class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_)
    {
        if (m.find(key_) != m.end())
        {
            node *resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res;
        }

        return -1;
    }

    void put(int key_, int value)
    {
        if (m.find(key_) != m.end())
        {
            node *existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key_, value));
        m[key_] = head->next;
    }
};

/*

// this is a good solution but uses linear time complexity for seearching the least recently used element:

class LRUCache {
public:
    int zval = 0;
    // key, {value, zvalue}
    int cap ;
    unordered_map<int, pair<int,int>>mapp;
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {

        if(mapp.find(key)==mapp.end()) {
            zval++;
            return -1;
        }
        zval++;
        mapp[key].second = zval;
        return mapp[key].first;
    }

    void put(int key, int value) {
        if(mapp.find(key)!=mapp.end()){
            zval++;
            mapp[key] = {value, zval};
        }else{
            if(mapp.size()>=cap){
                int minz = INT_MAX;
                int mink;
                for(auto i:mapp){
                    if(i.second.second<minz){
                        minz = i.second.second;
                        mink = i.first;
                    }
                }
                mapp.erase(mink);
                zval++;
                mapp[key] = {value, zval};

            }else{
                zval++;
                mapp[key] = {value, zval};
            }
        }

    }
};

*/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */