#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    jsHint = new JsHint;
    jsHint->start();

    connect(this, SIGNAL(runJsHint(QString)), jsHint, SLOT(runJsHint(QString)));
    connect(jsHint, SIGNAL(results(QList<jsHintData>)), this, SLOT(jsHintResult(QList<jsHintData>)));


    ui->setupUi(this);


    activeTabWidget = new QTabWidget(this);

    tabWidgets << activeTabWidget;
    //activeTabWidget->tabBar()->set

    activeDocument = new JsEdit(this);

    documents << activeDocument;

    activeDocument->setWindowTitle(QString("FOOO.js"));
    activeDocument->setFrameShape(JsEdit::NoFrame);
    activeDocument->setWordWrapMode(QTextOption::NoWrap);
    activeDocument->setTabStopWidth(4);
    activeDocument->resize(QApplication::desktop()->availableGeometry().size() / 2);

    QStringList keywords = activeDocument->keywords();
    keywords << "const";
    keywords << "let";
    activeDocument->setKeywords(keywords);

    // dark color scheme
    activeDocument->setColor(JsEdit::Background,    QColor("#0C152B"));
    activeDocument->setColor(JsEdit::Normal,        QColor("#FFFFFF"));
    activeDocument->setColor(JsEdit::Comment,       QColor("#666666"));
    activeDocument->setColor(JsEdit::Number,        QColor("#DBF76C"));
    activeDocument->setColor(JsEdit::String,        QColor("#5ED363"));
    activeDocument->setColor(JsEdit::Operator,      QColor("#FF7729"));
    activeDocument->setColor(JsEdit::Identifier,    QColor("#FFFFFF"));
    activeDocument->setColor(JsEdit::Keyword,       QColor("#FDE15D"));
    activeDocument->setColor(JsEdit::BuiltIn,       QColor("#9CB6D4"));
    activeDocument->setColor(JsEdit::Cursor,        QColor("#1E346B"));
    activeDocument->setColor(JsEdit::Marker,        QColor("#DBF76C"));
    activeDocument->setColor(JsEdit::BracketMatch,  QColor("#1AB0A6"));
    activeDocument->setColor(JsEdit::BracketError,  QColor("#A82224"));
    activeDocument->setColor(JsEdit::FoldIndicator, QColor("#555555"));

    activeDocument->setPlainText(QString("function() {\nsdfsdfsdfdsfsfsdf\nsdfsdf\n}"));

    activeTabWidget->addTab(activeDocument, QIcon(":/images/Save.png") ,QString("Untitled"));
    ui->gridLayout->addWidget(activeTabWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::jsHintResult(QList<jsHintData> data) {

}
