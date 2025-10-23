
#include "HashTable.h"
#include <iostream>

// Entry constructor
HashTable::Entry::Entry() : key(""), value(0), occupied(false), deleted(false) {}

// Hash function: polynomial rolling hash
int HashTable::hash(const std::string &key) const
{
    unsigned long hash = 0;
    for (char c : key)
    {
        hash = hash * 31 + c;
