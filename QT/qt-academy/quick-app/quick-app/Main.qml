import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id : column
        width: 125
        height: 75
        anchors.centerIn: parent

        TextField {
            id: textField
            placeholderText: "Enter some text"
        }
        Button {
            id: button
            text: "Click to open popup"

            onClicked: {
                myPopUp.open()
            }
        }
    }


    Popup {
        id: myPopUp
        anchors.centerIn: parent
        width: 125
        height: 75
        closePolicy: "CloseOnEscape"

        Column {
            anchors.centerIn: parent
            spacing: 10

            Text {
                text: textField.text
            }

            Button {
                text: "close"
                width: 100
                onClicked: {
                    myPopUp.close()
                }
            }
        }

    }
}
