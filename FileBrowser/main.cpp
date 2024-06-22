#include "CalculationStrategy.h"
#include "ByFileType_CalculationStrategy.h"
#include "ByFolder_CalculationStrategy.h"

int main() {
    QString directory = "D:/Projects/TRPO_labs/lab4/File_browser/FileBrowser/testFolder";

    CalculationStrategy* strategy = new ByFolder_CalculationStrategy();
    strategy->calculate(directory);
    delete strategy;
    strategy = new ByFileType_CalculationStrategy();
    strategy->calculate(directory);
    delete strategy;
    return 0;
}
