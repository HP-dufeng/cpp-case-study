import QtQuick 2.9
import components 1.0

Item {
    Rectangle {
        anchors.fill: parent
        color: "#f4c842"
        Text {
            anchors.centerIn: parent
            text: qsTr("Create Client View")
        }
    }

    CommandBar {
        commandList: masterController.ui_commandController.ui_createClientViewContextCommands
    }
}

