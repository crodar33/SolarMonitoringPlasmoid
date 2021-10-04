// main.qml
import QtQuick 2.0
import org.kde.plasma.components 2.0 as PlasmaComponents
import org.kde.plasma.core 2.0 as PlasmaCore
import QtQuick.Layouts 1.0

MainWidget {
    id: grid
    columns: 2

    PlasmaCore.SvgItem {
        id: test
        svg: PlasmaCore.Svg {
            imagePath: "icons/notification"
        }
    }
    PlasmaComponents.Label {
        text: "Item 2"
    }
    PlasmaCore.SvgItem {
        id: batteryIco
        smooth: true
        width: 64
        height: 64
        svg: PlasmaCore.Svg {
            imagePath: plasmoid.file('', 'ui/battery-00.svg')
        }
    }
    PlasmaComponents.Label {
        text: "Item 4"
    }
}
