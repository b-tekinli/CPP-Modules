#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "Usage: ./replace [fileName] [search] [replace]" << endl;
        return (1);
    }

    string fileName = argv[1];
    string search_word = argv[2];
    string replace_word = argv[3];
    string singleLine;

    size_t position = 0;
    int searchLength = search_word.length();
    int replaceLength = replace_word.length();

    if (fileName.empty() || search_word.empty() || replace_word.empty())
    {
        cout << "Arguments cannot be empty!" << endl;
        return (1);
    }

    ifstream readFile(fileName);
    if (!readFile.is_open())
    {
        std::cout << "File cannot be opened!" << endl;
        return (2);
    }

    ofstream writeFile((fileName + ".replace"), ios::trunc);
    if (!writeFile.is_open())
    {
        cout << "File cannot be opened!" << endl;
        return (3);
    }

    while (getline(readFile, singleLine))
    {
        while ((position = singleLine.find(search_word, position)) != string::npos)
        {
            singleLine.erase(position, searchLength);
            singleLine.insert(position, replace_word);
            position += replaceLength;
        }
        writeFile << singleLine << endl;
        position = 0;
    }

    return (0);
}
