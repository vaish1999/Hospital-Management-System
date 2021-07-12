# comments

#Target : dependency
#<TAB>Command

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
	gcc -I $(INC) $(SRC) -lncurses  -o a.out 
	
	
run :
	./a.out

#test:
#	gcc -I $(INC_H) -I $(INC_T) $(TEST_SRC) $(SRC) -o $(call FixPath,$(PROJECT_NAME))
#	./$(call FixPath,$(PROJECT_NAME))

#to delete all the exe files	
clean :
	rm -rf *exe
#del /q .exe didnt work
