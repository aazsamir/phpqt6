#include "php_qt6.h"

// Object handlers
static zend_object_handlers qslider_object_handlers;

// Callback wrapper for value changed signal
class PHPSliderCallback : public QObject {
    Q_OBJECT

public:
    PHPSliderCallback(QSlider *slider) : QObject(slider), slider(slider) {
        connect(slider, &QSlider::valueChanged, this, &PHPSliderCallback::onValueChanged);
    }
    
    void setCallback(zval *callback) {
        if (php_callback) {
            zval_ptr_dtor(php_callback);
            efree(php_callback);
        }
        php_callback = (zval*)emalloc(sizeof(zval));
        ZVAL_COPY(php_callback, callback);
    }

public slots:
    void onValueChanged(int value) {
        if (php_callback && Z_TYPE_P(php_callback) == IS_OBJECT) {
            zval retval;
            zval args[1];
            ZVAL_LONG(&args[0], value);
            
            call_user_function(NULL, php_callback, NULL, &retval, 1, args);
            
            zval_ptr_dtor(&retval);
            zval_ptr_dtor(&args[0]);
        }
    }

private:
    QSlider *slider;
    zval *php_callback = nullptr;
};

// Free object
static void qslider_free_object(zend_object *object)
{
    qslider_object *intern = qslider_fetch_object(object);
    
    if (intern->slider) {
        delete intern->slider;
        intern->slider = nullptr;
    }
    
    zend_object_std_dtor(&intern->std);
}

// Create object
static zend_object* qslider_create_object(zend_class_entry *ce)
{
    qslider_object *intern = (qslider_object*)ecalloc(1,
        sizeof(qslider_object) + zend_object_properties_size(ce));
    
    zend_object_std_init(&intern->std, ce);
    object_properties_init(&intern->std, ce);
    
    intern->std.handlers = &qslider_object_handlers;
    intern->slider = nullptr;
    
    return &intern->std;
}

// Arginfo
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QSlider___construct, 0, 0, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, orientation, IS_LONG, 0, "1")
    ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, parent, Qt\\Widget, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSlider_setValue, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSlider_value, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSlider_setRange, 0, 2, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSlider_onValueChanged, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, callback, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSlider_show, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSlider_setGeometry, 0, 4, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QSlider_setStyleSheet, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, styleSheet, IS_STRING, 0)
ZEND_END_ARG_INFO()

// __construct
PHP_METHOD(QSlider, __construct)
{
    zend_long orientation = 1; // Qt::Horizontal
    zval *parent = nullptr;
    
    ZEND_PARSE_PARAMETERS_START(0, 2)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(orientation)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent, qwidget_ce)
    ZEND_PARSE_PARAMETERS_END();
    
    qslider_object *intern = Z_QSLIDER_OBJ_P(ZEND_THIS);
    
    QWidget *parent_widget = nullptr;
    if (parent) {
        qwidget_object *parent_obj = Z_QWIDGET_OBJ_P(parent);
        parent_widget = parent_obj->widget;
    }
    
    intern->slider = new QSlider((Qt::Orientation)orientation, parent_widget);
}

// setValue
PHP_METHOD(QSlider, setValue)
{
    zend_long value;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(value)
    ZEND_PARSE_PARAMETERS_END();
    
    qslider_object *intern = Z_QSLIDER_OBJ_P(ZEND_THIS);
    if (intern->slider) {
        intern->slider->setValue(value);
    }
}

// value
PHP_METHOD(QSlider, value)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qslider_object *intern = Z_QSLIDER_OBJ_P(ZEND_THIS);
    if (intern->slider) {
        RETURN_LONG(intern->slider->value());
    }
    RETURN_LONG(0);
}

// setRange
PHP_METHOD(QSlider, setRange)
{
    zend_long min, max;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(min)
        Z_PARAM_LONG(max)
    ZEND_PARSE_PARAMETERS_END();
    
    qslider_object *intern = Z_QSLIDER_OBJ_P(ZEND_THIS);
    if (intern->slider) {
        intern->slider->setRange(min, max);
    }
}

// onValueChanged
PHP_METHOD(QSlider, onValueChanged)
{
    zval *callback;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ZVAL(callback)
    ZEND_PARSE_PARAMETERS_END();
    
    qslider_object *intern = Z_QSLIDER_OBJ_P(ZEND_THIS);
    if (intern->slider) {
        PHPSliderCallback *cb = new PHPSliderCallback(intern->slider);
        cb->setCallback(callback);
    }
}

// show
PHP_METHOD(QSlider, show)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qslider_object *intern = Z_QSLIDER_OBJ_P(ZEND_THIS);
    if (intern->slider) {
        intern->slider->show();
    }
}

// setGeometry
PHP_METHOD(QSlider, setGeometry)
{
    zend_long x, y, width, height;
    
    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_LONG(x)
        Z_PARAM_LONG(y)
        Z_PARAM_LONG(width)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();
    
    qslider_object *intern = Z_QSLIDER_OBJ_P(ZEND_THIS);
    if (intern->slider) {
        intern->slider->setGeometry(x, y, width, height);
    }
}

// setStyleSheet
PHP_METHOD(QSlider, setStyleSheet)
{
    char *stylesheet;
    size_t stylesheet_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(stylesheet, stylesheet_len)
    ZEND_PARSE_PARAMETERS_END();
    
    qslider_object *intern = Z_QSLIDER_OBJ_P(ZEND_THIS);
    if (intern->slider) {
        intern->slider->setStyleSheet(QString::fromUtf8(stylesheet, stylesheet_len));
    }
}

// Method entries
static const zend_function_entry qslider_methods[] = {
    PHP_ME(QSlider, __construct, arginfo_class_QSlider___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QSlider, setValue, arginfo_class_QSlider_setValue, ZEND_ACC_PUBLIC)
    PHP_ME(QSlider, value, arginfo_class_QSlider_value, ZEND_ACC_PUBLIC)
    PHP_ME(QSlider, setRange, arginfo_class_QSlider_setRange, ZEND_ACC_PUBLIC)
    PHP_ME(QSlider, onValueChanged, arginfo_class_QSlider_onValueChanged, ZEND_ACC_PUBLIC)
    PHP_ME(QSlider, show, arginfo_class_QSlider_show, ZEND_ACC_PUBLIC)
    PHP_ME(QSlider, setGeometry, arginfo_class_QSlider_setGeometry, ZEND_ACC_PUBLIC)
    PHP_ME(QSlider, setStyleSheet, arginfo_class_QSlider_setStyleSheet, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

// Initialize class
void qslider_init(INIT_FUNC_ARGS)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\Slider", qslider_methods);
    qslider_ce = zend_register_internal_class(&ce);
    qslider_ce->create_object = qslider_create_object;
    
    memcpy(&qslider_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    qslider_object_handlers.offset = XtOffsetOf(qslider_object, std);
    qslider_object_handlers.free_obj = qslider_free_object;
}

#include "qslider_binding.moc"
