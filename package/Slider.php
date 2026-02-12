<?php

declare(strict_types=1);

namespace Aazsamir\Qtlib;

class Slider implements WidgetInterface
{
    private \Qt\Slider $slider;

    public function __construct(
        ?int $value = 0,
        private ?int $min = null,
        private ?int $max = null,
        private ?int $x = 0,
        private ?int $y = 0,
        private ?int $width = 0,
        private ?int $height = 0,
        ?Widget $parent = null,
    ) {
        $this->slider = new \Qt\Slider(1, $parent ? $parent->getQt() : null);

        if ($x !== null && $y !== null && $width !== null && $height !== null) {
            $this->slider->setGeometry($x, $y, $width, $height);
        }

        if ($value !== null) {
            $this->slider->setValue($value);
        }

        if ($min !== null && $max !== null) {
            $this->slider->setRange($min, $max);
        }
    }

    public function setValue(int $value): void
    {
        $this->slider->setValue($value);
    }

    public function value(): int
    {
        return $this->slider->value();
    }

    public function setRange(int $min, int $max): void
    {
        $this->min = $min;
        $this->max = $max;
        $this->slider->setRange($min, $max);
    }

    public function onValueChanged(callable $callback): void
    {
        $this->slider->onValueChanged($callback);
    }

    public function show(): void
    {
        $this->slider->show();
    }

    public function hide(): void
    {
        $this->slider->hide();
    }

    public function setGeometry(int $x, int $y, int $width, int $height): void
    {
        $this->x = $x;
        $this->y = $y;
        $this->width = $width;
        $this->height = $height;
        $this->slider->setGeometry($x, $y, $width, $height);
    }

    public function setStyleSheet(string $style): void
    {
        $this->slider->setStyleSheet($style);
    }

    public function getQt(): mixed
    {
        return $this->slider;
    }
}