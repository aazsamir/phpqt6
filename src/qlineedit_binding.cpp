#include "php_qt6.h"

// Object handlers
static zend_object_handlers qlineedit_object_handlers;

// Arginfo
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QLineEdit___construct, 0, 0, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, text, IS_STRING, 0, "\"\"")
    ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, parent, Qt\\Widget, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QLineEdit_setText, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QLineEdit_text, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QLineEdit_setPlaceholderText, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QLineEdit_show, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QLineEdit_hide, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QLineEdit_setGeometry, 0, 4, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QLineEdit_setStyleSheet, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, styleSheet, IS_STRING, 0)
ZEND_END_ARG_INFO()

// __construct
PHP_METHOD(QLineEdit, __construct)
{
    char *text = nullptr;
    size_t text_len = 0;
    zval *parent = nullptr;
    
    ZEND_PARSE_PARAMETERS_START(0, 2)
        Z_PARAM_OPTIONAL
        Z_PARAM_STRING(text, text_len)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent, qt_ce_QWidget)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    
    QWidget *parent_widget = nullptr;
    if (parent) {
        qt_object *parent_obj = Z_QT_OBJ_P(parent);
        parent_widget = static_cast<QWidget*>(parent_obj->ptr);
    }
    
    QLineEdit *lineedit = new QLineEdit(parent_widget);
    if (text) {
        lineedit->setText(QString::fromUtf8(text, text_len));
    }
    intern->ptr = lineedit;
}

// setText
PHP_METHOD(QLineEdit, setText)
{
    char *text;
    size_t text_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QLineEdit *lineedit = static_cast<QLineEdit*>(intern->ptr);
    if (lineedit) {
        lineedit->setText(QString::fromUtf8(text, text_len));
    }
}

// text
PHP_METHOD(QLineEdit, text)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QLineEdit *lineedit = static_cast<QLineEdit*>(intern->ptr);
    if (lineedit) {
        QString text = lineedit->text();
        RETURN_STRING(text.toUtf8().constData());
    }
    RETURN_EMPTY_STRING();
}

// setPlaceholderText
PHP_METHOD(QLineEdit, setPlaceholderText)
{
    char *text;
    size_t text_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QLineEdit *lineedit = static_cast<QLineEdit*>(intern->ptr);
    if (lineedit) {
        lineedit->setPlaceholderText(QString::fromUtf8(text, text_len));
    }
}

// show
PHP_METHOD(QLineEdit, show)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QLineEdit *lineedit = static_cast<QLineEdit*>(intern->ptr);
    if (lineedit) {
        lineedit->show();
    }
}

// hide
PHP_METHOD(QLineEdit, hide)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QLineEdit *lineedit = static_cast<QLineEdit*>(intern->ptr);
    if (lineedit) {
        lineedit->hide();
    }
}

// setGeometry
PHP_METHOD(QLineEdit, setGeometry)
{
    zend_long x, y, width, height;
    
    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_LONG(x)
        Z_PARAM_LONG(y)
        Z_PARAM_LONG(width)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QLineEdit *lineedit = static_cast<QLineEdit*>(intern->ptr);
    if (lineedit) {
        lineedit->setGeometry(x, y, width, height);
    }
}

// setStyleSheet
PHP_METHOD(QLineEdit, setStyleSheet)
{
    char *stylesheet;
    size_t stylesheet_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(stylesheet, stylesheet_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QLineEdit *lineedit = static_cast<QLineEdit*>(intern->ptr);
    if (lineedit) {
        lineedit->setStyleSheet(QString::fromUtf8(stylesheet, stylesheet_len));
    }
}

// Method entries
static const zend_function_entry qlineedit_methods[] = {
    PHP_ME(QLineEdit, __construct, arginfo_class_QLineEdit___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QLineEdit, setText, arginfo_class_QLineEdit_setText, ZEND_ACC_PUBLIC)
    PHP_ME(QLineEdit, text, arginfo_class_QLineEdit_text, ZEND_ACC_PUBLIC)
    PHP_ME(QLineEdit, setPlaceholderText, arginfo_class_QLineEdit_setPlaceholderText, ZEND_ACC_PUBLIC)
    PHP_ME(QLineEdit, show, arginfo_class_QLineEdit_show, ZEND_ACC_PUBLIC)
    PHP_ME(QLineEdit, hide, arginfo_class_QLineEdit_hide, ZEND_ACC_PUBLIC)
    PHP_ME(QLineEdit, setGeometry, arginfo_class_QLineEdit_setGeometry, ZEND_ACC_PUBLIC)
    PHP_ME(QLineEdit, setStyleSheet, arginfo_class_QLineEdit_setStyleSheet, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

// Initialize class
void qt_register_QLineEdit_class()
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\LineEdit", qlineedit_methods);
    qt_ce_QLineEdit = zend_register_internal_class(&ce);
    qt_ce_QLineEdit->create_object = qt_object_new;
    
    memcpy(&qlineedit_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
    qlineedit_object_handlers.offset = XtOffsetOf(qt_object, std);
    qlineedit_object_handlers.free_obj = qt_object_free;
}
