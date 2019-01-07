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

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    QObject *rootItem = engine.rootObjects().first();
//    QObject *button = rootItem->findChild<QQuickItem*>(QString("button"), Qt::FindChildrenRecursively);
//    //QObject *buttonEnter = rectangle->findChild<QObject*>("b_enter");

//    qDebug()<< "test";
//    qDebug()<<rootItem->objectName();
//    qDebug()<<rootItem->children();
//    qDebug()<<button->objectName();
//    qDebug()<< "end";
//    Keypad myClass;
//    QObject::connect(button, SIGNAL(checkUserSignal(QString)),
//                     &myClass, SLOT(checkUser(QString)));

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/board.qml")));

//    QQmlEngine engine;
//    QQmlComponent component(&engine,
//            QUrl(QStringLiteral("qrc:/board.qml")));
//    QObject *object = component.create();

    QQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view.show();


    return app.exec();
}
