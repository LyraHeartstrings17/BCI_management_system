import QtQuick 2.0
import QtCharts 2.3
Item {
    property int point_num: 0
    function setSeriesname(names)
    {
       for(var i=0;i<5;i++)
       {
           var series=chartview.series(i)
           series.name=names[i]
       }
    }
    function append(data)
    {
        point_num++;
        for(var i=0;i<5;i++)
        {
            var series=chartview.series(i)
            series.append(point_num,data[i])

        }
        if(point_num>10)
        {
           xAxis.max=point_num
        }
    }
    //消除
    function clearData()
    {
        for (var i = 0; i < 5; i++) {
                    var series = chartview.series(i)
                    series.clear()
                }
        point_num=0;
    }
    ChartView {
        id:chartview
        anchors.fill: parent
        antialiasing: true
        ValueAxis{
            id:xAxis
            min:1
            max:7
        }

        ValueAxis{
            id:yAxis
            min:0
            max:1
        }
        SplineSeries {
            axisX: xAxis
            axisY: yAxis
        }
        SplineSeries {
            axisX: xAxis
            axisY: yAxis
        }
        SplineSeries {
            axisX: xAxis
            axisY: yAxis
        }
        SplineSeries {
            axisX: xAxis
            axisY: yAxis
        }
        SplineSeries {
            axisX: xAxis
            axisY: yAxis
        }
    }

}


//import QtQuick 2.0
//import QtCharts 2.3

//Item {
//    property int point_num: 0
//    property var names: []

//    function setSeriesname(names) {
//        this.names = names;
//        for(var i=0; i<5; i++) {
//            var series = chartview.series(i)
//            series.name = names[i]
//        }
//    }

//    function append(data) {

//        for(var i=0; i<5; i++) {
//            point_num++;
//            var series = chartview.series(i)
//            series.append(point_num, data[i])
//        }
//        if(point_num > 10) {
//           xAxis.max = point_num
//        }
//    }

//    ChartView {
//        id: chartview
//        anchors.fill: parent
//        antialiasing: true

//        ValueAxis {
//            id: xAxis
//            min: 1
//            max: 5
//            labelFormat: function(value) {
//                return names[value];
//            }
//        }

//        ValueAxis {
//            id: yAxis
//            min: 0
//            max: 1
//        }

//        SplineSeries {
//            axisX: xAxis
//            axisY: yAxis
//        }

//        SplineSeries {
//            axisX: xAxis
//            axisY: yAxis
//        }

//        SplineSeries {
//            axisX: xAxis
//            axisY: yAxis
//        }

//        SplineSeries {
//            axisX: xAxis
//            axisY: yAxis
//        }

//        SplineSeries {
//            axisX: xAxis
//            axisY: yAxis
//        }
//    }
//}
