#ifndef GAMEFINISHDATA_H
#define GAMEFINISHDATA_H

#include <QObject>

class GameFinishData : public QObject
{
    Q_OBJECT
public:
    explicit GameFinishData(QObject *parent = nullptr);
    void  setPath(QString name);
    void  setBCIPath(QString);
    void  readGameFinishData();

    void clearValue();

    void traverseFolders(const QString& folderPath);

    bool  readGameFile(QString name);
    QList<double> getEmotionValue();
    QList<double> getPericeiveValue();
    void  saveFinishData();
    int getTrainTime() const;

private:
    int train_time;
    QString gamefile_path;
    QString bci_save_path;
    QList<double> emotion_max_value;
    QList<double> periceive_max_value;
};

#endif // GAMEFINISHDATA_H
