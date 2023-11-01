#!/bin/bash

# Check if the folder name is provided as an argument
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <folder_name>"
  exit 1
fi

# Extract the folder name from the argument
folder_name="$1"

# Check if the folder already exists
if [ -d "$folder_name" ]; then
  echo "Folder '$folder_name' already exists."
  exit 1
fi

# Create the folder
mkdir "$folder_name"
if [ $? -ne 0 ]; then
  echo "Failed to create the folder."
  exit 1
fi

# Create the files within the folder
touch "$folder_name/problem.sql"
touch "$folder_name/in.txt"
touch "$folder_name/out.txt"

# Check if the files were created successfully
if [ $? -eq 0 ]; then
  echo "Folder '$folder_name' with files created successfully."
else
  echo "Failed to create one or more files."
fi
