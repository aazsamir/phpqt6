#include "php_qt6.h"
#include <QSplitter>

zend_class_entry *qt_ce_QSplitter;
zend_object_handlers qt_object_handlers_QSplitter;

// Arginfo declarations
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QSplitter___construct, 0, 0, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, orientation, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSplitter_addWidget, 0, 1, IS_VOID, 0)
    ZEND_ARG_OBJ_INFO(0, widget, Qt\\Widget, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSplitter_insertWidget, 0, 2, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
    ZEND_ARG_OBJ_INFO(0, widget, Qt\\Widget, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSplitter_setOrientation, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, orientation, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSplitter_count, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSplitter_setSizes, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, sizes, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

// Constructor: new Splitter(int $orientation = Qt::Horizontal)
PHP_METHOD(QSplitter, __construct) {
    zend_long orientation = Qt::Horizontal;
    
    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(orientation)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QSplitter(static_cast<Qt::Orientation>(orientation));
}

// void addWidget(Widget $widget)
PHP_METHOD(QSplitter, addWidget) {
    zval *widget_zval;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(widget_zval, qt_ce_QWidget)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    qt_object *widget_obj = Z_QT_OBJ_P(widget_zval);
    
    QSplitter *splitter = static_cast<QSplitter*>(intern->ptr);
    QWidget *widget = static_cast<QWidget*>(widget_obj->ptr);
    splitter->addWidget(widget);
}

// void insertWidget(int $index, Widget $widget)
PHP_METHOD(QSplitter, insertWidget) {
    zend_long index;
    zval *widget_zval;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(index)
        Z_PARAM_OBJECT_OF_CLASS(widget_zval, qt_ce_QWidget)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    qt_object *widget_obj = Z_QT_OBJ_P(widget_zval);
    
    QSplitter *splitter = static_cast<QSplitter*>(intern->ptr);
    QWidget *widget = static_cast<QWidget*>(widget_obj->ptr);
    splitter->insertWidget(index, widget);
}

// void setOrientation(int $orientation)
PHP_METHOD(QSplitter, setOrientation) {
    zend_long orientation;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(orientation)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QSplitter *splitter = static_cast<QSplitter*>(intern->ptr);
    splitter->setOrientation(static_cast<Qt::Orientation>(orientation));
}

// int count()
PHP_METHOD(QSplitter, count) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QSplitter *splitter = static_cast<QSplitter*>(intern->ptr);
    RETURN_LONG(splitter->count());
}

// void setSizes(array $sizes)
PHP_METHOD(QSplitter, setSizes) {
    zval *sizes_array;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(sizes_array)
    ZEND_PARSE_PARAMETERS_END();
    
    QList<int> sizes;
    zval *item;
    ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(sizes_array), item) {
        convert_to_long(item);
        sizes.append(Z_LVAL_P(item));
    } ZEND_HASH_FOREACH_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QSplitter *splitter = static_cast<QSplitter*>(intern->ptr);
    splitter->setSizes(sizes);
}

// Method entries
static const zend_function_entry qt_QSplitter_methods[] = {
    PHP_ME(QSplitter, __construct, arginfo_class_QSplitter___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QSplitter, addWidget, arginfo_class_QSplitter_addWidget, ZEND_ACC_PUBLIC)
    PHP_ME(QSplitter, insertWidget, arginfo_class_QSplitter_insertWidget, ZEND_ACC_PUBLIC)
    PHP_ME(QSplitter, setOrientation, arginfo_class_QSplitter_setOrientation, ZEND_ACC_PUBLIC)
    PHP_ME(QSplitter, count, arginfo_class_QSplitter_count, ZEND_ACC_PUBLIC)
    PHP_ME(QSplitter, setSizes, arginfo_class_QSplitter_setSizes, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QSplitter_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\Splitter", qt_QSplitter_methods);
    qt_ce_QSplitter = zend_register_internal_class_ex(&ce, qt_ce_QWidget);
    qt_ce_QSplitter->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QSplitter, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QSplitter.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QSplitter.free_obj = qt_object_free;
}
