<?php

declare(strict_types=1);

namespace Aazsamir\Qtlib;

class Widget implements WidgetInterface
{
    private \Qt\Widget $widget;
    private VBoxLayout|HBoxLayout|null $layout = null;

    public function __construct(
        ?Widget $parent = null,
    )
    {
        $this->widget = new \Qt\Widget($parent ? $parent->getQt() : null);
    }

    public function show(): void
    {
        $this->widget->show();
    }

    public function hide(): void
    {
        $this->widget->hide();
    }

    public function setWindowTitle(string $title): void
    {
        $this->widget->setWindowTitle($title);
    }

    public function resize(int $width, int $height): void
    {
        $this->widget->resize($width, $height);
    }

    public function move(int $x, int $y): void
    {
        $this->widget->move($x, $y);
    }

    public function setStyleSheet(string $style): void
    {
        $this->widget->setStyleSheet($style);
    }

    public function setGeometry(int $x, int $y, int $width, int $height): void
    {
        $this->widget->setGeometry($x, $y, $width, $height);
    }

    public function setLayout(VBoxLayout|HBoxLayout $layout): void
    {
        $this->layout = $layout;
        $layout = $layout instanceof VBoxLayout ? $layout->getQt() : $layout->getQt();
        $this->widget->setLayout($layout);
    }

    public function getQt(): \Qt\Widget
    {
        return $this->widget;
    }
}