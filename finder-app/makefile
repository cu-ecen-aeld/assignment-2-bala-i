# Variables
CC := gcc
CFLAGS := -Wall -Wextra -Werror
CROSS_COMPILE ?=
TARGET := writer

# Sources and objects
SRCS := writer.c
OBJS := $(SRCS:.c=.o)

# Default target
.PHONY: all
all: $(TARGET)

# Target for the writer application
$(TARGET): $(OBJS)
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -o $@ $^

# Compile object files
%.o: %.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -c $< -o $@

# Clean target
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)

# Cross-compilation
.PHONY: cross
cross: CROSS_COMPILE := aarch64-none-linux-gnu-
cross: clean all
