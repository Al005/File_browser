#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CalculationStrategy.h"
#include <memory>

class MainWindow {
    std::unique_ptr<CalculationStrategy> strategy_;

public:
    MainWindow(std::unique_ptr<CalculationStrategy> strategy) {
        if (strategy) {
            strategy_ = std::move(strategy);
        }
        else {
            qDebug() << "Strategy is nullptr!" << Qt::endl;
            return;
        }
    }

    void setStrategy(std::unique_ptr<CalculationStrategy> strategy) {
        if (strategy) {
            strategy_ = std::move(strategy);
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
