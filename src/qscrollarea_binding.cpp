#include "php_qt6.h"
#include <QScrollArea>

zend_class_entry *qt_ce_QScrollArea;
zend_object_handlers qt_object_handlers_QScrollArea;

// Arginfo declarations
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QScrollArea___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QScrollArea_setWidget, 0, 1, IS_VOID, 0)
    ZEND_ARG_OBJ_INFO(0, widget, Qt\\Widget, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QScrollArea_setWidgetResizable, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, resizable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

// Constructor: new ScrollArea()
PHP_METHOD(QScrollArea, __construct) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QScrollArea();
}

// void setWidget(Widget $widget)
PHP_METHOD(QScrollArea, setWidget) {
    zval *widget_zval;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(widget_zval, qt_ce_QWidget)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    qt_object *widget_obj = Z_QT_OBJ_P(widget_zval);
    
    QScrollArea *scrollArea = static_cast<QScrollArea*>(intern->ptr);
    QWidget *widget = static_cast<QWidget*>(widget_obj->ptr);
    scrollArea->setWidget(widget);
}

// void setWidgetResizable(bool $resizable)
PHP_METHOD(QScrollArea, setWidgetResizable) {
    zend_bool resizable;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(resizable)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QScrollArea *scrollArea = static_cast<QScrollArea*>(intern->ptr);
    scrollArea->setWidgetResizable(resizable);
}

// Method entries
static const zend_function_entry qt_QScrollArea_methods[] = {
    PHP_ME(QScrollArea, __construct, arginfo_class_QScrollArea___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QScrollArea, setWidget, arginfo_class_QScrollArea_setWidget, ZEND_ACC_PUBLIC)
    PHP_ME(QScrollArea, setWidgetResizable, arginfo_class_QScrollArea_setWidgetResizable, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QScrollArea_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\ScrollArea", qt_QScrollArea_methods);
    qt_ce_QScrollArea = zend_register_internal_class_ex(&ce, qt_ce_QWidget);
    qt_ce_QScrollArea->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QScrollArea, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QScrollArea.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QScrollArea.free_obj = qt_object_free;
}
