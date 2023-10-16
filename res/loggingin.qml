import QtQuick 2.0

import QtQuick.Controls 2.0

Item{
    id: element
    signal cancal();
    Column {
        id: column
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 20
        ProgressBar {
            id: progressBar
            width: 300
            height: 20
            anchors.bottomMargin: -50
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Courier"
            value: 1


            background: Rectangle {   //背景项
                implicitWidth: progressBar.width
                implicitHeight: progressBar.height
                //            color: "#ebedee"
                color: "#4facfe"
                radius: 50 //圆滑度
            }

            contentItem: Item {   //内容项
                Rectangle {
                    id:frontColor
                    width: progressBar.visualPosition * progressBar.width
                    height: progressBar.height
                    radius: 50
                    color: "#ebedee"
                    opacity: 0.2
                    SequentialAnimation {

                        id: scrollingAnimation
                        running: true
                        loops: Animation.Infinite

                        PropertyAnimation {
                            target: frontColor
                            property: "x"
                            to: progressBar.width
                            duration: 2000
                            easing.type: Easing.Linear
                        }

                        PropertyAnimation {
                            target: frontColor
                            property: "x"
                            to: 0
                            duration: 0
                        }
                    }
                }
            }
        }

        Text {
            id: element1
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 20
            text: qsTr("登录中...")
        }

        Button {
            id: button
            x: 270
            y: 190
            text: qsTr("取消")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked:
            {

                element.cancal()
            }
        }


    }

}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
