#include "php_qt6.h"

static zend_object_handlers qwidget_object_handlers;

// Arginfo declarations
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
    ZEND_ARG_OBJ_TYPE_MASK(0, layout, Qt\\VBoxLayout|Qt\\HBoxLayout|Qt\\GridLayout|Qt\\FormLayout, 0, NULL)
ZEND_END_ARG_INFO()

// __construct($parent = null)
PHP_METHOD(QWidget, __construct)
{
    zval *parent = nullptr;
    
    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent, qt_ce_QWidget)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    
    QWidget *parent_widget = nullptr;
    if (parent) {
        qt_object *parent_obj = Z_QT_OBJ_P(parent);
        parent_widget = static_cast<QWidget*>(parent_obj->ptr);
    }
    
    intern->ptr = new QWidget(parent_widget);
}

// show() : void
PHP_METHOD(QWidget, show)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QWidget *widget = static_cast<QWidget*>(intern->ptr);
    if (widget) {
        widget->show();
    }
}

// hide() : void
PHP_METHOD(QWidget, hide)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QWidget *widget = static_cast<QWidget*>(intern->ptr);
    if (widget) {
        widget->hide();
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
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QWidget *widget = static_cast<QWidget*>(intern->ptr);
    if (widget) {
        widget->setWindowTitle(QString::fromUtf8(title, title_len));
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
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QWidget *widget = static_cast<QWidget*>(intern->ptr);
    if (widget) {
        widget->resize(width, height);
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
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QWidget *widget = static_cast<QWidget*>(intern->ptr);
    if (widget) {
        widget->move(x, y);
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
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QWidget *widget = static_cast<QWidget*>(intern->ptr);
    if (widget) {
        widget->setStyleSheet(QString::fromUtf8(stylesheet, stylesheet_len));
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
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QWidget *widget = static_cast<QWidget*>(intern->ptr);
    if (widget) {
        widget->setGeometry(x, y, width, height);
    }
}

// setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout)
PHP_METHOD(QWidget, setLayout)
{
    zval *layout_zval;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT(layout_zval)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QWidget *widget = static_cast<QWidget*>(intern->ptr);
    
    if (!widget) {
        return;
    }
    
    // All layouts now use unified qt_object
    qt_object *layout_obj = Z_QT_OBJ_P(layout_zval);
    QLayout *layout = static_cast<QLayout*>(layout_obj->ptr);
    if (layout) {
        widget->setLayout(layout);
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
void qt_register_QWidget_class()
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\Widget", qwidget_methods);
    qt_ce_QWidget = zend_register_internal_class(&ce);
    qt_ce_QWidget->create_object = qt_object_new;
    
    memcpy(&qwidget_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
    qwidget_object_handlers.offset = XtOffsetOf(qt_object, std);
    qwidget_object_handlers.free_obj = qt_object_free;
}
