#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>

using namespace std;

bool IsDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

string RemoveDigits(const string& word)
{
    string result;
    for (char ch : word)
    {
        if (!IsDigit(ch))
        {
            result += ch;
        }
        else
        {
            break;
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream inputFile("D:\\study.txt");
    if (!inputFile.is_open())
    {
        cerr << "입력 파일을 열 수 없습니다.\n";
        return 1;
    }

    ofstream outputFile("D:\\wordList.txt");
    if (!outputFile.is_open())
    {
        cerr << "출력 파일을 열 수 없습니다.\n";
        return 1;
    }

    set<string> words;
    string line;

    while (getline(inputFile, line))
    {
        if (line.empty())
        {
            continue;
        }

        stringstream ss(line);
        string columns[5];
        int i = 0;
        while (getline(ss, columns[i], '\t') && i < 5)
        {
            i++;
        }

        if (i < 2)
        {
            continue;
        }

        string word = RemoveDigits(columns[1]);
        if (!word.empty())
        {
            words.insert(word);
        }
    }

    for (const string& word : words)
    {
        outputFile << word << '\n';
    }

	cout << "finished\n";

    inputFile.close();
    outputFile.close();

    return 0;
}
