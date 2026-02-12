<?php

declare(strict_types=1);

namespace Aazsamir\Qtlib;

class PushButton implements WidgetInterface
{
    private \Qt\PushButton $pushButton;

    public function __construct(
        private string $text = '',
        private ?int $x = 0,
        private ?int $y = 0,
        private ?int $width = 0,
        private ?int $height = 0,
        ?Widget $parent = null,
    ) {
        $this->pushButton = new \Qt\PushButton($text, $parent ? $parent->getQt() : null);

        if ($x !== null && $y !== null && $width !== null && $height !== null) {
            $this->pushButton->setGeometry($x, $y, $width, $height);
        }

        if ($text !== '') {
            $this->pushButton->setText($text);
        }
    }

    public function setText(string $text): void
    {
        $this->text = $text;
        $this->pushButton->setText($text);
    }

    public function text(): string
    {
        return $this->text;
    }

    public function setGeometry(int $x, int $y, int $width, int $height): void
    {
        $this->x = $x;
        $this->y = $y;
        $this->width = $width;
        $this->height = $height;
        $this->pushButton->setGeometry($x, $y, $width, $height);
    }

    public function show(): void
    {
        $this->pushButton->show();
    }

    public function hide(): void
    {
        $this->pushButton->hide();
    }

    public function onClick(callable $callback): void
    {
        $this->pushButton->onClick($callback);
    }

    public function setStyleSheet(string $style): void
    {
        $this->pushButton->setStyleSheet($style);
    }

    public function getQt(): \Qt\PushButton
    {
        return $this->pushButton;
    }
}
