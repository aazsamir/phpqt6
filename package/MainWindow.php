<?php

declare(strict_types=1);

namespace Aazsamir\Qtlib;

class MainWindow
{
    private \Qt\MainWindow $mainWindow;
    private ?Widget $centralWidget = null;

    public function __construct(
        private string $title = '',
        private ?int $width = null,
        private ?int $height = null,
        ?Widget $parent = null,
    ) {
        $this->mainWindow = new \Qt\MainWindow($parent ? $parent->getQt() : null);

        if ($width !== null && $height !== null) {
            $this->mainWindow->resize($width, $height);
        }

        if ($title) {
            $this->mainWindow->setWindowTitle($title);
        }
    }

    public function show(): void
    {
        $this->mainWindow->show();
    }

    public function setWindowTitle(string $title): void
    {
        $this->title = $title;
        $this->mainWindow->setWindowTitle($title);
    }

    public function resize(int $width, int $height): void
    {
        $this->width = $width;
        $this->height = $height;
        $this->mainWindow->resize($width, $height);
    }

    public function setCentralWidget(Widget $widget): void
    {
        $this->centralWidget = $widget; // Store reference to prevent garbage collection
        $this->mainWindow->setCentralWidget($widget->getQt());
    }

    public function setStyleSheet(string $style): void
    {
        $this->mainWindow->setStyleSheet($style);
    }
}