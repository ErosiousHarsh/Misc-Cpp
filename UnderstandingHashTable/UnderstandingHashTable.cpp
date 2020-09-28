#include <iostream>
#include <list>
#include <cstring>
using namespace std;
//Hastable Roll Number, Name

class Hashtable {
	private:
		static const int groups = 10;
		list<pair<int, string>> table[groups];

	public:
		bool isEmpty() const;
		int hashFunction(int key);
		void insertItem(int key, string value);
		void removeItem(int key);
		string searchTable(int key);
		void printTable();
};

bool Hashtable::isEmpty() const {
	int sum{};
	for (int i{}; i < groups; i++) {
		sum += table[i].size();
	}

	if (!sum)
		return true;
	return false;
}

int Hashtable::hashFunction(int key) {
	return key % groups;
}

void Hashtable::insertItem(int key, string value) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto beginItr = begin(cell);
	bool keyExists = false;
	for (; beginItr != end(cell); beginItr++) {
		if (beginItr->first == key) {
			keyExists = true;
			beginItr->second = value;
			std::cout << "'Key exists, value has been replaced.'" << endl;
			break;
		}
	}

	if (!keyExists) {
		cell.emplace_back(key, value);
	}

	return;
}

void Hashtable::removeItem(int key) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto beginItr = begin(cell);
	bool keyExists = false;
	for (; beginItr != end(cell); beginItr++) {
		if (beginItr->first == key) {
			keyExists = true;
			beginItr = cell.erase(beginItr);
			std::cout << "'Key, value has been removed.'" << endl;
			break;
		}
	}

	if (!keyExists) {
		std::cout << "Item not found.";
	}

	return;
}

void Hashtable::printTable() {
	for (int i{}; i < groups; i++) {
		if (table[i].size() == 0) continue;

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			std::cout << bItr->first << ":" << bItr->second << endl;
		}
	}

	return;
}

int main() {
	Hashtable ht;

	if (ht.isEmpty())
		std::cout << "Empty" << endl;

	ht.insertItem(118, "Jon");
	ht.insertItem(007, "Bond");
	ht.insertItem(106, "Bon");
	ht.insertItem(325, "Con");
	ht.insertItem(344, "Mon");
	ht.insertItem(353, "Pon");
	ht.insertItem(452, "Ron");
	ht.insertItem(121, "Ton");

	ht.printTable();

	ht.removeItem(118);
	ht.removeItem(121);

	ht.printTable();

	std::cin.get();
}