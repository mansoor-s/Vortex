#include "jshint.h"

JsHint::JsHint()
{

}

void JsHint::init()
{
    //start event loop
    exec();
}


/*
    If JsHint output format changes, this will need to be adjusted accordingly

*/
QList<jsHintData> JsHint::parse(QByteArray data) {
    QList<jsHintData> parsedData;

    QList<QByteArray> lines = data.split('\n');

    foreach(QByteArray line, lines) {
        //yay for arbitrary numbers!!
        if (line.length() < 15) {
            continue;
        }

        jsHintData formatedData;

        QList<QByteArray> parts = line.split(':')[1].split(',');

        //line number
        QByteArray lineNbr = parts[0].trimmed();
        lineNbr = lineNbr.right((lineNbr.length() - 1) - 4);
        formatedData.lineNumber = lineNbr.toInt();

        //column
        QByteArray col = parts[1].trimmed();
        col = col.right((col.length() - 1) - 3);
        formatedData.columnNumber = col.toInt();

        //message
        formatedData.message = parts[2].trimmed();

        parsedData.push_back(formatedData);
    }

    return parsedData;
}


void JsHint::runJsHint(QString fileName) {
    QProcess *jshint = new QProcess(this);
    QStringList args;
    args << fileName;

    jshint->start(QString("jshint"), args);

    if(!jshint->waitForReadyRead()) {
        qDebug() << "JsHint failed to run for some reasong...";
    }

    QByteArray data = jshint->readAllStandardOutput();

    emit results(parse(data));

}
