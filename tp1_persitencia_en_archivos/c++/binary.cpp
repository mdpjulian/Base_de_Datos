#include <iostream>
#include <fstream>

struct Score
{
    std::string name;
    int score;
    std::string time;
};
void saveScore(std::string fileName, Score scoreList[]);
void readScore(std::string fileName);
int main()
{
    Score scoreList[2] = {{"Pepe", 108, "4:16"}, {"Juana", 2315, "8:42"}};
    saveScore("binary.bin", scoreList);
    readScore("binary.bin");
}
void saveScore(std::string fileName, Score scoreList[])
{
    std::ofstream writeFile;
    writeFile.open(fileName, std::ios::binary);
    for (int i = 0; i < 2; i++)
    {
        writeFile << scoreList[i].name << "," << scoreList[i].score << "," << scoreList[i].time << std::endl;
    }
}
void readScore(std::string fileName)
{
    std::ifstream readFile;
    char c;
    int commaCounter = 0;
    readFile.open(fileName, std::ios::binary);
    while (readFile.get(c))
    {
        std::cout.put(c);
    }
}
