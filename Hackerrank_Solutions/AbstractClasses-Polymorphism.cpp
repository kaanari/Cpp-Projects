#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
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


class LRUCache : public Cache{
    public:
        LRUCache(int size){
            cp = size;
        }

        void set(int k, int v);
        int get(int k);

};

void LRUCache::set(int k, int v){

    map<int, Node*>::iterator it = mp.find(k);

    if(it != mp.end()){

                
        it->second->value = v;

    }else{
        

        Node* temp = new Node(k,v); // onemli!
        if(mp.size() == cp){

            
            tail->prev->next = NULL;
            mp.erase(tail->key);
            tail = tail->prev;

            temp -> next = head;
            head->prev = temp;
            head = temp;
            mp.insert(pair<int,Node*>(k,temp));

        }else{


            if(mp.size() == 0){

                head = temp;
                tail = temp;
                mp.insert(pair<int, Node*>(k,temp));

            }else{

                temp->next = head;
                head->prev = temp;
                head = temp;
                mp.insert(pair<int, Node*>(k,temp));
            }

        }
    }

}

int LRUCache::get(int k){

    if(mp.size() != 0 && k >= 1){
        map<int,Node*>::iterator it = mp.find(k);
        if(it != mp.end()){
            if(it->second != head){
                Node* nextp = it->second->next;
                Node* prevp = it->second->prev;
                it->second->next = head;
                head = it->second;
                head->prev = NULL;

                if(nextp != NULL){
                    nextp->prev = prevp;
                }
                if(prevp != NULL){
                    prevp->next = nextp;
                }

            }


            
            return it->second->value;
        }else{
            return -1;
        }
    }else{
        return -1;
    }

}

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

