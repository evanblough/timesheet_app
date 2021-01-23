QT       += core gui androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alarmnotification.cpp \
    chargelist.cpp \
    chargelistitem.cpp \
    main.cpp \
    mainwindow.cpp \
    timesheetcell.cpp \
    timesheetview.cpp

HEADERS += \
    alarmnotification.h \
    chargelist.h \
    chargelistitem.h \
    mainwindow.h \
    timesheetcell.h \
    timesheetview.h

FORMS += \
    alarmnotification.ui \
    chargelist.ui \
    chargelistitem.ui \
    mainwindow.ui \
    timesheetview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml \
    android/src/org/qtproject/example/timesheethelper/MyBroadcastReceiver.java \
    android/src/org/qtproject/example/timesheethelper/NotificationClient.java

contains(ANDROID_TARGET_ARCH,arm64-v8a) {
    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android
}
