import QtQuick 2.14
Item {
    property int radius: canvas.height/2*0.6
    property int edge_num: 5
    property int scale_line: 5
    property var chart_color: "rgba(75, 192, 192, 1)"
    property var label_color: "black"
    property var data_color: "blue"
    property int  centerX: canvas.width/2
    property int  centerY: canvas.height/2
    property var label: ["维度1","维度2","维度3","维度4","维度5"]
    property var chart_data: [0,0,0,0,0]
    function setRadarLabel(names)
    {
        label=names
    }
    function setData(data)
    {
        chart_data=data
        canvas.requestPaint()
    }
    Canvas{
        id: canvas
        anchors.fill: parent
        onPaint: {
            var ctx = canvas.getContext("2d");
            ctx.clearRect(0,0,width,height)
            drawPolygan(ctx)
            drawVertexTxt(ctx)
            drawData(ctx)
        }
        function drawPolygan(ctx)
        {
            ctx.beginPath();
            ctx.strokeStyle =chart_color;
            ctx.lineWidth = 2;
            //最外层的坐标
            var polygan_points=[]
            //计算多边形的坐标
            for(var i=0;i<scale_line;i++)
            {
                var current_radius=radius/scale_line
                for(var j=0;j<edge_num;j++)
                {
                    var start_x,start_y;
                     //计算多边形内角角度
                    var current_angle = (Math.PI * 2 * j) / edge_num - Math.PI / 2;
                    var x=centerX +current_radius*i*Math.cos(current_angle)
                    var y=centerY +current_radius*i*Math.sin(current_angle)
                    if(j===0)
                    {
                        start_x=x
                        start_y=y
                        ctx.moveTo(x, y);
                    }
                    else
                    {
                        ctx.lineTo(x, y);
                    }
                    if((j+1)==edge_num)
                    {
                        ctx.lineTo(start_x,start_y)
                    }
                    if((i+1)==scale_line)
                    {
                        polygan_points.push([x,y])
                    }
                }
            }
            ctx.closePath();
            ctx.stroke();
            //绘画刻度值
            for(var i=0;i<edge_num;i++)
            {
                ctx.moveTo(polygan_points[i][0],polygan_points[i][1])
                ctx.lineTo(centerX,centerY)
            }
            ctx.stroke();
        }
        function drawVertexTxt (ctx) {
            ctx.fillStyle=label_color
            for(var i=0;i<edge_num;i++)
            {
                 //计算多边形内角角度
                var current_angle = (Math.PI * 2 * i) / edge_num - Math.PI / 2;
                var x=centerX +radius*Math.cos(current_angle)
                var y=centerY +radius*Math.sin(current_angle)
                if(i===0)
                {
                    y+=radius/scale_line/2
                }
                if(i===1)
                {
                    ctx.textAlign="left"
                    x-=radius/scale_line/2
                    y+=10
                }
                else if(i===4)
                {
                    ctx.textAlign="right"
                    y+=10
                    x+=10
                }
                else{
                    ctx.textAlign="center"
                }
                ctx.fillText(label[i],x,y)
            }

        }
        function drawData(ctx)
        {
            ctx.beginPath();
            for(var i=0;i<edge_num;i++)
            {
                var scale=radius/scale_line
                var current_angle = (Math.PI * 2 * i) / edge_num - Math.PI / 2;
                var x=centerX+chart_data[i]*radius*0.8*Math.cos(current_angle)
                var y=centerY+chart_data[i]*radius*0.8*Math.sin(current_angle)
                if(i===0)
                {
                    ctx.moveTo(x, y);
                }
                else
                {
                    ctx.lineTo(x, y);
                }
            }
            ctx.closePath()
            ctx.stroke();
            ctx.globalAlpha=0.1
            ctx.fillStyle=data_color;
            ctx.fill()
             ctx.globalAlpha=1
        }
    }
}
