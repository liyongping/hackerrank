#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
using namespace std;
/*
 Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
 */


class LRUCache {
public:
    LRUCache(int capacity):
    capacity(capacity){
        
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        recent.erase(m[key]); // remove it firstly, then add into header`
        int value = m[key]->second;
        recent.push_front(pair<int, int>(key,value));
        m[key] = recent.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(m.find(key) == m.end()){//insert
            if(recent.size() >= capacity){
                m.erase(recent.back().first);
                recent.pop_back();
            }
        }else{// update
            recent.erase(m[key]);
        }
        recent.push_front(pair<int, int>(key,value));
        m[key] = recent.begin();
    }
private:
    int capacity;
    list<pair<int,int> > recent;
    map<int, list<pair<int,int> >::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char const *argv[])
{
    LRUCache s(2);
    s.put(1,1);
    s.put(2,3);

    cout<< s.get(1) << endl;
    cout<< s.get(2) << endl;
    cout<< s.get(3) << endl;
    s.put(3,1);
    s.put(4,3);
cout<< s.get(4) << endl;
    cout<< s.get(1) << endl;
    cout<< s.get(3) << endl;
    s.put(4,1);
    cout<< s.get(4) << endl;

    string str = "123456";
    cout<< str.size() << endl;
    return 0;
}