
#include <iostream>
#include <map>
#include <queue>
#include <stack>
using namespace std;

class AverageItem
{
public:
    int value;
    int count;
};
class Item
{

public:
    Item(int value_)
    {
        value = value_;
        left = nullptr;
        right = nullptr;
    }
    int value;
    Item *left;
    Item *right;
};
class Level
{
public:
    int depth;
    Item *item;
};
class Solution
{
public:
    int findAverageDFSRecursive(Item *item, int depth, map<int, AverageItem *> &average)
    {
        if (item == nullptr)
            return -1;
        auto it = average.find(depth);
        if (it != average.end())
        {
            AverageItem *aitem = it->second;
            aitem->value += item->value;
            aitem->count++;
        }
        else
        {
            AverageItem *aitem = new AverageItem();
            aitem->value = item->value;
            aitem->count = 1;
            average.insert(pair<int, AverageItem *>(depth, aitem));
        }
        findAverage(item->left, depth + 1, average);
        findAverage(item->right, depth + 1, average);
    }

    int findAverageBFS(Item *item, int depth, map<int, AverageItem *> &average)
    {
        if (item == nullptr)
            return -1;

        queue<Level *> q;
        Level *level = new Level();
        level->depth = 0;
        level->item = item;
        q.push(level);
        while (!q.empty())
        {
            Level *l = q.front();
            q.pop();
            auto it = average.find(l->depth);
            if (it != average.end())
            {
                AverageItem *a = it->second;
                a->value += l->item->value;
                a->count++;
            }
            else
            {
                AverageItem *a = new AverageItem();
                a->value = l->item->value;
                a->count = 1;
                int level = l->depth + 1;
                average[l->depth] = a;
            }

            if (l->item->left)
            {
                Level *litem = new Level();
                litem->depth = l->depth + 1;
                litem->item = l->item->left;
                q.push(litem);
            }
            if (l->item->right)
            {
                Level *litem = new Level();
                litem->depth = l->depth + 1;
                litem->item = l->item->right;
                q.push(litem);
            }
        }
    }

    int findAverageDFS(Item *item, int depth, map<int, AverageItem *> &average)
    {
        if (item == nullptr)
            return -1;

        stack<Level *> s;
        Level *level = new Level();
        level->depth = 0;
        level->item = item;
        s.push(level);
        while (!s.empty())
        {
            Level *l = s.top();
            s.pop();
            auto it = average.find(l->depth);
            if (it != average.end())
            {
                AverageItem *a = it->second;
                a->value += l->item->value;
                a->count++;
            }
            else
            {
                AverageItem *a = new AverageItem();
                a->value = l->item->value;
                a->count = 1;
                average[l->depth] = a;
            }

            if (l->item->left)
            {
                Level *litem = new Level();
                litem->depth = l->depth + 1;
                litem->item = l->item->left;
                s.push(litem);
            }
            if (l->item->right)
            {
                Level *litem = new Level();
                litem->depth = l->depth + 1;
                litem->item = l->item->right;
                s.push(litem);
            }
        }
    }
};

int main()
{
    Item *head = new Item(4);
    head->left = new Item(7);
    head->right = new Item(9);
    head->right->right = new Item(6);

    head->left->left = new Item(10);
    head->left->right = new Item(2);

    head->left->right->right = new Item(6);
    head->left->right->right->left = new Item(2);

    map<int, AverageItem *> average;

    Solution().findAverageBFS(head, 0, average);
    auto it{average.begin()};
    while (it != average.end())
    {
        cout << "level:" << it->first << " ,average=" << it->second->value / it->second->count << endl;
        it++;
    }
    return 0;
}