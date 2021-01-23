#ifndef QTJAVAINTERFACE_H
#define QTJAVAINTERFACE_H

#include <QObject>
#include <QtAndroidExtras/QAndroidJniObject>

class QtJavaInterface : public QObject
{
    Q_OBJECT
public:
    QtJavaInterface();
public slots:
    void updateAndroidNotification();
};

#endif // QTJAVAINTERFACE_H
