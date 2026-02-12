#include "php_qt6.h"

// Object handlers
static zend_object_handlers qlineedit_object_handlers;

// Free object
static void qlineedit_free_object(zend_object *object)
{
    qlineedit_object *intern = qlineedit_fetch_object(object);
    
    if (intern->lineedit) {
        delete intern->lineedit;
        intern->lineedit = nullptr;
    }
    
    zend_object_std_dtor(&intern->std);
}

// Create object
static zend_object* qlineedit_create_object(zend_class_entry *ce)
{
    qlineedit_object *intern = (qlineedit_object*)ecalloc(1,
        sizeof(qlineedit_object) + zend_object_properties_size(ce));
    
    zend_object_std_init(&intern->std, ce);
    object_properties_init(&intern->std, ce);
    
    intern->std.handlers = &qlineedit_object_handlers;
    intern->lineedit = nullptr;
    
    return &intern->std;
}

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
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent, qwidget_ce)
    ZEND_PARSE_PARAMETERS_END();
    
    qlineedit_object *intern = Z_QLINEEDIT_OBJ_P(ZEND_THIS);
    
    QWidget *parent_widget = nullptr;
    if (parent) {
        qwidget_object *parent_obj = Z_QWIDGET_OBJ_P(parent);
        parent_widget = parent_obj->widget;
    }
    
    intern->lineedit = new QLineEdit(parent_widget);
    if (text) {
        intern->lineedit->setText(QString::fromUtf8(text, text_len));
    }
}

// setText
PHP_METHOD(QLineEdit, setText)
{
    char *text;
    size_t text_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qlineedit_object *intern = Z_QLINEEDIT_OBJ_P(ZEND_THIS);
    if (intern->lineedit) {
        intern->lineedit->setText(QString::fromUtf8(text, text_len));
    }
}

// text
PHP_METHOD(QLineEdit, text)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qlineedit_object *intern = Z_QLINEEDIT_OBJ_P(ZEND_THIS);
    if (intern->lineedit) {
        QString text = intern->lineedit->text();
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
    
    qlineedit_object *intern = Z_QLINEEDIT_OBJ_P(ZEND_THIS);
    if (intern->lineedit) {
        intern->lineedit->setPlaceholderText(QString::fromUtf8(text, text_len));
    }
}

// show
PHP_METHOD(QLineEdit, show)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qlineedit_object *intern = Z_QLINEEDIT_OBJ_P(ZEND_THIS);
    if (intern->lineedit) {
        intern->lineedit->show();
    }
}

// hide
PHP_METHOD(QLineEdit, hide)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qlineedit_object *intern = Z_QLINEEDIT_OBJ_P(ZEND_THIS);
    if (intern->lineedit) {
        intern->lineedit->hide();
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
    
    qlineedit_object *intern = Z_QLINEEDIT_OBJ_P(ZEND_THIS);
    if (intern->lineedit) {
        intern->lineedit->setGeometry(x, y, width, height);
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
    
    qlineedit_object *intern = Z_QLINEEDIT_OBJ_P(ZEND_THIS);
    if (intern->lineedit) {
        intern->lineedit->setStyleSheet(QString::fromUtf8(stylesheet, stylesheet_len));
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
void qlineedit_init(INIT_FUNC_ARGS)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\LineEdit", qlineedit_methods);
    qlineedit_ce = zend_register_internal_class(&ce);
    qlineedit_ce->create_object = qlineedit_create_object;
    
    memcpy(&qlineedit_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    qlineedit_object_handlers.offset = XtOffsetOf(qlineedit_object, std);
    qlineedit_object_handlers.free_obj = qlineedit_free_object;
}
