#include "php_qt6.h"
#include <QWidget>

// Class entry is declared as extern in php_qt6.h and defined in php_qt6.cpp
zend_object_handlers qt_object_handlers_QWidget;

// Constructor: new Widget(QWidget $parent = null)
PHP_METHOD(QWidget, __construct) {
    zval *parent_zval = NULL;
    
    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent_zval, qt_ce_QWidget)
    ZEND_PARSE_PARAMETERS_END();
    
    QWidget *parent = NULL;
    if (parent_zval && Z_TYPE_P(parent_zval) == IS_OBJECT) {
        qt_object *parent_obj = Z_QT_OBJ_P(parent_zval);
        parent = static_cast<QWidget*>(parent_obj->ptr);
    }
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    intern->ptr = new QWidget(parent);
}

// void show()
PHP_METHOD(QWidget, show) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QWidget *widget = static_cast<QWidget*>(intern->ptr);
    widget->show();
}

// void hide()
PHP_METHOD(QWidget, hide) {
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QWidget *widget = static_cast<QWidget*>(intern->ptr);
    widget->hide();
}

// void setWindowTitle(string $title)
PHP_METHOD(QWidget, setWindowTitle) {
    char *title;
    size_t title_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(title, title_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QWidget *widget = static_cast<QWidget*>(intern->ptr);
    widget->setWindowTitle(QString::fromUtf8(title, title_len));
}

// void resize(int $width, int $height)
PHP_METHOD(QWidget, resize) {
    zend_long width, height;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(width)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    QWidget *widget = static_cast<QWidget*>(intern->ptr);
    widget->resize(width, height);
}

// void setLayout(QLayout $layout)
PHP_METHOD(QWidget, setLayout) {
    zval *layout_zval;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(layout_zval, qt_ce_QLayout)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(getThis());
    qt_object *layout_obj = Z_QT_OBJ_P(layout_zval);
    
    QWidget *widget = static_cast<QWidget*>(intern->ptr);
    QLayout *layout = static_cast<QLayout*>(layout_obj->ptr);
    widget->setLayout(layout);
}

// Method entries
static const zend_function_entry qt_QWidget_methods[] = {
    PHP_ME(QWidget, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QWidget, show, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(QWidget, hide, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(QWidget, setWindowTitle, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(QWidget, resize, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(QWidget, setLayout, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void qt_register_QWidget_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\Widget", qt_QWidget_methods);
    qt_ce_QWidget = zend_register_internal_class_ex(&ce, qt_ce_QObject);
    qt_ce_QWidget->create_object = qt_object_new;
    
    memcpy(&qt_object_handlers_QWidget, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers_QWidget.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers_QWidget.free_obj = qt_object_free;
}
