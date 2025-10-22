

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
    int capacity;
    int size;

    int hash(const string &key) const;

public:
    // Constructor
    HashTable(int capacity = 100);

    // Insert key-value pair
    void insert(const string &key, int value);

    // Get value by key
    int get(const string &key) const;

    // Remove key
    void remove(const string &key);

    // Display table contents
    void display() const;
};