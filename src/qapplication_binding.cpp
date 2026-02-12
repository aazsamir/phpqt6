#include "php_qt6.h"

// QApplication static instance (only one allowed)
static int qapp_argc = 0;
static char** qapp_argv = nullptr;
static QApplication* qapp_instance = nullptr;
static bool qapp_cleaned_up = false;

// Object handlers
static zend_object_handlers qapplication_object_handlers;

// Free object
static void qapplication_free_object(zend_object *object)
{
    qapplication_object *intern = qapplication_fetch_object(object);
    
    // Don't delete QApplication here - Qt will handle it
    intern->app = nullptr;
    
    zend_object_std_dtor(&intern->std);
}

// Create object
static zend_object* qapplication_create_object(zend_class_entry *ce)
{
    qapplication_object *intern = (qapplication_object*)ecalloc(1,
        sizeof(qapplication_object) + zend_object_properties_size(ce));
    
    zend_object_std_init(&intern->std, ce);
    object_properties_init(&intern->std, ce);
    
    intern->std.handlers = &qapplication_object_handlers;
    intern->app = nullptr;
    
    return &intern->std;
}

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
    
    qapplication_object *intern = Z_QAPPLICATION_OBJ_P(ZEND_THIS);
    
    // Only one QApplication allowed
    if (qapp_instance != nullptr) {
        intern->app = qapp_instance;
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
    intern->app = qapp_instance;
}

// exec() : int
PHP_METHOD(QApplication, exec)
{
    ZEND_PARSE_PARAMETERS_NONE();
    
    qapplication_object *intern = Z_QAPPLICATION_OBJ_P(ZEND_THIS);
    
    if (!intern->app) {
        php_error_docref(NULL, E_WARNING, "QApplication not initialized");
        RETURN_LONG(-1);
    }
    
    int result = intern->app->exec();
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
void qapplication_init(INIT_FUNC_ARGS)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Qt\\Application", qapplication_methods);
    qapplication_ce = zend_register_internal_class(&ce);
    qapplication_ce->create_object = qapplication_create_object;
    
    memcpy(&qapplication_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    qapplication_object_handlers.offset = XtOffsetOf(qapplication_object, std);
    qapplication_object_handlers.free_obj = qapplication_free_object;
}
