import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Window 2.0

Item {
    width: 505
    height: 590
    property alias b_enter: b_enter
    property alias exit: exit

    Rectangle {
        id: rectangle1
        objectName: qsTr("rectangle")
        color: "#ffffff"
        radius: 17
        width: 505
        height: 590
        border.width: 2

        Rectangle {
            id: rectangle
            x: 38
            y: 128
            width: 422
            height: 78
            color: "#ffffff"
            radius: 17
            border.width: 2
            clip: false
            rotation: 0
            z: 0
            border.color: "#000000"

            Text {
                id: text1
                x: 8
                y: 0
                width: 406
                height: 78
                text: keypad.textField
                z: 1
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 24
                signal checkUser(var anObject)
            }
        }

        Button {
            id: b_enter
            objectName: qsTr("button")
            x: 310
            y: 216
            width: 150
            height: 361
            text: qsTr("ENTER")
            font.pointSize: 24
            signal checkUserSignal(string code)

        }

        Grid {
            id: grid
            x: 38
            y: 126
            width: 272
            height: 361
            anchors.bottomMargin: 13
            spacing: 13
            flow: Grid.LeftToRight
            anchors.bottom: parent.bottom
            rows: 4
            columns: 3

            Button {
                id: b_1
                width: 80
                height: 80
                text: qsTr("1")
                onClicked: keypad.textField = text
                font.pointSize: 24
            }

            Button {
                id: b_2
                width: 80
                height: 80
                text: qsTr("2")
                font.pointSize: 24
                onClicked: keypad.textField = text
            }

            Button {
                id: b_3
                width: 80
                height: 80
                text: qsTr("3")
                font.pointSize: 24
                onClicked: keypad.textField = text
            }

            Button {
                id: b_4
                width: 80
                height: 80
                text: qsTr("4")
                font.pointSize: 24
                onClicked: keypad.textField = text
            }

            Button {
                id: b_5
                width: 80
                height: 80
                text: qsTr("5")
                font.pointSize: 24
                onClicked: keypad.textField = text
            }

            Button {
                id: b_6
                width: 80
                height: 80
                text: qsTr("6")
                font.pointSize: 24
                onClicked: keypad.textField = text
            }

            Button {
                id: b_7
                width: 80
                height: 80
                text: qsTr("7")
                font.pointSize: 24
                onClicked: keypad.textField = text
            }

            Button {
                id: b_8
                width: 80
                height: 80
                text: qsTr("8")
                font.pointSize: 24
                onClicked: keypad.textField = text
            }

            Button {
                id: b_9
                width: 80
                height: 80
                text: qsTr("9")
                font.pointSize: 24
                onClicked: keypad.textField = text
            }

            Button {
                id: b_ca
                width: 80
                height: 80
                text: qsTr("CA")
                checked: false
                autoExclusive: false
                font.pointSize: 24
                checkable: false
                onClicked: keypad.textField = text
            }

            Button {
                id: b_0
                width: 80
                height: 80
                text: qsTr("0")
                checked: false
                autoExclusive: false
                checkable: false
                font.pointSize: 24
                onClicked: keypad.textField = text
            }

            Button {
                id: b_10
                width: 80
                height: 80
                text: qsTr("C")
                checked: false
                autoExclusive: false
                checkable: false
                font.pointSize: 24
                onClicked: keypad.textField = text
            }
        }

        Rectangle {
            id: exitRectangle
            x: 465
            y: 8
            color: "red"
            radius: 8
            border.width: 1
            width: 27
            height: 21
            z: 1

            MouseArea {
                id: exit
                anchors.fill: parent
            }
        }

        Rectangle {
            id: rectangle2
            x: 173
            y: 44
            width: 287
            height: 78
            color: "#ffffff"
            radius: 17
            Text {
                id: text2
                text: "#keypad.textField#"
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                z: 1
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 24
            }
            rotation: 0
            clip: false
            border.color: "#000000"
            border.width: 2
            z: 0
        }

        Text {
            id: element
            x: 72
            y: 67
            width: 61
            height: 33
            text: qsTr("Total :")
            font.pixelSize: 24
        }

    }
}
