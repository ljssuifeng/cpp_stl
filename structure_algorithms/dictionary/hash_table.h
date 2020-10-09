#pragma once
#include <memory>
#include "structure_algorithms/my_exceptions.h"

template <typename K, typename E>
class HashTable {
 public:
  HashTable(int theDivisor = 11);
  ~HashTable() { delete[] table; }
  bool empty() const { return dSize == 0; }
  int size() const { return dSize; }
  std::pair<const K, E>* find(const K&) const;
  void insert(std::pair<const K, E>&);
  void output(std::ostream& out) const;
  void erase(const K&);

 protected:
  int search(const K&) const;
  std::pair<const K, E>** table;
  std::hash<K> hash;  // function maps K type to non-negative integer
  int dSize;          // number of pairs in dictionary
  int divisor;        // hash function divisor
};

template <typename K, typename E>
HashTable<K, E>::HashTable(int theDivisor) {
  divisor = theDivisor;
  dSize = 0;

  // allocate and init hashTable array
  table = new std::pair<const K, E>*[divisor];
  for (int i = 0; i < divisor; ++i) {
    table[i] = nullptr;
  }
}
/**
 * search an open addressed hash table for a pair with key theKey
 * return location of match ing pair if found, otherwise return location
 * where a pair with key theKey may be inserted provided the hash table
 * is not full.
 */
template <typename K, typename E>
int HashTable<K, E>::search(const K& theKey) const {
  int i = static_cast<int>(hash(theKey) % divisor);  // home bucket
  int j = i;                                         // start at home bucket
  do {
    if (table[j] == nullptr || table[j]->first == theKey) {
      return j;
    }
    j = (j + 1) % divisor;  // next bucket
  } while (j != i);
  return j;  // table is full
}

/**
 * return pointer to matching pair
 * return nullptr if no matching pair
 */
template <typename K, typename E>
std::pair<const K, E>* HashTable<K, E>::find(const K& theKey) const {
  // search the table
  int b = search(theKey);
  // see if a match was found at table b
  if (table[b] == nullptr || table[b]->first != theKey) {
    return nullptr;
  }
  return table[b];  // matching pair
}
/**
 * insert thePair into the dictionary, Overwrite existing pair,
 * if any, with same key.
 * Throw hashTableFull exception in case table is full.
 * search the table for a matching pair.
 */
template <typename K, typename E>
void HashTable<K, E>::insert(std::pair<const K, E>& thePair) {
  int b = search(thePair.first);
  // check if matching pair found
  if (table[b] == nullptr) {
    // no matching pair and not full
    table[b] = new std::pair<const K, E>(thePair);
    dSize++;
  } else {
    // check if duplicate or table full
    if (table[b]->first == thePair.first) {
      // duplicate, change table[b]->second
      table[b]->second = thePair.second;
    } else {
      // table if full
      throw HashTableFull();
    }
  }
}

template <typename K, typename E>
void HashTable<K, E>::output(std::ostream& out) const {
  for (int i = 0; i < divisor; ++i) {
    if (table[i] == nullptr) {
      std::cout << "nullptr" << std::endl;
    } else {
      std::cout << table[i]->first << ":" << table[i]->second << std::endl;
    }
  }
}

template <typename K, typename E>
void HashTable<K, E>::erase(const K& theKey) {
  int b = search(theKey);
  if (table[b] != nullptr && table[b]->first == theKey) {
    delete table[b];
    table[b] = nullptr;
    int k = (b + 1) % divisor;
    while (k != b && table[k] != nullptr) {
      table[k - 1] =
          new std::pair<const K, E>(table[k]->first, table[k]->second);
      delete table[k];
      table[k] = nullptr;
      k = (k + 1) % divisor;
    }
  }
}

// overload <<
template <typename K, typename E>
std::ostream& operator<<(std::ostream& out, const HashTable<K, E>& x) {
  x.output(out);
  return out;
}
