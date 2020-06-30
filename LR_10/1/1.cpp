#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

template< class T >
class Stack {

private:
	int MAX;
	int top;
	T* items;

public:
	Stack(int size) {
		MAX = size;
		top = -1;
		items = new T[MAX];
	}

	~Stack() { delete[] items; }

	void push(T c) {
		if (isFull()) {
			cout << "Stack Full!" << endl;
			exit(1);
		}

		items[++top] = c;
	}

	T pop() {
		if (isEmpty()) {
			cout << "Stack Empty!" << endl;
			exit(1);
		}

		return items[top--];
	}

	int isEmpty() { return top == -1; }

	int isFull() { return top + 1 == MAX; }
};

int main() {
	Stack<char> init(256);
	Stack<char> result(256);

	bool isDigit = false;
	bool isSpaceOnlyOne = false;
	char numbers[] = "0123456789";
	char line[256];

	cout << "Input a string:" << endl;

	cin.getline(line, 256);

	//init fill
	for (int i = 0; i < strlen(line); i++) {
		init.push(line[i]);
	}

	for (int j = 0; j < strlen(line); j++) {
		char letter = init.pop();

		for (int k = 0; k < strlen(numbers); k++) {
			if (letter == numbers[k] ||
				((letter == '-' || letter == '.') && isDigit && isSpaceOnlyOne)) {
				result.push(letter);
				isDigit = true;
				isSpaceOnlyOne = true;
				break;
			}
			else
				isDigit = false;
		}

		if (!isDigit && isSpaceOnlyOne) {
			isSpaceOnlyOne = false;
			isDigit = true;
			result.push(' ');
		}
	}

	if (result.isEmpty()) {
		cout << "No such numbers" << endl;
	}
	else {
		cout << endl << "Numbers: ";

		while (!result.isEmpty()) {
			cout << result.pop();
		}

	}

	return 0;
}
