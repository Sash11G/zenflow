
#!/bin/bash

read -p "Enter subdirectory in READ_JOURNAL: " dir
BASE_DIR="$HOME/zenflow/READ_JOURNAL/$dir"

# Error if directory doesn't exist
if [ ! -d "$BASE_DIR" ]; then
    echo "Error: Directory '$BASE_DIR' does not exist."
    exit 1
fi

# Create monthly subdirectory if needed
month_dir="$(date '+%Y-%m')"
MONTH_PATH="$BASE_DIR/$month_dir"
mkdir -p "$MONTH_PATH"

# Generate filename with directory name included
today="$(date '+%Y-%m-%d')"
filename="${today}_${dir}.txt"
FILEPATH="$MONTH_PATH/$filename"

# If the file doesn't exist, create it with header
if [ ! -f "$FILEPATH" ]; then
    {
        date
        echo ""
        echo "Log for $dir on $today"
        echo ""
    } > "$FILEPATH"
fi

# Open the file
nvim "$FILEPATH"

