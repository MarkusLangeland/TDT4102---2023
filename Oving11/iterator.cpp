
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

void iteratorVectorForward(std::vector<std::string> vec)
{
    std::cout << "----------------" << std::endl;

    for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "----------------" << std::endl;
}

void iteratorVectorBackward(std::vector<std::string> vec)
{
    std::cout << "----------------" << std::endl;
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "----------------" << std::endl;
}

void replace(std::vector<std::string> &vec, std::string old, std::string replacement)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        if (*it == old)
        {
            it = vec.erase(it);
            it = vec.insert(it, replacement);
        }
    }
}

void iteratorSetForward(std::set<std::string> s)
{
    std::cout << "----------------" << std::endl;

    for (auto it = s.begin(); it != s.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "----------------" << std::endl;
}

void iteratorSetBackwards(std::set<std::string> s)
{
    std::cout << "----------------" << std::endl;
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "----------------" << std::endl;
}

void replaceSet(std::set<std::string> &s, std::string old, std::string replacement)
{
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it == old)
        {
            it = s.erase(it);
            it = s.insert(it, replacement);
        }
    }
}