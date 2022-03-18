#include "DocAnalysis.cpp"
#include "WInFile.cpp"
#include "WOutFile.cpp"

int main()
{

    const char *inFileAName = "1";
    const char *inFileBName = "2";

    // const char *inFileAName = "�ʱ���";
    // const char *inFileBName = "����������";

    DocAnalysis *myDocAnalysis = new DocAnalysis(inFileAName, inFileBName);
    myDocAnalysis->run();
    delete myDocAnalysis;

    return 0;
}
