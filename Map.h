#ifndef MAP_H
#define MAP_H

template<typename KeyType, typename ValueType>
class Pair {
private:
	KeyType first;
	ValueType second;
public:
	Pair(KeyType first = KeyType(), ValueType second = ValueType()) : first(first), second(second) {
	}

	Pair<KeyType, ValueType> & operator=(const Pair<KeyType, ValueType>& other) {
		if (this != &other) {
			this->first = other.first;
			this->second = other.second;
			return *this;
		}
		return *this;
	}

	KeyType& getFirst() {
		return first;
	}

	ValueType& getSecond() {
		return second;
	}

	const KeyType& getFirst() const {
		return first;
	}

	const ValueType& getSecond() const {
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
		for (int i = 0; i < length; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = new Pair<KeyType, ValueType>[length];
		for (int i = 0; i < length; i++) {
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
		for (int i = 0; i < length; i++) {
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
		insert(Pair<KeyType, ValueType>(target, ValueType()));
	}

	const ValueType& operator[](KeyType target) const {
		Pair<KeyType, ValueType> * result = find(target);
		if (result != nullptr) {
			return result->getSecond();
		}
		insert(Pair<KeyType, ValueType>(target, ValueType()));
	}

	~Map() {
		delete[] arr;
	}
	Map(const Map& other) {
		this->arr = new Pair<KeyType, ValueType>[other.length];
		for (int i = 0; i < other.length; i++) {
			arr[i] = other.arr[i];
		}
		this->length = other.length;
	}
	Map& operator=(const Map& other) {
		delete[] this->arr;
		this->arr = new Pair<KeyType, ValueType>[other.length];
		for (int i = 0; i < other.length; i++) {
			arr[i] = other.arr[i];
		}
		this->length = other.length;
	}

	Pair<KeyType, ValueType>* begin() {
		return this->arr;
	}

	Pair<KeyType, ValueType>* end() {
		return &this->arr[this->length];
	}

	static class iterator {
		private:
			Pair<KeyType, ValueType>* current;
		public:
			iterator() {
				current = NULL;
			}

			iterator(const Pair<KeyType, ValueType>* other) {
				// magic happens here
				current = const_cast<Pair<KeyType, ValueType>* >(other);
			}

			~iterator() {
				current = NULL;
			}

			iterator& operator=(Pair<KeyType, ValueType>* other) {
				current = other;
			}
			iterator operator++(int) {
				current++;
				return *this;
			}

			Pair<KeyType, ValueType>* operator->() {
				return current;
			}

			bool operator!=(Pair<KeyType, ValueType>* other) {
				return current != other;
			}
	};
};

#endif