#!/bin/bash

while getopts ":p:" opt; do
  case $opt in
    p)
      file_name="$OPTARG"
      ;;
    :)
      echo "Error: Option -$OPTARG requires an argument."
      exit 1
      ;;
    \?)
      echo "Error: Invalid option -$OPTARG."
      exit 1
      ;;
  esac
done

if [ -z "$file_name" ]; then
  echo "Usage: $0 -f <file_name>"
  exit 1
fi

if [ -f "$file_name" ]; then
  echo "Error: File '$file_name' already exists."
  exit 1
fi



mkdir ./${file_name};
mkdir ./${file_name}/res/;
touch ./${file_name}/${file_name}.txt;
touch ./${file_name}/${file_name}.cpp;
touch ./${file_name}/${file_name}.in;
touch ./${file_name}/${file_name}.out;
cd ./${file_name};

inFile="in.cc"
outFile="out.cc"
touch ./${inFile}
touch ./${outFile}
