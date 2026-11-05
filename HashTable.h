#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {
    private:
        int n;
        int max;
        ListLinked<TableEntry<V>>* table;

        int h(std::string key) {
            int sum = 0;
            for (size_t i = 0; i < key.length(); i++) {
                sum += static_cast<int>(key.at(i));
            }
            return sum % max;
        }

    public:
        HashTable(int size) {
            if (size <= 0) {
                throw std::invalid_argument("El tamaño debe ser mayor que 0");
            }
            max = size;
            n = 0;
            table = new ListLinked<TableEntry<V>>[max];
        }

        ~HashTable() {
            delete[] table;
        }

        int capacity() {
            return max;
        }

        int entries() override {
            return n;
        }

        void insert(std::string key, V value) override {
            int idx = h(key);
            TableEntry<V> entry(key, value);
            if (table[idx].search(entry) != -1) {
                throw std::runtime_error("Key already exists: " + key);
            }
            table[idx].append(entry);
            n++;
        }

        V search(std::string key) override {
            int idx = h(key);
            TableEntry<V> dummy(key);
            int pos = table[idx].search(dummy);
            if (pos == -1) {
                throw std::runtime_error("Key not found: " + key);
            }
            return table[idx].get(pos).value;
        }

        V remove(std::string key) override {
            int idx = h(key);
            TableEntry<V> dummy(key);
            int pos = table[idx].search(dummy);
            if (pos == -1) {
                throw std::runtime_error("Key not found: " + key);
            }
            V val = table[idx].get(pos).value;
            table[idx].remove(pos);
            n--;
            return val;
        }

        V operator[](std::string key) {
            return search(key);
        }

        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
            out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]\n";
            out << "==============\n";
            for (int i = 0; i < th.max; i++) {
                out << "Cubeta " << i << ": " << th.table[i] << "\n";
            }
            out << "==============\n";
            return out;
        }
};

#endif
