#!/usr/bin/env php
<?php
/**
 * Qt6 PHP Extension Stub Generator
 * 
 * This script generates IDE stub files from the compiled qt6 extension.
 * Run: php generate_stubs.php > stubs/qt6.stub.php
 */

if (!extension_loaded('phpqt6')) {
    fwrite(STDERR, "Error: phpqt6 extension not loaded\n");
    fwrite(STDERR, "Load it with: php -d extension=phpqt6.so {$argv[0]}\n");
    exit(1);
}

echo "<?php\n";
echo "/**\n";
echo " * phpqt6 Extension Stubs\n";
echo " * \n";
echo " * This file provides IDE autocomplete and type hinting for the phpqt6 extension.\n";
echo " * DO NOT include this file in your project - it's for IDE reference only.\n";
echo " * \n";
echo " * @see https://github.com/aazsamir/phpqt6\n";
echo " */\n\n";

// Get all classes from the phpqt6 extension
$classes = [];
foreach (get_declared_classes() as $class) {
    if (strpos($class, 'Qt\\') === 0) {
        $classes[] = $class;
    }
}

sort($classes);

echo "namespace Qt {\n\n";

foreach ($classes as $fullClassName) {
    $reflection = new ReflectionClass($fullClassName);
    $shortName = $reflection->getShortName();
    
    // Class docblock
    echo "    /**\n";
    echo "     * Class {$shortName}\n";
    echo "     * @package Qt\n";
    echo "     */\n";
    
    // Class declaration
    echo "    class {$shortName}\n";
    echo "    {\n";
    
    // Methods
    $methods = $reflection->getMethods();
    foreach ($methods as $method) {
        if (!$method->isPublic()) {
            continue;
        }
        
        echo "\n";
        echo "        /**\n";
        echo "         * {$method->getName()}\n";
        
        // Parameters
        $params = $method->getParameters();
        foreach ($params as $param) {
            $paramType = $param->getType();
            if (!$paramType) {
                $typeStr = 'mixed';
            } elseif ($paramType instanceof ReflectionUnionType) {
                // Handle union types (e.g., VBoxLayout|HBoxLayout)
                $types = [];
                foreach ($paramType->getTypes() as $type) {
                    $name = $type->getName();
                    // Remove Qt\ prefix since we're inside namespace Qt {}
                    if (strpos($name, 'Qt\\') === 0) {
                        $name = substr($name, 3);
                    }
                    $types[] = $name;
                }
                $typeStr = implode('|', $types);
            } else {
                $typeStr = $paramType->getName();
                // Remove Qt\ prefix since we're inside namespace Qt {}
                if (strpos($typeStr, 'Qt\\') === 0) {
                    $typeStr = substr($typeStr, 3);
                }
            }
            $defaultStr = '';
            if ($param->isDefaultValueAvailable()) {
                $default = $param->getDefaultValue();
                if (is_array($default)) {
                    $defaultStr = ' = []';
                } elseif (is_null($default)) {
                    $defaultStr = ' = null';
                } elseif (is_string($default)) {
                    $defaultStr = " = '" . addslashes($default) . "'";
                } elseif (is_bool($default)) {
                    $defaultStr = $default ? ' = true' : ' = false';
                } else {
                    $defaultStr = ' = ' . $default;
                }
            } elseif ($param->allowsNull()) {
                $defaultStr = ' = null';
            }
            echo "         * @param {$typeStr} \${$param->getName()}{$defaultStr}\n";
        }
        
        // Return type
        $returnType = $method->getReturnType();
        if ($returnType) {
            echo "         * @return {$returnType->getName()}\n";
        } else {
            echo "         * @return void\n";
        }
        
        echo "         */\n";
        
        // Method signature
        echo "        ";
        if ($method->isStatic()) {
            echo "public static ";
        } else {
            echo "public ";
        }
        
        echo "function {$method->getName()}(";
        
        $paramStrings = [];
        foreach ($params as $param) {
            $paramStr = '';
            $paramType = $param->getType();
            
            if ($paramType) {
                if ($paramType instanceof ReflectionUnionType) {
                    // Handle union types
                    $types = [];
                    foreach ($paramType->getTypes() as $type) {
                        $name = $type->getName();
                        // Remove Qt\ prefix since we're inside namespace Qt {}
                        if (strpos($name, 'Qt\\') === 0) {
                            $name = substr($name, 3);
                        }
                        $types[] = $name;
                    }
                    $paramStr .= implode('|', $types) . ' ';
                } else {
                    $typeName = $paramType->getName();
                    // Remove Qt\ prefix since we're inside namespace Qt {}
                    if (strpos($typeName, 'Qt\\') === 0) {
                        $typeName = substr($typeName, 3);
                    }
                    if ($paramType->allowsNull() && !$paramType->isBuiltin()) {
                        $paramStr .= '?';
                    }
                    $paramStr .= $typeName . ' ';
                }
            }
            
            $paramStr .= '$' . $param->getName();
            
            if ($param->isDefaultValueAvailable()) {
                $default = $param->getDefaultValue();
                if (is_array($default)) {
                    $paramStr .= ' = []';
                } elseif (is_null($default)) {
                    $paramStr .= ' = null';
                } elseif (is_string($default)) {
                    $paramStr .= ' = ' . var_export($default, true);
                } else {
                    $paramStr .= ' = ' . var_export($default, true);
                }
            } elseif ($param->isOptional()) {
                $paramStr .= ' = null';
            }
            
            $paramStrings[] = $paramStr;
        }
        
        echo implode(', ', $paramStrings);
        echo ")";
        
        // Return type hint
        if ($returnType) {
            $returnTypeName = $returnType->getName();
            // Remove Qt\ prefix since we're inside namespace Qt {}
            if (strpos($returnTypeName, 'Qt\\') === 0) {
                $returnTypeName = substr($returnTypeName, 3);
            }
            echo ": {$returnTypeName}";
        }
        
        echo " {}\n";
    }
    
    echo "    }\n\n";
}

echo "}\n";

fwrite(STDERR, "\n✓ Generated stubs for " . count($classes) . " classes\n");
fwrite(STDERR, "Save to: stubs/qt6.stub.php\n");
