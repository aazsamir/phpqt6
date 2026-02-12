#include "php_qt6.h"

// Class entries
zend_class_entry *qapplication_ce;
zend_class_entry *qwidget_ce;
zend_class_entry *qpushbutton_ce;
zend_class_entry *qlabel_ce;
zend_class_entry *qmainwindow_ce;
zend_class_entry *qlineedit_ce;
zend_class_entry *qtextedit_ce;
zend_class_entry *qcheckbox_ce;
zend_class_entry *qradiobutton_ce;
zend_class_entry *qcombobox_ce;
zend_class_entry *qslider_ce;
zend_class_entry *qvboxlayout_ce;
zend_class_entry *qhboxlayout_ce;

// Module functions
PHP_MINIT_FUNCTION(qt6)
{
    qapplication_init(INIT_FUNC_ARGS_PASSTHRU);
    qwidget_init(INIT_FUNC_ARGS_PASSTHRU);
    qpushbutton_init(INIT_FUNC_ARGS_PASSTHRU);
    qlabel_init(INIT_FUNC_ARGS_PASSTHRU);
    qmainwindow_init(INIT_FUNC_ARGS_PASSTHRU);
    qlineedit_init(INIT_FUNC_ARGS_PASSTHRU);
    qtextedit_init(INIT_FUNC_ARGS_PASSTHRU);
    qcheckbox_init(INIT_FUNC_ARGS_PASSTHRU);
    qradiobutton_init(INIT_FUNC_ARGS_PASSTHRU);
    qcombobox_init(INIT_FUNC_ARGS_PASSTHRU);
    qslider_init(INIT_FUNC_ARGS_PASSTHRU);
    qvboxlayout_init(INIT_FUNC_ARGS_PASSTHRU);
    qhboxlayout_init(INIT_FUNC_ARGS_PASSTHRU);
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
