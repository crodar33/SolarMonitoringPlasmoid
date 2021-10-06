// main.qml
import QtQuick 2.0
import QtQuick.Layouts 1.0
import org.kde.plasma.plasmoid 2.0
import org.kde.plasma.components 2.0 as PlasmaComponents
import org.kde.plasma.core 2.0 as PlasmaCore

ColumnLayout {

    id: root

    PlasmaComponents.Label {
        id: gridText
        text: "Grid: -"
    }

    PlasmaComponents.Label {
        id: loadText
        text: "Load: -"
    }
    
    PlasmaComponents.Label {
        id: panelsText
        text: "Panels: -"
    }

    PlasmaComponents.Label {
        id: batteryPowerText
        text: "Battery P: -"
    }

    PlasmaComponents.Label {
        id: batteryCapacityText
        text: "Battery Cap: -"
    }

    Connections {
        target: plasmoid.nativeInterface
        function onDataUpdate(gridP, loadP, panelsP, batteryP, batteryC) {
            console.log(gridP, loadP, panelsP, batteryP, batteryC);
            gridText.text               = "Grid: " + gridP.toFixed(2);
            loadText.text               = "Load: " + loadP.toFixed(2);
            panelsText.text             = "Panels: " + panelsP.toFixed(2);
            batteryPowerText.text       = "Battery P: " + batteryP.toFixed(2);
            batteryCapacityText.text    = "Battery Cap: " + batteryC.toFixed(2);
        }
    }

    //PlasmaComponents.Label {
    //    Layout.alignment: Qt.AlignCenter
    //    text: plasmoid.nativeInterface.nativeText
    //}

    MouseArea {
        anchors.fill: parent
        onClicked: {
            plasmoid.nativeInterface.cppSlot();
        }
    }

}
