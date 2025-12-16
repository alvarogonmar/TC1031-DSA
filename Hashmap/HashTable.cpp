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
    states.resize(capacity, EMPTY); // todas las celdas empiezan vacías
}

void HashTable::insert(int key, int value)
{
    // 1) si ya existe la clave, ACTUALIZA su valor
    int idxExisting = findIndexOfKey(key);
    if (idxExisting != -1)
    {
        values[idxExisting] = value;
        return;
    }

    // 2) si no existe, busca dónde insertar (reutiliza DELETED o usa EMPTY)
    int idx = findIndexToInsert(key);
    if (idx == -1)
    {
        // tabla llena o probing exhausto → para este ejercicio solo avisa
        // (más adelante puedes implementar rehash)
        // throw std::runtime_error("HashTable llena");
        return;
    }

    keys[idx] = key;
    values[idx] = value;
    states[idx] = OCCUPIED;
    ++size;
}

size_t HashTable::hashFunction(int key) const
{
    long long k = key;
    long long m = static_cast<long long>(capacity);
    long long r = k % m;
    if (r < 0)
        r += m; // por si key < 0
    return static_cast<size_t>(r);
}

size_t HashTable::probe(size_t h, size_t i) const
{
    return (h + i * i) % capacity;
}

int HashTable::findIndexOfKey(int key) const
{
    size_t h = hashFunction(key);
    for (size_t i = 0; i < capacity; i++)
    {
        size_t j = probe(h, i);
        if (states[j] == EMPTY)
        {
            return -1;
        }

        if (states[j] == OCCUPIED && keys[j] == key)
        {
            return static_cast<int>(j);
        }
    }
    return -1;
}

int HashTable::findIndexToInsert(int key) const
{
    size_t h = hashFunction(key);

    int firstDeleted = -1;

    for (size_t i = 0; i < capacity; i++)
    {
        size_t j = probe(h, i);
        if (states[j] == OCCUPIED)
        {
            if (keys[j] == key)
            {
                return static_cast<int>(j);
            }
        }
        else if (states[j] == DELETED)
        {
            if (firstDeleted == -1)
            {
                firstDeleted = static_cast<int>(j);
            }
        }
        else
        {
            return (firstDeleted != -1) ? firstDeleted : static_cast<int>(j);
        }
    }

    if (firstDeleted != -1)
        return firstDeleted;
    return -1;
}

void HashTable::display() const
{
    for (size_t i = 0; i < capacity; i++)
    {
        if (states[i] == OCCUPIED)
        {
            cout << i << ": key=" << keys[i] << ", value=" << values[i] << "\n";
        }
        else if (states[i] == EMPTY)
        {
            cout << i << ": EMPTY\n";
        }
        else
        {
            cout << i << ": DELETED\n";
        }
    }
}

int *HashTable::get(int key)
{
    int idx = findIndexOfKey(key);
    if (idx == -1)
        return nullptr;
    return &values[idx];
}

bool HashTable::remove(int key)
{
    int idx = findIndexOfKey(key);
    if (idx == -1)
        return false;
    states[idx] = DELETED;
    return true;
}

int main()
{
    HashTable ht(7);

    // Inserciones (incluye colisión 3 y 17 si cap=7)
    ht.insert(10, 100);
    ht.insert(3, 200);
    ht.insert(17, 300);

    cout << "== Estado inicial ==\n";
    ht.display();

    // Lecturas
    auto p10 = ht.get(10);
    auto p3 = ht.get(3);
    auto p17 = ht.get(17);
    auto p99 = ht.get(99);

    cout << "\n== Lecturas ==\n";
    cout << "get(10): " << (p10 ? to_string(*p10) : string("nullptr")) << "\n";
    cout << "get(3):  " << (p3 ? to_string(*p3) : string("nullptr")) << "\n";
    cout << "get(17): " << (p17 ? to_string(*p17) : string("nullptr")) << "\n";
    cout << "get(99): " << (p99 ? to_string(*p99) : string("nullptr")) << " (esperado nullptr)\n";
