/** @file sequence_test.cpp
 * @brief An interactive test program for the new sequence class
 */
#include "sequence1.h" // With value_type defined as double
#include <cctype>      // Provides toupper
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <iostream>    // Provides cout and cin
using namespace std;
using namespace main_savitch_3;

// PROTOTYPES for functions used by this test program:

/**
 * Postcondition: A menu of choices for this program has been written to cout.
 */
void print_menu();
/**
 * Postcondition: The user has been prompted to enter a one character command.
 * The next character has been read (skipping blanks and newline characters),
 * and this character has been returned.
 */
char get_user_command();
/**
 * Postcondition: The items on display have been printed to cout (one per line).
 */
void show_sequence(sequence display);
/** 
 * Postcondition: The user has been prompted to enter a real number. The
 * number has been read, echoed to the screen, and returned by the function.
 */
double get_number();
/** Main method; executes test program. */
int main() {
    sequence test; // A sequence that we'll perform tests on
    char choice;   // A command character entered by the user

    cout << "I have initialized an empty sequence of real numbers." << endl;
    // modified method to ensure preconditions are met.
    do {
        print_menu();
        choice = toupper(get_user_command());
        switch (choice) {
        case '!':
            test.start();
            break;
        case '+':
            if (test.is_item())
                test.advance();
            else
                cout << "There is no current item. Could not advance." << endl;
            break;
        case '?':
            if (test.is_item())
                cout << "There is an item." << endl;
            else
                cout << "There is no current item." << endl;
            break;
        case 'C':
            if (test.is_item())
                cout << "Current item is: " << test.current() << endl;
            else
                cout << "There is no current item." << endl;
            break;
        case 'P':
            show_sequence(test);
            break;
        case 'S':
            cout << "Size is " << test.size() << '.' << endl;
            break;
        case 'I':
            if (test.size() < test.CAPACITY)
                test.insert(get_number());
            else
                cout << "Sequence is full. Could not insert." << endl;
            break;
        case 'A':
            if (test.size() < test.CAPACITY)
                test.attach(get_number());
            else
                cout << "Sequence is full. Could not attach." << endl;
            break;
        case 'R':
            if (test.is_item()) {
                test.remove_current();
                cout << "The current item has been removed." << endl;
            } else {
                cout << "There is no current item. Could not remove." << endl;
            }
            break;
        case 'Q':
            cout << "Ridicule is the best test of truth." << endl;
            break;
        default:
            cout << choice << " is invalid." << endl;
        }
    } while ((choice != 'Q'));

    return EXIT_SUCCESS;
}

// IMPLEMENTATIONS

void print_menu() {
    // Library facilities used: iostream.h
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << " !   Activate the start( ) function" << endl;
    cout << " +   Activate the advance( ) function" << endl;
    cout << " ?   Print the result from the is_item( ) function" << endl;
    cout << " C   Print the result from the current( ) function" << endl;
    cout << " P   Print a copy of the entire sequence" << endl;
    cout << " S   Print the result from the size( ) function" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " A   Attach a new number with the attach(...) function" << endl;
    cout << " R   Activate the remove_current( ) function" << endl;
    cout << " Q   Quit this test program" << endl;
    cout << endl; // Print blank line after the menu
}

char get_user_command() {
    // Library facilities used: iostream
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}

void show_sequence(sequence display) {
    // Library facilities used: iostream
    for (display.start(); display.is_item(); display.advance()) {
        cout << display.current() << endl;
    }
}

double get_number() {
    // Library facilities used: iostream
    double result;

    cout << "Please enter a real number for the sequence: ";
    cin >> result;
    cout << result << " has been read." << endl;
    return result;
}
