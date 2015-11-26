#Assignment 1 positif power of positif numbers

.data
str1: .asciiz "result = "
str2: .asciiz "\n"
str3: .asciiz "welcome\n"

.text
main:	addi $sp, $sp, -4		# set the stack
		sw $ra, 0($sp)			# store return adress to stack		
		
		la $a0, str3
		li $v0, 4
#		syscall
		
		li $v0, 5				# input integer 1
		syscall
		move $s0, $v0

		li $v0, 5				# input integer 2
		syscall
		move $s1, $v0

		move $a0, $s0			# move integer to register $a0 and $a1
		move $a1, $s1

		jal powpos				# call function powpos
		move $t0, $v0			# save the return value into regiter $t0
		
		la $a0, str1			# print str 1
		li $v0, 4
		syscall

		li $v0, 1				# pritn the result value
		move $a0, $t0
		syscall

		la $a0, str2			# print "\n"
		li $v0, 4
		syscall

		lw $ra, 0($sp)
		addi $sp, $sp, 4
		jr $ra

powpos:	addi $sp, $sp, -4		# create l-word stack frame
		sw $ra, 0($sp)			# save return address
		move $t0, $a1			# c ($t0) = b
		addi $t1, $0, 1			# d ($t1)= 1
		#move $t1, $a0			# d($t1) = a
loop:	beq $t0, $0, end		# if c == 0, jump to end loop
		mult $t1, $a0			# d = d*a
		mflo $t1
		addi $t0, $t0, -1		# c = c-1
		j loop

end:	move $v0, $t1			# move value to return
		lw $ra, 0($sp)			# load return address
		addi $sp, $sp, 4		# adjust stack pointer
		jr $ra					# jump to return address

