#include "datasource.h"
#include <chrono>
#include <random>
#include <iostream>
#include <QTextStream>

DataSource::DataSource(QObject *parent) :
    QObject(parent)
{
    // Per documentation:
    //  To use QSurface3DSeries pointers as parameters for class methods on all
    //  environments and builds, make sure the meta type is registered
    qRegisterMetaType<QSurface3DSeries *>();

    auto now = std::chrono::system_clock::now().time_since_epoch();
    m_now = std::chrono::duration<double>(now).count();

}

DataSource::~DataSource()
{
}

void DataSource::update(QSurface3DSeries *series)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(5.0, 2.0);
    int p[10] {};

    for (int i = 0; i < 1000; ++i) {
        double number = distribution(generator);
        if ((number >= 0.0) && (number < 10.0))
            ++p[int(number)];
    }

    QTextStream out(stdout);
    auto now = std::chrono::system_clock::now().time_since_epoch();
    auto time_ = std::chrono::duration<double>(now).count();
    for (int j = 0; j < 3; ++j) {
        QSurfaceDataRow *row = new QSurfaceDataRow(10);
        for (int i = 0; i < 10; ++i) {
            out << "x: " << time_ - m_now << ", z: " << double(i) << ", y: " << p[i] / 10. << '\n';
            (*row)[i] = QVector3D(time_ - m_now, p[i] / 10., double(i));
        }
        auto index = series->dataProxy()->addRow(row);
        out << "row added, index: " << index << '\n';
    }
}
