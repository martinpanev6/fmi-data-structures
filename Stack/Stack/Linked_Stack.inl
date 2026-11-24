template <typename T>
LinkedStack<T>::LinkedStack() : tos(nullptr) {}

template<typename T>
inline LinkedStack<T>::LinkedStack(const LinkedStack<T>& other) : LinkedStack()
{
	try {
		copy(other.tos);
	}
	catch (std::bad_alloc&) {
		clear();
		throw;
	}
}

template<typename T>
inline LinkedStack<T>::~LinkedStack()
{
	clear();
}

//Weak exception safety
template<typename T>
inline LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& other)
{
	if (this != &other) {
		clear();
		copy(other.tos);
	}
	return *this;
}

template <typename T>
void LinkedStack<T>::push(const T& elem) {
	Node* n = new(std::nothrow) Node(elem, tos);
	if (!n) {
		if (!spare) throw std::bad_alloc();
		spare->data = elem;
		spare->next = tos;
		n = spare;
		spare = nullptr;
	}
	tos = n;
}

template <typename T>
T LinkedStack<T>::pop() {
	T res = top();
	Node* keep = tos;
	tos = tos->next;
	if (spare) {
		delete keep;
	}
	else {
		spare = keep;
	}
	return res;
}

template <typename T>
const T& LinkedStack<T>::top()const {
	if (!isEmpty()) {
		return tos->data;
	}
	throw std::underflow_error("The stack is empty!");
}

template<typename T>
inline bool LinkedStack<T>::isEmpty() const
{
	return tos == nullptr;
}

template <typename T>
void LinkedStack<T>::clear() {
	while (!isEmpty()) {
		Node* keep = tos;
		tos = tos->next;
		delete keep;
	}
	if (spare) {
		delete spare;
		spare = nullptr;
	}
}

template<typename T>
inline void LinkedStack<T>::copy(const Node* top)
{
	assert(isEmpty());
	if (top) {
		tos = new Node(top->data);
		top = top->next;

		Node* prev = tos;
		while (top) {
			prev->next = new Node(top->data);
			prev = prev->next;
			top = top->next;
		}
	}
}

template<typename T>
inline bool LinkedStack<T>::isFull() const
{
	if (spare) {
		return false;
	}
	spare = new(std::nothrow) Node(T());
	return !spare;
}