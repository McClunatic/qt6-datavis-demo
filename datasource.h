#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QtCore/qobject.h>
#include <QtDataVisualization/qsurface3dseries.h>
#include <QtQml/qqmlregistration.h>

class DataSource : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit DataSource(QObject *parent = nullptr);
    virtual ~DataSource();

    Q_INVOKABLE void update(QSurface3DSeries *series);
private:
    double m_now;
};

#endif // DATASOURCE_H
