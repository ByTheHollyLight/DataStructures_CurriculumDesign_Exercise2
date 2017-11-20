#include<iostream>
using namespace std;

template<typename E>
struct stkNode {
	stkNode(E v, stkNode *p = NULL) :value(v), prev(p) {}
	E value;
	stkNode *prev;
};

template<typename E>
class stack {
public:
	stack(stkNode<E> *t = NULL) :top(t) {}
	void push(E value) {
		top = new stkNode<E>(value, top);
	}
	E pop() {
		stkNode<E> *tmp = top;
		E v = tmp->value;
		top = top->prev;
		delete tmp;
		return v;
	}
	E getTop() {
		return top->value;
	}
	bool isEmpty() { return top == NULL; }
private:
	stkNode<E> *top;
};