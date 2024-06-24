#ifndef BYFOLDER_CALCULATIONSTRATEGY_H
#define BYFOLDER_CALCULATIONSTRATEGY_H

#include "CalculationStrategy.h"

class ByFolder_CalculationStrategy : public CalculationStrategy {
public:
    void calculate(const QString& directory) override;
private:
    qint64 calculateSize(const QString& directory);
};


#endif // BYFOLDER_CALCULATIONSTRATEGY_H
