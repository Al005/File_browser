#ifndef BYFILETYPE_CALCULATIONSTRATEGY_H
#define BYFILETYPE_CALCULATIONSTRATEGY_H

#include "CalculationStrategy.h"

class ByFileType_CalculationStrategy : public CalculationStrategy {
public:
    void calculate(const QString& directory) override;
private:
    void calculateSizeAndTypes(const QString& directory, qint64& totalSize, QMap<QString, qint64>& types);
};

#endif // BYFILETYPE_CALCULATIONSTRATEGY_H
