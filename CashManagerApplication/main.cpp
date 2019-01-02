#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include <QDebug>
#include <QString>
#include "keypad.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Keypad>("io.qt.examples.keypad", 1, 0, "Keypad");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QQmlApplicationEngine view(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *rootItem = view.rootObjects().first();
    QObjectList list = rootItem->children();
    QObject *rectangle = rootItem->findChild<QObject*>(QString("b_enter"), Qt::FindChildrenRecursively);
    //QObject *buttonEnter = rectangle->findChild<QObject*>("b_enter");

    qDebug()<< "test";
    qDebug()<<rootItem->objectName();
    qDebug()<< "end";
    Keypad myClass;
    QObject::connect(rootItem, SIGNAL(checkUserSignal(QString)),
                     &myClass, SLOT(checkUser(QString)));



    return app.exec();
}
