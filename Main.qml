import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtDataVisualization

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Visualization Demo")

    Surface3D {
        width: parent.width
        height: parent.height
        Surface3DSeries {
            itemLabelFormat: "Pop density at (@xLabel N, @zLabel E): @yLabel"
            ItemModelSurfaceDataProxy {
                itemModel: dataModel
                // Mapping model roles to surface series rows, columns, and values.
                rowRole: "longitude"
                columnRole: "latitude"
                yPosRole: "pop_density"
            }
        }
    }
    ListModel {
        id: dataModel
        ListElement{ longitude: "20"; latitude: "10"; pop_density: "4.75"; }
        ListElement{ longitude: "21"; latitude: "10"; pop_density: "3.00"; }
        ListElement{ longitude: "22"; latitude: "10"; pop_density: "1.24"; }
        ListElement{ longitude: "23"; latitude: "10"; pop_density: "2.53"; }
        ListElement{ longitude: "20"; latitude: "11"; pop_density: "2.55"; }
        ListElement{ longitude: "21"; latitude: "11"; pop_density: "2.03"; }
        ListElement{ longitude: "22"; latitude: "11"; pop_density: "3.46"; }
        ListElement{ longitude: "23"; latitude: "11"; pop_density: "5.12"; }
        ListElement{ longitude: "20"; latitude: "12"; pop_density: "1.37"; }
        ListElement{ longitude: "21"; latitude: "12"; pop_density: "2.98"; }
        ListElement{ longitude: "22"; latitude: "12"; pop_density: "3.33"; }
        ListElement{ longitude: "23"; latitude: "12"; pop_density: "3.23"; }
        ListElement{ longitude: "20"; latitude: "13"; pop_density: "4.34"; }
        ListElement{ longitude: "21"; latitude: "13"; pop_density: "3.54"; }
        ListElement{ longitude: "22"; latitude: "13"; pop_density: "1.65"; }
        ListElement{ longitude: "23"; latitude: "13"; pop_density: "2.67"; }
    }
}
