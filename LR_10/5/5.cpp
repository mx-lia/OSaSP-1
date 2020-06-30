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
		if (full()) {
			cout << "Stack Full!" << endl;
			exit(1);
		}
		items[++top] = c;
	}

	T pop() {
		if (empty()) {
			cout << "Stack Empty!" << endl;
			exit(1);
		}
		return items[top--];
	}

	int empty() {
		return top == -1;
	}

	int full() {
		return top + 1 == MAX;
	}
};

int main() {
	Stack<char> st(256);
	int countL = 0;
	int countR = 0;
	char string[256];
	char letter;

	cout << "Input a string" << endl;
	cin.getline(string, 256);
	for (int i = 0; i < strlen(string); i++)
		st.push(string[i]);

	for (int j = 0; j < strlen(string); j++) {
		letter = st.pop();
		if (letter == '(')
			countL++;
		if (letter == ')')
			countR++;
	}

	if (countL != countR)
		cout << "Not balanced!" << endl;
	else
		cout << "Balanced!" << endl;

	return 0;
}