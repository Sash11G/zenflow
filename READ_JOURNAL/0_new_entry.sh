#!/bin/bash

READ_JOURNAL="$HOME/zenflow/READ_JOURNAL"

# Get subdirectories
mapfile -t dirs < <(find "$READ_JOURNAL" -mindepth 1 -maxdepth 1 -type d | sort)
if [ ${#dirs[@]} -eq 0 ]; then
    echo "No subdirectories found in $READ_JOURNAL."
    exit 1
fi

# Display dirs with indexes
echo "Select a directory:"
for i in "${!dirs[@]}"; do
    name=$(basename "${dirs[$i]}")
    printf "[%d] %s\n" "$i" "$name"
done

# Prompt
read -p "Enter index: " index

# Validate input
if ! [[ "$index" =~ ^[0-9]+$ ]] || [ "$index" -ge "${#dirs[@]}" ]; then
    echo "Invalid index."
    exit 1
fi

# Get selected dir name
dir=$(basename "${dirs[$index]}")
BASE_DIR="$READ_JOURNAL/$dir"

# Month subdirectory
month_dir="$(date '+%Y-%m')"
MONTH_PATH="$BASE_DIR/$month_dir"
mkdir -p "$MONTH_PATH"

# File name and path
today="$(date '+%Y-%m-%d')"
filename="${today}_${dir}.txt"
FILEPATH="$MONTH_PATH/$filename"

# Create file if new
if [ ! -f "$FILEPATH" ]; then
    {
        date
        echo ""
        echo "Log for $dir on $today"
        echo ""
        echo ""
    } > "$FILEPATH"
fi

# Open with editor
nvim + "$FILEPATH"


