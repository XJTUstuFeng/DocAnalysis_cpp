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

    std::string inFileAName; // 两个比较文件的文件名
    std::string inFileBName;
    std::map<wchar_t, int> charFreq; // 字符出现次数
    int sameCharNum = 0;             // 相同字符个数
    int totCharNum = 0;              // 总字符个数
    WInFile *dictFile = nullptr;
    WInFile *stopWordsFile = nullptr;
    TrieTree<wchar_t> *dictTrieTree = nullptr;
    TrieTree<wchar_t> *stopWordsTrieTree = nullptr;
    TrieTree<wchar_t>::qtype q;

    void buildTrieTreeFromFile(WInFile *trieTreeWInFile, TrieTree<wchar_t> *myTrieTree);
    bool isWCharValid(wchar_t wc); //判断字符是否为有效字符(英文、汉字或数字)
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
