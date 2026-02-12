<?php

declare(strict_types=1);

namespace Aazsamir\Qtlib;

interface WidgetInterface
{
    public function show(): void;
    public function hide(): void;
    public function setStyleSheet(string $style): void;
    public function getQt(): mixed;
}
