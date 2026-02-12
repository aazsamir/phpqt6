#include "php_qt6.h"
#include <QComboBox>

zend_class_entry *qt_ce_QComboBox;
zend_object_handlers qt_object_handlers_QComboBox;

// Arginfo
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QComboBox___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QComboBox_addItem, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QComboBox_addItems, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, texts, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QComboBox_currentText, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QComboBox_currentIndex, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QComboBox_setCurrentIndex, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QComboBox_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_QComboBox_count arginfo_class_QComboBox_currentIndex
#define arginfo_class_QComboBox_removeItem arginfo_class_QComboBox_setCurrentIndex

// Constructor: new ComboBox()
PHP_METHOD(QComboBox, __construct) {
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QComboBox();
}

// void addItem(string $text)
PHP_METHOD(QComboBox, addItem) {
    char *text;
    size_t text_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QComboBox *comboBox = static_cast<QComboBox*>(intern->ptr);
    comboBox->addItem(QString::fromUtf8(text, text_len));
}

// void addItems(array $items)
PHP_METHOD(QComboBox, addItems) {
    zval *items;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(items)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QComboBox *comboBox = static_cast<QComboBox*>(intern->ptr);
    
    QStringList stringList;
    zval *item;
    ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(items), item) {
        convert_to_string(item);
        stringList << QString::fromUtf8(Z_STRVAL_P(item), Z_STRLEN_P(item));
    } ZEND_HASH_FOREACH_END();
    
    comboBox->addItems(stringList);
}

// string currentText()
PHP_METHOD(QComboBox, currentText) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QComboBox *comboBox = static_cast<QComboBox*>(intern->ptr);
    QString text = comboBox->currentText();
    RETURN_STRING(text.toUtf8().constData());
}

// int currentIndex()
PHP_METHOD(QComboBox, currentIndex) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QComboBox *comboBox = static_cast<QComboBox*>(intern->ptr);
    RETURN_LONG(comboBox->currentIndex());
}

// void setCurrentIndex(int $index)
PHP_METHOD(QComboBox, setCurrentIndex) {
    zend_long index;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QComboBox *comboBox = static_cast<QComboBox*>(intern->ptr);
    comboBox->setCurrentIndex(index);
}

// void clear()
PHP_METHOD(QComboBox, clear) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QComboBox *comboBox = static_cast<QComboBox*>(intern->ptr);
    comboBox->clear();
}

// int count()
PHP_METHOD(QComboBox, count) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QComboBox *comboBox = static_cast<QComboBox*>(intern->ptr);
    RETURN_LONG(comboBox->count());
}

// void removeItem(int $index)
PHP_METHOD(QComboBox, removeItem) {
    zend_long index;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QComboBox *comboBox = static_cast<QComboBox*>(intern->ptr);
    comboBox->removeItem(index);
}

// Method entries
static const zend_function_entry qt_QComboBox_methods[] = {
    PHP_ME(QComboBox, __construct, arginfo_class_QComboBox___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QComboBox, addItem, arginfo_class_QComboBox_addItem, ZEND_ACC_PUBLIC)
    PHP_ME(QComboBox, addItems, arginfo_class_QComboBox_addItems, ZEND_ACC_PUBLIC)
    PHP_ME(QComboBox, currentText, arginfo_class_QComboBox_currentText, ZEND_ACC_PUBLIC)
    PHP_ME(QComboBox, currentIndex, arginfo_class_QComboBox_currentIndex, ZEND_ACC_PUBLIC)
    PHP_ME(QComboBox, setCurrentIndex, arginfo_class_QComboBox_setCurrentIndex, ZEND_ACC_PUBLIC)
    PHP_ME(QComboBox, clear, arginfo_class_QComboBox_clear, ZEND_ACC_PUBLIC)
    PHP_ME(QComboBox, count, arginfo_class_QComboBox_count, ZEND_ACC_PUBLIC)
    PHP_ME(QComboBox, removeItem, arginfo_class_QComboBox_removeItem, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QComboBox_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\ComboBox", qt_QComboBox_methods);
    qt_ce_QComboBox = zend_register_internal_class_ex(&ce, qt_ce_QWidget);
    qt_ce_QComboBox->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QComboBox, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QComboBox.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QComboBox.free_obj = qt_object_free;
}
