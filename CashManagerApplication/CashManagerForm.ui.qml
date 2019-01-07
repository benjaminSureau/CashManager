import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    width: 888
    height: 905
    property alias b_cards: b_cards
    property alias b_cheques: b_cheques
    property alias b_especes: b_especes
    property alias b_createBill: b_createBill
    Rectangle {
        id: rectangle
        color: "#ffffff"
        border.width: 2
        anchors.fill: parent

        Rectangle {
            id: titleRectangle
            x: 0
            y: 0
            width: 606
            height: 100
            color: "#ffffff"
            border.width: 2

            Text {
                id: element2
                x: 214
                y: 38
                text: qsTr("Cash Manager")
                font.pixelSize: 30
            }

            Rectangle {
                id: rectangle3
                x: 0
                y: 98
                width: 381
                height: 599
                color: "#ffffff"
                border.width: 2

                Rectangle {
                    id: rectangle6
                    x: 0
                    y: 545
                    width: 381
                    height: 54
                    color: "#ffffff"
                    border.width: 2

                    Text {
                        id: element5
                        x: 34
                        y: 16
                        text: qsTr("Total")
                        font.pixelSize: 18
                    }

                    Text {
                        id: element6
                        x: 155
                        y: 18
                        width: 226
                        height: 19
                        text: qsTr("0")
                        font.pixelSize: 16
                    }
                }

                Text {
                    id: text1
                    x: 8
                    y: 15
                    width: 284
                    height: 519
                    text: cashManager.text1
                    font.pixelSize: 20
                }

                Text {
                    id: text2
                    x: 309
                    y: 15
                    width: 64
                    height: 519
                    text: cashManager.text2
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignRight
                }
            }
        }

        Rectangle {
            id: rectangle2
            x: 389
            y: 98
            width: 499
            height: 198
            color: "#ffffff"
            border.width: 2

            Button {
                id: b_cards
                x: 26
                y: 85
                width: 100
                height: 100
                text: qsTr("Cards")
                checkable: false
                highlighted: false
                flat: false
                font.pointSize: 20
            }

            Button {
                id: b_cheques
                x: 156
                y: 85
                width: 143
                height: 100
                text: qsTr("Cheques")
                font.pointSize: 20
            }

            Button {
                id: b_especes
                x: 333
                y: 85
                width: 141
                height: 100
                text: qsTr("Especes")
                highlighted: false
                font.pointSize: 20
            }

            Text {
                id: element3
                x: 26
                y: 35
                text: qsTr("Timeout :")
                font.pixelSize: 14
            }

            ComboBox {
                id: cb_timeout
                x: 101
                y: 24
                width: 113
                height: 40
                font.pointSize: 14
                model: ["10", "20", "30", "40", "50", "60", "70", "80", "90", "100", "110", "120", "130", "140", "150", "160", "170", "180"]
            }

            Text {
                id: element4
                x: 305
                y: 35
                text: qsTr("Max co :")
                font.pixelSize: 14
            }

            ComboBox {
                id: cb_maxco
                x: 388
                y: 24
                width: 80
                height: 40
                font.pointSize: 14
                model: ["1", "2", "3"]
            }
        }

        Rectangle {
            id: rectangle4
            x: 0
            y: 765
            width: 383
            height: 86
            color: "#ffffff"
            radius: 8
            border.width: 2

            Text {
                id: textField
                x: 0
                y: 24
                width: 383
                height: 38
                text: cashManager.textField
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 26
            }
        }

        Button {
            id: button3
            x: 389
            y: 706
            width: 200
            height: 90
            text: qsTr("Pay")
            font.pointSize: 18
        }

        Button {
            id: button4
            x: 603
            y: 706
            width: 110
            height: 90
            text: qsTr("Next")
            font.pointSize: 16

            Button {
                id: button5
                x: 618
                y: 706
                height: 45
                text: qsTr("Button")
            }
        }

        Button {
            id: b_createBill
            objectName: qsTr("createBill")
            x: 603
            y: 812
            width: 110
            height: 90
            text: qsTr("Reçu")
            font.pointSize: 16
            signal createBillSignal(string code)
        }

        Rectangle {
            id: rectangle7
            x: 724
            y: 706
            width: 164
            height: 40
            color: "#ffffff"
            border.width: 2

            Text {
                id: element7
                x: 8
                y: 8
                width: 64
                height: 18
                text: qsTr("Cheques")
                font.family: "Verdana"
                font.pixelSize: 14
            }

            Text {
                id: element8
                x: 102
                y: 10
                width: 39
                height: 14
                color: "#0da046"
                text: qsTr("pending")
                font.pixelSize: 14
            }
        }

        Button {
            id: button8
            x: 389
            y: 812
            width: 200
            height: 90
            text: qsTr("Cancel")
            font.pointSize: 18
        }

        Rectangle {
            id: rectangle9
            x: 724
            y: 788
            width: 164
            height: 40
            color: "#ffffff"
            Text {
                id: element11
                x: 103
                y: 13
                width: 39
                height: 14
                color: "#0da046"
                text: qsTr("pending")
                font.pixelSize: 14
            }

            Text {
                id: element12
                x: 8
                y: 11
                width: 64
                height: 18
                text: qsTr("Cards code")
                font.family: "Verdana"
                font.pixelSize: 14
            }
            border.width: 2
        }

        Rectangle {
            id: rectangle10
            x: 724
            y: 862
            width: 164
            height: 40
            color: "#ffffff"
            Text {
                id: element13
                x: 104
                y: 13
                width: 39
                height: 14
                color: "#0da046"
                text: qsTr("pending")
                font.pixelSize: 14
            }

            Text {
                id: element14
                x: 8
                y: 11
                width: 64
                height: 18
                text: qsTr("Cards")
                font.family: "Verdana"
                font.pixelSize: 14
            }
            border.width: 2
        }

        Rectangle {
            id: rectangle8
            x: 603
            y: 0
            width: 285
            height: 100
            color: "#ffffff"
            Text {
                id: element10
                x: 194
                y: 38
                width: 83
                height: 25
                color: "#0da046"
                text: qsTr("pending")
                font.pixelSize: 20
            }

            Text {
                id: element9
                x: 19
                y: 41
                width: 152
                height: 18
                text: qsTr("Server Payment")
                font.family: "Verdana"
                font.pixelSize: 18
            }
            border.width: 2
        }
    }

    Rectangle {
        id: rectangle5
        x: 388
        y: 310
        width: 500
        height: 389
        color: "#ffffff"
        radius: 0
        border.width: 2
        objectName: qsTr("rectangle6")

        Button {
            id: b_enter
            x: 310
            y: 15
            width: 150
            height: 361
            text: qsTr("ENTER")
            font.pointSize: 24
            objectName: qsTr("button")
        }

        Grid {
            id: grid
            x: 38
            y: 126
            width: 272
            height: 361
            spacing: 13
            anchors.bottomMargin: 13
            anchors.bottom: parent.bottom
            flow: Grid.LeftToRight
            rows: 4
            Button {
                id: b_1
                width: 80
                height: 80
                text: qsTr("1")
                onClicked: cashManager.textField = text
                font.pointSize: 24
            }

            Button {
                id: b_2
                width: 80
                height: 80
                text: qsTr("2")
                onClicked: cashManager.textField = text
                font.pointSize: 24
            }

            Button {
                id: b_3
                width: 80
                height: 80
                text: qsTr("3")
                onClicked: cashManager.textField = text
                font.pointSize: 24
            }

            Button {
                id: b_4
                width: 80
                height: 80
                text: qsTr("4")
                onClicked: cashManager.textField = text
                font.pointSize: 24
            }

            Button {
                id: b_5
                width: 80
                height: 80
                text: qsTr("5")
                onClicked: cashManager.textField = text
                font.pointSize: 24
            }

            Button {
                id: b_6
                width: 80
                height: 80
                text: qsTr("6")
                onClicked: cashManager.textField = text
                font.pointSize: 24
            }

            Button {
                id: b_7
                width: 80
                height: 80
                text: qsTr("7")
                onClicked: cashManager.textField = text
                font.pointSize: 24
            }

            Button {
                id: b_8
                width: 80
                height: 80
                text: qsTr("8")
                onClicked: cashManager.textField = text
                font.pointSize: 24
            }

            Button {
                id: b_9
                width: 80
                height: 80
                text: qsTr("9")
                onClicked: cashManager.textField = text
                font.pointSize: 24
            }

            Button {
                id: b_ca
                width: 80
                height: 80
                text: qsTr("CA")
                onClicked: cashManager.textField = text
                checked: false
                font.pointSize: 24
                autoExclusive: false
                checkable: false
            }

            Button {
                id: b_0
                width: 80
                height: 80
                text: qsTr("0")
                onClicked: cashManager.textField = text
                checked: false
                font.pointSize: 24
                autoExclusive: false
                checkable: false
            }

            Button {
                id: b_10
                width: 80
                height: 80
                text: qsTr("C")
                onClicked: cashManager.textField = text
                checked: false
                font.pointSize: 24
                autoExclusive: false
                checkable: false
            }
            columns: 3
        }
    }
}
