1.更改了radar文件为max文件
2.finishwidget新增void readData();来读取并且记录每次数据的最大值
3.finishdata新增void clearValue();getvalue中不会清除，最后来总的消除内存，
4.showWidget()去除读取文件，新增clear
