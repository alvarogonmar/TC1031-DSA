
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
    }
    return hash % capacity;
}

// Constructor
HashTable::HashTable(int capacity) : capacity(capacity), size(0)
{
    table.resize(capacity);
}

// Insert key-value pair using quadratic probing
void HashTable::insert(const std::string &key, int value)
{
    int idx = hash(key);
    int i = 0;
    int firstDeleted = -1;
    while (i < capacity)
    {
        int probe = (idx + i * i) % capacity;
        if (!table[probe].occupied)
        {
            if (firstDeleted != -1)
                probe = firstDeleted;
            table[probe].key = key;
            table[probe].value = value;
            table[probe].occupied = true;
            table[probe].deleted = false;
            size++;
            return;
        }
        else if (table[probe].occupied && table[probe].key == key && !table[probe].deleted)
        {
            table[probe].value = value; // Update value
            return;
        }
        else if (table[probe].deleted && firstDeleted == -1)
        {
            firstDeleted = probe;
        }
        i++;
    }
    std::cout << "HashTable is full!\n";
}

// Get value by key
int HashTable::get(const std::string &key) const
{
    int idx = hash(key);
    int i = 0;
    while (i < capacity)
    {
        int probe = (idx + i * i) % capacity;
        if (table[probe].occupied && table[probe].key == key && !table[probe].deleted)
        {
            return table[probe].value;
        }
        else if (!table[probe].occupied && !table[probe].deleted)
        {
            break;
        }
        i++;
    }
    throw std::runtime_error("Key not found");
}

// Remove key
void HashTable::remove(const std::string &key)
{
    int idx = hash(key);
    int i = 0;
    while (i < capacity)
    {
        int probe = (idx + i * i) % capacity;
        if (table[probe].occupied && table[probe].key == key && !table[probe].deleted)
        {
            table[probe].deleted = true;
            table[probe].occupied = false;
            size--;
            return;
        }
        else if (!table[probe].occupied && !table[probe].deleted)
        {
            break;
        }
        i++;
    }
    std::cout << "Key not found for removal\n";
}

// Display table contents
void HashTable::display() const
{
    std::cout << "HashTable contents:\n";
    for (int i = 0; i < capacity; ++i)
    {
        if (table[i].occupied && !table[i].deleted)
        {
            std::cout << i << ": [" << table[i].key << ", " << table[i].value << "]\n";
        }
        else if (table[i].deleted)
        {
            std::cout << i << ": [DELETED]\n";
        }
