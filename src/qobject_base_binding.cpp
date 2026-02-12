#include "php_qt6.h"
#include <QObject>

// Class entry is declared as extern in php_qt6.h and defined in php_qt6.cpp
zend_object_handlers qt_object_handlers_QObject;

// QObject is typically not instantiated directly in Qt
// This is a base class for other Qt objects

// Method entries (empty for now, can add common methods later)
static const zend_function_entry qt_QObject_methods[] = {
    PHP_FE_END
};

void qt_register_QObject_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\Object", qt_QObject_methods);
    qt_ce_QObject = zend_register_internal_class(&ce);
    qt_ce_QObject->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QObject, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QObject.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QObject.free_obj = qt_object_free;
}
