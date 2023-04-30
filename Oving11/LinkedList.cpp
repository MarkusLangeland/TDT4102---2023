#include "LinkedList.h"

#include <cassert>
// #include <cstdio>
// #include <fstream>
#include <iostream>
// #include <memory>
// #include <stdexcept>

namespace LinkedList
{

    std::ostream &operator<<(std::ostream &os, const Node &node)
    {
        os << node.getValue();
        return os;
    }

    //     // The insert function takes a pointer to node (pos) and a string (value). It creates a new
    //     // node which contains value. The new node is inserted into the LinkedList BEFORE the
    //     // node pointed to by pos. Returns a pointer to the new Node
    Node *LinkedList::insert(Node *pos, const std::string &value)
    {
        assert(pos != nullptr);
        if (pos == begin())
        {
            head = std::make_unique<Node>(value, std::move(head), nullptr);
            pos->prev = begin();
        }
        else
        {
            std::unique_ptr<Node> newNode = std::make_unique<Node>(value, std::move(pos->prev->next), pos->prev);
            pos->prev->next = std::move(newNode);
            pos->prev = pos->prev->getNext();
        }
        return pos->prev;
    }

    // The remove function takes a pointer to a node, and removes the node from the list. The
    // function returns a pointer to the element after the removed node.
    Node *LinkedList::remove(Node *pos)
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

    // The find function traverses the linked list and returns a pointer to the first node
    // that contains the value given.
    // If the value isn't in the list, find returns a pointer to the dummy node at the end
    // of the list.
    Node *LinkedList::find(const std::string &value)
    {
        auto currNode = begin();
        while (currNode->getValue() != value && currNode != end())
        {
            currNode = currNode->getNext();
        }
        return currNode;
    }

    // The remove function takes a string and removes the first node which contains the value.
    void LinkedList::remove(const std::string &value)
    {
        auto posNode = find(value);
        if (posNode != end())
        {
            remove(posNode);
        }
    }

    std::ostream &operator<<(std::ostream &os, const LinkedList &list)
    {
        auto currNode = list.begin();
        os << "[ ";
        while (currNode != list.end())
        {
            os << *currNode;
            os << " ";
            currNode = currNode->getNext();
        }
        os << "]";
        return os;
    }

    LinkedList::~LinkedList()
    {
        auto currNode = end()->prev;
        while (currNode->prev != nullptr)
        {
            currNode->next = nullptr;
            currNode = currNode->prev;
        }
    }
}
void testLinkedList()
{
    std::cout << "Testing Linked List" << std::endl;
    LinkedList::LinkedList list;
    list.insert(list.begin(), "Element 1");
    list.insert(list.begin(), "Element 2");
    list.insert(list.begin(), "Element 3");
    std::cout << list << std::endl;
    list.remove("Element 2");
    std::cout << list << std::endl;
    list.insert(list.end(), "Element 4");
    std::cout << list << std::endl;
}

void testLinkedListOverflow()
{
    std::cout << "Testing LinkedList destructor overflow\n";
    using LinkedList::LinkedList;
    constexpr unsigned int N = 1'000'000;
    {
        LinkedList list;
        for (unsigned int i = 0; i < N; ++i)
        {
            list.insert(list.end(), "e");
        }
        std::cout << "Elements added\n";
    } // Destruktøren kjører
    //Can take som time, try to reduce number if it takes too long.
    std::cout << "List destructed\n";
}
