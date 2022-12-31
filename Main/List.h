#pragma once

template <class T>

class List {

    struct Node {

        T elem;
        Node* next;

        Node() {
            next = nullptr;
        };

        Node(T value) {
            elem = value;
            next = nullptr;
        };
    };

    Node* first = nullptr;
    size_t size = 0;

public:

    class Iterator {

        Node* it;

    public:

        Iterator() {

        };

        Iterator(Node* data) {
            it = data;
        };

        Iterator operator++() {
            it = it->next;
            return Iterator(it);
        };

        Iterator& operator++() {
            it = it->next;
            return *this;
        };

        bool operator!=(Iterator tmp) {
            return (it != tmp.it);
        };

        bool operator==(Iterator tmp) {
            return (it == tmp.it);
        };

        Iterator begin() {
            return Iterator(first);
        };

        Iterator end() {
            return Iterator(nullptr);
        };

        Node* get() {
            return it;
        }
    };

    List() {
        first = new Node();
        size++;
    };

    List(size_t count) {
        first = new Node();
        auto tmp = first;
        for (int i = 1; i < count; i++) {
            tmp->next = new Node();
            tmp = tmp->next;
        }
        size = count;
    };

    List(List& list) {
        Node* lptr = list.first;
        if (!list.first)
            return;
        first = new Node(lptr->elem);
        lptr = lptr->next;
        Node* tmp = first;
        while (lptr) {
            tmp->next = new Node(lptr->elem);
            lptr = lptr->next;
            tmp = tmp->next;
        }
        size = list.size;
    };

    ~List() {
        Node* tmp = first;
        while (tmp) {
            Node* tmpN = tmp->next;
            delete tmp;
            tmp = tmpN;
        }
        size = 0;
    };

    List<T>& operator=(const List& list) {
        if (this == &list) {
            clear();
            first = nullptr;
            return *this;
        }
        List copy(list);
        this->clear();
        this->first = copy.first;
        return *this;
    };

    bool empty() {
        return (size == 0);
    };

    size_t sizeL() {
        return size;
    };

    void clear() {
        Node* tmp = first;
        while (tmp != nullptr) {
            Node* tmpN = tmp->next;
            delete tmp;
            tmp = tmpN;
        }
        size = 0;
    };

    void reverse() {  // List task (9)
        Node* tmp = first;
        Node* it = first;
        Node* tmpN = nullptr;
        while (it) {
            tmp = it->next;
            it->next = tmpN;
            tmpN = it;
            it = tmp;
        }
        first = tmpN;
    };

    void push(T k) {
        Node* tmp = first;
        first = new Node(k);
        first->next = tmp;
        size++;
    };

    void pop() {
        Node* tmp = first->next;
        delete first;
        first = tmp;
        size--;
    };

    void pushIt(Iterator& it, T val) {
        Node* node = it.node;
        Node* tmp = node->next;
        node->next = new Node(val);
        node->next->next = tmp;
        size++;
    };

    void popIt(Iterator& it) {
        Node* node = it.node;
        Node* tmp = node->next;
        node->next = tmp ? tmp->next : nullptr;
        delete tmp;
        size--;
    };
};