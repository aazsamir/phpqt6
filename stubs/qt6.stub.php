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
     * Class HBoxLayout
     * @package Qt
     */
    class HBoxLayout
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
     * Class MainWindow
     * @package Qt
     */
    class MainWindow
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
     * Class VBoxLayout
     * @package Qt
     */
    class VBoxLayout
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
         * @param VBoxLayout|HBoxLayout $layout
         * @return void
         */
        public function setLayout(VBoxLayout|HBoxLayout $layout): void {}
    }

}
