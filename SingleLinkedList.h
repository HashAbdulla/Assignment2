#ifndef SINGLELINKEDLIST_H //header guard so that it wont be included multiple times
#define SINGLELINKEDLIST_H

#include <iostream>
using namespace std;

template <typename Item_Type>
class SingleLinkedList {
public:
    SingleLinkedList();  // Constructor
    ~SingleLinkedList(); // Destructor
    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type front() const;
    Item_Type back() const;
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item);
    
private:
    // Nested Node class
    class Node {
    public:
        Item_Type data;
        Node* next;

        Node(const Item_Type& item) : data(item), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;
};

#endif