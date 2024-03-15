#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw ": Enter args";

        std::vector<int> Vec;
        std::deque<int> Deq;

        double vectorSortingTime;
        double dequeSortingTime;
        int number;

        for (int index = 1; index < argc; index++)
        {
            std::stringstream ss(argv[index]);
            if (!(ss >> number) || !(ss.eof()))
                throw "";
            if (number <= 0)
                throw ": Not positive integer number: !";

            Vec.push_back(number);
            Deq.push_back(number);
        }

        std::cout << std::endl;

        print(Vec, Deq);

        caluclateTime(Vec, Deq, vectorSortingTime, dequeSortingTime);

        std::cout << std::endl;

        print(Vec, Deq);

        std::cout << std::endl
                  << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vectorSortingTime << " us" << std::endl;
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque :  " << dequeSortingTime << " us" << std::endl;
    }
    catch (const char *errorMsg)
    {
        std::cout << "Error " << errorMsg << std::endl;
    }
}