#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CalculationStrategy.h"
#include <memory>

class MainWindow {
    std::shared_ptr<CalculationStrategy> strategy_;

public:
    MainWindow(std::shared_ptr<CalculationStrategy> strategy) {
        if (strategy) {
            strategy_ = strategy;
        }
        else {
            qDebug() << "Strategy is nullptr!" << Qt::endl;
            return;
        }
    }

    void setStrategy(std::shared_ptr<CalculationStrategy> strategy) {
        if (strategy) {
            strategy_ = strategy;
        }
        else {
            qDebug() << "Strategy is nullptr!" << Qt::endl;
            return;
        }
    }

    void performCalculation(const QString& directory) {
        if (strategy_) {
            strategy_->calculate(directory);
        }
        else {
            qDebug() << "Strategy not set!" << Qt::endl;
        }
    }

};


#endif // MAINWINDOW_H
