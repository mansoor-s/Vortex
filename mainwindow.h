#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QList>
#include <QTabWidget>


#include "jshint.h"
#include "jsedit.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void runJsHint(QString);

private:
    Ui::MainWindow *ui;
    JsHint *jsHint;
    QList<JsEdit*> documents;
    QList<QTabWidget*> tabWidgets;
    JsEdit* activeDocument;
    QTabWidget* activeTabWidget;

public slots:
    void jsHintResult(QList<jsHintData> data);

};

#endif // MAINWINDOW_H
