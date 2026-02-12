#include "php_qt6.h"

// Object handlers
static zend_object_handlers qpushbutton_object_handlers;

// Callback handler for clicked signal
class PHPButtonCallback : public QObject {
    Q_OBJECT
public:
    zval callback;
    
    PHPButtonCallback() {
        ZVAL_UNDEF(&callback);
    }
    
    ~PHPButtonCallback() {
        if (!Z_ISUNDEF(callback)) {
            zval_ptr_dtor(&callback);
        }
    }
    
public slots:
    void onClicked() {
        if (!Z_ISUNDEF(callback) && Z_TYPE(callback) == IS_OBJECT) {
            zval retval;
            
            if (call_user_function(EG(function_table), NULL, &callback, &retval, 0, NULL) == SUCCESS) {
                zval_ptr_dtor(&retval);
            }
        }
    }
};

// Free object
static void qpushbutton_free_object(zend_object *object)
{
    qpushbutton_object *intern = qpushbutton_fetch_object(object);
    
    if (intern->button) {
        intern->button->deleteLater();
        intern->button = nullptr;
    }
    
    zend_object_std_dtor(&intern->std);
}

// Create object
static zend_object* qpushbutton_create_object(zend_class_entry *ce)
{
    qpushbutton_object *intern = (qpushbutton_object*)ecalloc(1,
        sizeof(qpushbutton_object) + zend_object_properties_size(ce));
    
    zend_object_std_init(&intern->std, ce);
    object_properties_init(&intern->std, ce);
    
    intern->std.handlers = &qpushbutton_object_handlers;
    intern->button = nullptr;
    
    return &intern->std;
}

// Arginfo declarations (PHP 8+)
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QPushButton___construct, 0, 0, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, text, IS_STRING, 0, "\"\"")
    ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, parent, Qt\\Widget, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QPushButton_setText, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QPushButton_show, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QPushButton_hide, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QPushButton_setGeometry, 0, 4, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QPushButton_onClick, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, callback, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QPushButton_setStyleSheet, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, styleSheet, IS_STRING, 0)
ZEND_END_ARG_INFO()

// __construct(string $text = "", $parent = null)
PHP_METHOD(QPushButton, __construct)
{
    char *text = nullptr;
    size_t text_len = 0;
    zval *parent = nullptr;
    
    ZEND_PARSE_PARAMETERS_START(0, 2)
        Z_PARAM_OPTIONAL
        Z_PARAM_STRING(text, text_len)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent, qwidget_ce)
    ZEND_PARSE_PARAMETERS_END();
    
    qpushbutton_object *intern = Z_QPUSHBUTTON_OBJ_P(ZEND_THIS);
    
    QWidget *parent_widget = nullptr;
    if (parent) {
        qwidget_object *parent_obj = Z_QWIDGET_OBJ_P(parent);
        parent_widget = parent_obj->widget;
    }
    
    if (text) {
        intern->button = new QPushButton(QString::fromUtf8(text, text_len), parent_widget);
    } else {
        intern->button = new QPushButton(parent_widget);
    }
}

// setText(string $text) : void
PHP_METHOD(QPushButton, setText)
{
    char *text;
    size_t text_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qpushbutton_object *intern = Z_QPUSHBUTTON_OBJ_P(ZEND_THIS);
    if (intern->button) {
        intern->button->setText(QString::fromUtf8(text, text_len));
    }
}

// show() : void
PHP_METHOD(QPushButton, show)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qpushbutton_object *intern = Z_QPUSHBUTTON_OBJ_P(ZEND_THIS);
    if (intern->button) {
        intern->button->show();
    }
}

// hide() : void
PHP_METHOD(QPushButton, hide)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qpushbutton_object *intern = Z_QPUSHBUTTON_OBJ_P(ZEND_THIS);
    if (intern->button) {
        intern->button->hide();
    }
}

// setGeometry(int $x, int $y, int $width, int $height) : void
PHP_METHOD(QPushButton, setGeometry)
{
    zend_long x, y, width, height;
    
    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_LONG(x)
        Z_PARAM_LONG(y)
        Z_PARAM_LONG(width)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();
    
    qpushbutton_object *intern = Z_QPUSHBUTTON_OBJ_P(ZEND_THIS);
    if (intern->button) {
        intern->button->setGeometry(x, y, width, height);
    }
}

// onClick(callable $callback) : void
PHP_METHOD(QPushButton, onClick)
{
    zval *callback;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ZVAL(callback)
    ZEND_PARSE_PARAMETERS_END();
    
    qpushbutton_object *intern = Z_QPUSHBUTTON_OBJ_P(ZEND_THIS);
    if (!intern->button) {
        return;
    }
    
    PHPButtonCallback *cb = new PHPButtonCallback();
    ZVAL_COPY(&cb->callback, callback);
    
    QObject::connect(intern->button, &QPushButton::clicked, cb, &PHPButtonCallback::onClicked);
}

// setStyleSheet(string $styleSheet) : void
PHP_METHOD(QPushButton, setStyleSheet)
{
    char *stylesheet;
    size_t stylesheet_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(stylesheet, stylesheet_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qpushbutton_object *intern = Z_QPUSHBUTTON_OBJ_P(ZEND_THIS);
    if (intern->button) {
        intern->button->setStyleSheet(QString::fromUtf8(stylesheet, stylesheet_len));
    }
}

// Method entries
static const zend_function_entry qpushbutton_methods[] = {
    PHP_ME(QPushButton, __construct, arginfo_class_QPushButton___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QPushButton, setText, arginfo_class_QPushButton_setText, ZEND_ACC_PUBLIC)
    PHP_ME(QPushButton, show, arginfo_class_QPushButton_show, ZEND_ACC_PUBLIC)
    PHP_ME(QPushButton, hide, arginfo_class_QPushButton_hide, ZEND_ACC_PUBLIC)
    PHP_ME(QPushButton, setGeometry, arginfo_class_QPushButton_setGeometry, ZEND_ACC_PUBLIC)
    PHP_ME(QPushButton, onClick, arginfo_class_QPushButton_onClick, ZEND_ACC_PUBLIC)
    PHP_ME(QPushButton, setStyleSheet, arginfo_class_QPushButton_setStyleSheet, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

// Initialize class
void qpushbutton_init(INIT_FUNC_ARGS)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\PushButton", qpushbutton_methods);
    qpushbutton_ce = zend_register_internal_class(&ce);
    qpushbutton_ce->create_object = qpushbutton_create_object;
    
    memcpy(&qpushbutton_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    qpushbutton_object_handlers.offset = XtOffsetOf(qpushbutton_object, std);
    qpushbutton_object_handlers.free_obj = qpushbutton_free_object;
}

#include "qpushbutton_binding.moc"
