#include "databasehandler.h"

DataBaseHandler::DataBaseHandler()
{
    _cashmanager = QSqlDatabase::addDatabase("QMYSQL", "cashManagerConnection");
    _cashmanager.setHostName("localhost");
    _cashmanager.setDatabaseName("CashManager");
    _cashmanager.setUserName("root");
    _cashmanager.setPassword("");

    _common_products = QSqlDatabase::addDatabase("QMYSQL", "commonProductsConnection");
    _common_products.setHostName("localhost");
    _common_products.setDatabaseName("common_products");
    _common_products.setUserName("root");
    _common_products.setPassword("");
}

QList<Bill> DataBaseHandler::selectAllBill(){
    QList<Bill> bills;
    if(_cashmanager.isOpen() || _cashmanager.open()){
        QSqlQuery res(_cashmanager);
        res.prepare("SELECT * FROM BILL");
        res.exec();
        while(res.next()){
            Bill *b = new Bill(res.value(0).toInt(), res.value(1).toDateTime(),
                              res.value(2).toString(), selectCashier(res.value(3).toInt()));
            if(b->getCashier() != nullptr)
                bills << *b;
        }
        _cashmanager.close();
    }
    return bills;
}

Bill* DataBaseHandler::selectBill(int id){
    if(_cashmanager.isOpen() || _cashmanager.open()){
        QSqlQuery res(_cashmanager);
        res.prepare("SELECT * FROM BILL WHERE id=:id");
        res.bindValue(":id", id);
        res.exec();
        Bill *b;
        while(res.next()){
            b = new Bill(res.value(0).toInt(), res.value(1).toDateTime(),
                              res.value(2).toString(), selectCashier(res.value(3).toInt()));
        }
        _cashmanager.close();
        return b;
    }
}

QList<Cashier> DataBaseHandler::selectAllCashier(){
    QList<Cashier> cashiers;
    if(_cashmanager.isOpen() || _cashmanager.open()){
        QSqlQuery res(_cashmanager);
        res.prepare("SELECT * FROM CASHIER");
        res.exec();
        while(res.next()){
            Cashier *c = new Cashier(res.value(0).toInt(), res.value(1).toString(), res.value(2).toInt());
            cashiers << *c;
        }
        _cashmanager.close();
    }
    return cashiers;
}

Cashier* DataBaseHandler::selectCashier(int id){
    if(_cashmanager.isOpen() || _cashmanager.open()){
        QSqlQuery res(_cashmanager);
        res.prepare("SELECT * FROM CASHIER WHERE id=:id");
        res.bindValue(":id", id);
        res.exec();
        Cashier *c;
        while(res.next()){
            c = new Cashier(res.value(0).toInt(), res.value(1).toString(), res.value(2).toInt());
        }
        _cashmanager.close();
        return c;
    }
}

QList<Categorie> DataBaseHandler::selectAllCategorie(){
    QList<Categorie> categories;
    if(_common_products.isOpen() || _common_products.open()){
        QSqlQuery res(_common_products);
        res.prepare("SELECT * FROM CATEGORIE");
        res.exec();
        while(res.next()){
            Categorie *c = new Categorie(res.value(0).toInt(), res.value(1).toString(), res.value(2).toFloat());
            categories << *c;
        }
        _common_products.close();
    }
    return categories;
}

Categorie* DataBaseHandler::selectCategorie(int id){
    if(_common_products.isOpen() || _common_products.open()){
        QSqlQuery res(_common_products);
        res.prepare("SELECT * FROM CATEGORIE WHERE id=:id");
        res.bindValue(":id", id);
        res.exec();
        Categorie *c;
        while(res.next()){
            c = new Categorie(res.value(0).toInt(), res.value(1).toString(), res.value(2).toFloat());
        }
        _common_products.close();
        return c;
    }
}

QList<Product> DataBaseHandler::selectAllProduct(){
    QList<Product> products;
    if(_common_products.isOpen() || _common_products.open()){
        QSqlQuery res(_common_products);
        res.prepare("SELECT * FROM PRODUCT");
        res.exec();
        while(res.next()){
            Product *p = new Product(res.value(0).toString(), res.value(1).toString(), res.value(2).toFloat(),
                                     selectCategorie(res.value(3).toInt()));
            if(p->getCategorie() != nullptr)
                products << *p;
        }
        _common_products.close();
    }
    return products;
}

Product* DataBaseHandler::selectProduct(QString code){
    if(_common_products.isOpen() || _common_products.open()){
        QSqlQuery res(_common_products);
        res.prepare("SELECT * FROM PRODUCT WHERE code=:code");
        res.bindValue(":code", code);
        res.exec();
        Product *p;
        while(res.next()){
            p = new Product(res.value(0).toString(), res.value(1).toString(), res.value(2).toFloat(),
                            selectCategorie(res.value(3).toInt()));
        }
        _common_products.close();
        return p;
    }
}

QList<Bill_Product> DataBaseHandler::selectAllBill_Product(){
    QList<Bill_Product> bill_products;
    if(_cashmanager.isOpen() || _cashmanager.open()){
        QSqlQuery res(_cashmanager);
        res.prepare("SELECT * FROM BILL_PRODUCT");
        res.exec();
        while(res.next()){
            Bill_Product *bp = new Bill_Product(selectBill(res.value(0).toInt()), selectProduct(res.value(1).toString()), res.value(2).toInt());
            if(bp->getBill() != nullptr && bp->getProduct() != nullptr)
                bill_products << *bp;
        }
        _cashmanager.close();
    }
    return bill_products;
}

Bill_Product* DataBaseHandler::selectBill_Product(QString codeProd, int idBill){
    if(_cashmanager.isOpen() || _cashmanager.open()){
        QSqlQuery res(_cashmanager);
        res.prepare("SELECT * FROM BILL_PRODUCT WHERE idBill=:id AND codeProd=:code");
        res.bindValue(":id", idBill);
        res.bindValue(":code", codeProd);
        res.exec();
        Bill_Product *bp;
        while(res.next()){
            bp = new Bill_Product(selectBill(res.value(0).toInt()), selectProduct(res.value(1).toString()), res.value(2).toInt());
        }
        _cashmanager.close();
        return bp;
    }
}

QList<Bill_Product> DataBaseHandler::selectBill_ProductByBill(int idBill){
    QList<Bill_Product> bill_products;
    if(_cashmanager.isOpen() || _cashmanager.open()){
        QSqlQuery res(_cashmanager);
        res.prepare("SELECT * FROM BILL_PRODUCT WHERE idBill=:id");
        res.bindValue(":id", idBill);
        res.exec();
        while(res.next()){
            Bill_Product *bp = new Bill_Product(selectBill(res.value(0).toInt()), selectProduct(res.value(1).toString()), res.value(2).toInt());
            if(bp->getBill() != nullptr && bp->getProduct() != nullptr)
                bill_products << *bp;
        }
        _cashmanager.close();
    }
    return bill_products;
}

QList<Bill_Product> DataBaseHandler::selectBill_ProductByProduct(QString codeProd){
    QList<Bill_Product> bill_products;
    if(_cashmanager.isOpen() || _cashmanager.open()){
        QSqlQuery res(_cashmanager);
        res.prepare("SELECT * FROM BILL_PRODUCT WHERE codeProduct=:code");
        res.bindValue(":code", codeProd);
        res.exec();
        while(res.next()){
            Bill_Product *bp = new Bill_Product(selectBill(res.value(0).toInt()), selectProduct(res.value(1).toString()), res.value(2).toInt());
            if(bp->getBill() != nullptr && bp->getProduct() != nullptr)
                bill_products << *bp;
        }
        _cashmanager.close();
    }
    return bill_products;
}

bool DataBaseHandler::insertCashier(QString name, int code){
    if(_cashmanager.isOpen() || _cashmanager.open()){
        QSqlQuery res(_cashmanager);
        res.prepare("INSERT INTO CASHIER (name, code)  VALUES(?,?)");
        res.addBindValue(name);
        res.addBindValue(code);
        res.exec();
        _cashmanager.close();
        return true;
    }
    return false;
}

bool DataBaseHandler::insertBill(QString paymentMode, int cashier){
    if(_cashmanager.isOpen() || _cashmanager.open()){
        QSqlQuery res(_cashmanager);
        res.prepare("INSERT INTO BILL (sellingDate, paymentMode, cashier)  VALUES(?,?,?)");
        res.addBindValue(QDateTime::currentDateTime());
        res.addBindValue(paymentMode);
        res.addBindValue(cashier);
        res.exec();
        _cashmanager.close();
        return true;
    }
    return false;
}

bool DataBaseHandler::insertBill_Product(int bill, QString product, int quantity){
    if(_cashmanager.isOpen() || _cashmanager.open()){
        QSqlQuery res(_cashmanager);
        res.prepare("INSERT INTO Bill_Product (idBill, codeProduct, quantity)  VALUES(?,?,?)");
        res.addBindValue(bill);
        res.addBindValue(product);
        res.addBindValue(quantity);
        res.exec();
        _cashmanager.close();
        return true;
    }
    return false;
}

bool DataBaseHandler::insertCategorie(QString name, float tax){
    if(_common_products.isOpen() || _common_products.open()){
        QSqlQuery res(_common_products);
        res.prepare("INSERT INTO Categorie (name, tax)  VALUES(?,?)");
        res.addBindValue(name);
        res.addBindValue(tax);
        res.exec();
        _common_products.close();
        return true;
    }
    return false;
}

bool DataBaseHandler::insertProduct(QString code, QString name, QString price, int categorie){
    if(_common_products.isOpen() || _common_products.open()){
        QSqlQuery res(_common_products);
        res.prepare("INSERT INTO Product (code, name, price, categorie)  VALUES(?,?,?,?)");
        res.addBindValue(code);
        res.addBindValue(name);
        res.addBindValue(price);
        res.addBindValue(categorie);
        res.exec();
        _common_products.close();
        return true;
    }
    return false;
}
