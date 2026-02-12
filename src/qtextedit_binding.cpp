#include "php_qt6.h"
#include <QTextEdit>

zend_class_entry *qt_ce_QTextEdit;
zend_object_handlers qt_object_handlers_QTextEdit;

// Arginfo
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QTextEdit___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTextEdit_setPlainText, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTextEdit_toPlainText, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_QTextEdit_setHtml arginfo_class_QTextEdit_setPlainText
#define arginfo_class_QTextEdit_toHtml arginfo_class_QTextEdit_toPlainText
#define arginfo_class_QTextEdit_append arginfo_class_QTextEdit_setPlainText

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTextEdit_setReadOnly, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, readOnly, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTextEdit_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

// Constructor: new TextEdit()
PHP_METHOD(QTextEdit, __construct) {
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QTextEdit();
}

// void setPlainText(string $text)
PHP_METHOD(QTextEdit, setPlainText) {
    char *text;
    size_t text_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTextEdit *textEdit = static_cast<QTextEdit*>(intern->ptr);
    textEdit->setPlainText(QString::fromUtf8(text, text_len));
}

// string toPlainText()
PHP_METHOD(QTextEdit, toPlainText) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTextEdit *textEdit = static_cast<QTextEdit*>(intern->ptr);
    QString text = textEdit->toPlainText();
    RETURN_STRING(text.toUtf8().constData());
}

// void setHtml(string $html)
PHP_METHOD(QTextEdit, setHtml) {
    char *html;
    size_t html_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(html, html_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTextEdit *textEdit = static_cast<QTextEdit*>(intern->ptr);
    textEdit->setHtml(QString::fromUtf8(html, html_len));
}

// string toHtml()
PHP_METHOD(QTextEdit, toHtml) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTextEdit *textEdit = static_cast<QTextEdit*>(intern->ptr);
    QString html = textEdit->toHtml();
    RETURN_STRING(html.toUtf8().constData());
}

// void setReadOnly(bool $readOnly)
PHP_METHOD(QTextEdit, setReadOnly) {
    zend_bool readOnly;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(readOnly)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTextEdit *textEdit = static_cast<QTextEdit*>(intern->ptr);
    textEdit->setReadOnly(readOnly);
}

// void clear()
PHP_METHOD(QTextEdit, clear) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTextEdit *textEdit = static_cast<QTextEdit*>(intern->ptr);
    textEdit->clear();
}

// void append(string $text)
PHP_METHOD(QTextEdit, append) {
    char *text;
    size_t text_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTextEdit *textEdit = static_cast<QTextEdit*>(intern->ptr);
    textEdit->append(QString::fromUtf8(text, text_len));
}

// Method entries
static const zend_function_entry qt_QTextEdit_methods[] = {
    PHP_ME(QTextEdit, __construct, arginfo_class_QTextEdit___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QTextEdit, setPlainText, arginfo_class_QTextEdit_setPlainText, ZEND_ACC_PUBLIC)
    PHP_ME(QTextEdit, toPlainText, arginfo_class_QTextEdit_toPlainText, ZEND_ACC_PUBLIC)
    PHP_ME(QTextEdit, setHtml, arginfo_class_QTextEdit_setHtml, ZEND_ACC_PUBLIC)
    PHP_ME(QTextEdit, toHtml, arginfo_class_QTextEdit_toHtml, ZEND_ACC_PUBLIC)
    PHP_ME(QTextEdit, setReadOnly, arginfo_class_QTextEdit_setReadOnly, ZEND_ACC_PUBLIC)
    PHP_ME(QTextEdit, clear, arginfo_class_QTextEdit_clear, ZEND_ACC_PUBLIC)
    PHP_ME(QTextEdit, append, arginfo_class_QTextEdit_append, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QTextEdit_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\TextEdit", qt_QTextEdit_methods);
    qt_ce_QTextEdit = zend_register_internal_class_ex(&ce, qt_ce_QWidget);
    qt_ce_QTextEdit->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QTextEdit, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QTextEdit.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QTextEdit.free_obj = qt_object_free;
}
