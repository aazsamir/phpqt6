#include "php_qt6.h"
#include <QListWidget>

zend_class_entry *qt_ce_QListWidget;
zend_object_handlers qt_object_handlers_QListWidget;

// Arginfo declarations
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QListWidget___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QListWidget_addItem, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QListWidget_addItems, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, texts, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QListWidget_currentRow, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QListWidget_setCurrentRow, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QListWidget_count, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QListWidget_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

// Constructor: new ListWidget()
PHP_METHOD(QListWidget, __construct) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QListWidget();
}

// void addItem(string $text)
PHP_METHOD(QListWidget, addItem) {
    char *text;
    size_t text_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QListWidget *list = static_cast<QListWidget*>(intern->ptr);
    list->addItem(QString::fromUtf8(text, text_len));
}

// void addItems(array $texts)
PHP_METHOD(QListWidget, addItems) {
    zval *texts_array;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(texts_array)
    ZEND_PARSE_PARAMETERS_END();
    
    QStringList texts;
    zval *item;
    ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(texts_array), item) {
        convert_to_string(item);
        texts.append(QString::fromUtf8(Z_STRVAL_P(item), Z_STRLEN_P(item)));
    } ZEND_HASH_FOREACH_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QListWidget *list = static_cast<QListWidget*>(intern->ptr);
    list->addItems(texts);
}

// int currentRow()
PHP_METHOD(QListWidget, currentRow) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QListWidget *list = static_cast<QListWidget*>(intern->ptr);
    RETURN_LONG(list->currentRow());
}

// void setCurrentRow(int $row)
PHP_METHOD(QListWidget, setCurrentRow) {
    zend_long row;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(row)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QListWidget *list = static_cast<QListWidget*>(intern->ptr);
    list->setCurrentRow(row);
}

// int count()
PHP_METHOD(QListWidget, count) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QListWidget *list = static_cast<QListWidget*>(intern->ptr);
    RETURN_LONG(list->count());
}

// void clear()
PHP_METHOD(QListWidget, clear) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QListWidget *list = static_cast<QListWidget*>(intern->ptr);
    list->clear();
}

// Method entries
static const zend_function_entry qt_QListWidget_methods[] = {
    PHP_ME(QListWidget, __construct, arginfo_class_QListWidget___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QListWidget, addItem, arginfo_class_QListWidget_addItem, ZEND_ACC_PUBLIC)
    PHP_ME(QListWidget, addItems, arginfo_class_QListWidget_addItems, ZEND_ACC_PUBLIC)
    PHP_ME(QListWidget, currentRow, arginfo_class_QListWidget_currentRow, ZEND_ACC_PUBLIC)
    PHP_ME(QListWidget, setCurrentRow, arginfo_class_QListWidget_setCurrentRow, ZEND_ACC_PUBLIC)
    PHP_ME(QListWidget, count, arginfo_class_QListWidget_count, ZEND_ACC_PUBLIC)
    PHP_ME(QListWidget, clear, arginfo_class_QListWidget_clear, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QListWidget_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\ListWidget", qt_QListWidget_methods);
    qt_ce_QListWidget = zend_register_internal_class_ex(&ce, qt_ce_QWidget);
    qt_ce_QListWidget->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QListWidget, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QListWidget.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QListWidget.free_obj = qt_object_free;
}
