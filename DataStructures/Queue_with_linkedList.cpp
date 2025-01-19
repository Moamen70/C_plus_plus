#include <iostream>
using namespace std;

template<typename T>
class Lqueue {
private:
	struct Node
	{
		T value;
		Node* nextPtr;
	};
	Node* front;
	Node* rear;
	int count;

public:
	Lqueue() {
		front = rear = nullptr;
		count = 0;
	}

	void enqueue(T element) {
		if(isEmbty()){
			front = new Node;
			front->value = element;
			front->nextPtr = nullptr;
			rear = front;
			count++;
		}
		else {
			Node* newNode = new Node;
			rear->nextPtr = newNode;
			newNode->value = element;
			newNode->nextPtr = nullptr;
			rear = newNode;
			count++;
		}
	}

	bool isEmbty() {
		return count == 0;
	}

	void dequeue() {
		if (isEmbty()) {
			cout << "The Queue Is Embty!" << endl;
		}
		else {
			Node* deletedNode = front;
			deletedNode->value = front->value;
			front = deletedNode->nextPtr;
			count--;
			delete deletedNode;
		}
	}

	void getFront(T& item) {
		item = front->value;
	}

	void getRear(T& item) {
		item = rear->value;
	}

	void getSize(T& size) {
		size = count;
		cout << "size is :" << size << endl;
	}

	void print() {
		if (isEmbty()) {
			cout << "The Queue Is Embty!" << endl;
		}
		else {
			Node* temp = front;
			while (temp != rear) {
				cout << "Queue element:" << temp->value << endl;
				temp = temp->nextPtr;
			}
			cout << "Queue element:" << temp->value << endl;
		}
	}
	void clear() {
		while (front != nullptr) {
			Node* temp = new Node;
			temp = front;
			front = front->nextPtr;
			delete temp;
			count--;
		}
		rear = nullptr;
	}
};

