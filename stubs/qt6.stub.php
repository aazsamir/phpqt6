<?php
/**
 * phpqt6 Extension Stubs
 * 
 * This file provides IDE autocomplete and type hinting for the phpqt6 extension.
 * DO NOT include this file in your project - it's for IDE reference only.
 * 
 * @see https://github.com/aazsamir/phpqt6
 */

namespace Qt {

    /**
     * Class Application
     * @package Qt
     */
    class Application
    {

        /**
         * __construct
         * @param array $argv = []
         * @return void
         */
        public function __construct(array $argv = []) {}

        /**
         * exec
         * @return int
         */
        public function exec(): int {}

        /**
         * quit
         * @return void
         */
        public static function quit(): void {}
    }

    /**
     * Class CheckBox
     * @package Qt
     */
    class CheckBox extends Widget
    {

        /**
         * __construct
         * @param string $text = ''
         * @return void
         */
        public function __construct(string $text = '') {}

        /**
         * isChecked
         * @return bool
         */
        public function isChecked(): bool {}

        /**
         * setChecked
         * @param bool $checked
         * @return void
         */
        public function setChecked(bool $checked): void {}

        /**
         * setText
         * @param string $text
         * @return void
         */
        public function setText(string $text): void {}

        /**
         * text
         * @return string
         */
        public function text(): string {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

    /**
     * Class ComboBox
     * @package Qt
     */
    class ComboBox extends Widget
    {

        /**
         * __construct
         * @return void
         */
        public function __construct() {}

        /**
         * addItem
         * @param string $text
         * @return void
         */
        public function addItem(string $text): void {}

        /**
         * addItems
         * @param array $texts
         * @return void
         */
        public function addItems(array $texts): void {}

        /**
         * currentText
         * @return string
         */
        public function currentText(): string {}

        /**
         * currentIndex
         * @return int
         */
        public function currentIndex(): int {}

        /**
         * setCurrentIndex
         * @param int $index
         * @return void
         */
        public function setCurrentIndex(int $index): void {}

        /**
         * clear
         * @return void
         */
        public function clear(): void {}

        /**
         * count
         * @return int
         */
        public function count(): int {}

        /**
         * removeItem
         * @param int $index
         * @return void
         */
        public function removeItem(int $index): void {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

    /**
     * Class Dialog
     * @package Qt
     */
    class Dialog extends Widget
    {

        /**
         * __construct
         * @param Widget $parent = null
         * @return void
         */
        public function __construct(?Widget $parent = null) {}

        /**
         * exec
         * @return int
         */
        public function exec(): int {}

        /**
         * accept
         * @return void
         */
        public function accept(): void {}

        /**
         * reject
         * @return void
         */
        public function reject(): void {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

    /**
     * Class FileDialog
     * @package Qt
     */
    class FileDialog
    {

        /**
         * getOpenFileName
         * @param Widget $parent = null
         * @param string $caption
         * @param string $dir = ''
         * @param string $filter = ''
         * @return string
         */
        public static function getOpenFileName(?Widget $parent, string $caption, string $dir = '', string $filter = ''): string {}

        /**
         * getSaveFileName
         * @param Widget $parent = null
         * @param string $caption
         * @param string $dir = ''
         * @param string $filter = ''
         * @return string
         */
        public static function getSaveFileName(?Widget $parent, string $caption, string $dir = '', string $filter = ''): string {}

        /**
         * getExistingDirectory
         * @param Widget $parent = null
         * @param string $caption
         * @param string $dir = ''
         * @return string
         */
        public static function getExistingDirectory(?Widget $parent, string $caption, string $dir = ''): string {}
    }

    /**
     * Class FormLayout
     * @package Qt
     */
    class FormLayout extends Layout
    {

        /**
         * __construct
         * @return void
         */
        public function __construct() {}

        /**
         * addRow
         * @param string $label
         * @param Widget $field
         * @return void
         */
        public function addRow(string $label, Widget $field): void {}

        /**
         * addRowWidget
         * @param Widget $widget
         * @return void
         */
        public function addRowWidget(Widget $widget): void {}

        /**
         * setSpacing
         * @param int $spacing
         * @return void
         */
        public function setSpacing(int $spacing): void {}
    }

    /**
     * Class GridLayout
     * @package Qt
     */
    class GridLayout extends Layout
    {

        /**
         * __construct
         * @return void
         */
        public function __construct() {}

        /**
         * addWidget
         * @param Widget $widget
         * @param int $row
         * @param int $column
         * @param int $rowSpan = 1
         * @param int $columnSpan = 1
         * @return void
         */
        public function addWidget(Widget $widget, int $row, int $column, int $rowSpan = 1, int $columnSpan = 1): void {}

        /**
         * addLayout
         * @param Layout $layout
         * @param int $row
         * @param int $column
         * @param int $rowSpan = 1
         * @param int $columnSpan = 1
         * @return void
         */
        public function addLayout(Layout $layout, int $row, int $column, int $rowSpan = 1, int $columnSpan = 1): void {}

        /**
         * setSpacing
         * @param int $spacing
         * @return void
         */
        public function setSpacing(int $spacing): void {}

        /**
         * setRowStretch
         * @param int $row
         * @param int $stretch
         * @return void
         */
        public function setRowStretch(int $row, int $stretch): void {}

        /**
         * setColumnStretch
         * @param int $column
         * @param int $stretch
         * @return void
         */
        public function setColumnStretch(int $column, int $stretch): void {}
    }

    /**
     * Class HBoxLayout
     * @package Qt
     */
    class HBoxLayout extends Layout
    {

        /**
         * __construct
         * @return void
         */
        public function __construct() {}

        /**
         * addWidget
         * @param mixed $widget = null
         * @param int $stretch = 0
         * @return void
         */
        public function addWidget($widget, int $stretch = 0): void {}

        /**
         * addStretch
         * @param int $stretch = 0
         * @return void
         */
        public function addStretch(int $stretch = 0): void {}

        /**
         * addSpacing
         * @param int $size
         * @return void
         */
        public function addSpacing(int $size): void {}

        /**
         * setSpacing
         * @param int $spacing
         * @return void
         */
        public function setSpacing(int $spacing): void {}

        /**
         * setContentsMargins
         * @param int $left
         * @param int $top
         * @param int $right
         * @param int $bottom
         * @return void
         */
        public function setContentsMargins(int $left, int $top, int $right, int $bottom): void {}
    }

    /**
     * Class Label
     * @package Qt
     */
    class Label
    {

        /**
         * __construct
         * @param string $text = ''
         * @param Widget $parent = null
         * @return void
         */
        public function __construct(string $text = '', ?Widget $parent = null) {}

        /**
         * setText
         * @param string $text
         * @return void
         */
        public function setText(string $text): void {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}
    }

    /**
     * Class Layout
     * @package Qt
     */
    class Layout
    {
    }

    /**
     * Class LineEdit
     * @package Qt
     */
    class LineEdit
    {

        /**
         * __construct
         * @param string $text = ''
         * @param Widget $parent = null
         * @return void
         */
        public function __construct(string $text = '', ?Widget $parent = null) {}

        /**
         * setText
         * @param string $text
         * @return void
         */
        public function setText(string $text): void {}

        /**
         * text
         * @return string
         */
        public function text(): string {}

        /**
         * setPlaceholderText
         * @param string $text
         * @return void
         */
        public function setPlaceholderText(string $text): void {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}
    }

    /**
     * Class ListWidget
     * @package Qt
     */
    class ListWidget extends Widget
    {

        /**
         * __construct
         * @return void
         */
        public function __construct() {}

        /**
         * addItem
         * @param string $text
         * @return void
         */
        public function addItem(string $text): void {}

        /**
         * addItems
         * @param array $texts
         * @return void
         */
        public function addItems(array $texts): void {}

        /**
         * currentRow
         * @return int
         */
        public function currentRow(): int {}

        /**
         * setCurrentRow
         * @param int $row
         * @return void
         */
        public function setCurrentRow(int $row): void {}

        /**
         * count
         * @return int
         */
        public function count(): int {}

        /**
         * clear
         * @return void
         */
        public function clear(): void {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

    /**
     * Class MainWindow
     * @package Qt
     */
    class MainWindow extends Widget
    {

        /**
         * __construct
         * @param Widget $parent = null
         * @return void
         */
        public function __construct(?Widget $parent = null) {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * setCentralWidget
         * @param Widget $widget
         * @return void
         */
        public function setCentralWidget(Widget $widget): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setAttribute
         * @param int $attribute
         * @param bool $on
         * @return void
         */
        public function setAttribute(int $attribute, bool $on): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

    /**
     * Class MessageBox
     * @package Qt
     */
    class MessageBox
    {

        /**
         * information
         * @param Widget $parent = null
         * @param string $title
         * @param string $text
         * @return void
         */
        public static function information(?Widget $parent, string $title, string $text): void {}

        /**
         * warning
         * @param Widget $parent = null
         * @param string $title
         * @param string $text
         * @return void
         */
        public static function warning(?Widget $parent, string $title, string $text): void {}

        /**
         * critical
         * @param Widget $parent = null
         * @param string $title
         * @param string $text
         * @return void
         */
        public static function critical(?Widget $parent, string $title, string $text): void {}

        /**
         * question
         * @param Widget $parent = null
         * @param string $title
         * @param string $text
         * @return bool
         */
        public static function question(?Widget $parent, string $title, string $text): bool {}
    }

    /**
     * Class Object
     * @package Qt
     */
    class Object
    {
    }

    /**
     * Class ProgressBar
     * @package Qt
     */
    class ProgressBar extends Widget
    {

        /**
         * __construct
         * @return void
         */
        public function __construct() {}

        /**
         * value
         * @return int
         */
        public function value(): int {}

        /**
         * setValue
         * @param int $value
         * @return void
         */
        public function setValue(int $value): void {}

        /**
         * setMinimum
         * @param int $min
         * @return void
         */
        public function setMinimum(int $min): void {}

        /**
         * setMaximum
         * @param int $max
         * @return void
         */
        public function setMaximum(int $max): void {}

        /**
         * setRange
         * @param int $min
         * @param int $max
         * @return void
         */
        public function setRange(int $min, int $max): void {}

        /**
         * setFormat
         * @param string $format
         * @return void
         */
        public function setFormat(string $format): void {}

        /**
         * reset
         * @return void
         */
        public function reset(): void {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

    /**
     * Class PushButton
     * @package Qt
     */
    class PushButton
    {

        /**
         * __construct
         * @param string $text = ''
         * @param Widget $parent = null
         * @return void
         */
        public function __construct(string $text = '', ?Widget $parent = null) {}

        /**
         * setText
         * @param string $text
         * @return void
         */
        public function setText(string $text): void {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * onClick
         * @param callable $callback
         * @return void
         */
        public function onClick(callable $callback): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}
    }

    /**
     * Class RadioButton
     * @package Qt
     */
    class RadioButton extends Widget
    {

        /**
         * __construct
         * @param string $text = ''
         * @return void
         */
        public function __construct(string $text = '') {}

        /**
         * isChecked
         * @return bool
         */
        public function isChecked(): bool {}

        /**
         * setChecked
         * @param bool $checked
         * @return void
         */
        public function setChecked(bool $checked): void {}

        /**
         * setText
         * @param string $text
         * @return void
         */
        public function setText(string $text): void {}

        /**
         * text
         * @return string
         */
        public function text(): string {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

    /**
     * Class ScrollArea
     * @package Qt
     */
    class ScrollArea extends Widget
    {

        /**
         * __construct
         * @return void
         */
        public function __construct() {}

        /**
         * setWidget
         * @param Widget $widget
         * @return void
         */
        public function setWidget(Widget $widget): void {}

        /**
         * setWidgetResizable
         * @param bool $resizable
         * @return void
         */
        public function setWidgetResizable(bool $resizable): void {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

    /**
     * Class Slider
     * @package Qt
     */
    class Slider
    {

        /**
         * __construct
         * @param int $orientation = 1
         * @param Widget $parent = null
         * @return void
         */
        public function __construct(int $orientation = 1, ?Widget $parent = null) {}

        /**
         * setValue
         * @param int $value
         * @return void
         */
        public function setValue(int $value): void {}

        /**
         * value
         * @return int
         */
        public function value(): int {}

        /**
         * setRange
         * @param int $min
         * @param int $max
         * @return void
         */
        public function setRange(int $min, int $max): void {}

        /**
         * onValueChanged
         * @param callable $callback
         * @return void
         */
        public function onValueChanged(callable $callback): void {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}
    }

    /**
     * Class SpinBox
     * @package Qt
     */
    class SpinBox extends Widget
    {

        /**
         * __construct
         * @return void
         */
        public function __construct() {}

        /**
         * value
         * @return int
         */
        public function value(): int {}

        /**
         * setValue
         * @param int $value
         * @return void
         */
        public function setValue(int $value): void {}

        /**
         * setMinimum
         * @param int $min
         * @return void
         */
        public function setMinimum(int $min): void {}

        /**
         * setMaximum
         * @param int $max
         * @return void
         */
        public function setMaximum(int $max): void {}

        /**
         * setRange
         * @param int $min
         * @param int $max
         * @return void
         */
        public function setRange(int $min, int $max): void {}

        /**
         * setSingleStep
         * @param int $step
         * @return void
         */
        public function setSingleStep(int $step): void {}

        /**
         * setPrefix
         * @param string $prefix
         * @return void
         */
        public function setPrefix(string $prefix): void {}

        /**
         * setSuffix
         * @param string $prefix
         * @return void
         */
        public function setSuffix(string $prefix): void {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

    /**
     * Class Splitter
     * @package Qt
     */
    class Splitter extends Widget
    {

        /**
         * __construct
         * @param int $orientation = 1
         * @return void
         */
        public function __construct(int $orientation = 1) {}

        /**
         * addWidget
         * @param Widget $widget
         * @return void
         */
        public function addWidget(Widget $widget): void {}

        /**
         * insertWidget
         * @param int $index
         * @param Widget $widget
         * @return void
         */
        public function insertWidget(int $index, Widget $widget): void {}

        /**
         * setOrientation
         * @param int $orientation
         * @return void
         */
        public function setOrientation(int $orientation): void {}

        /**
         * count
         * @return int
         */
        public function count(): int {}

        /**
         * setSizes
         * @param array $sizes
         * @return void
         */
        public function setSizes(array $sizes): void {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

    /**
     * Class TabWidget
     * @package Qt
     */
    class TabWidget extends Widget
    {

        /**
         * __construct
         * @return void
         */
        public function __construct() {}

        /**
         * addTab
         * @param Widget $widget
         * @param string $label
         * @return int
         */
        public function addTab(Widget $widget, string $label): int {}

        /**
         * setCurrentIndex
         * @param int $index
         * @return void
         */
        public function setCurrentIndex(int $index): void {}

        /**
         * currentIndex
         * @return int
         */
        public function currentIndex(): int {}

        /**
         * removeTab
         * @param int $index
         * @return void
         */
        public function removeTab(int $index): void {}

        /**
         * count
         * @return int
         */
        public function count(): int {}

        /**
         * setTabText
         * @param int $index
         * @param string $text
         * @return void
         */
        public function setTabText(int $index, string $text): void {}

        /**
         * tabText
         * @param int $index
         * @return string
         */
        public function tabText(int $index): string {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

    /**
     * Class TableWidget
     * @package Qt
     */
    class TableWidget extends Widget
    {

        /**
         * __construct
         * @param int $rows = 0
         * @param int $columns = 0
         * @return void
         */
        public function __construct(int $rows = 0, int $columns = 0) {}

        /**
         * setRowCount
         * @param int $rows
         * @return void
         */
        public function setRowCount(int $rows): void {}

        /**
         * setColumnCount
         * @param int $columns
         * @return void
         */
        public function setColumnCount(int $columns): void {}

        /**
         * rowCount
         * @return int
         */
        public function rowCount(): int {}

        /**
         * columnCount
         * @return int
         */
        public function columnCount(): int {}

        /**
         * setItem
         * @param int $row
         * @param int $column
         * @param TableWidgetItem $item
         * @return void
         */
        public function setItem(int $row, int $column, TableWidgetItem $item): void {}

        /**
         * setHorizontalHeaderLabels
         * @param array $labels
         * @return void
         */
        public function setHorizontalHeaderLabels(array $labels): void {}

        /**
         * setVerticalHeaderLabels
         * @param array $labels
         * @return void
         */
        public function setVerticalHeaderLabels(array $labels): void {}

        /**
         * clear
         * @return void
         */
        public function clear(): void {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

    /**
     * Class TableWidgetItem
     * @package Qt
     */
    class TableWidgetItem
    {

        /**
         * __construct
         * @param string $text = ''
         * @return void
         */
        public function __construct(string $text = '') {}

        /**
         * text
         * @return string
         */
        public function text(): string {}

        /**
         * setText
         * @param string $text
         * @return void
         */
        public function setText(string $text): void {}
    }

    /**
     * Class TextEdit
     * @package Qt
     */
    class TextEdit extends Widget
    {

        /**
         * __construct
         * @return void
         */
        public function __construct() {}

        /**
         * setPlainText
         * @param string $text
         * @return void
         */
        public function setPlainText(string $text): void {}

        /**
         * toPlainText
         * @return string
         */
        public function toPlainText(): string {}

        /**
         * setHtml
         * @param string $text
         * @return void
         */
        public function setHtml(string $text): void {}

        /**
         * toHtml
         * @return string
         */
        public function toHtml(): string {}

        /**
         * setReadOnly
         * @param bool $readOnly
         * @return void
         */
        public function setReadOnly(bool $readOnly): void {}

        /**
         * clear
         * @return void
         */
        public function clear(): void {}

        /**
         * append
         * @param string $text
         * @return void
         */
        public function append(string $text): void {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

    /**
     * Class Timer
     * @package Qt
     */
    class Timer extends Object
    {

        /**
         * __construct
         * @return void
         */
        public function __construct() {}

        /**
         * start
         * @param int $msec
         * @return void
         */
        public function start(int $msec): void {}

        /**
         * stop
         * @return void
         */
        public function stop(): void {}

        /**
         * setInterval
         * @param int $msec
         * @return void
         */
        public function setInterval(int $msec): void {}

        /**
         * interval
         * @return int
         */
        public function interval(): int {}

        /**
         * isActive
         * @return bool
         */
        public function isActive(): bool {}

        /**
         * setSingleShot
         * @param bool $singleShot
         * @return void
         */
        public function setSingleShot(bool $singleShot): void {}

        /**
         * isSingleShot
         * @return bool
         */
        public function isSingleShot(): bool {}
    }

    /**
     * Class VBoxLayout
     * @package Qt
     */
    class VBoxLayout extends Layout
    {

        /**
         * __construct
         * @return void
         */
        public function __construct() {}

        /**
         * addWidget
         * @param mixed $widget = null
         * @param int $stretch = 0
         * @return void
         */
        public function addWidget($widget, int $stretch = 0): void {}

        /**
         * addStretch
         * @param int $stretch = 0
         * @return void
         */
        public function addStretch(int $stretch = 0): void {}

        /**
         * addSpacing
         * @param int $size
         * @return void
         */
        public function addSpacing(int $size): void {}

        /**
         * setSpacing
         * @param int $spacing
         * @return void
         */
        public function setSpacing(int $spacing): void {}

        /**
         * setContentsMargins
         * @param int $left
         * @param int $top
         * @param int $right
         * @param int $bottom
         * @return void
         */
        public function setContentsMargins(int $left, int $top, int $right, int $bottom): void {}
    }

    /**
     * Class Widget
     * @package Qt
     */
    class Widget
    {

        /**
         * __construct
         * @param Widget $parent = null
         * @return void
         */
        public function __construct(?Widget $parent = null) {}

        /**
         * show
         * @return void
         */
        public function show(): void {}

        /**
         * hide
         * @return void
         */
        public function hide(): void {}

        /**
         * setWindowTitle
         * @param string $title
         * @return void
         */
        public function setWindowTitle(string $title): void {}

        /**
         * resize
         * @param int $width
         * @param int $height
         * @return void
         */
        public function resize(int $width, int $height): void {}

        /**
         * move
         * @param int $x
         * @param int $y
         * @return void
         */
        public function move(int $x, int $y): void {}

        /**
         * setStyleSheet
         * @param string $styleSheet
         * @return void
         */
        public function setStyleSheet(string $styleSheet): void {}

        /**
         * setGeometry
         * @param int $x
         * @param int $y
         * @param int $width
         * @param int $height
         * @return void
         */
        public function setGeometry(int $x, int $y, int $width, int $height): void {}

        /**
         * setLayout
         * @param VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout|GridLayout|FormLayout $layout): void {}
    }

}
