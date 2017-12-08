#include <iostream>

bool queen(std::pair<char, int> black, std::pair<char, int> whitemove)
{
    if ((whitemove.first == black.first) || (whitemove.second == black.second) ||
        (std::abs(whitemove.first - black.first) == std::abs(whitemove.second - black.second)))
        return true;
    else
        return false;
}
bool elephant(std::pair<char, int> black, std::pair<char, int> whitemove)
{
    if (std::abs(whitemove.first - black.first) == std::abs(whitemove.second - black.second))
        return true;
    else
        return false;
}
bool rook(std::pair<char, int> black, std::pair<char, int> whitemove)
{
    if ((whitemove.first == black.first) || (whitemove.second == black.second))
        return true;
    else
        return false;
}
bool paw(std::pair<char, int> black, std::pair<char, int> whitemove)
{
    if ((whitemove.first == black.first) &&
        ((whitemove.second == black.second) || (whitemove.second == black.second - 1)))
        return false;
    else if (((whitemove.first + 1 == black.first) && (whitemove.second - 1 == black.second)) ||
             ((whitemove.first - 1 == black.first) && (whitemove.second + 1 == black.second)))
        return true;
    else if ((whitemove.first == 2) && ((whitemove.first == black.first) &&
                                        (whitemove.second + 2 == black.second)) ||
             (whitemove.first == black.first) && (whitemove.second + 1 == black.second))
        return true;
    else
        return false;
}
bool horse(std::pair<char, int> black, std::pair<char, int> whitemove)
{
    if (((whitemove.first == black.first + 2) ||
         (whitemove.first == black.first - 2) &&
         (whitemove.second == black.second + 1) ||
         (whitemove.second == black.second - 1)) ||
        ((whitemove.first == black.first + 1) ||
         (whitemove.first == black.first - 1) &&
         (whitemove.second == black.second + 2) ||
         (whitemove.second == black.second - 2)))
        return true;
    else
        return false;
}
int main()
{

    std::pair<char, int> black;
    black.first = 'g';
    black.second = 3;
    std::cout << "What chess piece?" << std::endl;
    char namefigure;
    std::cin >> namefigure;
    std::cout << "initial coordinate" << std::endl;
    std::pair<char, int> whitemove;
    std::cin >> whitemove.first >> whitemove.second;
    //////////////check correct coordinate
    if ((whitemove.first > 'h') || (whitemove.second > 8))
    {
        bool flag;
        do
        {
            std::cout << "initial coordinate" << std::endl;
            std::cin >> whitemove.first >> whitemove.second;
            if (whitemove.first <= 'h' && whitemove.second <= 8)
                flag = true;
            else
                flag = false;
        } while (!flag);
    }
    switch (namefigure)
    {
        case 'Q':
            if (queen(black,whitemove))
                std::cout << "Queen true" << std::endl;
            else
                std::cout << "Queen false!" << std::endl;
            break;
        case 'B':
            if (elephant(black,whitemove))
                std::cout << "Elephant true" << std::endl;
            else
                std::cout << "Elephant false" << std::endl;
            break;
        case 'R':
            if (rook(black,whitemove))
                std::cout << "Rook true" << std::endl;
            else
                std::cout << "Rook false!" << std::endl;
            break;
        case 'p':
            if (paw(black,whitemove))
                std::cout << "Paw true " << std::endl;
            else
                std::cout << "Paw false!" << std::endl;
            break;
        case 'N':
            if (horse(black,whitemove))
                std::cout << "Horse true";
            else
                std::cout << "Horse false!";
            break;
    }
    return 0;
}
