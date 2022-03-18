#pragma once
#include <string>
#include "TrieTree.hpp"

class WInFile;
class WOutFile;

class DocAnalysis
{
private:
    static const char *DICT_DIR;
    static const char *DOC_EXTENSION;

    std::string inFileAName; // �����Ƚ��ļ����ļ���
    std::string inFileBName;
    std::map<wchar_t, int> charFreq; // �ַ����ִ���
    int sameCharNum = 0;             // ��ͬ�ַ�����
    int totCharNum = 0;              // ���ַ�����
    WInFile *dictFile = nullptr;
    WInFile *stopWordsFile = nullptr;
    TrieTree<wchar_t> *dictTrieTree = nullptr;
    TrieTree<wchar_t> *stopWordsTrieTree = nullptr;
    TrieTree<wchar_t>::qtype q;

    void buildTrieTreeFromFile(WInFile *trieTreeWInFile, TrieTree<wchar_t> *myTrieTree);
    bool isWCharValid(wchar_t wc); //�ж��ַ��Ƿ�Ϊ��Ч�ַ�(Ӣ�ġ����ֻ�����)
    void getCharFreq(std::wstring &myDoc);
    void getWordFreq(std::wstring &myDoc);
    void printResult(WOutFile *outFile);
    void analyzeFile(std::string &fileName);

public:
    DocAnalysis(const char *inFileAName_, const char *inFileBName_);
    DocAnalysis(std::string &inFileAName_, std::string &inFileBName_);
    ~DocAnalysis();
    void run();
};
