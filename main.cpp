//Hashim Abdulla
//CS303 assignment 2

#include <iostream>

#include "SingleLinkedList.cpp"
#include "Employee.h"



using namespace std;

int main() {
  SingleLinkedList<string> my_list; // Create an instance of SingleLinkedList for names (strings)

    // Testing push_front and push_back
    my_list.push_front("louis");
    my_list.push_front("mike");
    my_list.push_back("ashley");
    my_list.push_back("brad");

    // Testing insert
    my_list.insert(2, "cooper"); // Insert 99 at index 2

    // Displaying the list
    cout << "List: [" << my_list.front() << ", " << my_list.back() << "]" << endl;

    // Testing pop_front and pop_back
    my_list.pop_front();
    my_list.pop_back();

    // Testing remove
    my_list.remove(2); // Remove item at index 2

    // Displaying the modified list
    std::cout << "List: [" << my_list.front() << ", " << my_list.back() << "]" << std::endl;

    // Testing find
    int index = my_list.find("cooper"); // Find the index of cooper
    if (index < my_list.find("cooper")) {
        std::cout << "Found cooper at index: " << index << std::endl;
    } else {
        std::cout << "cooper not found in the list" << std::endl;
    }

cout<<endl;

Professional professionalEmployee("John Smith", 101, 5000.0, 15);
    Nonprofessional nonProfessionalEmployee("Alice Johnson", 102, 12.5, 45);

    cout << "Professional Employee Information:" << endl;
    professionalEmployee.displayInfo();
    cout << endl;

    cout << "Nonprofessional Employee Information:" << endl;
    nonProfessionalEmployee.displayInfo();

  
    return 0;
}