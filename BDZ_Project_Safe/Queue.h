#ifndef QUEUE_H_
#define QUEUE_H_

template <typename T>
class Queue {
private:

	struct Node {
		T data;
		Node* next;
	};

	Node* front;
	Node* back;
	int size;

	void erase();
	void copy(const Queue& other);

public:

	Queue();
	~Queue();
	Queue(const Queue& other);
	Queue<T>& operator=(const Queue& other);

	void push(T data);
	void pop();
	T backData() const;
	T frontData() const;
	bool isEmpty() const;
	int getSize() const;

};

template<typename T>
inline void Queue<T>::erase() {
	while (!isEmpty()) {
		Node* temp = front;
		front = front->next;
		delete temp;
	}
}

template<typename T>
inline void Queue<T>::copy(const Queue & other) {
	this->size = other.size;
	if (other.isEmpty()) {
		front = NULL;
		back = NULL;
	}
	else {
		Node* temp = other.front;
		while (temp != NULL) {
			push(temp->data);
			temp = temp->next;
		}
	}
}

template<typename T>
inline bool Queue<T>::isEmpty() const {
	return front == NULL;
}

template<typename T>
inline int Queue<T>::getSize() const {
	return size;
}


template<typename T>
inline Queue<T>::Queue() {
	this->front = NULL;
	this->back = NULL;
	this->size = 0;
}

template<typename T>
inline Queue<T>::~Queue() {
	erase();
}

template<typename T>
inline Queue<T>::Queue(const Queue & other) {
	copy(other);
}

template<typename T>
inline Queue<T>& Queue<T>::operator=(const Queue& other) {
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

template<typename T>
inline void Queue<T>::push(T data) {
		Node* temp = new Node;
		temp->data = data;
		temp->next = NULL;
	if (isEmpty()) {
		front = back = temp;
	}
	else {
		back->next = temp;
		back = temp;
	}
	size++;
}

template<typename T>
inline void Queue<T>::pop() {
	if (!isEmpty()) {
		Node* temp = front;
		front = front->next;
		delete temp;
		size--;
	}
}

template<typename T>
inline T Queue<T>::backData() const {
	return back->data;
}

template<typename T>
inline T Queue<T>::frontData() const {
	return front->data;
}

#endif
