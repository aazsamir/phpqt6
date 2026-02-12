<?php

declare(strict_types=1);

namespace Aazsamir\Qtlib;

class LineEdit implements WidgetInterface
{
    private \Qt\LineEdit $lineEdit;

    public function __construct(
        string $text = '',
        ?Widget $parent = null
    ) {
        $this->lineEdit = new \Qt\LineEdit($text, $parent ? $parent->getQt() : null);
    }

    public function setText(string $text): void
    {
        $this->lineEdit->setText($text);
    }

    public function text(): string
    {
        return $this->lineEdit->text();
    }

    public function setPlaceholderText(string $text): void
    {
        $this->lineEdit->setPlaceholderText($text);
    }

    public function setStyleSheet(string $style): void
    {
        $this->lineEdit->setStyleSheet($style);
    }

    public function show(): void
    {
        $this->lineEdit->show();
    }

    public function hide(): void
    {
        $this->lineEdit->hide();
    }

    public function getQt(): \Qt\LineEdit
    {
        return $this->lineEdit;
    }
}