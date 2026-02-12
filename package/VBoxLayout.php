<?php

declare(strict_types=1);

namespace Aazsamir\Qtlib;

class VBoxLayout
{
    private \Qt\VBoxLayout $vBoxLayout;

    public function __construct(
        private array $widgets = [],
        private ?int $stretch = null,
        private ?int $spacing = null,
        private ?int $marginLeft = null,
        private ?int $marginTop = null,
        private ?int $marginRight = null,
        private ?int $marginBottom = null,
    ) {
        $this->vBoxLayout = new \Qt\VBoxLayout();

        if ($stretch !== null) {
            $this->addStretch($stretch);
        }

        if ($spacing !== null) {
            $this->setSpacing($spacing);
        }

        if ($marginLeft !== null && $marginTop !== null && $marginRight !== null && $marginBottom !== null) {
            $this->setContentsMargins($marginLeft, $marginTop, $marginRight, $marginBottom);
        }
    }

    public function addWidget(WidgetInterface $widget): void
    {
        $this->widgets[] = $widget;
        $this->vBoxLayout->addWidget($widget->getQt());
    }

    public function addStretch(int $stretch): void
    {
        $this->stretch ??= 0;
        $this->stretch += $stretch;
        $this->vBoxLayout->addStretch($stretch);
    }

    public function addSpacing(int $spacing): void
    {
        $this->spacing ??= 0;
        $this->spacing += $spacing;
        $this->vBoxLayout->addSpacing($spacing);
    }

    public function setSpacing(int $spacing): void
    {
        $this->spacing = $spacing;
        $this->vBoxLayout->setSpacing($spacing);
    }

    public function setContentsMargins(int $left, int $top, int $right, int $bottom): void
    {
        $this->marginLeft = $left;
        $this->marginTop = $top;
        $this->marginRight = $right;
        $this->marginBottom = $bottom;
        $this->vBoxLayout->setContentsMargins($left, $top, $right, $bottom);
    }

    public function getQt(): \Qt\VBoxLayout
    {
        return $this->vBoxLayout;
    }
}
