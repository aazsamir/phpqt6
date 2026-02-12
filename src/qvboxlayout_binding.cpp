#include "php_qt6.h"
#include <QVBoxLayout>

// Object handlers
static zend_object_handlers qvboxlayout_object_handlers;

// Free object
static void qvboxlayout_free_object(zend_object *object)
{
    qvboxlayout_object *intern = qvboxlayout_fetch_object(object);
    
    // Qt manages layout lifetime through parent widget
    intern->layout = nullptr;
    
    zend_object_std_dtor(&intern->std);
}

// Create object
static zend_object* qvboxlayout_create_object(zend_class_entry *ce)
{
    qvboxlayout_object *intern = (qvboxlayout_object*)ecalloc(1,
        sizeof(qvboxlayout_object) + zend_object_properties_size(ce));
    
    zend_object_std_init(&intern->std, ce);
    object_properties_init(&intern->std, ce);
    
    intern->std.handlers = &qvboxlayout_object_handlers;
    intern->layout = nullptr;
    
    return &intern->std;
}

// Arginfo
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QVBoxLayout___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QVBoxLayout_addWidget, 0, 1, IS_VOID, 0)
    ZEND_ARG_INFO(0, widget)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, stretch, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QVBoxLayout_addStretch, 0, 0, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, stretch, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QVBoxLayout_addSpacing, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QVBoxLayout_setSpacing, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QVBoxLayout_setContentsMargins, 0, 4, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, left, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, top, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, right, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, bottom, IS_LONG, 0)
ZEND_END_ARG_INFO()

// __construct()
PHP_METHOD(QVBoxLayout, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qvboxlayout_object *intern = Z_QVBOXLAYOUT_OBJ_P(ZEND_THIS);
    intern->layout = new QVBoxLayout();
}

// addWidget(Widget $widget, int $stretch = 0)
PHP_METHOD(QVBoxLayout, addWidget)
{
    zval *widget_zval;
    zend_long stretch = 0;
    
    ZEND_PARSE_PARAMETERS_START(1, 2)
        Z_PARAM_OBJECT(widget_zval)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(stretch)
    ZEND_PARSE_PARAMETERS_END();
    
    qvboxlayout_object *intern = Z_QVBOXLAYOUT_OBJ_P(ZEND_THIS);
    
    if (!intern->layout) {
        return;
    }
    
    // Check for different widget types
    QWidget *qwidget = nullptr;
    
    if (instanceof_function(Z_OBJCE_P(widget_zval), qwidget_ce)) {
        qwidget_object *widget_obj = Z_QWIDGET_OBJ_P(widget_zval);
        qwidget = widget_obj->widget;
    } else if (instanceof_function(Z_OBJCE_P(widget_zval), qlabel_ce)) {
        qlabel_object *label_obj = Z_QLABEL_OBJ_P(widget_zval);
        qwidget = label_obj->label;
    } else if (instanceof_function(Z_OBJCE_P(widget_zval), qpushbutton_ce)) {
        qpushbutton_object *btn_obj = Z_QPUSHBUTTON_OBJ_P(widget_zval);
        qwidget = btn_obj->button;
    } else if (instanceof_function(Z_OBJCE_P(widget_zval), qlineedit_ce)) {
        qlineedit_object *edit_obj = Z_QLINEEDIT_OBJ_P(widget_zval);
        qwidget = edit_obj->lineedit;
    }
    
    if (qwidget) {
        intern->layout->addWidget(qwidget, stretch);
    }
}

// addStretch(int $stretch = 0)
PHP_METHOD(QVBoxLayout, addStretch)
{
    zend_long stretch = 0;
    
    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(stretch)
    ZEND_PARSE_PARAMETERS_END();
    
    qvboxlayout_object *intern = Z_QVBOXLAYOUT_OBJ_P(ZEND_THIS);
    
    if (intern->layout) {
        intern->layout->addStretch(stretch);
    }
}

// addSpacing(int $size)
PHP_METHOD(QVBoxLayout, addSpacing)
{
    zend_long size;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(size)
    ZEND_PARSE_PARAMETERS_END();
    
    qvboxlayout_object *intern = Z_QVBOXLAYOUT_OBJ_P(ZEND_THIS);
    
    if (intern->layout) {
        intern->layout->addSpacing(size);
    }
}

// setSpacing(int $spacing)
PHP_METHOD(QVBoxLayout, setSpacing)
{
    zend_long spacing;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(spacing)
    ZEND_PARSE_PARAMETERS_END();
    
    qvboxlayout_object *intern = Z_QVBOXLAYOUT_OBJ_P(ZEND_THIS);
    
    if (intern->layout) {
        intern->layout->setSpacing(spacing);
    }
}

// setContentsMargins(int $left, int $top, int $right, int $bottom)
PHP_METHOD(QVBoxLayout, setContentsMargins)
{
    zend_long left, top, right, bottom;
    
    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_LONG(left)
        Z_PARAM_LONG(top)
        Z_PARAM_LONG(right)
        Z_PARAM_LONG(bottom)
    ZEND_PARSE_PARAMETERS_END();
    
    qvboxlayout_object *intern = Z_QVBOXLAYOUT_OBJ_P(ZEND_THIS);
    
    if (intern->layout) {
        intern->layout->setContentsMargins(left, top, right, bottom);
    }
}

// Method entries
static const zend_function_entry qvboxlayout_methods[] = {
    PHP_ME(QVBoxLayout, __construct, arginfo_class_QVBoxLayout___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QVBoxLayout, addWidget, arginfo_class_QVBoxLayout_addWidget, ZEND_ACC_PUBLIC)
    PHP_ME(QVBoxLayout, addStretch, arginfo_class_QVBoxLayout_addStretch, ZEND_ACC_PUBLIC)
    PHP_ME(QVBoxLayout, addSpacing, arginfo_class_QVBoxLayout_addSpacing, ZEND_ACC_PUBLIC)
    PHP_ME(QVBoxLayout, setSpacing, arginfo_class_QVBoxLayout_setSpacing, ZEND_ACC_PUBLIC)
    PHP_ME(QVBoxLayout, setContentsMargins, arginfo_class_QVBoxLayout_setContentsMargins, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

// Initialize class
void qvboxlayout_init(INIT_FUNC_ARGS)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\VBoxLayout", qvboxlayout_methods);
    qvboxlayout_ce = zend_register_internal_class(&ce);
    qvboxlayout_ce->create_object = qvboxlayout_create_object;
    
    memcpy(&qvboxlayout_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    qvboxlayout_object_handlers.offset = XtOffsetOf(qvboxlayout_object, std);
    qvboxlayout_object_handlers.free_obj = qvboxlayout_free_object;
}
