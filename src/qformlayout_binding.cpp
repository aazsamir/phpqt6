#include "php_qt6.h"
#include <QFormLayout>

zend_class_entry *qt_ce_QFormLayout;
zend_object_handlers qt_object_handlers_QFormLayout;

// Arginfo declarations
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QFormLayout___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QFormLayout_addRow, 0, 2, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
    ZEND_ARG_OBJ_INFO(0, field, Qt\\Widget, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QFormLayout_addRowWidget, 0, 1, IS_VOID, 0)
    ZEND_ARG_OBJ_INFO(0, widget, Qt\\Widget, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QFormLayout_setSpacing, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

// Constructor: new FormLayout()
PHP_METHOD(QFormLayout, __construct) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QFormLayout();
}

// void addRow(string $label, QWidget $field)
PHP_METHOD(QFormLayout, addRow) {
    char *label;
    size_t label_len;
    zval *field_zval;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STRING(label, label_len)
        Z_PARAM_OBJECT_OF_CLASS(field_zval, qt_ce_QWidget)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    qt_object *field_obj = Z_QT_OBJ_P(field_zval);
    
    QFormLayout *layout = static_cast<QFormLayout*>(intern->ptr);
    QWidget *field = static_cast<QWidget*>(field_obj->ptr);
    layout->addRow(QString::fromUtf8(label, label_len), field);
}

// void addRowWidget(Widget $widget)
PHP_METHOD(QFormLayout, addRowWidget) {
    zval *widget_zval;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(widget_zval, qt_ce_QWidget)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    qt_object *widget_obj = Z_QT_OBJ_P(widget_zval);
    
    QFormLayout *layout = static_cast<QFormLayout*>(intern->ptr);
    QWidget *widget = static_cast<QWidget*>(widget_obj->ptr);
    layout->addRow(widget);
}

// void setSpacing(int $spacing)
PHP_METHOD(QFormLayout, setSpacing) {
    zend_long spacing;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(spacing)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QFormLayout *layout = static_cast<QFormLayout*>(intern->ptr);
    layout->setSpacing(spacing);
}

// Method entries
static const zend_function_entry qt_QFormLayout_methods[] = {
    PHP_ME(QFormLayout, __construct, arginfo_class_QFormLayout___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QFormLayout, addRow, arginfo_class_QFormLayout_addRow, ZEND_ACC_PUBLIC)
    PHP_ME(QFormLayout, addRowWidget, arginfo_class_QFormLayout_addRowWidget, ZEND_ACC_PUBLIC)
    PHP_ME(QFormLayout, setSpacing, arginfo_class_QFormLayout_setSpacing, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QFormLayout_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\FormLayout", qt_QFormLayout_methods);
    qt_ce_QFormLayout = zend_register_internal_class_ex(&ce, qt_ce_QLayout);
    qt_ce_QFormLayout->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QFormLayout, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QFormLayout.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QFormLayout.free_obj = qt_object_free;
}
