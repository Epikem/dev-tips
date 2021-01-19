using namespace std;

class Node
{
public:
	Node* next;
	Node* prev;
	char data;

	void erase();
};

void Node::erase() {
	this->prev->next = this->next;
	this->next->prev = this->prev;
}

class LinkedList
{
public:
	int length;
	Node* head;
	Node* cur;
	Node* tail;

	LinkedList();
	~LinkedList();
	//void add(int data);
	Node* erase();
	Node* put(char data);
	Node* moveLeft();
	Node* moveRight();
	void print();
};

LinkedList::LinkedList() {
	Node* node = new Node();
	node->data = '-';
	this->length = 0;
	this->head = node;
	this->cur = node;
	this->tail = node;
}

LinkedList::~LinkedList() {
	std::cout << "LIST DELETED";
}

Node* LinkedList::moveLeft() {
	if (this->head == this->cur) return this->cur;
	this->cur = this->cur->prev;
	return this->cur;
}

Node* LinkedList::moveRight() {
	if (this->cur->next == NULL) return this->cur;
	this->cur = this->cur->next;
	return this->cur;
}

Node* LinkedList::put(char data) {
	
	Node* node = new Node();
	node->data = data;
	Node* cur = this->cur;

	// cur.prev, cur, cur.next
	// cur.prev, new node, cur, cur.next
	node->next = cur;

	if (this->head != cur) {
		Node* prev = cur->prev;
		prev->next = node;
		node->prev = prev;
	}
	else {
		this->head = node;
	}

	cur->prev = node;

	this->length++;
	return this->cur;
}

Node* LinkedList::erase() {
	Node* cur = this->cur;
	Node* deleteTarget = cur->prev;
	Node* prev;

	if (this->head == cur) return cur;

	if (deleteTarget == NULL) {
		return cur;
	}

	//deleteTarget -> next = cur;
	//cur->prev = deleteTarget;

	if (deleteTarget->prev == NULL) {
		cur->prev = NULL;
		this->head = cur;
	}
	else {
		prev = deleteTarget->prev;
		prev->next = cur;
		cur->prev = prev;
	}
	this->length--;
	return this->cur;
}

void LinkedList::print() {
	Node* head = this->head;
	int i = 1;
	while (head->data != '-') {
		std::cout << head->data;
		head = head->next;
		i++;
	}
	cout << endl;
}



void solve() {
	string st;
	cin >> st;
	int cmds;
	cin >> cmds;
	char cmd;
	char ch;
	int stlen = st.length();
	int pos = stlen;
	LinkedList* list = new LinkedList();
	FOR(i, 0, stlen, 1) {
		list->put(st[i]);
	}

	FOR(i, 0, cmds, 1) {
		cin >> cmd;
		switch (cmd)
		{
		case 'L':
			//if (pos != 0) pos--;
			list->moveLeft();
			break;
		case 'D':
			//if (pos < stlen) pos++;
			list->moveRight();
			break;
		case 'B':
			//if (pos != 0) {
			//	st = st.erase(pos - 1, 1);
			//	pos--;
			//	stlen--;
			//}
			list->erase();
			break;
		case 'P':
			cin >> ch;
			//st = st.insert(pos, 1, ch);
			//stlen++;
			//pos++;
			list->put(ch);

			break;
		default:
			break;
		}
	}
	list->print();
}