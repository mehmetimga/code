#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Item
{
    int key;
    int value;
    Item *next;
    Item *prev;
};
class LRUCache
{
public:
    int limit;
    Item *head;
    Item *last;
    LRUCache(int capacity)
    {
        limit = capacity;
        head = nullptr;
        last = nullptr;
    }
    unordered_map<int, Item *> imap;
    int get(int key)
    {
        auto it = imap.find(key);
        if (it != imap.end())
        {
            moveItemtoFirst(it->second);
            return it->second->value;
        }
        else
            return -1;
    }
    void addItemToFirst(Item *item)
    {
        if (head == nullptr)
        {
            head = item;
            last = item;
        }else{
            item->prev = nullptr;
            head->prev=item;
            item->next = head;
            head = item;
        }

        if (imap.size() > limit)
        {
            imap.erase(last->key);
            Item *lastprev = last;
            last = last->prev;
            last->next = nullptr;
            delete lastprev;
        }
    }
    void moveItemtoFirst(Item *item)
    {


        if (item == head)
            return;

        if (item == last)
        {
            Item *temp = last;
            last = last->prev;
            last->next=nullptr;

            head->prev=temp;
            temp->prev = nullptr;
            temp->next = head;

            head = temp;
        }
        else
        {

            item->prev->next = item->next;
            item->next->prev = item->prev;
            item->prev = nullptr;
            item->next = head;
            head->prev=item;

            head = item;
        }
    }

    void put(int key, int value)
    {

        auto it=imap.find(key);
        if (it!=imap.end()){
            moveItemtoFirst(it->second);
            //imap.erase(key); 
            it->second->value=value;
            imap.insert(make_pair(key, it->second));
           
        }else{
            Item *item = new Item();
            item->key = key;
            item->value = value;
            imap.insert(make_pair(key, item));

            addItemToFirst(item);
        }

            
        //imap.insert(pair<int,Item*>{key,item});
        //item[key]=item;
    }
};

int main()
{
    LRUCache lRUCache(3);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.put(3, 3); // cache is {1=1, 2=2}
    lRUCache.put(4, 4); // cache is {1=1, 2=2}
    cout << "return -1 =" << lRUCache.get(4) << endl;    // return 1
    cout << "return -1 =" << lRUCache.get(3) << endl;    // return 1
    cout << "return -1 =" << lRUCache.get(2) << endl;    // return 1
    cout << "return -1 =" << lRUCache.get(1) << endl;    // return 1
    lRUCache.put(5, 5); // cache is {1=1, 2=2}

   
    cout << "return 3 =" << lRUCache.get(1) << endl;    // return 1
    cout << "return 3 =" << lRUCache.get(2) << endl;    // return 1
    cout << "return 3 =" << lRUCache.get(3) << endl;    // return 1
    cout << "return 3 =" << lRUCache.get(4) << endl;    // return 1
    cout << "return 3 =" << lRUCache.get(5) << endl;    // return 1
   

//["LRUCache","put","put","put","put","get","get","get","get","put","get","get","get","get","get"]
//[[3],[1,1],[2,2],[3,3],[4,4],[4],[3],[2],[1],[5,5],[1],[2],[3],[4],[5]]
}