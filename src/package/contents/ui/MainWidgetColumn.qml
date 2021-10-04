// main.qml
import QtQuick 2.0
import org.kde.plasma.components 2.0 as PlasmaComponents
import org.kde.plasma.core 2.0 as PlasmaCore
import QtQuick.Layouts 1.0

ColumnLayout {

    id: root

    PlasmaComponents.Label {
        id: gridText
        text: "Grid: "
    }

    PlasmaComponents.Label {
        id: loadText
        text: "Load: "
    }
    
    PlasmaComponents.Label {
        id: panelsText
        text: "Panels: "
    }

    PlasmaComponents.Label {
        id: batteryPowerText
        text: "Battery P: "
    }

    PlasmaComponents.Label {
        id: batteryCapacityText
        text: "Battery Cap: "
    }
    
        PlasmaComponents.Label {
            Layout.alignment: Qt.AlignCenter
            text: plasmoid.nativeInterface.nativeText
        }

}
