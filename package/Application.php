<?php

declare(strict_types=1);

namespace Aazsamir\Qtlib;

use Aazsamir\Qtlib\Exception\ApplicationNotInitialized;

class Application
{
    private static \Qt\Application $application;

    public static function init(array $args = []): void
    {
        self::$application = new \Qt\Application($args);
    }

    public static function exec(): int
    {
        if (!isset(self::$application)) {
            throw new ApplicationNotInitialized();
        }

        return self::$application->exec();
    }

    public static function quit(): void
    {
        if (!isset(self::$application)) {
            return;
        }

        self::$application->quit();
    }
}
