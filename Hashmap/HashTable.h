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
