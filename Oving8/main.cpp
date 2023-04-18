
//------------------------------------------------------------------------------'
#include "fibonacci.h"
#include "Matrix.h"
#include "Dummy.h"
#include <iostream>

int main()
{
    // cout << "Hello, World!" << endl;
    int input;
    std::cout << "Write a number (0-5): " << std::endl;
    std::cin >> input;
    Matrix M{4};
    Matrix M2{4, 7};

    Matrix M3{2, 4};
    Matrix M4{2, 7};

    Matrix A{2};
    A.set(0, 0, 1.0);
    A.set(0, 1, 2.0);
    A.set(1, 0, 3.0);
    A.set(1, 1, 4.0);

    Matrix B{2};
    B.set(0, 0, 4.0);
    B.set(0, 1, 3.0);
    B.set(1, 0, 2.0);
    B.set(1, 1, 1.0);

    Matrix C{2};
    C.set(0, 0, 1.0);
    C.set(0, 1, 3.0);
    C.set(1, 0, 1.5);
    C.set(1, 1, 2.0);

    switch (input)
    {
    case 0:
        createFibonacci();
        break;
    case 1:
        M.set(2, 3, 5);
        std::cout << M.get(2, 3) << std::endl;
        std::cout << M[1][0] << std::endl;
        std::cout << M[0][0] << std::endl;
        std::cout << M;

        M2.set(2, 3, 5);
        std::cout << M2.get(2, 3) << std::endl;
        std::cout << M2[1][0] << std::endl;
        std::cout << M2[0][0] << std::endl;
        std::cout << M2;

        break;
    case 2:
        dummyTest();
        break;
    case 3:
        std::cout << M3 << std::endl;
        std::cout << M4 << std::endl;

        M4 = M3;

        std::cout << M3 << std::endl;
        std::cout << M4 << std::endl;
        break;

    case 4:
        std::cout << A << std::endl;
        std::cout << B << std::endl;
        std::cout << C << std::endl;

        A += B + C;

        std::cout << A << std::endl;
        std::cout << B << std::endl;
        std::cout << C << std::endl;
        break;
    case 5:

        A -= B - C;
        std::cout << A << std::endl;
        std::cout << B << std::endl;
        std::cout << C << std::endl;

        A *= B * C;
        std::cout << A << std::endl;
        std::cout << B << std::endl;
        std::cout << C << std::endl;
        break;
    default:

        break;
    }

    return 0;
}

//------------------------------------------------------------------------------
