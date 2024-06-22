#include "ByFileType_CalculationStrategy.h"


void ByFileType_CalculationStrategy::calculate(const QString& directory){
    QMap<QString, qint64> types;  // Создаем контейнер, который будет хранить в себе ключ-тип и значение-размер
    qint64 totalSize = 0;
    calculateSizeAndTypes(directory, totalSize, types);  // Находим общий размер папки
    qDebug() << "Directory size: " << totalSize << " bytes" << Qt::endl;
    for (auto it = types.begin(); it != types.end(); ++it) { // Пробегаемся по всем элементам (типам файлов) контейнера
        double percent = (double)it.value() / totalSize * 100;
        if (it.value() != 0 && percent < 0.01) {
            qDebug() << it.key() << ":" << it.value() << " bytes (< 0.01%)" << Qt::endl;
        } else {
            qDebug() << it.key() << ":" << it.value() << "bytes (" << QString::number(percent, 'f', 2) << "%)"<< Qt::endl;
        }
    }
}

void ByFileType_CalculationStrategy::calculateSizeAndTypes(const QString& directory, qint64& totalSize, QMap<QString, qint64>& types) {
    QDir dir(directory);
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);  // В список включены: файлы, папки(директории),
    for (const QFileInfo &fileInfo : list) {                                                   // и ислючены: текушая дирректори и родительская
        if (fileInfo.isDir()) {
            calculateSizeAndTypes(fileInfo.absoluteFilePath(), totalSize, types);
        } else {
            types[fileInfo.suffix()] += fileInfo.size();
            totalSize += fileInfo.size();
        }
    }
}
