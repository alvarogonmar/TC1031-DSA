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
