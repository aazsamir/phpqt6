#include "php_qt6.h"

// Class entries (unified architecture)
zend_class_entry *qt_ce_QApplication = NULL;
zend_class_entry *qt_ce_QObject = NULL;
zend_class_entry *qt_ce_QWidget = NULL;
zend_class_entry *qt_ce_QLayout = NULL;
zend_class_entry *qt_ce_QPushButton = NULL;
zend_class_entry *qt_ce_QLabel = NULL;
zend_class_entry *qt_ce_QMainWindow = NULL;
zend_class_entry *qt_ce_QLineEdit = NULL;
zend_class_entry *qt_ce_QSlider = NULL;
zend_class_entry *qt_ce_QVBoxLayout = NULL;
zend_class_entry *qt_ce_QHBoxLayout = NULL;

static zend_object_handlers qt_object_handlers;

// Unified object handlers
zend_object* qt_object_new(zend_class_entry *ce) {
    qt_object *object = (qt_object*)ecalloc(1, sizeof(qt_object) + zend_object_properties_size(ce));
    zend_object_std_init(&object->std, ce);
    object_properties_init(&object->std, ce);
    object->std.handlers = &qt_object_handlers;
    object->ptr = nullptr;
    return &object->std;
}

void qt_object_free(zend_object *object) {
    qt_object *qt_obj = (qt_object*)((char*)object - XtOffsetOf(qt_object, std));

    // Ownership-aware cleanup:
    // - QApplication is managed by qapplication_cleanup().
    // - QTableWidgetItem may be owned by QTableWidget after setItem().
    // - QObject-derived wrappers are deleted only when they have no parent.
    // This avoids both leaks and previous double-free/invalid-cast crashes.
    if (qt_obj->ptr && !qt_obj->skip_dtor) {
        zend_class_entry *ce = object->ce;

        if (qt_obj->native_dtor) {
            qt_obj->native_dtor(qt_obj->ptr);
        } else if (qt_ce_QApplication && instanceof_function(ce, qt_ce_QApplication)) {
            // Managed globally in qapplication_cleanup().
        } else if (qt_ce_QObject && instanceof_function(ce, qt_ce_QObject)) {
            QObject *qobj = static_cast<QObject*>(qt_obj->ptr);
            if (qobj->parent() == nullptr) {
                delete qobj;
            }
        }
    }

    qt_obj->ptr = nullptr;
    qt_obj->native_dtor = nullptr;
    qt_obj->skip_dtor = false;
    
    zend_object_std_dtor(&qt_obj->std);
}

void qt_register_all_classes()
{
    qt_register_QApplication_class();
    qt_register_QWidget_class();
    qt_register_QPushButton_class();
    qt_register_QLabel_class();
    qt_register_QMainWindow_class();
    qt_register_QLineEdit_class();
    qt_register_QSlider_class();
    qt_register_QVBoxLayout_class();
    qt_register_QHBoxLayout_class();
    qt_register_QTabWidget_class();
    qt_register_QTextEdit_class();
    qt_register_QComboBox_class();
    qt_register_QCheckBox_class();
    qt_register_QRadioButton_class();
    qt_register_QSpinBox_class();
    qt_register_QMessageBox_class();
    qt_register_QDialog_class();
    qt_register_QFileDialog_class();
    qt_register_QTableWidget_class();
    qt_register_QTableWidgetItem_class();
    qt_register_QSplitter_class();
    qt_register_QScrollArea_class();
    qt_register_QProgressBar_class();
    qt_register_QGridLayout_class();
    qt_register_QFormLayout_class();
    qt_register_QListWidget_class();
    qt_register_QTimer_class();
}

// Module functions
PHP_MINIT_FUNCTION(qt6)
{
    memcpy(&qt_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
    qt_object_handlers.offset = XtOffsetOf(qt_object, std);
    qt_object_handlers.free_obj = qt_object_free;
    
    // Create QObject base class
    zend_class_entry ce_qobject;
    INIT_CLASS_ENTRY(ce_qobject, "Qt\\Object", NULL);
    qt_ce_QObject = zend_register_internal_class(&ce_qobject);
    
    // Create QLayout base class without methods (to avoid signature conflicts)
    zend_class_entry ce_qlayout;
    INIT_CLASS_ENTRY(ce_qlayout, "Qt\\Layout", NULL);
    qt_ce_QLayout = zend_register_internal_class(&ce_qlayout);

    // Register all classes (single unified registration entry-point)
    qt_register_all_classes();
    
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(qt6)
{
    // Clean up QApplication
    qapplication_cleanup();
    return SUCCESS;
}

PHP_RINIT_FUNCTION(qt6)
{
    return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(qt6)
{
    // Clean up QApplication at request shutdown too
    qapplication_cleanup();
    return SUCCESS;
}

PHP_MINFO_FUNCTION(qt6)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "Qt6 Support", "enabled");
    php_info_print_table_row(2, "Qt6 Extension Version", PHP_QT6_VERSION);
    php_info_print_table_end();
}

// Module entry
extern "C" {
__attribute__((visibility("default")))
zend_module_entry phpqt6_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_QT6_EXTNAME,
    NULL, // functions
    PHP_MINIT(qt6),
    PHP_MSHUTDOWN(qt6),
    PHP_RINIT(qt6),
    PHP_RSHUTDOWN(qt6),
    PHP_MINFO(qt6),
    PHP_QT6_VERSION,
    STANDARD_MODULE_PROPERTIES
};
}

#ifdef COMPILE_DL_QT6
extern "C" {
ZEND_GET_MODULE(phpqt6)
}
#endif
