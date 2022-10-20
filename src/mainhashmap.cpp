#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Item
{
    Item *next;
    int key;
    int value;
    bool operator==(int s) {return key == s;}
    bool operator==(Item s) {return key == s.key;}
};
class FindKey
{
    int key;

public:
    FindKey(int key) : key(key) {}

    bool operator()(Item* item) const
        { return item->key == key; }
};

class MyHashMap1
{
public:
    vector<Item *> v;
    MyHashMap1()
    {
        v.resize(65513);
        //for(int i=0;i<2069;i++)
        //  v[i]=nullptr;
    }

    void put(int key, int value)
    {
        Item *item = v[key % 65513];
        Item *lastitem = nullptr;
        while (item != nullptr)
        {
            if (item->key == key)
            {
                item->value = value;
                return;
            }
            lastitem = item;
            item = item->next;
        }
        Item *newitem = new Item();
        newitem->key = key;
        newitem->value = value;
        newitem->next = nullptr;
        if (lastitem)
        {
            lastitem->next = newitem;
        }
        else
        {
            v[key % 2069] = newitem;
        }
    }

    int get(int key)
    {
        Item *item = v[key % 65513];
        while (item)
        {
            if (item->key == key)
            {
                return item->value;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        Item *item = v[key % 65513];
        Item *lastitem = nullptr;

        while (item)
        {
            if (item->key == key)
            {
                if (lastitem)
                    lastitem->next = item->next;
                else
                    v[key % 65513] = nullptr;

                delete item;
            }
            lastitem = item;
            item = item->next;
            return;
        }
    }
};

class MyHashMap
{
public:
    vector<deque<Item*>* > v;
    MyHashMap()
    {
        v.resize(2069);
        for(int i=0;i<2069;i++)
            v[i]=new deque<Item*>();
    }

    void put(int key, int value)
    {
        deque<Item*>* d = v[key % 65513];
        Item* itemkey=new Item();
        itemkey->key=key;
        itemkey->value=value;
        //auto it = find_if(d->begin(),d->end(),FindKey(key));
        //auto it = find_if(d->begin(),d->end(),[key](Item* item){return item->key==key;});
        auto it = find_if(d->begin(),d->end(),[&](Item* item){return item->key==key;});

        if (it!=d->end()){
            (*it)->value=value;
        }
        else 
            d->push_back(itemkey);  
    }

    int get(int key)
    {
        deque<Item*>* d = v[key % 65513];
        //auto it = find_if(d->begin(),d->end(),FindKey(key));
        auto it = find_if(d->begin(),d->end(),[key](Item* item){return item->key==key;});

        if (it!=d->end())
        {
            return (*it)->value;
        }

        return -1;
    }

    void remove(int key)
    {
        deque<Item*>* d =  v[key % 65513];
        //auto it = find_if(d->begin(),d->end(),FindKey(key));
        auto it = find_if(d->begin(),d->end(),[key](Item* item){return item->key==key;});
        if (it!=d->end())
        {
            d->erase(it);
        }

    }
};
int main()
{
    MyHashMap h;
    h.put(1, 1);
    h.put(2, 2);
    cout << "1=" << h.get(1) << endl;
    cout << "3=" << h.get(3) << endl;
    h.put(2, 1);
    cout << "2=" << h.get(2) << endl;
    h.remove(2);
    cout << "2=" << h.get(2) << endl;

    return 0;
}