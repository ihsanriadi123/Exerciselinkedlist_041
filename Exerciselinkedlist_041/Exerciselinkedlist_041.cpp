#include <iostream>
#include <string>
using namespace std;

class Node {			// untuk membuat kelas node pada circular linkedlist
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {		//untuk membuat kelas  circular linkedlist
private:	
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** riadi, Node** ihsan);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() { //untuk menambahkan data yang ingin dibuat
}

bool CircularLinkedList::search(int rollno, Node** riadi, Node** ihsan) {
	*riadi = LAST->next;
	*ihsan = LAST->next;
	while (*ihsan != LAST) {		//mengambil data rollno dengan nomor roll yang diberikan dalam daftar tertaut
		if (rollno == (*ihsan)->rollNumber) {
			return true;
		}*riadi = *ihsan; *ihsan = (*ihsan)->next;
	}
	if (rollno == LAST->rollNumber) {	//mencari node dengan nomor roll yang diberikan dalam daftar tertaut melingkar
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {		//untuk mengisi data yang =ingin dipakai
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { //untuk menghapus data yang kurang dipakai
	return LAST == NULL;
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {				//untuk menampilkan data yang ingin kita ketahui
		cout << "\nRecords in the list are:\n";
		Node* ihsanNode = LAST->next;
		while (ihsanNode != LAST) {
			cout << ihsanNode->rollNumber << " " << ihsanNode->name << endl;
			ihsanNode = ihsanNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {					//memunculkan data yang dibuat dari hasil sebelumnya
	CircularLinkedList obj;
	while (true) {
		try {									//mengumpulkan data yang ingin diambil
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {							//memilih data yang ingin dicari dan dikelola
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break; 
			}
			case '4': {
				return 0; 
			}
			default: {
				cout << "Invalid option" << endl;
				break; 
			}
		}
	}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;					//mengakhiri data yang baru saja dibuat
}
