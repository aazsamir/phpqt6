#ifndef PHP_QT6_H
#define PHP_QT6_H

extern "C" {
#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "zend_exceptions.h"
}

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QObject>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QComboBox>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <Qt>

#define PHP_QT6_EXTNAME "phpqt6"
#define PHP_QT6_VERSION "0.1.0"

// Module entry (with C linkage)
extern "C" {
__attribute__((visibility("default"))) extern zend_module_entry phpqt6_module_entry;
}
#define phpext_phpqt6_ptr &phpqt6_module_entry

// Class entries
extern zend_class_entry *qapplication_ce;
extern zend_class_entry *qwidget_ce;
extern zend_class_entry *qpushbutton_ce;
extern zend_class_entry *qlabel_ce;
extern zend_class_entry *qmainwindow_ce;
extern zend_class_entry *qlineedit_ce;
extern zend_class_entry *qtextedit_ce;
extern zend_class_entry *qcheckbox_ce;
extern zend_class_entry *qradiobutton_ce;
extern zend_class_entry *qcombobox_ce;
extern zend_class_entry *qslider_ce;
extern zend_class_entry *qvboxlayout_ce;
extern zend_class_entry *qhboxlayout_ce;

// Object structures
struct qapplication_object {
    QApplication *app;
    zend_object std;
};

struct qwidget_object {
    QWidget *widget;
    zend_object std;
};

struct qpushbutton_object {
    QPushButton *button;
    zend_object std;
};

struct qlabel_object {
    QLabel *label;
    zend_object std;
};

struct qmainwindow_object {
    QMainWindow *window;
    zend_object std;
};

struct qlineedit_object {
    QLineEdit *lineedit;
    zend_object std;
};

struct qtextedit_object {
    QTextEdit *textedit;
    zend_object std;
};

struct qcheckbox_object {
    QCheckBox *checkbox;
    zend_object std;
};

struct qradiobutton_object {
    QRadioButton *radiobutton;
    zend_object std;
};

struct qcombobox_object {
    QComboBox *combobox;
    zend_object std;
};

struct qslider_object {
    QSlider *slider;
    zend_object std;
};

struct qvboxlayout_object {
    QVBoxLayout *layout;
    zend_object std;
};

struct qhboxlayout_object {
    QHBoxLayout *layout;
    zend_object std;
};

// Helper macros
#define Z_QAPPLICATION_OBJ_P(zv) qapplication_fetch_object(Z_OBJ_P(zv))
#define Z_QWIDGET_OBJ_P(zv) qwidget_fetch_object(Z_OBJ_P(zv))
#define Z_QPUSHBUTTON_OBJ_P(zv) qpushbutton_fetch_object(Z_OBJ_P(zv))
#define Z_QLABEL_OBJ_P(zv) qlabel_fetch_object(Z_OBJ_P(zv))
#define Z_QMAINWINDOW_OBJ_P(zv) qmainwindow_fetch_object(Z_OBJ_P(zv))
#define Z_QLINEEDIT_OBJ_P(zv) qlineedit_fetch_object(Z_OBJ_P(zv))
#define Z_QTEXTEDIT_OBJ_P(zv) qtextedit_fetch_object(Z_OBJ_P(zv))
#define Z_QCHECKBOX_OBJ_P(zv) qcheckbox_fetch_object(Z_OBJ_P(zv))
#define Z_QRADIOBUTTON_OBJ_P(zv) qradiobutton_fetch_object(Z_OBJ_P(zv))
#define Z_QCOMBOBOX_OBJ_P(zv) qcombobox_fetch_object(Z_OBJ_P(zv))
#define Z_QSLIDER_OBJ_P(zv) qslider_fetch_object(Z_OBJ_P(zv))
#define Z_QVBOXLAYOUT_OBJ_P(zv) qvboxlayout_fetch_object(Z_OBJ_P(zv))
#define Z_QHBOXLAYOUT_OBJ_P(zv) qhboxlayout_fetch_object(Z_OBJ_P(zv))

// Fetch object helpers
static inline qapplication_object* qapplication_fetch_object(zend_object *obj) {
    return (qapplication_object*)((char*)(obj) - XtOffsetOf(qapplication_object, std));
}

static inline qwidget_object* qwidget_fetch_object(zend_object *obj) {
    return (qwidget_object*)((char*)(obj) - XtOffsetOf(qwidget_object, std));
}

static inline qpushbutton_object* qpushbutton_fetch_object(zend_object *obj) {
    return (qpushbutton_object*)((char*)(obj) - XtOffsetOf(qpushbutton_object, std));
}

static inline qlabel_object* qlabel_fetch_object(zend_object *obj) {
    return (qlabel_object*)((char*)(obj) - XtOffsetOf(qlabel_object, std));
}

static inline qmainwindow_object* qmainwindow_fetch_object(zend_object *obj) {
    return (qmainwindow_object*)((char*)(obj) - XtOffsetOf(qmainwindow_object, std));
}

static inline qlineedit_object* qlineedit_fetch_object(zend_object *obj) {
    return (qlineedit_object*)((char*)(obj) - XtOffsetOf(qlineedit_object, std));
}

static inline qtextedit_object* qtextedit_fetch_object(zend_object *obj) {
    return (qtextedit_object*)((char*)(obj) - XtOffsetOf(qtextedit_object, std));
}

static inline qcheckbox_object* qcheckbox_fetch_object(zend_object *obj) {
    return (qcheckbox_object*)((char*)(obj) - XtOffsetOf(qcheckbox_object, std));
}

static inline qradiobutton_object* qradiobutton_fetch_object(zend_object *obj) {
    return (qradiobutton_object*)((char*)(obj) - XtOffsetOf(qradiobutton_object, std));
}

static inline qcombobox_object* qcombobox_fetch_object(zend_object *obj) {
    return (qcombobox_object*)((char*)(obj) - XtOffsetOf(qcombobox_object, std));
}

static inline qslider_object* qslider_fetch_object(zend_object *obj) {
    return (qslider_object*)((char*)(obj) - XtOffsetOf(qslider_object, std));
}

static inline qvboxlayout_object* qvboxlayout_fetch_object(zend_object *obj) {
    return (qvboxlayout_object*)((char*)(obj) - XtOffsetOf(qvboxlayout_object, std));
}

static inline qhboxlayout_object* qhboxlayout_fetch_object(zend_object *obj) {
    return (qhboxlayout_object*)((char*)(obj) - XtOffsetOf(qhboxlayout_object, std));
}

// Initialization functions
void qapplication_init(INIT_FUNC_ARGS);
void qapplication_cleanup(); // Cleanup function
void qwidget_init(INIT_FUNC_ARGS);
void qpushbutton_init(INIT_FUNC_ARGS);
void qlabel_init(INIT_FUNC_ARGS);
void qmainwindow_init(INIT_FUNC_ARGS);
void qlineedit_init(INIT_FUNC_ARGS);
void qtextedit_init(INIT_FUNC_ARGS);
void qcheckbox_init(INIT_FUNC_ARGS);
void qradiobutton_init(INIT_FUNC_ARGS);
void qcombobox_init(INIT_FUNC_ARGS);
void qslider_init(INIT_FUNC_ARGS);
void qvboxlayout_init(INIT_FUNC_ARGS);
void qhboxlayout_init(INIT_FUNC_ARGS);

#endif // PHP_QT6_H
