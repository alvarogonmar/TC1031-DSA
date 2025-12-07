#include <iostream>
#include <vector>
#include <cstddef>

#include "HashTable.h"

using namespace std;

HashTable::HashTable(size_t cap)
    : keys(), values(), states(), capacity(cap), size(0)
{
    keys.resize(capacity);
    values.resize(capacity);
