#include "php_qt6.h"
#include <QGridLayout>

zend_class_entry *qt_ce_QGridLayout;
zend_object_handlers qt_object_handlers_QGridLayout;

// Arginfo declarations
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QGridLayout___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QGridLayout_addWidget, 0, 3, IS_VOID, 0)
    ZEND_ARG_OBJ_INFO(0, widget, Qt\\Widget, 0)
    ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, rowSpan, IS_LONG, 0, "1")
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, columnSpan, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QGridLayout_addLayout, 0, 3, IS_VOID, 0)
    ZEND_ARG_OBJ_INFO(0, layout, Qt\\Layout, 0)
    ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, rowSpan, IS_LONG, 0, "1")
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, columnSpan, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QGridLayout_setSpacing, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QGridLayout_setRowStretch, 0, 2, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, stretch, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QGridLayout_setColumnStretch, 0, 2, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, stretch, IS_LONG, 0)
ZEND_END_ARG_INFO()

// Constructor: new GridLayout()
PHP_METHOD(QGridLayout, __construct) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QGridLayout();
}

// void addWidget(Widget $widget, int $row, int $column, int $rowSpan = 1, int $columnSpan = 1)
PHP_METHOD(QGridLayout, addWidget) {
    zval *widget_zval;
    zend_long row, column, rowSpan = 1, columnSpan = 1;
    
    ZEND_PARSE_PARAMETERS_START(3, 5)
        Z_PARAM_OBJECT_OF_CLASS(widget_zval, qt_ce_QWidget)
        Z_PARAM_LONG(row)
        Z_PARAM_LONG(column)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(rowSpan)
        Z_PARAM_LONG(columnSpan)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    qt_object *widget_obj = Z_QT_OBJ_P(widget_zval);
    
    QGridLayout *layout = static_cast<QGridLayout*>(intern->ptr);
    QWidget *widget = static_cast<QWidget*>(widget_obj->ptr);
    layout->addWidget(widget, row, column, rowSpan, columnSpan);
}

// void addLayout(Layout $layout, int $row, int $column, int $rowSpan = 1, int $columnSpan = 1)
PHP_METHOD(QGridLayout, addLayout) {
    zval *layout_zval;
    zend_long row, column, rowSpan = 1, columnSpan = 1;
    
    ZEND_PARSE_PARAMETERS_START(3, 5)
        Z_PARAM_OBJECT_OF_CLASS(layout_zval, qt_ce_QLayout)
        Z_PARAM_LONG(row)
        Z_PARAM_LONG(column)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(rowSpan)
        Z_PARAM_LONG(columnSpan)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    qt_object *layout_obj = Z_QT_OBJ_P(layout_zval);
    
    QGridLayout *gridLayout = static_cast<QGridLayout*>(intern->ptr);
    QLayout *layout = static_cast<QLayout*>(layout_obj->ptr);
    gridLayout->addLayout(layout, row, column, rowSpan, columnSpan);
}

// void setSpacing(int $spacing)
PHP_METHOD(QGridLayout, setSpacing) {
    zend_long spacing;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(spacing)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QGridLayout *layout = static_cast<QGridLayout*>(intern->ptr);
    layout->setSpacing(spacing);
}

// void setRowStretch(int $row, int $stretch)
PHP_METHOD(QGridLayout, setRowStretch) {
    zend_long row, stretch;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(row)
        Z_PARAM_LONG(stretch)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QGridLayout *layout = static_cast<QGridLayout*>(intern->ptr);
    layout->setRowStretch(row, stretch);
}

// void setColumnStretch(int $column, int $stretch)
PHP_METHOD(QGridLayout, setColumnStretch) {
    zend_long column, stretch;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(column)
        Z_PARAM_LONG(stretch)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QGridLayout *layout = static_cast<QGridLayout*>(intern->ptr);
    layout->setColumnStretch(column, stretch);
}

// Method entries
static const zend_function_entry qt_QGridLayout_methods[] = {
    PHP_ME(QGridLayout, __construct, arginfo_class_QGridLayout___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QGridLayout, addWidget, arginfo_class_QGridLayout_addWidget, ZEND_ACC_PUBLIC)
    PHP_ME(QGridLayout, addLayout, arginfo_class_QGridLayout_addLayout, ZEND_ACC_PUBLIC)
    PHP_ME(QGridLayout, setSpacing, arginfo_class_QGridLayout_setSpacing, ZEND_ACC_PUBLIC)
    PHP_ME(QGridLayout, setRowStretch, arginfo_class_QGridLayout_setRowStretch, ZEND_ACC_PUBLIC)
    PHP_ME(QGridLayout, setColumnStretch, arginfo_class_QGridLayout_setColumnStretch, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QGridLayout_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\GridLayout", qt_QGridLayout_methods);
    qt_ce_QGridLayout = zend_register_internal_class_ex(&ce, qt_ce_QLayout);
    qt_ce_QGridLayout->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QGridLayout, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QGridLayout.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QGridLayout.free_obj = qt_object_free;
}
