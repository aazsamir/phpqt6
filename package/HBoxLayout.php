<?php

declare(strict_types=1);

namespace Aazsamir\Qtlib;

class HBoxLayout
{
    private \Qt\HBoxLayout $hBoxLayout;

    public function __construct(
        private array $widgets = [],
        private ?int $stretch = null,
        private ?int $spacing = null,
        private ?int $marginLeft = null,
        private ?int $marginTop = null,
        private ?int $marginRight = null,
        private ?int $marginBottom = null,
    )
    {
        $this->hBoxLayout = new \Qt\HBoxLayout();

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
        $this->widgets[] = $widget; // Store reference to prevent garbage collection
        $this->hBoxLayout->addWidget($widget->getQt());
    }

    public function addStretch(int $stretch = 0): void
    {
        $this->stretch ??= 0;
        $this->stretch += $stretch;
        $this->hBoxLayout->addStretch($stretch);
    }

    public function addSpacing(int $size): void
    {
        $this->spacing ??= 0;
        $this->spacing += $size;
        $this->hBoxLayout->addSpacing($size);
    }

    public function setSpacing(int $spacing): void
    {
        $this->spacing = $spacing;
        $this->hBoxLayout->setSpacing($spacing);
    }

    public function setContentsMargins(int $left, int $top, int $right, int $bottom): void
    {
        $this->marginLeft = $left;
        $this->marginTop = $top;
        $this->marginRight = $right;
        $this->marginBottom = $bottom;
        $this->hBoxLayout->setContentsMargins($left, $top, $right, $bottom);
    }

    public function getQt(): \Qt\HBoxLayout
    {
        return $this->hBoxLayout;
    }
}
