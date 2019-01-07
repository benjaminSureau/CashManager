import QtQuick 2.4
import QtQuick.Controls 2.0
import io.qt.examples.cashmanager 1.0


ApplicationWindow {
    id: cashManagerWindow
    CashManagerForm{
    }
    CashManager {
        id: cashManager
    }
}
