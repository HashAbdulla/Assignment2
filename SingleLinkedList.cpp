#include "SingleLinkedList.h"



// Constructor
template <typename Item_Type>
SingleLinkedList<Item_Type>::SingleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor
template <typename Item_Type>
SingleLinkedList<Item_Type>::~SingleLinkedList() {
    while (!empty()) { //will keep repeating till list is empty
        pop_front();
    }
}

// member function implementations //

//add an item to the front of the list
template <typename Item_Type>
void SingleLinkedList<Item_Type>::push_front(const Item_Type& item) {
   Node* new_node = new Node(item);
    if (!head) {
        head = tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    num_items++;
}

//add an item to the back of the list
template <typename Item_Type>
void SingleLinkedList<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (!head) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

//remove the item from the front of the list
template <typename Item_Type>
void SingleLinkedList<Item_Type>::pop_front() {
     if (!head) {
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    num_items--;
}


//remove the item from the back of the list
template <typename Item_Type>
void SingleLinkedList<Item_Type>::pop_back() {
     if (!head) {
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
}

//returns the item at the front of the list
template <typename Item_Type>
Item_Type SingleLinkedList<Item_Type>::front() const {
    if (head) {
        return head->data;
    }
}

//returns the item at the back of the list
template <typename Item_Type>
Item_Type SingleLinkedList<Item_Type>::back() const {
    if (tail) {
        return tail->data;
    }
}

//checks if the list is empty
template <typename Item_Type>
bool SingleLinkedList<Item_Type>::empty() const {
     return num_items == 0;
}

//inserts an item at a specific position in the list
template <typename Item_Type>
void SingleLinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index <= 0) {
        push_front(item);
    } else if (index >= num_items) {
        push_back(item);
    } else {
        Node* new_node = new Node(item);
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        num_items++;
    }
}

//removes an item at a specific position in the list
template <typename Item_Type>
bool SingleLinkedList<Item_Type>::remove(size_t index) {
    if (index < 0 || index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    } else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        if (current->next == tail) {
            tail = current;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        num_items--;
    }
    return true;
}

//finds the position of the first occurence of an item
template <typename Item_Type>
size_t SingleLinkedList<Item_Type>::find(const Item_Type& item) {
    Node* current = head;
    size_t index = 0;
    while (current) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items; // Item not found
}