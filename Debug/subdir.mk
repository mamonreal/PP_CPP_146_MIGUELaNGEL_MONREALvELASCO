################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Catalogo.cpp \
../Contenido.cpp \
../Documental.cpp \
../Episodio.cpp \
../Pelicula.cpp \
../Serie.cpp \
../Temporada.cpp \
../main.cpp 

OBJS += \
./Catalogo.o \
./Contenido.o \
./Documental.o \
./Episodio.o \
./Pelicula.o \
./Serie.o \
./Temporada.o \
./main.o 

CPP_DEPS += \
./Catalogo.d \
./Contenido.d \
./Documental.d \
./Episodio.d \
./Pelicula.d \
./Serie.d \
./Temporada.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


