#ifndef MAP_H
#define MAP_H

template<typename KeyType, typename ValueType>
class Pair {
private:
	KeyType first;
	ValueType second;
public:
	Pair(KeyType first = KeyType(), ValueType second = ValueType()) : first(first), second(second) 
	{
	}

	Pair<KeyType, ValueType> & operator=(const Pair<KeyType, ValueType>& other) {
		if (this != &other) {
			this->first = other.first;
			this->second = other.second;
			return *this;
		}
		return *this;
	}

	KeyType getFirst() {
		return first;
	}

	ValueType getSecond() {
		return second;
	}

};

template<typename KeyType, typename ValueType>
class Map {
private:
	Pair<KeyType, ValueType>* arr;
	int length;

	void changeLength(int length) {
		Pair<KeyType, ValueType>* temp = new Pair<KeyType, ValueType>[length];
		for (int i = 0; i < length; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = new Pair<KeyType, ValueType>[length];
		for (int i = 0; i < length; i++)
		{
			arr[i] = temp[i];
		}
		delete[] temp;
		this->length = length;
	}

public:
	Map() : arr(new Pair<KeyType, ValueType>[0]) {
		length = 0;
	}

	void insert(Pair<KeyType, ValueType> x) {
		changeLength(length + 1);
		arr[length - 1] = x;
	}

	Pair<KeyType, ValueType>* find(KeyType target) {
		for (int i = 0; i < length; i++)
		{
			if (arr[i].getFirst() == target) {
				return &arr[i];
			}
		}
		return nullptr;
	}

	ValueType& operator[](KeyType target) {
		Pair<KeyType, ValueType> * result = find(target);
		if (result != nullptr) {
			return result->getSecond();
		}
		//insert(Pair<KeyType, ValueType>(target, ValueType()));
	}


};

#endif
