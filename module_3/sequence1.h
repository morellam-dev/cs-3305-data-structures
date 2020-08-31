/** 
 * @file    sequence1.h
 * @brief   Class-provided declaration for `sequence` class.
 * 
 * Note: As a matter of personal preference, the monolithic documentation
 * provided in this header has been inlined into the implementation as 
 * Doxygen-style block comments. This enables IDE's with IntelliSense to read 
 * them, although they may be slightly unwieldy if not collapsed.
 */

#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H
#include <cstdlib> // Provides size_t

namespace main_savitch_3 {
/** @class sequence
 * @brief Stores a sequence of numbers.
 */
class sequence {
public:
    // TYPEDEFS and MEMBER CONSTANTS
    typedef double value_type;            // The data type of the items in the sequence.
    typedef std::size_t size_type;        // The data type of any variable that keeps track of how many items are in a sequence.
    static const size_type CAPACITY = 30; // The maximum number of items that a sequence can hold.
    /** Construct the sequence class.
     * Postcondition: The sequence has been initialized as an empty sequence.
     */
    sequence();
    /** Return to the start of the sequence.
     * Postcondition: The first item on the sequence becomes the current item 
     * (but if the sequence is empty, then there is no current item).
     */
    void start();
    /** Advance to the next item in the sequence.
     * Precondition: is_item returns true.
     * Postcondition: If the current item was already the last item in the
     * sequence, then there is no longer any current item. Otherwise, the new
     * current item is the item immediately after the original current item.
     */
    void advance();
    /** Insert an element before the current element, or at the start of the array.
     * Precondition: size( ) < CAPACITY.
     * Postcondition: A new copy of entry has been inserted in the sequence
     * before the current item. If there was no current item, then the new entry
     * has been inserted at the front of the sequence. In either case, the newly
     * inserted item is now the current item of the sequence.
     */
    void insert(const value_type &entry);
    /** Attach an element after the current element, or at the end of the array.
     * Precondition: size( ) < CAPACITY.
     * Postcondition: A new copy of entry has been inserted in the sequence after
     * the current item. If there was no current item, then the new entry has
     * been attached to the end of the sequence. In either case, the newly
     * inserted item is now the current item of the sequence.
     * */
    void attach(const value_type &entry);
    /** Remove the current element.
     * Precondition: is_item returns true.
     * Postcondition: The current item has been removed from the sequence, and the
     * item after this (if there is one) is now the new current item
     */
    void remove_current();
    // CONSTANT MEMBER FUNCTIONS

    /** Get the current size of the sequence.
     * Postcondition: The return value is the number of items in the sequence.
     */
    size_type size() const;
    /** Get whether or not there is an item at the current position.
     * Postcondition: A true return value indicates that there is a valid
     * "current" item that may be retrieved by activating the current
     * member function (listed below). A false return value indicates that
     * there is no valid current item.
     */
    bool is_item() const;
    /** Get the current element.
     * Precondition: is_item( ) returns true.
     * Postcondition: The item returned is the current item in the sequence.
     */
    value_type current() const;
private:
    value_type data[CAPACITY]; // an array which stores the data.
    size_type used;            // the size of the sequence. the last element is located at index `used-1`
    size_type current_index;   // the current element which is being accessed
};
} // namespace main_savitch_3

#endif
