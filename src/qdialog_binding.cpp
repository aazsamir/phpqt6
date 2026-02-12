#include "php_qt6.h"
#include <QDialog>

zend_class_entry *qt_ce_QDialog;
zend_object_handlers qt_object_handlers_QDialog;

// Arginfo
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QDialog___construct, 0, 0, 0)
    ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, parent, Qt\\Widget, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QDialog_exec, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QDialog_accept, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_QDialog_reject arginfo_class_QDialog_accept

// Constructor: new Dialog(Widget $parent = null)
PHP_METHOD(QDialog, __construct) {
    zval *parent_zval = NULL;
    
    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent_zval, qt_ce_QWidget)
    ZEND_PARSE_PARAMETERS_END();
    
    QWidget *parent = NULL;
    if (parent_zval && Z_TYPE_P(parent_zval) == IS_OBJECT) {
        qt_object *parent_obj = Z_QT_OBJ_P(parent_zval);
        parent = static_cast<QWidget*>(parent_obj->ptr);
    }
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QDialog(parent);
}

// int exec()
PHP_METHOD(QDialog, exec) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QDialog *dialog = static_cast<QDialog*>(intern->ptr);
    RETURN_LONG(dialog->exec());
}

// void accept()
PHP_METHOD(QDialog, accept) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QDialog *dialog = static_cast<QDialog*>(intern->ptr);
    dialog->accept();
}

// void reject()
PHP_METHOD(QDialog, reject) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QDialog *dialog = static_cast<QDialog*>(intern->ptr);
    dialog->reject();
}

// Method entries
static const zend_function_entry qt_QDialog_methods[] = {
    PHP_ME(QDialog, __construct, arginfo_class_QDialog___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QDialog, exec, arginfo_class_QDialog_exec, ZEND_ACC_PUBLIC)
    PHP_ME(QDialog, accept, arginfo_class_QDialog_accept, ZEND_ACC_PUBLIC)
    PHP_ME(QDialog, reject, arginfo_class_QDialog_reject, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QDialog_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\Dialog", qt_QDialog_methods);
    qt_ce_QDialog = zend_register_internal_class_ex(&ce, qt_ce_QWidget);
    qt_ce_QDialog->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QDialog, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QDialog.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QDialog.free_obj = qt_object_free;
}
