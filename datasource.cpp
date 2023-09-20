#include "datasource.h"
#include <chrono>
#include <random>

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

    auto now = std::chrono::system_clock::now().time_since_epoch();
    auto time_ = std::chrono::duration<double>(now).count();
    QSurfaceDataRow row(10);
    for (int i = 0; i < 10; ++i) {
        row[i] = QVector3D(time_ - m_now, double(i), p[i] / 10.);
    }
    series->dataProxy()->addRow(&row);
}
