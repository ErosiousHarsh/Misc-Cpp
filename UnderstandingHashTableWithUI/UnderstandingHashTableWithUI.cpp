#include <iostream>
#include <cstring>
#include <list>
using namespace std;

class UnderstandingHashTableWithUI {
	private:
		int n;
		list<pair<int, string>>* table;

	public:
		UnderstandingHashTableWithUI(int);
		void insertItem(int k, string v);
		void deleteItem(int k);
		int hashFunction(int k);
		void printTable();
};

UnderstandingHashTableWithUI::UnderstandingHashTableWithUI(int size) {
	this->n = size;
	table = new list<pair<int, string>>[n];
}

int UnderstandingHashTableWithUI::hashFunction(int k) {
	return (k % n);
}

void UnderstandingHashTableWithUI::insertItem(int k, string v) {
	int index = hashFunction(k);
	auto& cell = table[index];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == k) {
			keyExists = true;
			bItr->second = v;
			std::cout << "'Key exists, value has been replaced.'" << endl;
			break;
		}
	}
}