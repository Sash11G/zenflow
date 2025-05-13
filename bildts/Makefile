
# Compiler and settings
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Directory paths
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = test
LOG_DIR = logs

# Default target — shows usage instructions
all:
	@echo "Usage:"
	@echo "  make build FILE=<name>    - compile src/<name>.c to object file"
	@echo "  make test FILE=<name>     - build and run test/test_<name>.c"
	@echo "  make clean                - remove build and log files"
	@echo "  make clean_logs           - remove only logs"

# Build a single .c file into a .o file
build:
	@mkdir -p $(BUILD_DIR) $(LOG_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(FILE).c -o $(BUILD_DIR)/$(FILE).o
	@echo "Built: $(FILE).o at $$(date +'%Y-%m-%d %H:%M:%S')" | tee -a $(LOG_DIR)/build.log

# Build and run a test for the given FILE
test:
	@mkdir -p $(BUILD_DIR) $(LOG_DIR)
	@if [ ! -f $(TEST_DIR)/test_$(FILE).c ]; then \
		echo '// Auto-created test file for $(FILE)' > $(TEST_DIR)/test_$(FILE).c; \
		echo '#include <stdio.h>' >> $(TEST_DIR)/test_$(FILE).c; \
		echo 'int main() { printf("Test $(FILE)\\n"); return 0; }' >> $(TEST_DIR)/test_$(FILE).c; \
		echo "Created stub: test/test_$(FILE).c"; \
		echo "You can now edit it to test your function."; \
	fi
	$(CC) $(CFLAGS) $(SRC_DIR)/$(FILE).c $(TEST_DIR)/test_$(FILE).c -o $(BUILD_DIR)/test_$(FILE)
	@echo "Test built: $(FILE) at $$(date +'%Y-%m-%d %H:%M:%S')" | tee -a $(LOG_DIR)/build.log
	@echo "Running test for $(FILE)..."
	@./$(BUILD_DIR)/test_$(FILE)

# Remove all build files and logs
clean:
	rm -rf $(BUILD_DIR)/* $(LOG_DIR)/*

# Remove only logs
clean_logs:
	rm -f $(LOG_DIR)/*.log


.PHONY: all build test clean clean_logs
