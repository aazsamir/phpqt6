<?php

declare(strict_types=1);

namespace Aazsamir\Qtlib\Exception;

class ApplicationNotInitialized extends \Exception
{
    public function __construct()
    {
        parent::__construct('Application not initialized. Call Application::init() before exec().');
    }
}