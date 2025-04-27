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

    string inputVecFilePath = "D:\\cc.ko.300.vec"; // fastText 한국어 벡터 파일 경로
    string outputWordFilePath = "D:\\korean_words.txt"; // 저장할 단어 파일 경로

    ifstream inputFile(inputVecFilePath);
    ofstream outputFile(outputWordFilePath);

    if (!inputFile.is_open())
    {
        cout << "입력 파일을 열 수 없습니다.\n";
        return 1;
    }

    if (!outputFile.is_open())
    {
        cout << "출력 파일을 열 수 없습니다.\n";
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
            continue; // 첫 번째 줄은 단어 수와 벡터 차원 수 -> 무시
        }

        size_t firstSpacePos = line.find(' ');
        if (firstSpacePos == string::npos)
        {
            continue; // 잘못된 라인 -> 무시
        }

        string word = line.substr(0, firstSpacePos);

        if (!word.empty())
        {
            wordSet.insert(word);
            cout << cnt << '\n';
            cnt++;
            if (cnt >= 1000)
				break; // 10만 개 단어만 추출
        }
    }

    for (const auto& word : wordSet)
    {
        outputFile << word << '\n';
    }

    cout << "총 " << wordSet.size() << "개의 단어를 추출하여 저장했습니다.\n";

    inputFile.close();
    outputFile.close();

    return 0;
}