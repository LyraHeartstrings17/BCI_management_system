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

    void traverseFolders(const QString& folderPath);

<<<<<<< HEAD
    void clearValue();

    bool  readGameFile(QString name);
    QList<double> getEmotionValue();
    QList<double> getPericeiveValue();
    QList<double> getallEmotionValue();
    QList<double> getallPericeiveValue();
=======
    bool  readGameFile(QString name);
    QList<double> getEmotionValue();
    QList<double> getPericeiveValue();
>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
    void  saveFinishData();
    int getTrainTime() const;

private:
    int train_time;
    QString gamefile_path;
    QString bci_save_path;
    QList<double> emotion_max_value;
    QList<double> periceive_max_value;
<<<<<<< HEAD
    QList<double> emotion_max_value_all;
    QList<double> periceive_max_value_all;
=======
>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
};

#endif // GAMEFINISHDATA_H
