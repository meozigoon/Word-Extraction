#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string inputVecFilePath = "D:\\cc.ko.300.vec"; // fastText �ѱ��� ���� ���� ���
    string outputWordFilePath = "D:\\korean_words.txt"; // ������ �ܾ� ���� ���

    ifstream inputFile(inputVecFilePath);
    ofstream outputFile(outputWordFilePath);

    if (!inputFile.is_open())
    {
        cout << "�Է� ������ �� �� �����ϴ�.\n";
        return 1;
    }

    if (!outputFile.is_open())
    {
        cout << "��� ������ �� �� �����ϴ�.\n";
        return 1;
    }

    unordered_set<string> wordSet;
    string line;
    bool isFirstLine = true;

    long long cnt = 0;
    while (getline(inputFile, line))
    {
        if (isFirstLine)
        {
            isFirstLine = false;
            continue; // ù ��° ���� �ܾ� ���� ���� ���� �� -> ����
        }

        size_t firstSpacePos = line.find(' ');
        if (firstSpacePos == string::npos)
        {
            continue; // �߸��� ���� -> ����
        }

        string word = line.substr(0, firstSpacePos);

        if (!word.empty())
        {
            wordSet.insert(word);
            cout << cnt << '\n';
            cnt++;
            if (cnt >= 1000)
				break; // 10�� �� �ܾ ����
        }
    }

    for (const auto& word : wordSet)
    {
        outputFile << word << '\n';
    }

    cout << "�� " << wordSet.size() << "���� �ܾ �����Ͽ� �����߽��ϴ�.\n";

    inputFile.close();
    outputFile.close();

    return 0;
}