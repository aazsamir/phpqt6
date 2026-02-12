#include "php_qt6.h"
#include <QTabWidget>

zend_class_entry *qt_ce_QTabWidget;
zend_object_handlers qt_object_handlers_QTabWidget;

// Arginfo declarations
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QTabWidget___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTabWidget_addTab, 0, 2, IS_LONG, 0)
    ZEND_ARG_OBJ_INFO(0, widget, Qt\\Widget, 0)
    ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTabWidget_setCurrentIndex, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTabWidget_currentIndex, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_QTabWidget_removeTab arginfo_class_QTabWidget_setCurrentIndex
#define arginfo_class_QTabWidget_count arginfo_class_QTabWidget_currentIndex

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTabWidget_setTabText, 0, 2, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTabWidget_tabText, 0, 1, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

// Constructor: new TabWidget()
PHP_METHOD(QTabWidget, __construct) {
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QTabWidget();
}

// int addTab(Widget $widget, string $label)
PHP_METHOD(QTabWidget, addTab) {
    zval *widget_zval;
    char *label;
    size_t label_len;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_OBJECT_OF_CLASS(widget_zval, qt_ce_QWidget)
        Z_PARAM_STRING(label, label_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    qt_object *widget_obj = Z_QT_OBJ_P(widget_zval);
    
    QTabWidget *tabWidget = static_cast<QTabWidget*>(intern->ptr);
    QWidget *widget = static_cast<QWidget*>(widget_obj->ptr);
    
    int index = tabWidget->addTab(widget, QString::fromUtf8(label, label_len));
    RETURN_LONG(index);
}

// void setCurrentIndex(int $index)
PHP_METHOD(QTabWidget, setCurrentIndex) {
    zend_long index;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTabWidget *tabWidget = static_cast<QTabWidget*>(intern->ptr);
    tabWidget->setCurrentIndex(index);
}

// int currentIndex()
PHP_METHOD(QTabWidget, currentIndex) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTabWidget *tabWidget = static_cast<QTabWidget*>(intern->ptr);
    RETURN_LONG(tabWidget->currentIndex());
}

// void removeTab(int $index)
PHP_METHOD(QTabWidget, removeTab) {
    zend_long index;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTabWidget *tabWidget = static_cast<QTabWidget*>(intern->ptr);
    tabWidget->removeTab(index);
}

// int count()
PHP_METHOD(QTabWidget, count) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTabWidget *tabWidget = static_cast<QTabWidget*>(intern->ptr);
    RETURN_LONG(tabWidget->count());
}

// void setTabText(int $index, string $text)
PHP_METHOD(QTabWidget, setTabText) {
    zend_long index;
    char *text;
    size_t text_len;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(index)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTabWidget *tabWidget = static_cast<QTabWidget*>(intern->ptr);
    tabWidget->setTabText(index, QString::fromUtf8(text, text_len));
}

// string tabText(int $index)
PHP_METHOD(QTabWidget, tabText) {
    zend_long index;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTabWidget *tabWidget = static_cast<QTabWidget*>(intern->ptr);
    QString text = tabWidget->tabText(index);
    RETURN_STRING(text.toUtf8().constData());
}

// Method entries
static const zend_function_entry qt_QTabWidget_methods[] = {
    PHP_ME(QTabWidget, __construct, arginfo_class_QTabWidget___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QTabWidget, addTab, arginfo_class_QTabWidget_addTab, ZEND_ACC_PUBLIC)
    PHP_ME(QTabWidget, setCurrentIndex, arginfo_class_QTabWidget_setCurrentIndex, ZEND_ACC_PUBLIC)
    PHP_ME(QTabWidget, currentIndex, arginfo_class_QTabWidget_currentIndex, ZEND_ACC_PUBLIC)
    PHP_ME(QTabWidget, removeTab, arginfo_class_QTabWidget_removeTab, ZEND_ACC_PUBLIC)
    PHP_ME(QTabWidget, count, arginfo_class_QTabWidget_count, ZEND_ACC_PUBLIC)
    PHP_ME(QTabWidget, setTabText, arginfo_class_QTabWidget_setTabText, ZEND_ACC_PUBLIC)
    PHP_ME(QTabWidget, tabText, arginfo_class_QTabWidget_tabText, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QTabWidget_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\TabWidget", qt_QTabWidget_methods);
    qt_ce_QTabWidget = zend_register_internal_class_ex(&ce, qt_ce_QWidget);
    qt_ce_QTabWidget->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QTabWidget, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QTabWidget.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QTabWidget.free_obj = qt_object_free;
}
