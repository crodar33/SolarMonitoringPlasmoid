import QtQuick 2.0
import QtQuick.Controls 2.5
import org.kde.kirigami 2.4 as Kirigami

Item {
    id: page
    width: childrenRect.width
    height: childrenRect.height

    property alias cfg_informationHost: informationHost.text
    
    Kirigami.FormLayout {
        anchors.left: parent.left
        anchors.right: parent.right

        TextField {
            id: informationHost
            Kirigami.FormData.label: i18n("Information host:")
            placeholderText: i18n("192.168.0.0")
        }
    }
}
