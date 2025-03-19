CC=gcc
ED=vim
SRC=src/main
DEPS=src/headers
BUILD=build

$(BUILD)/godforma: $(SRC)/godforma.c $(SRC)/find.c $(BUILD)
	$(CC) -o $@ $< $(SRC)/find.c -I $(DEPS) 
debug: $(SRC)/godforma.c $(BUILD)
	$(CC) -o $(BUILD)/godforma $< -I $(DEPS) -g
clean:
	rm -rf $(BUILD)
work: 
	$(ED) $(SRC) 
$(BUILD):
	mkdir -pv $@
