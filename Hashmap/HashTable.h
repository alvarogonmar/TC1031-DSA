#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <cstddef>

using namespace std;

class HashTable
{
public:
    explicit HashTable(size_t capacity = 7);

    void insert(int key, int value);
    int *get(int key);
    bool remove(int key);

    size_t hashFunction(int keys) const;
    size_t probe(size_t h, size_t i) const;
    int findIndexOfKey(int key) const;
    int findIndexToInsert(int key) const;
    void display() const;
