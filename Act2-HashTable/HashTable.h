

#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// HashTable declaration with quadratic probing
class HashTable
{
private:
    struct Entry
    {
        string key;
        int value;
        bool occupied;
        bool deleted;
        Entry();
    };
    vector<Entry> table;
