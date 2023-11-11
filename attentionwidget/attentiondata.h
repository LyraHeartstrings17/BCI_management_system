#ifndef ATTENTIONDATA_H
#define ATTENTIONDATA_H

#include <QObject>

class AttentionData : public QObject
{
    Q_OBJECT
public:
    explicit AttentionData(QObject *parent = nullptr);
    void  setPath(QString name);
    void  setBCIPath(QString);
    void  readGameFinishData();

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

#endif // ATTENTIONDATA_H
