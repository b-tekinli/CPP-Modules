#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Usage: ./replace [fileName] [search] [replace]" << std::endl;
        return (1);
    }

    std::string fileName = argv[1];
    std::string search_word = argv[2];
    std::string replace_word = argv[3];
    std::string singleLine;

    size_t position = 0;
    int searchLength = search_word.length();
    int replaceLength = replace_word.length();

    if (fileName.empty() || search_word.empty() || replace_word.empty())
    {
        std::cout << "Arguments cannot be empty!" << std::endl;
        return (1);
    }

    std::ifstream readFile(fileName);
    if (!readFile.is_open())
    {
        std::cout << "File cannot be opened!" << std::endl;
        return (2);
    }

    std::ofstream writeFile((fileName + ".replace"), std::ios::trunc);
    if (!writeFile.is_open())
    {
        std::cout << "File cannot be opened!" << std::endl;
        return (3);
    }

    while (std::getline(readFile, singleLine))
    {
        while ((position = singleLine.find(search_word, position)) != std::string::npos)
        {
            singleLine.erase(position, searchLength);
            singleLine.insert(position, replace_word);
            position += replaceLength;
        }
        writeFile << singleLine << std::endl;
        position = 0;
    }

    return (0);
}
