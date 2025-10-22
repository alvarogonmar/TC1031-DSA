
#include "HashTable.h"
#include <iostream>

// Entry constructor
HashTable::Entry::Entry() : key(""), value(0), occupied(false), deleted(false) {}
