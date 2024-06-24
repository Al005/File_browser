#include "ByFileType_CalculationStrategy.h"
#include "ByFolder_CalculationStrategy.h"
#include "MainWindow.h"


int main() {
    QString directory = "D:/Projects/TRPO_labs/lab4/File_browser/FileBrowser/testFolder";

    qDebug() << "ByFolder: ";
    MainWindow context(nullptr);
    context.performCalculation(directory);

    qDebug() << "ByFolder: ";
    context.setStrategy(std::make_shared<ByFolder_CalculationStrategy>());
    context.performCalculation(directory);

    qDebug() << "ByFileType: ";
    context.setStrategy(std::make_shared<ByFileType_CalculationStrategy>());
    context.performCalculation(directory);

    return 0;
}
