#include <iostream>
using namespace std;
const int Max = 100;

template <typename T>
class Stack
{
private:
	int top;
	T item[Max];
public:
	Stack();
	~Stack();

	void push(T element) {
		if (top >= Max) {
			cout << "Stack Is Full"<<endl;
		}
		else {
			top++;
			item[top] = element;
		}
		
	}
	bool isEmbty() {
		return (top == -1 ? true : false);
	}
	void pop() {
		if (isEmbty()) {
			cout << "Stack Is Embty!" << endl;
		}
		else {
			top--;
		}
	}

	int pop(T &element) {
		if (isEmbty()) {
			cout << "Stack Is Embty!" << endl;
		}
		else {
			element = item[top];
			top--;
			return element;
		}
	}

	void getTop(T &element) {
		if (isEmbty()) {
			cout << "Stack Is Embty!" << endl;
		}
		else {
			element = item[top];
		//	return element;
		}
	}

	void print() {
		if (isEmbty()) {
			cout << "Stack Is Embty!" << endl;
		}
		else {
			for (int i = top; i >= 0; i--) {
				cout << item[i] << "\n";
			}
		}
		
	}


};
template <typename T>
Stack<T>::Stack():top(-1)
{
}

template <typename T>
Stack<T>::~Stack()
{
}

