#include "TemplatesClass.h"

// using namespace TemplateLinkedList;
// namespace TemplateLinkedList
// {
void testTeplateLinkedList()
{
    TemplateLinkedList::LinkedList<int> list1;
    list1.insert(list1.end(), 1);
    list1.insert(list1.end(), 2);
    list1.insert(list1.end(), 3);
    TemplateLinkedList::LinkedList<double> list2;
    list2.insert(list2.end(), 2.4);
    list2.insert(list2.end(), 3.1);
    list2.insert(list2.end(), 1.5);
    TemplateLinkedList::LinkedList<std::string> list3;
    list3.insert(list3.end(), "Element 1");
    list3.insert(list3.end(), "Element 2");
    list3.insert(list3.end(), "Element 3");

    std::cout << list1 << std::endl;
    std::cout << list2 << std::endl;
    std::cout << list3 << std::endl;
}

// }
