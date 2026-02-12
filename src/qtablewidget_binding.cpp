#include "php_qt6.h"
#include <QTableWidget>

zend_class_entry *qt_ce_QTableWidget;
zend_object_handlers qt_object_handlers_QTableWidget;

// Arginfo declarations
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QTableWidget___construct, 0, 0, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, rows, IS_LONG, 0, "0")
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, columns, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTableWidget_setRowCount, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, rows, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTableWidget_setColumnCount, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, columns, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTableWidget_rowCount, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_QTableWidget_columnCount arginfo_class_QTableWidget_rowCount

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTableWidget_setItem, 0, 3, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
    ZEND_ARG_OBJ_INFO(0, item, Qt\\TableWidgetItem, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTableWidget_setHorizontalHeaderLabels, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, labels, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_QTableWidget_setVerticalHeaderLabels arginfo_class_QTableWidget_setHorizontalHeaderLabels

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTableWidget_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

// Constructor: new TableWidget(int $rows = 0, int $columns = 0)
PHP_METHOD(QTableWidget, __construct) {
    zend_long rows = 0, columns = 0;
    
    ZEND_PARSE_PARAMETERS_START(0, 2)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(rows)
        Z_PARAM_LONG(columns)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QTableWidget(rows, columns);
}

// void setRowCount(int $rows)
PHP_METHOD(QTableWidget, setRowCount) {
    zend_long rows;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(rows)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTableWidget *table = static_cast<QTableWidget*>(intern->ptr);
    table->setRowCount(rows);
}

// void setColumnCount(int $columns)
PHP_METHOD(QTableWidget, setColumnCount) {
    zend_long columns;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(columns)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTableWidget *table = static_cast<QTableWidget*>(intern->ptr);
    table->setColumnCount(columns);
}

// int rowCount()
PHP_METHOD(QTableWidget, rowCount) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTableWidget *table = static_cast<QTableWidget*>(intern->ptr);
    RETURN_LONG(table->rowCount());
}

// int columnCount()
PHP_METHOD(QTableWidget, columnCount) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTableWidget *table = static_cast<QTableWidget*>(intern->ptr);
    RETURN_LONG(table->columnCount());
}

// void setItem(int $row, int $column, TableWidgetItem $item)
PHP_METHOD(QTableWidget, setItem) {
    zend_long row, column;
    zval *item_zval;
    
    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_LONG(row)
        Z_PARAM_LONG(column)
        Z_PARAM_OBJECT_OF_CLASS(item_zval, qt_ce_QTableWidgetItem)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    qt_object *item_obj = Z_QT_OBJ_P(item_zval);
    
    QTableWidget *table = static_cast<QTableWidget*>(intern->ptr);
    QTableWidgetItem *item = static_cast<QTableWidgetItem*>(item_obj->ptr);
    table->setItem(row, column, item);

    // Ownership transferred to QTableWidget.
    item_obj->skip_dtor = true;
}

// void setHorizontalHeaderLabels(array $labels)
PHP_METHOD(QTableWidget, setHorizontalHeaderLabels) {
    zval *labels_array;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(labels_array)
    ZEND_PARSE_PARAMETERS_END();
    
    QStringList labels;
    zval *item;
    ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(labels_array), item) {
        convert_to_string(item);
        labels.append(QString::fromUtf8(Z_STRVAL_P(item), Z_STRLEN_P(item)));
    } ZEND_HASH_FOREACH_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTableWidget *table = static_cast<QTableWidget*>(intern->ptr);
    table->setHorizontalHeaderLabels(labels);
}

// void setVerticalHeaderLabels(array $labels)
PHP_METHOD(QTableWidget, setVerticalHeaderLabels) {
    zval *labels_array;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(labels_array)
    ZEND_PARSE_PARAMETERS_END();
    
    QStringList labels;
    zval *item;
    ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(labels_array), item) {
        convert_to_string(item);
        labels.append(QString::fromUtf8(Z_STRVAL_P(item), Z_STRLEN_P(item)));
    } ZEND_HASH_FOREACH_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTableWidget *table = static_cast<QTableWidget*>(intern->ptr);
    table->setVerticalHeaderLabels(labels);
}

// void clear()
PHP_METHOD(QTableWidget, clear) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTableWidget *table = static_cast<QTableWidget*>(intern->ptr);
    table->clear();
}

// Method entries
static const zend_function_entry qt_QTableWidget_methods[] = {
    PHP_ME(QTableWidget, __construct, arginfo_class_QTableWidget___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QTableWidget, setRowCount, arginfo_class_QTableWidget_setRowCount, ZEND_ACC_PUBLIC)
    PHP_ME(QTableWidget, setColumnCount, arginfo_class_QTableWidget_setColumnCount, ZEND_ACC_PUBLIC)
    PHP_ME(QTableWidget, rowCount, arginfo_class_QTableWidget_rowCount, ZEND_ACC_PUBLIC)
    PHP_ME(QTableWidget, columnCount, arginfo_class_QTableWidget_columnCount, ZEND_ACC_PUBLIC)
    PHP_ME(QTableWidget, setItem, arginfo_class_QTableWidget_setItem, ZEND_ACC_PUBLIC)
    PHP_ME(QTableWidget, setHorizontalHeaderLabels, arginfo_class_QTableWidget_setHorizontalHeaderLabels, ZEND_ACC_PUBLIC)
    PHP_ME(QTableWidget, setVerticalHeaderLabels, arginfo_class_QTableWidget_setVerticalHeaderLabels, ZEND_ACC_PUBLIC)
    PHP_ME(QTableWidget, clear, arginfo_class_QTableWidget_clear, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QTableWidget_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\TableWidget", qt_QTableWidget_methods);
    qt_ce_QTableWidget = zend_register_internal_class_ex(&ce, qt_ce_QWidget);
    qt_ce_QTableWidget->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QTableWidget, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QTableWidget.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QTableWidget.free_obj = qt_object_free;
}
