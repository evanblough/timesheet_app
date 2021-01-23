#include "qtjavainterface.h"

QtJavaInterface::QtJavaInterface()
{

}

void QtJavaInterface::updateAndroidNotification()
{
    QString *temp =  new QString("Howdy");
    QAndroidJniObject javaNotification = QAndroidJniObject::fromString(*temp);
    QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/timesheethelper/NotificationClient",
                                       "notify",
                                       "(Ljava/lang/String;)V",
                                       javaNotification.object<jstring>());
}
