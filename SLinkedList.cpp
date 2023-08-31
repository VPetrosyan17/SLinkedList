#include <iostream>

template<typename T>
struct Node{
	T data;
	Node<T>* next;
	Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
class LinkedList{
	public:
	LinkedList() : head(nullptr) {}
	
	//insert node	
	void insert(T value){
		Node<T>* newNode = new Node<T>(value);
		if(head == nullptr){
			head = newNode;
		}
		Node<T>* temp = head;
		while(temp->next != nullptr){
			temp = temp->next;
		}
		temp->next = newNode;
	}
	
	//print nodes of the linked list
	void print(){
		Node<T>* temp = head;
		if(head == nullptr){
			isEmpty();
		}
		while(temp != nullptr){
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}
	
	//remove the node at given position
	void remove(int nodeOffset){
		Node<T>* temp1 = head;
		Node<T>* temp2 = nullptr;
		int ListLength = 0;
		if(head == nullptr){
			isEmpty();
		}
		while(temp1 != nullptr){
			temp1 = temp1->next;
			ListLength++;
		}
		if(ListLength < nodeOffset){
			throw std::out_of_range("Index out of range");
		}
		temp1 = head;
		if(nodeOffset == 1){
			head = head->next;
			delete temp1;
		}
		while(nodeOffset > 1){
			temp2 = temp1;
			temp1 = temp1->next;
			nodeOffset--;
		}
		temp2->next = temp1->next;
		delete temp1;
	}
	
	//checking whether is empty or not
	bool isEmpty() {
		return head == nullptr;
	}
	private:
	Node<T>* head;
};

int main(){
	LinkedList<int> list;

	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);

	std::cout << "Elements of list: ";
	list.print();
	std::cout << std::endl;

	list.remove(3);
	std::cout << "Elements of list: ";
	list.print();
	std::cout << std::endl;
	return 0;
}
