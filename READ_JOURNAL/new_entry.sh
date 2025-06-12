#!/bin/bash


read -p "Enter directory name: " dir
mkdir -p "$HOME/$dir"

echo "Directory ensured: $HOME/$dir"
JOURNAL_DIR="$HOME/zenflow/READ_JOURNAL/caffein_log"

# Get the next available number by finding the max and adding 1
last_number=$(find "$JOURNAL_DIR" -name "day_*.txt" | sed -E 's/.*day_([0-9]+)\.txt/\1/' | sort -n | tail -n 1)
next_number=$((last_number + 1))

# Format the filename
filename="day_${next_number}.txt"
filepath="${JOURNAL_DIR}/${filename}"

# Create the new file with the header
{
    date
    echo ""
    echo "Day ${next_number}:"
    echo ""
} > "$filepath"

# Open it with your editor (e.g., nvim)
nvim "$filepath"
