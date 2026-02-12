#include "php_qt6.h"
#include <QSpinBox>

zend_class_entry *qt_ce_QSpinBox;
zend_object_handlers qt_object_handlers_QSpinBox;

// Arginfo
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QSpinBox___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSpinBox_value, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSpinBox_setValue, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSpinBox_setMinimum, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSpinBox_setMaximum, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSpinBox_setRange, 0, 2, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSpinBox_setSingleStep, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, step, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSpinBox_setPrefix, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_QSpinBox_setSuffix arginfo_class_QSpinBox_setPrefix

// Constructor: new SpinBox()
PHP_METHOD(QSpinBox, __construct) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QSpinBox();
}

// int value()
PHP_METHOD(QSpinBox, value) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QSpinBox *spinBox = static_cast<QSpinBox*>(intern->ptr);
    RETURN_LONG(spinBox->value());
}

// void setValue(int $value)
PHP_METHOD(QSpinBox, setValue) {
    zend_long value;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(value)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QSpinBox *spinBox = static_cast<QSpinBox*>(intern->ptr);
    spinBox->setValue(value);
}

// void setMinimum(int $min)
PHP_METHOD(QSpinBox, setMinimum) {
    zend_long min;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(min)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QSpinBox *spinBox = static_cast<QSpinBox*>(intern->ptr);
    spinBox->setMinimum(min);
}

// void setMaximum(int $max)
PHP_METHOD(QSpinBox, setMaximum) {
    zend_long max;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(max)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QSpinBox *spinBox = static_cast<QSpinBox*>(intern->ptr);
    spinBox->setMaximum(max);
}

// void setRange(int $min, int $max)
PHP_METHOD(QSpinBox, setRange) {
    zend_long min, max;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(min)
        Z_PARAM_LONG(max)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QSpinBox *spinBox = static_cast<QSpinBox*>(intern->ptr);
    spinBox->setRange(min, max);
}

// void setSingleStep(int $step)
PHP_METHOD(QSpinBox, setSingleStep) {
    zend_long step;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(step)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QSpinBox *spinBox = static_cast<QSpinBox*>(intern->ptr);
    spinBox->setSingleStep(step);
}

// void setPrefix(string $prefix)
PHP_METHOD(QSpinBox, setPrefix) {
    char *prefix;
    size_t prefix_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(prefix, prefix_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QSpinBox *spinBox = static_cast<QSpinBox*>(intern->ptr);
    spinBox->setPrefix(QString::fromUtf8(prefix, prefix_len));
}

// void setSuffix(string $suffix)
PHP_METHOD(QSpinBox, setSuffix) {
    char *suffix;
    size_t suffix_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(suffix, suffix_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QSpinBox *spinBox = static_cast<QSpinBox*>(intern->ptr);
    spinBox->setSuffix(QString::fromUtf8(suffix, suffix_len));
}

// Method entries
static const zend_function_entry qt_QSpinBox_methods[] = {
    PHP_ME(QSpinBox, __construct, arginfo_class_QSpinBox___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QSpinBox, value, arginfo_class_QSpinBox_value, ZEND_ACC_PUBLIC)
    PHP_ME(QSpinBox, setValue, arginfo_class_QSpinBox_setValue, ZEND_ACC_PUBLIC)
    PHP_ME(QSpinBox, setMinimum, arginfo_class_QSpinBox_setMinimum, ZEND_ACC_PUBLIC)
    PHP_ME(QSpinBox, setMaximum, arginfo_class_QSpinBox_setMaximum, ZEND_ACC_PUBLIC)
    PHP_ME(QSpinBox, setRange, arginfo_class_QSpinBox_setRange, ZEND_ACC_PUBLIC)
    PHP_ME(QSpinBox, setSingleStep, arginfo_class_QSpinBox_setSingleStep, ZEND_ACC_PUBLIC)
    PHP_ME(QSpinBox, setPrefix, arginfo_class_QSpinBox_setPrefix, ZEND_ACC_PUBLIC)
    PHP_ME(QSpinBox, setSuffix, arginfo_class_QSpinBox_setSuffix, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QSpinBox_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\SpinBox", qt_QSpinBox_methods);
    qt_ce_QSpinBox = zend_register_internal_class_ex(&ce, qt_ce_QWidget);
    qt_ce_QSpinBox->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QSpinBox, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QSpinBox.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QSpinBox.free_obj = qt_object_free;
}
