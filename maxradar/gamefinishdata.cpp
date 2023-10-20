#include "gamefinishdata.h"
#include "QFile"
#include "QDir"
#include "QDebug"
#include <QString>
#include <QRegularExpression>
#include <QStringList>

GameFinishData::GameFinishData(QObject *parent) : QObject(parent)
{

    //game文件保存位置初始化
    this->bci_save_path="E:\\ddd\\qtprogram\\GameFinishWidget\\result";
}

void GameFinishData::setPath(QString path)
{
    this->gamefile_path=path;
}

void GameFinishData::setBCIPath(QString name)
{
    this->bci_save_path=name;
}

void GameFinishData::readGameFinishData()
{
    QDir directory(this->gamefile_path);
    QStringList files = directory.entryList(QStringList() << "*.bci", QDir::Files);
    if(!files.isEmpty())
    {
        for(QString file:files)
        {
            file=this->gamefile_path+"/"+file;
            readGameFile(file);
        }
        saveFinishData();

    }

}

bool  GameFinishData::readGameFile(QString name)
{
    QList<double> emotion_value;
    QList<double> periceive_value;
    QFile file(name);
    QString line;
    QStringList arr;
    file.open(QIODevice::ReadOnly);
    int cnt=0;
    bool flag=false;
    while (!file.atEnd()) {
        line=file.readLine();
        if(line.contains("Result"))
            flag=true;
        if(flag==false) continue;
        //数据处理按照冒号、空格和换行符进行分割
        if(cnt<11){
            QStringList parts = line.split(QRegularExpression("[: \r\n]"), Qt::SkipEmptyParts);
            arr += parts;
            cnt++;
        }
        else break;
    }
    //十个指标
    //若发来的BCI文件有误应该返回错误
    if(arr.size()<11) {

        return false;
    }
    //数据处理
    for(int i=1;i<11;i++){

        QStringList  strs=  arr[i].split("=");
        if(i<6)
        {
            periceive_value.append(strs[1].toDouble()/10000);
        }
        else
        {
            emotion_value.append(strs[1].toDouble()/10000);
        }
    }
    if(emotion_max_value.isEmpty())
    {
        emotion_max_value=emotion_value;
        periceive_max_value=periceive_value;
    }
    else
    {
        for(int i=0;i<5;i++)
        {
            emotion_max_value[i]=emotion_max_value[i]>emotion_value[i]?emotion_max_value[i]:emotion_value[i];
            periceive_max_value[i]=periceive_max_value[i]>periceive_value[i]?periceive_max_value[i]:periceive_value[i];
        }
    }
    file.close();
    return true;
}

QList<double>GameFinishData::getEmotionValue()
{
    QList<double> value=emotion_max_value;
//    emotion_max_value.clear();
    return value;
}
QList<double>GameFinishData::getPericeiveValue()
{
    QList<double> value=periceive_max_value;
//    periceive_max_value.clear();
    return value;
}
void GameFinishData::clearValue(){
    periceive_max_value.clear();
    emotion_max_value.clear();
}
void GameFinishData::saveFinishData()
{
    QString game_path=this->bci_save_path+"/finish.game";
    QFile file(game_path);
    file.open(QIODevice::Append);
    QString data="";
    for(int i=0;i<5;i++)
    {
        data+=QString::number(periceive_max_value[i])+" ";
    }
    for(int i=0;i<5;i++)
    {
        data+=QString::number(emotion_max_value[i])+" ";
    }
    data+="\n";
    file.write(data.toUtf8());
    file.close();
}




