#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

template<class T>
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

	~Stack() {
		delete[] items;
	}

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

	bool isEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top + 1 == MAX;
	}
};

int main() {
	Stack<char> st(256);
	Stack<char> res(256);
	bool f = true;
	bool g = false;
	char number[] = "0123456789", string[256], letter;
	cout << "Input a string" << endl;
	cin.getline(string, 256);

	for (int i = 0; i < strlen(string); i++)
		st.push(string[i]);

	for (int j = 0; j < strlen(string); j++) {
		letter = st.pop();
		for (int k = 0; k < strlen(number); k++) {
			if (letter == number[k] ||
				((letter == 'e' || letter == '-' || letter == '.' || letter == '+') && f && g)) {
				res.push(letter);
				f = true;
				g = true;
				break;
			}
			else
				f = false;
		}
		if (!f && g) {
			g = false;
			f = true;
			res.push(' ');
		}
	}

	if (res.isEmpty())
		cout << "There is no spoon" << endl;
	else {
		while (!res.isEmpty())
			cout << res.pop();
		cout << endl << "We've got some numbers!" << endl;
	}
	return 0;
}
