#include "php_qt6.h"

// QApplication static instance (only one allowed)
static int qapp_argc = 0;
static char** qapp_argv = nullptr;
static QApplication* qapp_instance = nullptr;
static bool qapp_cleaned_up = false;

// Object handlers
static zend_object_handlers qapplication_object_handlers;

// Arginfo declarations (PHP 8+)
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_QApplication___construct, 0, 0, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, argv, IS_ARRAY, 1, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QApplication_exec, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_QApplication_quit, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

// __construct($argv = [])
PHP_METHOD(QApplication, __construct)
{
    zval *argv_array = nullptr;
    
    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_ARRAY(argv_array)
    ZEND_PARSE_PARAMETERS_END();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    
    // Only one QApplication allowed
    if (qapp_instance != nullptr) {
        intern->ptr = qapp_instance;
        return;
    }
    
    // Prepare arguments
    if (argv_array) {
        qapp_argc = zend_hash_num_elements(Z_ARRVAL_P(argv_array));
        qapp_argv = (char**)emalloc(sizeof(char*) * (qapp_argc + 1));
        
        int i = 0;
        zval *entry;
        ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(argv_array), entry) {
            convert_to_string(entry);
            qapp_argv[i] = estrdup(Z_STRVAL_P(entry));
            i++;
        } ZEND_HASH_FOREACH_END();
        qapp_argv[qapp_argc] = nullptr;
    } else {
        qapp_argc = 1;
        qapp_argv = (char**)emalloc(sizeof(char*) * 2);
        qapp_argv[0] = estrdup("php");
        qapp_argv[1] = nullptr;
    }
    
    qapp_instance = new QApplication(qapp_argc, qapp_argv);
    intern->ptr = qapp_instance;
}

// exec() : int
PHP_METHOD(QApplication, exec)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qt_object *intern = Z_QT_OBJ_P(ZEND_THIS);
    QApplication *app = static_cast<QApplication*>(intern->ptr);
    
    if (!app) {
        php_error_docref(NULL, E_WARNING, "QApplication not initialized");
        RETURN_LONG(-1);
    }
    
    int result = app->exec();
    RETURN_LONG(result);
}

// quit() : void
PHP_METHOD(QApplication, quit)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    if (qapp_instance) {
        QApplication::quit();
    }
}

// Cleanup function called at shutdown
void qapplication_cleanup()
{
    if (qapp_cleaned_up) {
        return;
    }
    
    qapp_cleaned_up = true;
    
    // Delete QApplication instance
    if (qapp_instance) {
        delete qapp_instance;
        qapp_instance = nullptr;
    }
    
    // Free argv
    if (qapp_argv) {
        for (int i = 0; i < qapp_argc; i++) {
            if (qapp_argv[i]) {
                efree(qapp_argv[i]);
            }
        }
        efree(qapp_argv);
        qapp_argv = nullptr;
    }
    
    qapp_argc = 0;
}

// Method entries
static const zend_function_entry qapplication_methods[] = {
    PHP_ME(QApplication, __construct, arginfo_class_QApplication___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(QApplication, exec, arginfo_class_QApplication_exec, ZEND_ACC_PUBLIC)
    PHP_ME(QApplication, quit, arginfo_class_QApplication_quit, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_FE_END
};

// Initialize class
void qt_register_QApplication_class()
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\Application", qapplication_methods);
    qt_ce_QApplication = zend_register_internal_class(&ce);
    qt_ce_QApplication->create_object = qt_object_new;
    
    memcpy(&qapplication_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
    qapplication_object_handlers.offset = XtOffsetOf(qt_object, std);
    qapplication_object_handlers.free_obj = qt_object_free;
}
