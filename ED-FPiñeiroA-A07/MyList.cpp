#pragma once
#include <iostream>
#include "MyList.h"

using namespace std;

MyList::MyList(){ //nullptr is for pointers
	first = nullptr;
	last = nullptr;
	pointer = nullptr;
}

MyList::MyList(int d) {
	Node* node = new Node(d);
	first = node;
	last = node;
	node -> next = nullptr;
}

bool MyList::isEmpty() {
	return first == nullptr;
}

void MyList::insertFirst(int d) {
	Node* node = new Node(d);
	if (isEmpty()) { //Caso: lista vacia
		first = node;
		last = node;
		node->next = nullptr;
	}
	else { //Caso: lista con elementos
		node->next = first;
		first = node;
	}

}

void MyList::insertLast(int d) {
	Node* node = new Node(d);
	if (isEmpty()) { //Caso: lista vacia
		first = node;
		last = node;
		node->next = nullptr;
	}
	else { //Caso: lista con elementos
		last->next = node;
		last = node;
	}
}

void MyList::deleteFirst() {
	if (!isEmpty()) {
		if (first->next == nullptr) { //Si la lista solo tiene un elemento
			first = nullptr;
			last = nullptr;

		}
		else { //Si la lista tiene mas de un elemento
			first = first->next;
		}
	}
}

void MyList::deleteLast() {
	if (!isEmpty()) {
		if (first == last) { //Si la lista solo tiene un elemento
			first = last = nullptr;

		}
		else { //Buscamos dentro del arreglo
			pointer = first;
			while (pointer->next != last) { //Recorre la lista hasta el penultimo elemento
				pointer = pointer->next;
			}
			last = pointer;
			last->next = pointer = nullptr;
		}
	}
}
}