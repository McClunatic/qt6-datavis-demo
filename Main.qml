import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtDataVisualization
import demo

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Visualization Demo")

    DataSource {
        id: source
    }

    Surface3D {
        id: graph
        width: parent.width
        height: parent.height

        Surface3DSeries {
            id: series
            drawMode: Surface3DSeries.DrawSurfaceAndWireframe
            itemLabelFormat: "@xLabel, @zLabel: @yLabel"
        }
    }

    Timer {
        id: refresher
        interval: 1000
        running: true
        repeat: true
        onTriggered: source.update(series);
    }
}
