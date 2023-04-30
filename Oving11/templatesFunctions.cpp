
#include <iostream>
#include <vector>
#include <random>

template <typename T>
T maximum(T num1, T num2)
{
    return num1 > num2 ? num1 : num2;
}

template <typename T>
void shuffle(std::vector<T> &vec)
{
    for (int i = 0; i < 1000; i++)
    {
        int randVal1 = rand() % (vec.size() - 1);
        int randVal2 = rand() % (vec.size() - 1);
        T value1 = vec[randVal1];
        vec[randVal1] = vec[randVal2];
        vec[randVal2] = value1;
    }
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{

    for (auto item : vec)
    {
        os << item << ", ";
    }
    return os;
}

void testTemplateFunc()
{
    std::cout << "maximum: " << maximum(1, 2) << std::endl;
    std::cout << "maximum: " << maximum(2.4, 2.3) << std::endl;

    std::vector<std::string> vec1{"H1", "H2", "H3", "H4"};
    std::vector<int> vec2{1, 2, 3, 4};
    std::vector<double> vec3{1.2, 2.3, 5.6, 1.4};

    shuffle(vec1);
    shuffle(vec2);
    shuffle(vec3);

    std::cout << vec1 << std::endl;
    std::cout << vec2 << std::endl;
    std::cout << vec3 << std::endl;
}