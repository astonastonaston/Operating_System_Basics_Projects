main: main.cu virtual_memory.cu user_program.cu virtual_memory.h
	nvcc --relocatable-device-code=true main.cu virtual_memory.cu user_program.cu -o main.out
clean: 
	rm -rf main.out
