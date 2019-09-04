#!/bin/sh

find .. -name *.dSYM -type d -print -exec rm -rf {} \;
find .. -name *.out -type f -print -exec rm -rf {} \;
