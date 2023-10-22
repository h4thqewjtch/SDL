#ifndef FB2FILES_H
#define FB2FILES_H

#include <QFile>
#include <QObject>

class FB2Files : public QObject
{
    Q_OBJECT
public:
    explicit FB2Files(QObject *parent = nullptr);
    bool openFB2File(QFile&, QString&, QString, int);

signals:

};

#endif // FB2FILES_H
