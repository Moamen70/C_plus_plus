#include <iostream>
using namespace std;

const int MaxSize = 100;
template<typename T>
class Aqueue {
private:
	int front , rear ,count;
	T queue[MaxSize];
public:
	Aqueue() {
		this->front = 0;
		this->rear = MaxSize - 1;
		this->count = 0;
	}

	void enqueue(T element) {
		if (isFull()) {
			cout << "The Queue Is Full!" << endl;
		}
		else {
			rear = (rear + 1) % MaxSize;
			queue[rear] = element;
			count++;
			cout << queue[rear] << endl;
		}
	}

	bool isEmbty(){
		return count == 0;
	}

	bool isFull() {
		return count == MaxSize;
	}
	void dequeue() {
		if (isEmbty()) {
			cout << "The Queue Is Embty!" << endl;
		}
		else {
			front = (front + 1) % MaxSize;
			count--;
		}
	}

	void dequeue(T &element) {
		if (isEmbty()) {
			cout << "The Queue Is Embty!" << endl;
		}
		else {
			element = queue[front];
			front = (front + 1) % MaxSize;
			count--;
		}
	}

	void getFront(T &item) {
		if (isEmbty()) {
			cout << "The Queue Is Embty!" << endl;
		}
		else {
			item = queue[front];
		}
	}

	void getRear(T& item) {
		if (isEmbty()) {
			cout << "The Queue Is Embty!" << endl;
		}
		else {
			item = queue[rear];
		}
	}

	void getSize(int &size) {
		if (isEmbty()) {
			cout << "The Queue Is Embty!" << endl;
		}
		else if (front == rear){
		}
		else if (rear > front){
			size = rear - front + 1;
		}
		else {
			size = MaxSize - front + rear + 1;
		}
	}
};