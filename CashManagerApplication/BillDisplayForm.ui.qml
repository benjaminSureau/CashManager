import QtQuick 2.4

Item {
    width: 300
    height: 100
    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.fill: parent

        Text {
            id: element
            x: 163
            y: 38
            width: 96
            height: 24
            text: qsTr("0")
            font.pixelSize: 20
        }

        Text {
            id: element1
            x: 28
            y: 38
            text: qsTr("Total :")
            font.pixelSize: 20
        }
    }
}
