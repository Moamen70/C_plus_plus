#include <iostream>
using namespace std;


template<typename T >
class StackLL {
private:
	struct Node
	{
		T value;
		Node* nextPtr;
	};
	Node* top;
public:
	StackLL();
	
	void push(T element) {
		Node* newItemPtr = new Node;
		if (newItemPtr == nullptr) {
			cout << "Stack Cannot Allocate Memory!" << endl;
		}
		else {
			newItemPtr->value = element;
			newItemPtr->nextPtr = top;
			top = newItemPtr;
		}
	}
	bool isEmbty() {
		return top == nullptr;
	}
	void pop() {
		if (isEmbty()) {
			cout << "Stack Is Embty!" << endl;
		}
		else {
			Node* deletedPtr = top;
			top = deletedPtr->nextPtr;
			delete deletedPtr;
		}
	}
	template<typename T >
	void pop(T &temp) {
		if (isEmbty()) {
			cout << "Stack Is Embty!" << endl;
		}
		else {
			temp = top->value;
			Node* deletedPtr = top;
			top = deletedPtr->nextPtr;
			delete deletedPtr;
		}
	}

	template<typename T >
	void getTop(T& temp) {
		if (isEmbty()) {
			cout << "Stack Is Embty!" << endl;
		}
		else {
			temp = top->value;
		}
	}

	void print() {
		if (isEmbty()) {
			cout << "Stack Is Embty!" << endl;
		}
		else {
			Node* tempPtr = top;
			while (tempPtr != nullptr) {
				cout << tempPtr->value << endl;
				tempPtr = tempPtr->nextPtr;
			}
		}
		}
};
	

template<typename T >
StackLL<T>::StackLL() {
	top = nullptr;
}
