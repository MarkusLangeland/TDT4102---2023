#pragma once

#include <ostream>
#include <string>
#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>

// test code
void testTeplateLinkedList();

namespace TemplateLinkedList
{

    template <typename T>
    class LinkedList;

    template <typename T>
    class Node
    {
    private:
        const T value;                 // The data held by the LinkedList
        std::unique_ptr<Node<T>> next; // unique_ptr to the next node
        Node<T> *prev;                 // raw (non-owning) ptr to the previous node
    public:
        Node() : value(), next(nullptr), prev(nullptr) {}
        // construct a node with string value, a unique_ptr to the next node, and a pointer to the previous node
        Node(const T &value, std::unique_ptr<Node<T>> next, Node<T> *prev)
            : value(value), next(std::move(next)), prev(prev)
        {
        }
        // We can use the default constructor, since unique_ptr takes care of deleting memory
        ~Node() = default;
        // return the value of the node
        T getValue() const { return value; }

        // return a raw (non-owning) pointer to the next node
        Node<T> *getNext() const { return next.get(); }
        // return a raw (non-owning) pointer to the previous node
        Node<T> *getPrev() const { return prev; }

        // write the value of the node to the ostream
        friend std::ostream &operator<<(std::ostream &os, const Node<T> &node)
        {
            os << node.getValue();
            return os;
        }

        friend class LinkedList<T>;
    };

    template <typename T>
    class LinkedList
    {
    private:
        // ptr to the first node
        std::unique_ptr<Node<T>> head;
        // a raw pointer to the last node, the last node is always a dummy node
        // this is declared as a const ptr to a Node, so that tail never can
        // point anywhere else
        Node<T> *const tail;

    public:
        // create the dummy node, and make tail point to it
        LinkedList()
            : head(std::make_unique<Node<T>>()), tail(head.get())
        {
        }
        ~LinkedList() = default;

        // if next is a nullptr (i.e. head is the dummy node), the list is emtpy
        bool isEmpty() const { return head->next == nullptr; }

        // return a pointer to first element
        Node<T> *begin() const { return head.get(); }
        // return a pointer to beyond-end element
        Node<T> *end() const { return tail; }

        // The insert function takes a pointer to node (pos) and a string (value). It creates a new
        // node which contains value. The new node is inserted into the LinkedList BEFORE the
        // node pointed to by pos. Returns a pointer to the new Node
        Node<T> *insert(Node<T> *pos, const T &value)
        {
            assert(pos != nullptr);
            if (pos == begin())
            {
                head = std::make_unique<Node<T>>(value, std::move(head), nullptr);
                pos->prev = begin();
            }
            else
            {
                std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value, std::move(pos->prev->next), pos->prev);
                pos->prev->next = std::move(newNode);
                pos->prev = pos->prev->getNext();
            }
            return pos->prev;
        }

        // The find function traverses the linked list and returns a pointer to the first node
        // that contains the value given.
        // If the value isn't in the list, find returns a pointer to the dummy node at the end
        // of the list.
        Node<T> *find(T &value)
        {
            auto currNode = begin();
            while (currNode->getValue() != value && currNode != end())
            {
                currNode = currNode->getNext();
            }
            return currNode;
        }

        // The remove function takes a pointer to a node, and removes the node from the list. The
        // function returns a pointer to the element after the removed node.
        Node<T> *remove(Node<T> *pos)
        {
            assert(pos != nullptr);
            assert(pos != end());

            if (pos == begin())
            {
                head = std::move(pos->next);
                head->prev = nullptr;
                return begin();
            }

            // Move the pointers on the next node and prev node:
            pos->next->prev = pos->prev;
            pos->prev->next = move(pos->next);

            return pos->getNext();
        }

        // The remove function takes a string and removes the first node which contains the value.
        void remove(const T &value)
        {
            auto posNode = find(value);
            if (posNode != end())
            {
                remove(posNode);
            }
        }

        friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)
        {
            auto currNode = list.begin();
            os << "[ ";
            while (currNode != list.end())
            {
                os << currNode->getValue();
                os << " ";
                currNode = currNode->getNext();
            }
            os << "]";
            return os;
        }
    };
}
