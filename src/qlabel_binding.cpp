#include "php_qt6.h"

// Object handlers
static zend_object_handlers qlabel_object_handlers;

// Free object
static void qlabel_free_object(zend_object *object)
{
    qlabel_object *intern = qlabel_fetch_object(object);
    
    if (intern->label) {
        intern->label->deleteLater();
        intern->label = nullptr;
    }
    
    zend_object_std_dtor(&intern->std);
}

// Create object
static zend_object* qlabel_create_object(zend_class_entry *ce)
{
    qlabel_object *intern = (qlabel_object*)ecalloc(1,
        sizeof(qlabel_object) + zend_object_properties_size(ce));
    
    zend_object_std_init(&intern->std, ce);
    object_properties_init(&intern->std, ce);
    
    intern->std.handlers = &qlabel_object_handlers;
    intern->label = nullptr;
    
    return &intern->std;
}

// Arginfo declarations (PHP 8+)
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QLabel___construct, 0, 0, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, text, IS_STRING, 0, "\"\"")
    ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, parent, Qt\\Widget, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QLabel_setText, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QLabel_show, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QLabel_hide, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QLabel_setGeometry, 0, 4, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QLabel_setStyleSheet, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, styleSheet, IS_STRING, 0)
ZEND_END_ARG_INFO()

// __construct(string $text = "", $parent = null)
PHP_METHOD(QLabel, __construct)
{
    char *text = nullptr;
    size_t text_len = 0;
    zval *parent = nullptr;
    
    ZEND_PARSE_PARAMETERS_START(0, 2)
        Z_PARAM_OPTIONAL
        Z_PARAM_STRING(text, text_len)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent, qwidget_ce)
    ZEND_PARSE_PARAMETERS_END();
    
    qlabel_object *intern = Z_QLABEL_OBJ_P(ZEND_THIS);
    
    QWidget *parent_widget = nullptr;
    if (parent) {
        qwidget_object *parent_obj = Z_QWIDGET_OBJ_P(parent);
        parent_widget = parent_obj->widget;
    }
    
    if (text) {
        intern->label = new QLabel(QString::fromUtf8(text, text_len), parent_widget);
    } else {
        intern->label = new QLabel(parent_widget);
    }
}

// setText(string $text) : void
PHP_METHOD(QLabel, setText)
{
    char *text;
    size_t text_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qlabel_object *intern = Z_QLABEL_OBJ_P(ZEND_THIS);
    if (intern->label) {
        intern->label->setText(QString::fromUtf8(text, text_len));
    }
}

// show() : void
PHP_METHOD(QLabel, show)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qlabel_object *intern = Z_QLABEL_OBJ_P(ZEND_THIS);
    if (intern->label) {
        intern->label->show();
    }
}

// hide() : void
PHP_METHOD(QLabel, hide)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qlabel_object *intern = Z_QLABEL_OBJ_P(ZEND_THIS);
    if (intern->label) {
        intern->label->hide();
    }
}

// setGeometry(int $x, int $y, int $width, int $height) : void
PHP_METHOD(QLabel, setGeometry)
{
    zend_long x, y, width, height;
    
    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_LONG(x)
        Z_PARAM_LONG(y)
        Z_PARAM_LONG(width)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();
    
    qlabel_object *intern = Z_QLABEL_OBJ_P(ZEND_THIS);
    if (intern->label) {
        intern->label->setGeometry(x, y, width, height);
    }
}

// setStyleSheet(string $styleSheet) : void
PHP_METHOD(QLabel, setStyleSheet)
{
    char *stylesheet;
    size_t stylesheet_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(stylesheet, stylesheet_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qlabel_object *intern = Z_QLABEL_OBJ_P(ZEND_THIS);
    if (intern->label) {
        intern->label->setStyleSheet(QString::fromUtf8(stylesheet, stylesheet_len));
    }
}

// Method entries
static const zend_function_entry qlabel_methods[] = {
    PHP_ME(QLabel, __construct, arginfo_class_QLabel___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QLabel, setText, arginfo_class_QLabel_setText, ZEND_ACC_PUBLIC)
    PHP_ME(QLabel, show, arginfo_class_QLabel_show, ZEND_ACC_PUBLIC)
    PHP_ME(QLabel, hide, arginfo_class_QLabel_hide, ZEND_ACC_PUBLIC)
    PHP_ME(QLabel, setGeometry, arginfo_class_QLabel_setGeometry, ZEND_ACC_PUBLIC)
    PHP_ME(QLabel, setStyleSheet, arginfo_class_QLabel_setStyleSheet, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

// Initialize class
void qlabel_init(INIT_FUNC_ARGS)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\Label", qlabel_methods);
    qlabel_ce = zend_register_internal_class(&ce);
    qlabel_ce->create_object = qlabel_create_object;
    
    memcpy(&qlabel_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    qlabel_object_handlers.offset = XtOffsetOf(qlabel_object, std);
    qlabel_object_handlers.free_obj = qlabel_free_object;
}
