#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include "node2.h"
#include "bag5.h"

using namespace std;



// PROTOTYPE for a function used by this demonstration program
template <class Item, class SizeType, class MessageType>
void get_items(bag<Item>& collection, SizeType n, MessageType description)
// Postcondition: The string description has been written as a prompt to the
// screen. Then n items have been read from cin and added to the collection.
// Library facilities used: iostream, bag4.h
{
    Item user_input; // An item typed by the program's user
    SizeType i;

    cout << "Please type " << n << " " << description;
    cout << ", separated by spaces.\n";
    cout << "Press the <return> key after the final entry:\n";
    for (i = 1; i <= n; ++i)
    {
        cin >> user_input;
        collection.insert(user_input);
    }
    cout << endl;
}

int main()
{
    //demonstrate bag template class
    bag<int> bag_of_int;
    bag<string> bag_of_string;

    bag_of_int.insert(3);
    bag_of_string.insert("hello");
    bag_of_string.insert("goodbye");
    bag_of_string.insert("auf wiedersehen");
    bag_of_string.insert("goodbye");
    bag_of_string.insert("hello");
    bag_of_string.insert("goodbye");

    cout << "count of goodbye: " << bag_of_string.count("goodbye") << endl;
    cout << "count of guten morgen: " << bag_of_string.count("guten morgen") << endl;
    cout << "count of 3: " << bag_of_int.count(3) << endl;
    

    for(bag<string>::iterator cursor = bag_of_string.begin(); cursor != bag_of_string.end(); ++cursor)
        cout<<*cursor<< " ";
    cout<<endl;  
    
   bag<int> bag_int;
   bag_int.insert (7);
   bag_int.insert (6);
   bag_int.insert (5);
   bag_int.insert (4);
   bag_int.insert (5);
   bag_int.insert (3);
   bag_int.insert (2);
   bag_int.insert (1);
   bag_int.insert (1);
   bag_int.insert (5);
   bag_int.print_value_range (5,20);
   bag_int.remove_repetitions();
   bag_int.print_value_range (5,20);
   return EXIT_SUCCESS;
    
}
