#include "map.h"

int main() {
    MapType map = MapType(100);

    ItemType matt;
    matt.key = 1234;
    matt.value = "Matt";

    cout << map.IsIn(matt) << endl;
    map.Put(matt);
    cout << map.IsIn(matt) << endl;
    map.Put(matt);
    cout << map.IsIn(matt) << endl;
}