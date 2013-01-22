################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/STACK.cpp \
../sources/STACK2.cpp \
../sources/postfix.cpp \
../sources/stack.cpp 

OBJS += \
./sources/STACK.o \
./sources/STACK2.o \
./sources/postfix.o \
./sources/stack.o 

CPP_DEPS += \
./sources/STACK.d \
./sources/STACK2.d \
./sources/postfix.d \
./sources/stack.d 


# Each subdirectory must supply rules for building sources it contributes
sources/%.o: ../sources/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


