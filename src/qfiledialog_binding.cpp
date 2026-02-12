#include "php_qt6.h"
#include <QFileDialog>

zend_class_entry *qt_ce_QFileDialog;
zend_object_handlers qt_object_handlers_QFileDialog;

// Arginfo declarations
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QFileDialog_getOpenFileName, 0, 2, IS_STRING, 0)
    ZEND_ARG_OBJ_INFO(0, parent, Qt\\Widget, 1)
    ZEND_ARG_TYPE_INFO(0, caption, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, dir, IS_STRING, 0, "\"\"")
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, filter, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

#define arginfo_class_QFileDialog_getSaveFileName arginfo_class_QFileDialog_getOpenFileName

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QFileDialog_getExistingDirectory, 0, 2, IS_STRING, 0)
    ZEND_ARG_OBJ_INFO(0, parent, Qt\\Widget, 1)
    ZEND_ARG_TYPE_INFO(0, caption, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, dir, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

// Static method: string getOpenFileName(Widget $parent, string $caption, string $dir = "", string $filter = "")
PHP_METHOD(QFileDialog, getOpenFileName) {
    zval *parent_zval = NULL;
    char *caption, *dir = nullptr, *filter = nullptr;
    size_t caption_len, dir_len = 0, filter_len = 0;
    
    ZEND_PARSE_PARAMETERS_START(2, 4)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent_zval, qt_ce_QWidget)
        Z_PARAM_STRING(caption, caption_len)
        Z_PARAM_OPTIONAL
        Z_PARAM_STRING(dir, dir_len)
        Z_PARAM_STRING(filter, filter_len)
    ZEND_PARSE_PARAMETERS_END();
    
    QWidget *parent = NULL;
    if (parent_zval && Z_TYPE_P(parent_zval) == IS_OBJECT) {
        qt_object *parent_obj = Z_QT_OBJ_P(parent_zval);
        parent = static_cast<QWidget*>(parent_obj->ptr);
    }
    
    QString fileName = QFileDialog::getOpenFileName(
        parent,
        QString::fromUtf8(caption, caption_len),
        dir ? QString::fromUtf8(dir, dir_len) : QString(),
        filter ? QString::fromUtf8(filter, filter_len) : QString()
    );
    
    RETURN_STRING(fileName.toUtf8().constData());
}

// Static method: string getSaveFileName(Widget $parent, string $caption, string $dir = "", string $filter = "")
PHP_METHOD(QFileDialog, getSaveFileName) {
    zval *parent_zval = NULL;
    char *caption, *dir = nullptr, *filter = nullptr;
    size_t caption_len, dir_len = 0, filter_len = 0;
    
    ZEND_PARSE_PARAMETERS_START(2, 4)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent_zval, qt_ce_QWidget)
        Z_PARAM_STRING(caption, caption_len)
        Z_PARAM_OPTIONAL
        Z_PARAM_STRING(dir, dir_len)
        Z_PARAM_STRING(filter, filter_len)
    ZEND_PARSE_PARAMETERS_END();
    
    QWidget *parent = NULL;
    if (parent_zval && Z_TYPE_P(parent_zval) == IS_OBJECT) {
        qt_object *parent_obj = Z_QT_OBJ_P(parent_zval);
        parent = static_cast<QWidget*>(parent_obj->ptr);
    }
    
    QString fileName = QFileDialog::getSaveFileName(
        parent,
        QString::fromUtf8(caption, caption_len),
        dir ? QString::fromUtf8(dir, dir_len) : QString(),
        filter ? QString::fromUtf8(filter, filter_len) : QString()
    );
    
    RETURN_STRING(fileName.toUtf8().constData());
}

// Static method: string getExistingDirectory(Widget $parent, string $caption, string $dir = "")
PHP_METHOD(QFileDialog, getExistingDirectory) {
    zval *parent_zval = NULL;
    char *caption, *dir = nullptr;
    size_t caption_len, dir_len = 0;
    
    ZEND_PARSE_PARAMETERS_START(2, 3)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent_zval, qt_ce_QWidget)
        Z_PARAM_STRING(caption, caption_len)
        Z_PARAM_OPTIONAL
        Z_PARAM_STRING(dir, dir_len)
    ZEND_PARSE_PARAMETERS_END();
    
    QWidget *parent = NULL;
    if (parent_zval && Z_TYPE_P(parent_zval) == IS_OBJECT) {
        qt_object *parent_obj = Z_QT_OBJ_P(parent_zval);
        parent = static_cast<QWidget*>(parent_obj->ptr);
    }
    
    QString dirName = QFileDialog::getExistingDirectory(
        parent,
        QString::fromUtf8(caption, caption_len),
        dir ? QString::fromUtf8(dir, dir_len) : QString()
    );
    
    RETURN_STRING(dirName.toUtf8().constData());
}

// Method entries
static const zend_function_entry qt_QFileDialog_methods[] = {
    PHP_ME(QFileDialog, getOpenFileName, arginfo_class_QFileDialog_getOpenFileName, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_ME(QFileDialog, getSaveFileName, arginfo_class_QFileDialog_getSaveFileName, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_ME(QFileDialog, getExistingDirectory, arginfo_class_QFileDialog_getExistingDirectory, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_FE_END
};

void qt_register_QFileDialog_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\FileDialog", qt_QFileDialog_methods);
    qt_ce_QFileDialog = zend_register_internal_class(&ce);
}
