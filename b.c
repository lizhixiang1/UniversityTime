#!/bin/sh
asd

if [ $# -lt 2 ]; then
    echo "Usage: $0 <compile|run|build> <name>"
    exit 1
fi

command=$1
name=${2%.c}

case $command in
    compile)
        if [ ! -e "$name.c" ]; then
            echo "Error: $name.c does not exist"
            exit 1
        fi
        gcc -Wall -std=c11 -g "$name.c" -o "$name"
        ;;
    run)
        if [ ! -x "$name" ]; then
            echo "Error: $name does not exist or is not executable"
            exit 1
        fi
        ./"$name"
        ;;
    build)
        if [ ! -e "$name.c" ]; then
            echo "Error: $name.c does not exist"
            exit 1
        fi
        gcc -Wall -std=c11 -g "$name.c" -o "$name" && ./"$name"
        ;;
    *)
        echo "Usage: $0 <compile|run|build> <name>"
        exit 1
        ;;
esac
