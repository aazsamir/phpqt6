#include "php_qt6.h"
#include <QLayout>

// Class entry is declared as extern in php_qt6.h and defined in php_qt6.cpp
zend_object_handlers qt_object_handlers_QLayout;

// QLayout is an abstract base class in Qt
// Most methods will be in derived classes like QVBoxLayout, QHBoxLayout, QGridLayout

// void setSpacing(int $spacing)
PHP_METHOD(QLayout, setSpacing) {
    zend_long spacing;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(spacing)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QLayout *layout = static_cast<QLayout*>(intern->ptr);
    layout->setSpacing(spacing);
}

// void setContentsMargins(int $left, int $top, int $right, int $bottom)
PHP_METHOD(QLayout, setContentsMargins) {
    zend_long left, top, right, bottom;
    
    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_LONG(left)
        Z_PARAM_LONG(top)
        Z_PARAM_LONG(right)
        Z_PARAM_LONG(bottom)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QLayout *layout = static_cast<QLayout*>(intern->ptr);
    layout->setContentsMargins(left, top, right, bottom);
}

// Method entries
static const zend_function_entry qt_QLayout_methods[] = {
    PHP_ME(QLayout, setSpacing, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(QLayout, setContentsMargins, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QLayout_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\Layout", qt_QLayout_methods);
    qt_ce_QLayout = zend_register_internal_class_ex(&ce, qt_ce_QObject);
    qt_ce_QLayout->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QLayout, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QLayout.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QLayout.free_obj = qt_object_free;
}
