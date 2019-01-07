import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Window 2.2


Item {
   Keypad{
       flags: Qt.FramelessWindowHint
       width: 505
       height: 590
       visible: false
   }

   CashManager{
       flags: Qt.FramelessWindowHint
       width: 888
       height: 905
       visible: true
   }

}
