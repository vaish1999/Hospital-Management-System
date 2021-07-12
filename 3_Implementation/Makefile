# comments

#Target : dependency
#<TAB>Command
ifeq ($(OS), Windows_NT)
	EXECUTABLE=a.exe
else
	EXECUTABLE=a.out
endif




PROJECT_NAME = 3_Implementation
TEST_PROJ_NAME = Test_$(PROJ_NAME)


SRC = hospital.c\
src/Add_rec.c\
src/Dlt_rec.c\
src/Edit_rec.c\
src/ex_it.c\
src/func_list.c\
src/Search_rec.c\
src/Title.c

INC = inc

$(PROJECT_NAME):$(SRC)
	gcc -I $(INC) $(SRC) -lncurses  -o $(EXECUTABLE) 
	
	
run :
	./$(EXECUTABLE)


doc:
	make -C ./documentation

# Build and run the unit tests
# $(INCLUDE_LIBS) 
test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) 
	./$(TEST_OUTPUT)

analyze: test memcheck staticcheck coverage sanitize_check

staticcheck:
	cppcheck --enable=all -iunity .

memcheck:
	valgrind ./$(TEST_OUTPUT)

sanitize_check:
	gcc -fsanitize=address -fno-omit-frame-pointer $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) $(INCLUDE_LIBS)
	./$(TEST_OUTPUT)

coverage:$(TEST_SRC)
	gcc -fprofile-arcs -ftest-coverage $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) $(INCLUDE_LIBS)
	./$(TEST_OUTPUT)
	gcov -a calculator_operations.c

#test:
#	gcc -I $(INC_H) -I $(INC_T) $(TEST_SRC) $(SRC) -o $(call FixPath,$(PROJECT_NAME))
#	./$(call FixPath,$(PROJECT_NAME))

#to delete all the exe files	
clean :
	rm -rf *exe
#del /q .exe didnt work
