#include <iostream>

using namespace std;

struct Item
{
    int val;
    Item* left;
    Item* right;
    Item(int val): val(val),left(nullptr),right(nullptr){}
    Item(int val, Item *left, Item* right):val(val),left(left),right(right){}

    void insert(int inputval){
        if (inputval>val){
            if (left==nullptr)
                left=new Item(inputval);
            else   
                left->insert(inputval);
        }
        else{
            if (right==nullptr)
                right=new Item(inputval);
            else
                right->insert(inputval);
        }
    }
    bool contains(int value)
    {
        if (val==value)
            return true;
        if (value>val)
        {
            if (left==nullptr)
                return false;
            else 
                return left->contains(value);

        }else{
            if (right==nullptr)
                return false;
            else   
                return right->contains(value);
        }
    }
    void printinorder(){
        if (left)
            left->printinorder();
        
        cout << " " << val;

        if (right)
            right->printinorder();
    }
};

int main()
{
    Item* root=new Item(10);
    root->insert(5);
    root->insert(8);
    root->insert(20);
    if (root->contains(9))
         cout << "item 9found"<<endl;


    root->printinorder();

}