#include "php_qt6.h"

// Object handlers
static zend_object_handlers qmainwindow_object_handlers;

// Free object
static void qmainwindow_free_object(zend_object *object)
{
    qmainwindow_object *intern = qmainwindow_fetch_object(object);
    
    if (intern->window) {
        intern->window->deleteLater();
        intern->window = nullptr;
    }
    
    zend_object_std_dtor(&intern->std);
}

// Create object
static zend_object* qmainwindow_create_object(zend_class_entry *ce)
{
    qmainwindow_object *intern = (qmainwindow_object*)ecalloc(1,
        sizeof(qmainwindow_object) + zend_object_properties_size(ce));
    
    zend_object_std_init(&intern->std, ce);
    object_properties_init(&intern->std, ce);
    
    intern->std.handlers = &qmainwindow_object_handlers;
    intern->window = nullptr;
    
    return &intern->std;
}

// Arginfo declarations (PHP 8+)
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QMainWindow___construct, 0, 0, 0)
    ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, parent, Qt\\Widget, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QMainWindow_show, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QMainWindow_setWindowTitle, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QMainWindow_resize, 0, 2, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QMainWindow_setCentralWidget, 0, 1, IS_VOID, 0)
    ZEND_ARG_OBJ_INFO(0, widget, Qt\\Widget, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QMainWindow_setStyleSheet, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, styleSheet, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QMainWindow_setAttribute, 0, 2, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, attribute, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, on, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

// __construct($parent = null)
PHP_METHOD(QMainWindow, __construct)
{
    zval *parent = nullptr;
    
    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent, qwidget_ce)
    ZEND_PARSE_PARAMETERS_END();
    
    qmainwindow_object *intern = Z_QMAINWINDOW_OBJ_P(ZEND_THIS);
    
    QWidget *parent_widget = nullptr;
    if (parent) {
        qwidget_object *parent_obj = Z_QWIDGET_OBJ_P(parent);
        parent_widget = parent_obj->widget;
    }
    
    intern->window = new QMainWindow(parent_widget);
    
    // Force window to have native decorations with explicit window flags
    intern->window->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | 
                                   Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | 
                                   Qt::WindowCloseButtonHint);
    intern->window->setAttribute(Qt::WA_NativeWindow, true);
}

// show() : void
PHP_METHOD(QMainWindow, show)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qmainwindow_object *intern = Z_QMAINWINDOW_OBJ_P(ZEND_THIS);
    if (intern->window) {
        intern->window->show();
    }
}

// setWindowTitle(string $title) : void
PHP_METHOD(QMainWindow, setWindowTitle)
{
    char *title;
    size_t title_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(title, title_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qmainwindow_object *intern = Z_QMAINWINDOW_OBJ_P(ZEND_THIS);
    if (intern->window) {
        intern->window->setWindowTitle(QString::fromUtf8(title, title_len));
    }
}

// resize(int $width, int $height) : void
PHP_METHOD(QMainWindow, resize)
{
    zend_long width, height;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(width)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();
    
    qmainwindow_object *intern = Z_QMAINWINDOW_OBJ_P(ZEND_THIS);
    if (intern->window) {
        intern->window->resize(width, height);
    }
}

// setCentralWidget(QWidget $widget) : void
PHP_METHOD(QMainWindow, setCentralWidget)
{
    zval *widget;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(widget, qwidget_ce)
    ZEND_PARSE_PARAMETERS_END();
    
    qmainwindow_object *intern = Z_QMAINWINDOW_OBJ_P(ZEND_THIS);
    qwidget_object *widget_obj = Z_QWIDGET_OBJ_P(widget);
    
    if (intern->window && widget_obj->widget) {
        intern->window->setCentralWidget(widget_obj->widget);
    }
}

// setStyleSheet(string $styleSheet) : void
PHP_METHOD(QMainWindow, setStyleSheet)
{
    char *stylesheet;
    size_t stylesheet_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(stylesheet, stylesheet_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qmainwindow_object *intern = Z_QMAINWINDOW_OBJ_P(ZEND_THIS);
    if (intern->window) {
        intern->window->setStyleSheet(QString::fromUtf8(stylesheet, stylesheet_len));
    }
}

// setAttribute(int $attribute, bool $on) : void
PHP_METHOD(QMainWindow, setAttribute)
{
    zend_long attribute;
    zend_bool on;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(attribute)
        Z_PARAM_BOOL(on)
    ZEND_PARSE_PARAMETERS_END();
    
    qmainwindow_object *intern = Z_QMAINWINDOW_OBJ_P(ZEND_THIS);
    if (intern->window) {
        intern->window->setAttribute(static_cast<Qt::WidgetAttribute>(attribute), on);
    }
}

// Method entries
static const zend_function_entry qmainwindow_methods[] = {
    PHP_ME(QMainWindow, __construct, arginfo_class_QMainWindow___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QMainWindow, show, arginfo_class_QMainWindow_show, ZEND_ACC_PUBLIC)
    PHP_ME(QMainWindow, setWindowTitle, arginfo_class_QMainWindow_setWindowTitle, ZEND_ACC_PUBLIC)
    PHP_ME(QMainWindow, resize, arginfo_class_QMainWindow_resize, ZEND_ACC_PUBLIC)
    PHP_ME(QMainWindow, setCentralWidget, arginfo_class_QMainWindow_setCentralWidget, ZEND_ACC_PUBLIC)
    PHP_ME(QMainWindow, setStyleSheet, arginfo_class_QMainWindow_setStyleSheet, ZEND_ACC_PUBLIC)
    PHP_ME(QMainWindow, setAttribute, arginfo_class_QMainWindow_setAttribute, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

// Initialize class
void qmainwindow_init(INIT_FUNC_ARGS)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\MainWindow", qmainwindow_methods);
    qmainwindow_ce = zend_register_internal_class(&ce);
    qmainwindow_ce->create_object = qmainwindow_create_object;
    
    memcpy(&qmainwindow_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    qmainwindow_object_handlers.offset = XtOffsetOf(qmainwindow_object, std);
    qmainwindow_object_handlers.free_obj = qmainwindow_free_object;
}
