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
    saveScore("score.txt", scoreList);
    readScore("score.txt");
}
void saveScore(std::string fileName, Score scoreList[])
{
    std::ofstream writeFile;
    writeFile.open(fileName);
    for (int i = 0; i < 2; i++)
    {
        writeFile << scoreList[i].name << "," << scoreList[i].score << "," << scoreList[i].time << std::endl;
    }
}
void readScore(std::string fileName)
{
    std::ifstream readFile;
    std::string s;
    int commaCounter = 0;
    readFile.open(fileName, std::ios::app);
    while (getline(readFile, s))
    {
        std::cout << "[(";
        for (int j = 0; j < s.size(); j++)
        {
            if (s.at(j) == ',')
                commaCounter++;

            if (commaCounter % 2 == 0)
            {
                std::cout << s.at(j);
            }
            else if (s.at(j) == ',')
            {
                std::cout << s.at(j);
            }
            else
            {
                char x = s.at(j);
                int a = x - 48;
                std::cout << a;
            }
        }
        std::cout << ")], ";
    }
}