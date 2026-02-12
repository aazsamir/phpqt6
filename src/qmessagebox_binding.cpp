#include "php_qt6.h"
#include <QMessageBox>

zend_class_entry *qt_ce_QMessageBox;
zend_object_handlers qt_object_handlers_QMessageBox;

// Arginfo
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QMessageBox_information, 0, 3, IS_VOID, 0)
    ZEND_ARG_OBJ_INFO(0, parent, Qt\\Widget, 1)
    ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_QMessageBox_warning arginfo_class_QMessageBox_information
#define arginfo_class_QMessageBox_critical arginfo_class_QMessageBox_information

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QMessageBox_question, 0, 3, _IS_BOOL, 0)
    ZEND_ARG_OBJ_INFO(0, parent, Qt\\Widget, 1)
    ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

// Static method: void information(Widget $parent, string $title, string $text)
PHP_METHOD(QMessageBox, information) {
    zval *parent_zval = NULL;
    char *title, *text;
    size_t title_len, text_len;
    
    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent_zval, qt_ce_QWidget)
        Z_PARAM_STRING(title, title_len)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    QWidget *parent = NULL;
    if (parent_zval && Z_TYPE_P(parent_zval) == IS_OBJECT) {
        qt_object *parent_obj = Z_QT_OBJ_P(parent_zval);
        parent = static_cast<QWidget*>(parent_obj->ptr);
    }
    
    QMessageBox::information(parent, 
        QString::fromUtf8(title, title_len), 
        QString::fromUtf8(text, text_len));
}

// Static method: void warning(Widget $parent, string $title, string $text)
PHP_METHOD(QMessageBox, warning) {
    zval *parent_zval = NULL;
    char *title, *text;
    size_t title_len, text_len;
    
    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent_zval, qt_ce_QWidget)
        Z_PARAM_STRING(title, title_len)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    QWidget *parent = NULL;
    if (parent_zval && Z_TYPE_P(parent_zval) == IS_OBJECT) {
        qt_object *parent_obj = Z_QT_OBJ_P(parent_zval);
        parent = static_cast<QWidget*>(parent_obj->ptr);
    }
    
    QMessageBox::warning(parent, 
        QString::fromUtf8(title, title_len), 
        QString::fromUtf8(text, text_len));
}

// Static method: void critical(Widget $parent, string $title, string $text)
PHP_METHOD(QMessageBox, critical) {
    zval *parent_zval = NULL;
    char *title, *text;
    size_t title_len, text_len;
    
    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent_zval, qt_ce_QWidget)
        Z_PARAM_STRING(title, title_len)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    QWidget *parent = NULL;
    if (parent_zval && Z_TYPE_P(parent_zval) == IS_OBJECT) {
        qt_object *parent_obj = Z_QT_OBJ_P(parent_zval);
        parent = static_cast<QWidget*>(parent_obj->ptr);
    }
    
    QMessageBox::critical(parent, 
        QString::fromUtf8(title, title_len), 
        QString::fromUtf8(text, text_len));
}

// Static method: bool question(Widget $parent, string $title, string $text)
PHP_METHOD(QMessageBox, question) {
    zval *parent_zval = NULL;
    char *title, *text;
    size_t title_len, text_len;
    
    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent_zval, qt_ce_QWidget)
        Z_PARAM_STRING(title, title_len)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    QWidget *parent = NULL;
    if (parent_zval && Z_TYPE_P(parent_zval) == IS_OBJECT) {
        qt_object *parent_obj = Z_QT_OBJ_P(parent_zval);
        parent = static_cast<QWidget*>(parent_obj->ptr);
    }
    
    QMessageBox::StandardButton result = QMessageBox::question(parent, 
        QString::fromUtf8(title, title_len), 
        QString::fromUtf8(text, text_len));
    
    RETURN_BOOL(result == QMessageBox::Yes);
}

// Method entries
static const zend_function_entry qt_QMessageBox_methods[] = {
    PHP_ME(QMessageBox, information, arginfo_class_QMessageBox_information, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_ME(QMessageBox, warning, arginfo_class_QMessageBox_warning, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_ME(QMessageBox, critical, arginfo_class_QMessageBox_critical, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_ME(QMessageBox, question, arginfo_class_QMessageBox_question, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_FE_END
};

void qt_register_QMessageBox_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\MessageBox", qt_QMessageBox_methods);
    qt_ce_QMessageBox = zend_register_internal_class(&ce);
}
