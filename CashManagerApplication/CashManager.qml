import QtQuick 2.4
import QtQuick.Controls 2.0
import io.qt.examples.cashmanager 1.0


ApplicationWindow {
    id: cashManagerWindow
    CashManagerForm{
        b_cards.onClicked:{
            b_cards.highlighted = true
            b_especes.highlighted = false
            b_cheques.highlighted = false
        }
        b_cheques.onClicked:{
            b_cards.highlighted = false
            b_especes.highlighted = false
            b_cheques.highlighted = true
        }
        b_especes.onClicked:{
            b_cards.highlighted = false
            b_especes.highlighted = true
            b_cheques.highlighted = false
        }
    }
    CashManager {
        id: cashManager
    }
}
