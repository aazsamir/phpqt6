#include "php_qt6.h"
#include <QRadioButton>

zend_class_entry *qt_ce_QRadioButton;
zend_object_handlers qt_object_handlers_QRadioButton;

// Arginfo
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QRadioButton___construct, 0, 0, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, text, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QRadioButton_isChecked, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QRadioButton_setChecked, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, checked, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QRadioButton_setText, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QRadioButton_text, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

// Constructor: new RadioButton(string $text = "")
PHP_METHOD(QRadioButton, __construct) {
    char *text = NULL;
    size_t text_len = 0;
    
    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    if (text) {
        intern->ptr = new QRadioButton(QString::fromUtf8(text, text_len));
    } else {
        intern->ptr = new QRadioButton();
    }
}

// bool isChecked()
PHP_METHOD(QRadioButton, isChecked) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QRadioButton *radioButton = static_cast<QRadioButton*>(intern->ptr);
    RETURN_BOOL(radioButton->isChecked());
}

// void setChecked(bool $checked)
PHP_METHOD(QRadioButton, setChecked) {
    zend_bool checked;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(checked)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QRadioButton *radioButton = static_cast<QRadioButton*>(intern->ptr);
    radioButton->setChecked(checked);
}

// void setText(string $text)
PHP_METHOD(QRadioButton, setText) {
    char *text;
    size_t text_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QRadioButton *radioButton = static_cast<QRadioButton*>(intern->ptr);
    radioButton->setText(QString::fromUtf8(text, text_len));
}

// string text()
PHP_METHOD(QRadioButton, text) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QRadioButton *radioButton = static_cast<QRadioButton*>(intern->ptr);
    QString text = radioButton->text();
    RETURN_STRING(text.toUtf8().constData());
}

// Method entries
static const zend_function_entry qt_QRadioButton_methods[] = {
    PHP_ME(QRadioButton, __construct, arginfo_class_QRadioButton___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QRadioButton, isChecked, arginfo_class_QRadioButton_isChecked, ZEND_ACC_PUBLIC)
    PHP_ME(QRadioButton, setChecked, arginfo_class_QRadioButton_setChecked, ZEND_ACC_PUBLIC)
    PHP_ME(QRadioButton, setText, arginfo_class_QRadioButton_setText, ZEND_ACC_PUBLIC)
    PHP_ME(QRadioButton, text, arginfo_class_QRadioButton_text, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QRadioButton_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\RadioButton", qt_QRadioButton_methods);
    qt_ce_QRadioButton = zend_register_internal_class_ex(&ce, qt_ce_QWidget);
    qt_ce_QRadioButton->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QRadioButton, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QRadioButton.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QRadioButton.free_obj = qt_object_free;
}
