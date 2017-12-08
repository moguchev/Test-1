#include <iostream>

int main()
{
    bool flag;
    std::pair<char, int> black;
    black.first = 'g';
    black.second = 3;
    std::cout << "What chess piece?" << std::endl;
    char namefigure = 0;
    std::cin >> namefigure;
    std::cout << "initial coordinate" << std::endl;
    std::pair<char, int> whitemove;
    std::cin >> whitemove.first >> whitemove.second;
    //////////////check correct coordinate
    if ((whitemove.first > 'h') || (whitemove.second > 8))
    {
        while (flag == false)
        {
            std::cout << "initial coordinate" << std::endl;
            std::cin >> whitemove.first >> whitemove.second;
            if ((whitemove.first <= 'h') && (whitemove.second <= 8))
                flag = true;
            else
                flag = false;
        }
    }
    switch (namefigure)
    {
        case 'Q':
            if ((whitemove.first == black.first) || (whitemove.second == black.second) ||
                (std::abs(whitemove.first - black.first) == std::abs(whitemove.second - black.second)))
                std::cout << "Queen true" << std::endl;
            else
                std::cout << "Queen false!" << std::endl;
            break;
        case 'B':
            if (std::abs(whitemove.first - black.first) == std::abs(whitemove.second - black.second))
                std::cout << "Elephant true" << std::endl;
            else
                std::cout << "Elephant false" << std::endl;
            break;
        case 'R':
            if ((whitemove.first == black.first) || (whitemove.second == black.second))
                std::cout << "Rook true" << std::endl;
            else
                std::cout << "Rook false!" << std::endl;
            break;
        case 'p':
            if ((whitemove.first == black.first) &&
                ((whitemove.second == black.second) || (whitemove.second == black.second - 1)))
                std::cout << "Paw false!" << std::endl;
            else if (((whitemove.first + 1 == black.first) && (whitemove.second - 1 == black.second)) ||
                       ((whitemove.first - 1 == black.first) && (whitemove.second + 1 == black.second)))
                std::cout << "Paw true" << std::endl;
            else if ((whitemove.first == 2) && ((whitemove.first == black.first) &&
                                                  (whitemove.second + 2 == black.second)) ||
                       (whitemove.first == black.first) && (whitemove.second + 1 == black.second))
                std::cout << "Paw true " << std::endl;
            else
                std::cout << "Paw false!" << std::endl;
            break;
        case 'N':
            if (((whitemove.first == black.first + 2) ||
                 (whitemove.first == black.first - 2) &&
                 (whitemove.second == black.second + 1) ||
                 (whitemove.second == black.second - 1)) ||
                ((whitemove.first == black.first + 1) ||
                 (whitemove.first == black.first - 1) &&
                 (whitemove.second == black.second + 2) ||
                 (whitemove.second == black.second - 2)))
                std::cout << "Horse true";
            else
                std::cout << "Horse false!";
            break;
    }
    return 0;
}
