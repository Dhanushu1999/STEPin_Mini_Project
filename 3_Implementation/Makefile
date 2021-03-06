PROJ_NAME = RecordMangement
TEST_PROJ_NAME = Test_$(PROJ_NAME)

BUILD_DIR = Build

SRC = src/addrecord.c\
src/deleterecord.c\
src/displayrecord.c\
src/modifyrecord.c

TEST_SRC =test/recordmanagement_test.c\
unity/unity.c\

INC = -Iinc\
-Iunity 

# Document files1
DOCUMENTATION_OUTPUT = documentation/html

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out 
   endif
endif

# Makefile will not run target command if the name with file already exists. To override, use .PHONY
.PHONY : all test coverage run clean doc

all:$(BUILD_DIR)
	gcc recordmanagement.c $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

test:
	gcc $(INC) $(SRC) $(TEST_SRC) -o $(call FixPath,$(TEST_PROJ_NAME).$(EXEC))
	./$(call FixPath,$(TEST_PROJ_NAME).$(EXEC))

staticcheck:
	cppcheck --enable=all $(SRC) recordmanagement.c 

memcheck:
	valgrind ./$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

coverage:${PROJECT_NAME}
	gcc -fprofile-arcs -ftest-coverage $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(TEST_PROJ_NAME).$(EXEC)) 
	$(call FixPath,./$(TEST_PROJ_NAME).$(EXEC))
	gcov -a recordmanagement_test.c 
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov 

doc:
	make -C ./documentation
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
	rm -rf $(DOCUMENTATION_OUTPUT)
