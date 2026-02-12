#include "php_qt6.h"
#include <QTimer>

zend_class_entry *qt_ce_QTimer;
zend_object_handlers qt_object_handlers_QTimer;

// Arginfo declarations
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QTimer___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTimer_start, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, msec, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTimer_stop, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTimer_setInterval, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, msec, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTimer_interval, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTimer_isActive, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTimer_setSingleShot, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, singleShot, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_QTimer_isSingleShot arginfo_class_QTimer_isActive

// Constructor: new Timer()
PHP_METHOD(QTimer, __construct) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QTimer();
}

// void start(int $msec)
PHP_METHOD(QTimer, start) {
    zend_long msec;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(msec)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTimer *timer = static_cast<QTimer*>(intern->ptr);
    timer->start(msec);
}

// void stop()
PHP_METHOD(QTimer, stop) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTimer *timer = static_cast<QTimer*>(intern->ptr);
    timer->stop();
}

// void setInterval(int $msec)
PHP_METHOD(QTimer, setInterval) {
    zend_long msec;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(msec)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTimer *timer = static_cast<QTimer*>(intern->ptr);
    timer->setInterval(msec);
}

// int interval()
PHP_METHOD(QTimer, interval) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTimer *timer = static_cast<QTimer*>(intern->ptr);
    RETURN_LONG(timer->interval());
}

// bool isActive()
PHP_METHOD(QTimer, isActive) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTimer *timer = static_cast<QTimer*>(intern->ptr);
    RETURN_BOOL(timer->isActive());
}

// void setSingleShot(bool $singleShot)
PHP_METHOD(QTimer, setSingleShot) {
    zend_bool singleShot;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(singleShot)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTimer *timer = static_cast<QTimer*>(intern->ptr);
    timer->setSingleShot(singleShot);
}

// bool isSingleShot()
PHP_METHOD(QTimer, isSingleShot) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTimer *timer = static_cast<QTimer*>(intern->ptr);
    RETURN_BOOL(timer->isSingleShot());
}

// Method entries
static const zend_function_entry qt_QTimer_methods[] = {
    PHP_ME(QTimer, __construct, arginfo_class_QTimer___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QTimer, start, arginfo_class_QTimer_start, ZEND_ACC_PUBLIC)
    PHP_ME(QTimer, stop, arginfo_class_QTimer_stop, ZEND_ACC_PUBLIC)
    PHP_ME(QTimer, setInterval, arginfo_class_QTimer_setInterval, ZEND_ACC_PUBLIC)
    PHP_ME(QTimer, interval, arginfo_class_QTimer_interval, ZEND_ACC_PUBLIC)
    PHP_ME(QTimer, isActive, arginfo_class_QTimer_isActive, ZEND_ACC_PUBLIC)
    PHP_ME(QTimer, setSingleShot, arginfo_class_QTimer_setSingleShot, ZEND_ACC_PUBLIC)
    PHP_ME(QTimer, isSingleShot, arginfo_class_QTimer_isSingleShot, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QTimer_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\Timer", qt_QTimer_methods);
    qt_ce_QTimer = zend_register_internal_class_ex(&ce, qt_ce_QObject);
    qt_ce_QTimer->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QTimer, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QTimer.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QTimer.free_obj = qt_object_free;
}
