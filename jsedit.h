#ifndef JsEdit_H
#define JsEdit_H

#include <QColor>
#include <QPlainTextEdit>
#include <QScopedPointer>

class JsEditPrivate;

class JsEdit: public QPlainTextEdit
{
    Q_OBJECT
    Q_PROPERTY(bool bracketsMatchingEnabled READ isBracketsMatchingEnabled WRITE setBracketsMatchingEnabled)
    Q_PROPERTY(bool codeFoldingEnabled READ isCodeFoldingEnabled WRITE setCodeFoldingEnabled)
    Q_PROPERTY(bool lineNumbersVisible READ isLineNumbersVisible WRITE setLineNumbersVisible)
    Q_PROPERTY(bool textWrapEnabled READ isTextWrapEnabled WRITE setTextWrapEnabled)

public:

    typedef enum {
        Background,
        Normal,
        Comment,
        Number,
        String,
        Operator,
        Identifier,
        Keyword,
        BuiltIn,
        Sidebar,
        LineNumber,
        Cursor,
        Marker,
        BracketMatch,
        BracketError,
        FoldIndicator
    } ColorComponent;

    JsEdit(QWidget *parent = 0);
    ~JsEdit();

    void setColor(ColorComponent component, const QColor &color);

    QStringList keywords() const;
    void setKeywords(const QStringList &keywords);

    bool isBracketsMatchingEnabled() const;
    bool isCodeFoldingEnabled() const;
    bool isLineNumbersVisible() const;
    bool isTextWrapEnabled() const;

    bool isFoldable(int line) const;
    bool isFolded(int line) const;

public slots:
    void updateSidebar();
    void mark(const QString &str, Qt::CaseSensitivity sens = Qt::CaseInsensitive);
    void setBracketsMatchingEnabled(bool enable);
    void setCodeFoldingEnabled(bool enable);
    void setLineNumbersVisible(bool visible);
    void setTextWrapEnabled(bool enable);

    void fold(int line);
    void unfold(int line);
    void toggleFold(int line);

protected:
    void resizeEvent(QResizeEvent *e);
    void wheelEvent(QWheelEvent *e);

private slots:
    void updateCursor();
    void updateSidebar(const QRect &rect, int d);

private:
    QScopedPointer<JsEditPrivate> d_ptr;
    Q_DECLARE_PRIVATE(JsEdit);
    Q_DISABLE_COPY(JsEdit);
};


#endif // JsEdit_H
