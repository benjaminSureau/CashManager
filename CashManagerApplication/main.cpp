#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include <QDebug>
#include <QString>
#include "keypad.h"
#include "cashmanager.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Keypad>("io.qt.examples.keypad", 1, 0, "Keypad");
    qmlRegisterType<CashManager>("io.qt.examples.cashmanager", 1, 0, "CashManager");

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
    QObject *object = view.rootObject();
    QObject *b_enter = object->findChild<QQuickItem*>(QString("Enter"), Qt::FindChildrenRecursively);
    QObject *b_createBill = object->findChild<QQuickItem*>(QString("createBill"), Qt::FindChildrenRecursively);

    Keypad myClass;
    CashManager myCashManager;

    QObject::connect(b_enter, SIGNAL(addProductSignal(QString)),
                         &myCashManager, SLOT(addProduct(QString)));
    QObject::connect(b_createBill, SIGNAL(createBillSignal(QString)),
                         &myCashManager, SLOT(createBill(QString)));
    return app.exec();
}
