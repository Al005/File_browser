#include "ByFolder_CalculationStrategy.h"

void ByFolder_CalculationStrategy::calculate(const QString& directory) {
    QDir dir(directory);
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    qint64 totalSize = 0;
    for (const QFileInfo &fileInfo : list) {
        qint64 size = 0;
        if (fileInfo.isDir()) {
            size += calculateSize(fileInfo.absoluteFilePath());
        }
        else {
            size += fileInfo.size();
        }
        totalSize += size;
    }
    qDebug() << "Directory size: " << totalSize << " bytes" << Qt::endl;
    for (const QFileInfo &fileInfo : list) {
        qint64 size = 0;
        if (fileInfo.isDir()) {
            size += calculateSize(fileInfo.absoluteFilePath());
        }
        else {
            size += fileInfo.size();
        }
        double percent = (double)size / totalSize * 100;
        if (size != 0 && percent < 0.01) {
            qDebug() << fileInfo.fileName() << ":" << size << "bytes (< 0.01%)" << Qt::endl;
        } else {
            qDebug() << fileInfo.fileName() << ":" << size << "bytes (" << QString::number(percent, 'f', 2) << "%)" << Qt::endl;
        }
    }
    qDebug() << Qt::endl;
}

qint64 ByFolder_CalculationStrategy::calculateSize(const QString& directory) {
    QDir dir(directory);
    qint64 size = 0;
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QFileInfo &fileInfo : list) {
        if (fileInfo.isDir()) {
            size += calculateSize(fileInfo.absoluteFilePath());
        } else {
            size += fileInfo.size();
        }
    }
    return size;
}
