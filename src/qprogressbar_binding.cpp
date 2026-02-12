#include "php_qt6.h"
#include <QProgressBar>

zend_class_entry *qt_ce_QProgressBar;
zend_object_handlers qt_object_handlers_QProgressBar;

// Arginfo declarations
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QProgressBar___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QProgressBar_value, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QProgressBar_setValue, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QProgressBar_setMinimum, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QProgressBar_setMaximum, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QProgressBar_setRange, 0, 2, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QProgressBar_setFormat, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, format, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QProgressBar_reset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

// Constructor: new ProgressBar()
PHP_METHOD(QProgressBar, __construct) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QProgressBar();
}

// int value()
PHP_METHOD(QProgressBar, value) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QProgressBar *progressBar = static_cast<QProgressBar*>(intern->ptr);
    RETURN_LONG(progressBar->value());
}

// void setValue(int $value)
PHP_METHOD(QProgressBar, setValue) {
    zend_long value;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(value)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QProgressBar *progressBar = static_cast<QProgressBar*>(intern->ptr);
    progressBar->setValue(value);
}

// void setMinimum(int $min)
PHP_METHOD(QProgressBar, setMinimum) {
    zend_long min;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(min)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QProgressBar *progressBar = static_cast<QProgressBar*>(intern->ptr);
    progressBar->setMinimum(min);
}

// void setMaximum(int $max)
PHP_METHOD(QProgressBar, setMaximum) {
    zend_long max;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(max)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QProgressBar *progressBar = static_cast<QProgressBar*>(intern->ptr);
    progressBar->setMaximum(max);
}

// void setRange(int $min, int $max)
PHP_METHOD(QProgressBar, setRange) {
    zend_long min, max;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(min)
        Z_PARAM_LONG(max)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QProgressBar *progressBar = static_cast<QProgressBar*>(intern->ptr);
    progressBar->setRange(min, max);
}

// void setFormat(string $format)
PHP_METHOD(QProgressBar, setFormat) {
    char *format;
    size_t format_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(format, format_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QProgressBar *progressBar = static_cast<QProgressBar*>(intern->ptr);
    progressBar->setFormat(QString::fromUtf8(format, format_len));
}

// void reset()
PHP_METHOD(QProgressBar, reset) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QProgressBar *progressBar = static_cast<QProgressBar*>(intern->ptr);
    progressBar->reset();
}

// Method entries
static const zend_function_entry qt_QProgressBar_methods[] = {
    PHP_ME(QProgressBar, __construct, arginfo_class_QProgressBar___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QProgressBar, value, arginfo_class_QProgressBar_value, ZEND_ACC_PUBLIC)
    PHP_ME(QProgressBar, setValue, arginfo_class_QProgressBar_setValue, ZEND_ACC_PUBLIC)
    PHP_ME(QProgressBar, setMinimum, arginfo_class_QProgressBar_setMinimum, ZEND_ACC_PUBLIC)
    PHP_ME(QProgressBar, setMaximum, arginfo_class_QProgressBar_setMaximum, ZEND_ACC_PUBLIC)
    PHP_ME(QProgressBar, setRange, arginfo_class_QProgressBar_setRange, ZEND_ACC_PUBLIC)
    PHP_ME(QProgressBar, setFormat, arginfo_class_QProgressBar_setFormat, ZEND_ACC_PUBLIC)
    PHP_ME(QProgressBar, reset, arginfo_class_QProgressBar_reset, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QProgressBar_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\ProgressBar", qt_QProgressBar_methods);
    qt_ce_QProgressBar = zend_register_internal_class_ex(&ce, qt_ce_QWidget);
    qt_ce_QProgressBar->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QProgressBar, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QProgressBar.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QProgressBar.free_obj = qt_object_free;
}
