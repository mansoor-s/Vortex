#ifndef JSHINT_H
#define JSHINT_H

#include <QObject>
#include <QThread>
#include <QList>
#include <QProcess>
#include <QDebug>

struct jsHintData{
    int lineNumber;
    int columnNumber;
    QString message;
};

class JsHint : public QThread
{
Q_OBJECT

public:
    JsHint();
    void init();

private:
     QList<jsHintData> parse(QByteArray data);

signals:
    void results(QList<jsHintData> data);

public slots:
    void runJsHint(QString fileName);

};
#endif // JSHINT_H
