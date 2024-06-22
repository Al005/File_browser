#include "CalculationStrategy.h"
#include "ByFileType_CalculationStrategy.h"

int main(int argc, char *argv[]) {
    CalculationStrategy* strategy = new ByFileType_CalculationStrategy();
    strategy->calculate("D:/Projects/TRPO_labs/lab4/File_browser/FileBrowser/testFolder");
    delete strategy;
    return 0;
}
