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
#include <QTabWidget>
#include <QMessageBox>
#include <QDialog>
#include <QFileDialog>
#include <QSpinBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSplitter>
#include <QScrollArea>
#include <QProgressBar>
#include <QGridLayout>
#include <QFormLayout>
#include <QListWidget>
#include <QTimer>

#define PHP_QT6_EXTNAME "phpqt6"
#define PHP_QT6_VERSION "0.1.0"

// Module entry (with C linkage)
extern "C" {
__attribute__((visibility("default"))) extern zend_module_entry phpqt6_module_entry;
}
#define phpext_phpqt6_ptr &phpqt6_module_entry
struct qt_object {
    void *ptr;
    void (*native_dtor)(void *);
    bool skip_dtor;
    zend_object std;
};

// Object creation/destruction
zend_object* qt_object_new(zend_class_entry *ce);
void qt_object_free(zend_object *object);

// Macro for unified object access
#define Z_QT_OBJ_P(zv) ((qt_object*)((char*)Z_OBJ_P(zv) - XtOffsetOf(qt_object, std)))

// Class entries
extern zend_class_entry *qt_ce_QApplication;
extern zend_class_entry *qt_ce_QObject;
extern zend_class_entry *qt_ce_QWidget;
extern zend_class_entry *qt_ce_QLayout;
extern zend_class_entry *qt_ce_QPushButton;
extern zend_class_entry *qt_ce_QLabel;
extern zend_class_entry *qt_ce_QMainWindow;
extern zend_class_entry *qt_ce_QLineEdit;
extern zend_class_entry *qt_ce_QSlider;
extern zend_class_entry *qt_ce_QVBoxLayout;
extern zend_class_entry *qt_ce_QHBoxLayout;
extern zend_class_entry *qt_ce_QTabWidget;
extern zend_class_entry *qt_ce_QTextEdit;
extern zend_class_entry *qt_ce_QComboBox;
extern zend_class_entry *qt_ce_QCheckBox;
extern zend_class_entry *qt_ce_QRadioButton;
extern zend_class_entry *qt_ce_QSpinBox;
extern zend_class_entry *qt_ce_QMessageBox;
extern zend_class_entry *qt_ce_QDialog;
extern zend_class_entry *qt_ce_QFileDialog;
extern zend_class_entry *qt_ce_QTableWidget;
extern zend_class_entry *qt_ce_QTableWidgetItem;
extern zend_class_entry *qt_ce_QSplitter;
extern zend_class_entry *qt_ce_QScrollArea;
extern zend_class_entry *qt_ce_QProgressBar;
extern zend_class_entry *qt_ce_QGridLayout;
extern zend_class_entry *qt_ce_QFormLayout;
extern zend_class_entry *qt_ce_QListWidget;
extern zend_class_entry *qt_ce_QTimer;

// Lifecycle helpers
void qapplication_cleanup(); // Cleanup function

void qt_register_all_classes();
void qt_register_QApplication_class();
void qt_register_QWidget_class();
void qt_register_QPushButton_class();
void qt_register_QLabel_class();
void qt_register_QMainWindow_class();
void qt_register_QLineEdit_class();
void qt_register_QSlider_class();
void qt_register_QVBoxLayout_class();
void qt_register_QHBoxLayout_class();
void qt_register_QTabWidget_class();
void qt_register_QTextEdit_class();
void qt_register_QComboBox_class();
void qt_register_QCheckBox_class();
void qt_register_QRadioButton_class();
void qt_register_QSpinBox_class();
void qt_register_QMessageBox_class();
void qt_register_QDialog_class();
void qt_register_QFileDialog_class();
void qt_register_QTableWidget_class();
void qt_register_QTableWidgetItem_class();
void qt_register_QSplitter_class();
void qt_register_QScrollArea_class();
void qt_register_QProgressBar_class();
void qt_register_QGridLayout_class();
void qt_register_QFormLayout_class();
void qt_register_QListWidget_class();
void qt_register_QTimer_class();

#endif // PHP_QT6_H
