import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Window 2.0
import io.qt.examples.keypad 1.0

Window {
    id: keypadWindow
    KeypadForm{
        b_enter.onClicked: checkUserSignal(text1.text)
        exit.onClicked: window.close()
    }

    Keypad {
        id: keypad
    }


}
