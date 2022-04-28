#include <string>
#include <iostream>

/**
 * This file implements a hash map using the bucket and chain
 * method for handling hash collisions.
 */

using namespace std;

// Custom hardcoded ItemType containing a key/value pair
// where the key is always an integer and the value is
// always a string.
//
// Can be refactored to use templating, but this makes the
// code simpler for demonstration purposes.
class ItemType {
    public:
        int key;
        string value;
};

// Standard linked list node type
struct NodeType {
    ItemType info;
    NodeType *next;
};

class MapType {
    public:
        MapType(int max) {
            // Initialize an array of dummy first node pointers.
            // This is not a great solution, but it helps us avoid
            // an array of pointers.
            items = new NodeType[max];

            for (int i = 0; i < max; i++) {
                items[i].next = NULL;
            }

            this->max = max;
        }

        // Puts an item in the hash table.
        // If the item is not already in the hash table, it will be added.
        // If the item is already in the hash table, nothing will happen.
        void Put(ItemType item) {
            // Hash the key to determine the index where it belongs.
            int i = item.key % this->max;

            NodeType *node = new NodeType;
            node->info = item;

            // Determine whether the item exists in the chain
            // at index i. This is a simple linear search.
            NodeType *nodeTmp = items[i].next;
            bool found = false;
            while (nodeTmp != NULL) {
                if (nodeTmp->info.key == item.key) {
                    found = true;
                    break;
                }
                nodeTmp = nodeTmp->next;
            }

            // If it is already there, do nothing.
            if (found) {
                cout << "Already in hash table" << endl;
                return;
            }

            // Otherwise, add it to the table.
            node->next = items[i].next;
            items[i].next = node;
            cout << "Added " << node->info.value << " at " << i << endl;
        }
    
        // Returns whether a given item is in the hash table.
        bool IsIn(ItemType item) {
            // Hash the key to determine the index where it belongs.
            int i = item.key % this->max;

            // Perform a linear search at index i to find item,
            // and return whether we found it or not.
            NodeType *nodeTmp = items[i].next;
            bool found = false;
            while (nodeTmp != NULL) {
                if (nodeTmp->info.key == item.key) {
                    found = true;
                    break;
                }
                nodeTmp = nodeTmp->next;
            }

            return found;
        }
    private:
        NodeType *items;
        int max;
};