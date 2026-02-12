<?php

declare(strict_types=1);

namespace Aazsamir\Qtlib;

class Label implements WidgetInterface
{
    private \Qt\Label $label;

    public function __construct(
        private string $text = '',
        private ?int $x = 0,
        private ?int $y = 0,
        private ?int $width = 0,
        private ?int $height = 0,
        ?Widget $parent = null,
    ) {
        $this->label = new \Qt\Label($text, $parent ? $parent->getQt() : null);

        if ($x !== null && $y !== null && $width !== null && $height !== null) {
            $this->label->setGeometry($x, $y, $width, $height);
        }
    }

    public function setText(string $text): void
    {
        $this->text = $text;
        $this->label->setText($text);
    }

    public function text(): string
    {
        return $this->text;
    }

    public function setStyleSheet(string $style): void
    {
        $this->label->setStyleSheet($style);
    }

    public function setGeometry(int $x, int $y, int $width, int $height): void
    {
        $this->x = $x;
        $this->y = $y;
        $this->width = $width;
        $this->height = $height;
        $this->label->setGeometry($x, $y, $width, $height);
    }

    public function show(): void
    {
        $this->label->show();
    }

    public function hide(): void
    {
        $this->label->hide();
    }

    public function getQt(): \Qt\Label
    {
        return $this->label;
    }
}
