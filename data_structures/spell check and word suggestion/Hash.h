#ifndef HASH_H
#define HASH_H

#include <iostream>
#include<algorithm>

// Default hash function class
using namespace std;

template <typename K>
struct KeyHash {
	int operator()(const K& key, int size) const
	{
		return key % size;
	}
};

template <typename K, typename V>
class HashNode {
public:
	HashNode(const K &key, const V &value) :
		key(key), value(value), next(NULL) {

	}

	K getKey() const {
		return key;
	}

	V getValue() const {
		return value;
	}

	void setValue(V value) {
		HashNode::value = value;
	}

	HashNode *getNext() const {
		return next;
	}

	void setNext(HashNode *next) {
		HashNode::next = next;
	}

private:
	// key-value pair
	K key;
	V value;
	// next bucket with the same key
	HashNode *next;
};

template <typename K, typename V, typename F = KeyHash<K>>
class HashMap {
public:
	HashMap() {
		// construct zero initialized hash table of size
		size = 0;
		TABLE_SIZE = 4;
		table = new HashNode<K, V> *[TABLE_SIZE]();
	}

	~HashMap() {
		// destroy all buckets one by one
		for (int i = 0; i < TABLE_SIZE; ++i) {
			HashNode<K, V> *entry = table[i];
			while (entry != NULL) {
				HashNode<K, V> *prev = entry;
				entry = entry->getNext();
				delete prev;
			}
			table[i] = NULL;
		}
		// destroy the hash table
		delete[] table;
	}

	bool get(const K &key, V &value) {
		unsigned long hashValue = hashFunc(key, TABLE_SIZE);
		HashNode<K, V> *entry = table[hashValue];
		int c = 0;
		while (entry != NULL) {
			if (entry->getKey() == key) {
				vector<V> vec;
				value = entry->getValue();
//				value.push_back(entry->getValue());
				vec.push_back(value);
				c++;
			}
			if (c!=0){
				return true;
			}
			entry = entry->getNext();
		}
		return false;
	}
	void rehash(){
		std::cout << "\n--------------------------\nRehashing\n--------------------------\n";
		int old_ts = TABLE_SIZE;
		TABLE_SIZE *= 2;
		HashNode<K, V> **table2;
		table2 = table;
		table = new HashNode<K, V> *[TABLE_SIZE]();
		size = 0;
		for (size_t i = 0; i < old_ts; i++)
		{
			HashNode<K, V> *entry = table2[i];
			while (entry != NULL) {
				put(entry->getKey(), entry->getValue());
				entry = entry->getNext();
			}
		}
		delete table2;
	}
	void put(const K &key, const V &value) {
		if ((double(size) / TABLE_SIZE) > 0.5)
			rehash();
		int hashValue = hashFunc(key, TABLE_SIZE);
		HashNode<K, V> *prev = NULL;
		HashNode<K, V> *entry = table[hashValue];

		while (entry != NULL && entry->getKey() != key) {
			prev = entry;
			entry = entry->getNext();
		}

		if (entry == NULL) {
			entry = new HashNode<K, V>(key, value);
			if (prev == NULL) {
				// insert as first bucket
				table[hashValue] = entry;
			}
			else {
				prev->setNext(entry);
			}
		}
		else {
			// just update the value
			entry->setValue(value);
		}
		size++;
	}

	void remove(const K &key) {
		unsigned long hashValue = hashFunc(key, TABLE_SIZE);
		HashNode<K, V> *prev = NULL;
		HashNode<K, V> *entry = table[hashValue];

		while (entry != NULL && entry->getKey() != key) {
			prev = entry;
			entry = entry->getNext();
		}

		if (entry == NULL) {
			// key not found
			return;
		}
		else {
			if (prev == NULL) {
				// remove first bucket of the list
				table[hashValue] = entry->getNext();
			}
			else {
				prev->setNext(entry->getNext());
			}
			delete entry;
		}
		size--;
	}

private:
	// hash table
	HashNode<K, V> **table;
	F hashFunc;
	int size;
	int TABLE_SIZE; 
};
#endif