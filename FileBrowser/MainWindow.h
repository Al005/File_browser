#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CalculationStrategy.h"
#include <memory>

class MainWindow {
    std::unique_ptr<CalculationStrategy> strategy_;

public:
    MainWindow(std::unique_ptr<CalculationStrategy> strategy) : strategy_(std::move(strategy)) {}

    void setStrategy(std::unique_ptr<CalculationStrategy> strategy) {
        strategy_ = std::move(strategy);
    }

    void performCalculation(const QString& directory) {
        strategy_->calculate(directory);
    }

};


#endif // MAINWINDOW_H
