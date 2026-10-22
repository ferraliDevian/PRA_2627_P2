#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2627_P1/ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
        int max;
        ListLinked<TableEntry<V>>* table;

        int h(std::string key) {
            int sum = 0;
            for (size_t i = 0; i < key.size(); i++)
                sum += int(key.at(i));
            return sum % max;
        }

    public:
        HashTable(int size) : n(0), max(size) {
            table = new ListLinked<TableEntry<V>>[size];
        }

        ~HashTable() {
            delete[] table;
        }

        int capacity() {
            return max;
        }

        void insert(std::string key, V value) override {
            int b = h(key);
            if (table[b].search(TableEntry<V>(key)) != -1)
                throw std::runtime_error("Key '" + key + "' already exists!");
            table[b].prepend(TableEntry<V>(key, value));
            n++;
        }

        V search(std::string key) override {
            int b = h(key);
            int pos = table[b].search(TableEntry<V>(key));
            if (pos == -1)
                throw std::runtime_error("Key '" + key + "' not found!");
            return table[b].get(pos).value;
        }

        V remove(std::string key) override {
            int b = h(key);
            int pos = table[b].search(TableEntry<V>(key));
            if (pos == -1)
                throw std::runtime_error("Key '" + key + "' not found!");
            TableEntry<V> e = table[b].remove(pos);
            n--;
            return e.value;
        }

        int entries() override {
            return n;
        }

        V operator[](std::string key) {
            return search(key);
        }

        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
            out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]\n";
            out << "==============\n\n";
            for (int i = 0; i < th.max; i++) {
                out << "== Cubeta " << i << " ==\n\n";
                out << th.table[i] << "\n\n";
            }
            out << "==============\n";
            return out;
        }
};

#endif
