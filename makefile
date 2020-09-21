CC = g++
CFLAGS = -Wall
OUTDIR = ./out/

# naively compile all of the modules into separate files in the out directory

all:
	mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) -o $(OUTDIR)1_1_about_me module_1/ex_01.cpp
	$(CC) $(CFLAGS) -o $(OUTDIR)1_2_pyramid module_1/ex_02.cpp
	$(CC) $(CFLAGS) -o $(OUTDIR)2_bank_account module_2/*.cpp
	$(CC) $(CFLAGS) -o $(OUTDIR)3_sequence_test module_3/*.cpp
	$(CC) $(CFLAGS) -o $(OUTDIR)4_polynomial_exam module_4/{poly0,polyexam0}.cpp
	$(CC) $(CFLAGS) -o $(OUTDIR)4_polynomial_test module_4/{poly0,polytest0}.cpp
	$(CC) $(CFLAGS) -o $(OUTDIR)5_linked_list_demo module_5/*.cpp

clean:
	rm -r $(OUTDIR)