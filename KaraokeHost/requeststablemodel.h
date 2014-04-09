#ifndef REQUESTSTABLEMODEL_H
#define REQUESTSTABLEMODEL_H

#include <QAbstractTableModel>
#include <QNetworkAccessManager>
#include <QTimer>


class Request
{
public:
    Request(int RequestId, QString Singer, QString Artist, QString Title, int ts);
    int requestId() const;
    void setRequestId(int requestId);
    int timeStamp() const;
    void setTimeStamp(int timeStamp);
    QString artist() const;
    void setArtist(const QString &artist);
    QString title() const;
    void setTitle(const QString &title);
    QString singer() const;
    void setSinger(const QString &singer);

private:
    int m_requestId;
    int m_timeStamp;
    QString m_artist;
    QString m_title;
    QString m_singer;
};

class RequestsTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit RequestsTableModel(QObject *parent = 0);
    enum {REQUESTID=0,SINGER,ARTIST,TITLE,TIMESTAMP};

signals:

public slots:
    void timerExpired();
    void onNetworkReply(QNetworkReply* reply);
    void onSslErrors(QNetworkReply * reply);

private:
    QTimer *timer;
    QList<Request> requests;
    QNetworkAccessManager *networkManager;
    int curSerial;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

};

#endif // REQUESTSTABLEMODEL_H