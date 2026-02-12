#include "php_qt6.h"
#include <QTableWidgetItem>

zend_class_entry *qt_ce_QTableWidgetItem;
zend_object_handlers qt_object_handlers_QTableWidgetItem;

static void qt_delete_QTableWidgetItem(void *ptr) {
    QTableWidgetItem *item = static_cast<QTableWidgetItem*>(ptr);
    if (item && item->tableWidget() == nullptr) {
        delete item;
    }
}

// Arginfo declarations
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QTableWidgetItem___construct, 0, 0, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, text, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTableWidgetItem_text, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QTableWidgetItem_setText, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

// Constructor: new TableWidgetItem(string $text = "")
PHP_METHOD(QTableWidgetItem, __construct) {
    char *text = NULL;
    size_t text_len = 0;
    
    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    if (text) {
        intern->ptr = new QTableWidgetItem(QString::fromUtf8(text, text_len));
    } else {
        intern->ptr = new QTableWidgetItem();
    }
    intern->native_dtor = qt_delete_QTableWidgetItem;
    intern->skip_dtor = false;
}

// string text()
PHP_METHOD(QTableWidgetItem, text) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTableWidgetItem *item = static_cast<QTableWidgetItem*>(intern->ptr);
    QString text = item->text();
    RETURN_STRING(text.toUtf8().constData());
}

// void setText(string $text)
PHP_METHOD(QTableWidgetItem, setText) {
    char *text;
    size_t text_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QTableWidgetItem *item = static_cast<QTableWidgetItem*>(intern->ptr);
    item->setText(QString::fromUtf8(text, text_len));
}

// Method entries
static const zend_function_entry qt_QTableWidgetItem_methods[] = {
    PHP_ME(QTableWidgetItem, __construct, arginfo_class_QTableWidgetItem___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QTableWidgetItem, text, arginfo_class_QTableWidgetItem_text, ZEND_ACC_PUBLIC)
    PHP_ME(QTableWidgetItem, setText, arginfo_class_QTableWidgetItem_setText, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QTableWidgetItem_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\TableWidgetItem", qt_QTableWidgetItem_methods);
    qt_ce_QTableWidgetItem = zend_register_internal_class(&ce);
    qt_ce_QTableWidgetItem->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QTableWidgetItem, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QTableWidgetItem.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QTableWidgetItem.free_obj = qt_object_free;
}
