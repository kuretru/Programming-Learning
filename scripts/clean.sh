#!/bin/sh

old_dir=$(find . -name *.dSYM -type d -print | wc -l)
old_file=$(find . -name *.out -type f -print | wc -l)
find . -name *.dSYM -type d -exec rm -rf {} \; >/dev/null 2>&1
find . -name *.out -type f -exec rm -rf {} \; >/dev/null 2>&1
new_dir=$(find . -name *.dSYM -type d -print | wc -l)
new_file=$(find . -name *.out -type f -print | wc -l)

echo "finished"
echo "cleand $((old_dir - new_dir))/$((old_dir)) directories"
echo "cleand $((old_file - new_file))/$((old_file)) files"
