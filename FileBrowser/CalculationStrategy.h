#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H

#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include <QString>
#include <QMap>
#include <QDebug>


class CalculationStrategy {
public:
    virtual ~CalculationStrategy() = default;
    virtual void calculate(const QString& directory) = 0;
};

#endif // CALCULATIONSTRATEGY_H
