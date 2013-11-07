TARGET = cea
CFLAGS = -ansi -Wall -Wextra -Wpedantic -O2

# Scan the directory for *.c filenames and transform them into *.o
OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c))

# Link
$(TARGET): $(OBJECTS)
	gcc $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Pull in dependency info for existing .o files
-include $(OBJECTS:.o=.d)

# Compile and produce dependency files with added phony targets
%.o: %.c
	gcc -c -MMD -MP $(CFLAGS) -o $@ $<

# Clean
.PHONY: clean
clean:
	rm -f $(TARGET) *.o *.d
