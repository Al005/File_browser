#include "ByFileType_CalculationStrategy.h"
#include "ByFolder_CalculationStrategy.h"
#include "MainWindow.h"


int main() {
    QString directory = "D:/Projects/TRPO_labs/lab4/File_browser/FileBrowser/testFolder";

    qDebug() << "ByFolder: ";
    MainWindow context(std::make_unique<ByFolder_CalculationStrategy>());
    context.executeStrategy(directory);

    qDebug() << "ByFileType: ";
    context.setStrategy(std::make_unique<ByFileType_CalculationStrategy>());
    context.executeStrategy(directory);

    return 0;
}
