#include "php_qt6.h"
#include <QCheckBox>

zend_class_entry *qt_ce_QCheckBox;
zend_object_handlers qt_object_handlers_QCheckBox;

// Arginfo
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QCheckBox___construct, 0, 0, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, text, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QCheckBox_isChecked, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QCheckBox_setChecked, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, checked, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QCheckBox_setText, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QCheckBox_text, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

// Constructor: new CheckBox(string $text = "")
PHP_METHOD(QCheckBox, __construct) {
    char *text = NULL;
    size_t text_len = 0;
    
    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    if (text) {
        intern->ptr = new QCheckBox(QString::fromUtf8(text, text_len));
    } else {
        intern->ptr = new QCheckBox();
    }
}

// bool isChecked()
PHP_METHOD(QCheckBox, isChecked) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QCheckBox *checkBox = static_cast<QCheckBox*>(intern->ptr);
    RETURN_BOOL(checkBox->isChecked());
}

// void setChecked(bool $checked)
PHP_METHOD(QCheckBox, setChecked) {
    zend_bool checked;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(checked)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QCheckBox *checkBox = static_cast<QCheckBox*>(intern->ptr);
    checkBox->setChecked(checked);
}

// void setText(string $text)
PHP_METHOD(QCheckBox, setText) {
    char *text;
    size_t text_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QCheckBox *checkBox = static_cast<QCheckBox*>(intern->ptr);
    checkBox->setText(QString::fromUtf8(text, text_len));
}

// string text()
PHP_METHOD(QCheckBox, text) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QCheckBox *checkBox = static_cast<QCheckBox*>(intern->ptr);
    QString text = checkBox->text();
    RETURN_STRING(text.toUtf8().constData());
}

// Method entries
static const zend_function_entry qt_QCheckBox_methods[] = {
    PHP_ME(QCheckBox, __construct, arginfo_class_QCheckBox___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QCheckBox, isChecked, arginfo_class_QCheckBox_isChecked, ZEND_ACC_PUBLIC)
    PHP_ME(QCheckBox, setChecked, arginfo_class_QCheckBox_setChecked, ZEND_ACC_PUBLIC)
    PHP_ME(QCheckBox, setText, arginfo_class_QCheckBox_setText, ZEND_ACC_PUBLIC)
    PHP_ME(QCheckBox, text, arginfo_class_QCheckBox_text, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QCheckBox_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\CheckBox", qt_QCheckBox_methods);
    qt_ce_QCheckBox = zend_register_internal_class_ex(&ce, qt_ce_QWidget);
    qt_ce_QCheckBox->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QCheckBox, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QCheckBox.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QCheckBox.free_obj = qt_object_free;
}
