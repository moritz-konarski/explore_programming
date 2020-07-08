#!/bin/bash

cd ./build
latexmk -pdf ../note_collection.tex
cd ..
cp ./build/note_collection.pdf ../
