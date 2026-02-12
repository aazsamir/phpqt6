#include "php_qt6.h"

// Object handlers
static zend_object_handlers qwidget_object_handlers;

// Free object
static void qwidget_free_object(zend_object *object)
{
    qwidget_object *intern = qwidget_fetch_object(object);
    
    // Use deleteLater() for safe Qt cleanup
    if (intern->widget) {
        intern->widget->deleteLater();
        intern->widget = nullptr;
    }
    
    zend_object_std_dtor(&intern->std);
}

// Create object
static zend_object* qwidget_create_object(zend_class_entry *ce)
{
    qwidget_object *intern = (qwidget_object*)ecalloc(1,
        sizeof(qwidget_object) + zend_object_properties_size(ce));
    
    zend_object_std_init(&intern->std, ce);
    object_properties_init(&intern->std, ce);
    
    intern->std.handlers = &qwidget_object_handlers;
    intern->widget = nullptr;
    
    return &intern->std;
}

// Arginfo declarations (PHP 8+)
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QWidget___construct, 0, 0, 0)
    ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, parent, Qt\\Widget, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QWidget_show, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_QWidget_hide arginfo_class_QWidget_show

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QWidget_setWindowTitle, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QWidget_resize, 0, 2, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QWidget_move, 0, 2, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QWidget_setStyleSheet, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, styleSheet, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QWidget_setGeometry, 0, 4, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QWidget_setLayout, 0, 1, IS_VOID, 0)
    ZEND_ARG_OBJ_TYPE_MASK(0, layout, Qt\\VBoxLayout|Qt\\HBoxLayout, 0, NULL)
ZEND_END_ARG_INFO()

// __construct($parent = null)
PHP_METHOD(QWidget, __construct)
{
    zval *parent = nullptr;
    
    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent, qwidget_ce)
    ZEND_PARSE_PARAMETERS_END();
    
    qwidget_object *intern = Z_QWIDGET_OBJ_P(ZEND_THIS);
    
    QWidget *parent_widget = nullptr;
    if (parent) {
        qwidget_object *parent_obj = Z_QWIDGET_OBJ_P(parent);
        parent_widget = parent_obj->widget;
    }
    
    intern->widget = new QWidget(parent_widget);
}

// show() : void
PHP_METHOD(QWidget, show)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qwidget_object *intern = Z_QWIDGET_OBJ_P(ZEND_THIS);
    if (intern->widget) {
        intern->widget->show();
    }
}

// hide() : void
PHP_METHOD(QWidget, hide)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qwidget_object *intern = Z_QWIDGET_OBJ_P(ZEND_THIS);
    if (intern->widget) {
        intern->widget->hide();
    }
}

// setWindowTitle(string $title) : void
PHP_METHOD(QWidget, setWindowTitle)
{
    char *title;
    size_t title_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(title, title_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qwidget_object *intern = Z_QWIDGET_OBJ_P(ZEND_THIS);
    if (intern->widget) {
        intern->widget->setWindowTitle(QString::fromUtf8(title, title_len));
    }
}

// resize(int $width, int $height) : void
PHP_METHOD(QWidget, resize)
{
    zend_long width, height;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(width)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();
    
    qwidget_object *intern = Z_QWIDGET_OBJ_P(ZEND_THIS);
    if (intern->widget) {
        intern->widget->resize(width, height);
    }
}

// move(int $x, int $y) : void
PHP_METHOD(QWidget, move)
{
    zend_long x, y;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(x)
        Z_PARAM_LONG(y)
    ZEND_PARSE_PARAMETERS_END();
    
    qwidget_object *intern = Z_QWIDGET_OBJ_P(ZEND_THIS);
    if (intern->widget) {
        intern->widget->move(x, y);
    }
}

// setStyleSheet(string $styleSheet) : void
PHP_METHOD(QWidget, setStyleSheet)
{
    char *stylesheet;
    size_t stylesheet_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(stylesheet, stylesheet_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qwidget_object *intern = Z_QWIDGET_OBJ_P(ZEND_THIS);
    if (intern->widget) {
        intern->widget->setStyleSheet(QString::fromUtf8(stylesheet, stylesheet_len));
    }
}

// setGeometry(int $x, int $y, int $width, int $height) : void
PHP_METHOD(QWidget, setGeometry)
{
    zend_long x, y, width, height;
    
    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_LONG(x)
        Z_PARAM_LONG(y)
        Z_PARAM_LONG(width)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();
    
    qwidget_object *intern = Z_QWIDGET_OBJ_P(ZEND_THIS);
    if (intern->widget) {
        intern->widget->setGeometry(x, y, width, height);
    }
}

// setLayout(VBoxLayout|HBoxLayout $layout)
PHP_METHOD(QWidget, setLayout)
{
    zval *layout_zval;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT(layout_zval)
    ZEND_PARSE_PARAMETERS_END();
    
    qwidget_object *intern = Z_QWIDGET_OBJ_P(ZEND_THIS);
    
    if (!intern->widget) {
        return;
    }
    
    // Check if it's VBoxLayout
    if (instanceof_function(Z_OBJCE_P(layout_zval), qvboxlayout_ce)) {
        qvboxlayout_object *layout_obj = Z_QVBOXLAYOUT_OBJ_P(layout_zval);
        if (layout_obj->layout) {
            intern->widget->setLayout(layout_obj->layout);
        }
    }
    // Check if it's HBoxLayout
    else if (instanceof_function(Z_OBJCE_P(layout_zval), qhboxlayout_ce)) {
        qhboxlayout_object *layout_obj = Z_QHBOXLAYOUT_OBJ_P(layout_zval);
        if (layout_obj->layout) {
            intern->widget->setLayout(layout_obj->layout);
        }
    }
}

// Method entries
static const zend_function_entry qwidget_methods[] = {
    PHP_ME(QWidget, __construct, arginfo_class_QWidget___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QWidget, show, arginfo_class_QWidget_show, ZEND_ACC_PUBLIC)
    PHP_ME(QWidget, hide, arginfo_class_QWidget_hide, ZEND_ACC_PUBLIC)
    PHP_ME(QWidget, setWindowTitle, arginfo_class_QWidget_setWindowTitle, ZEND_ACC_PUBLIC)
    PHP_ME(QWidget, resize, arginfo_class_QWidget_resize, ZEND_ACC_PUBLIC)
    PHP_ME(QWidget, move, arginfo_class_QWidget_move, ZEND_ACC_PUBLIC)
    PHP_ME(QWidget, setStyleSheet, arginfo_class_QWidget_setStyleSheet, ZEND_ACC_PUBLIC)
    PHP_ME(QWidget, setGeometry, arginfo_class_QWidget_setGeometry, ZEND_ACC_PUBLIC)
    PHP_ME(QWidget, setLayout, arginfo_class_QWidget_setLayout, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

// Initialize class
void qwidget_init(INIT_FUNC_ARGS)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\Widget", qwidget_methods);
    qwidget_ce = zend_register_internal_class(&ce);
    qwidget_ce->create_object = qwidget_create_object;
    
    memcpy(&qwidget_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    qwidget_object_handlers.offset = XtOffsetOf(qwidget_object, std);
    qwidget_object_handlers.free_obj = qwidget_free_object;
}
