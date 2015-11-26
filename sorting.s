# sorting
.data
	x: .word 4
	y: .word 7
	i: .word 10
	array: .space 6
	array2: .word 45, 98, 2, 1, 2, 3
	str1: .asciiz "Give 6 numbers: "
	str2: .asciiz "\n"
	output: .asciiz "\n\nSorted numbers are: "
	output2: .asciiz " "
.text
main: 	addi $sp, $sp, -4		# set the stack
		sw $ra, 0($sp)			# store return adress to stack
		la $s0, array


		la $a0, str1
		li $v0, 4
		syscall

		move $t0, $zero			# i= 0
		addu $t1, $zero, 6		# limit 5
		

init:	beq $t0, $t1, endit
		move $t2, $t0			# i for address= i
		li $v0, 5				# input integer
		syscall
		move $s1, $v0
		add $t2, $t2, $t2
		add $t2, $t2, $t2		# i * 4
		add $t2, $t2, $s0		# i + initial address
		
		move $a0, $s1
		li $v0, 1
		syscall

		la $a0, output2
		li $v0, 4
		syscall

		sw $s1, 0($t2)			# store in the array
		addu $t0, $t0, 1
		j init

endit:	

##########################################
############# for loop print #########
#		move $t0, $zero			# i= 0
#		addu $t1, $zero, 6		# limit 6

#printo:	beq $t0, $t1, eprino
#		move $t2, $t0			# i for address= i

#		add $t2, $t2, $t2
#		add $t2, $t2, $t2		# i * 4
#		add $t2, $t2, $s0		# i + initial address
		
#		lw $s2, 0($t2)			# load in the array 
#		li $v0, 1
#		move $a0, $s2
#		syscall

#		la $a0, str2
#		li $v0, 4
#		syscall

#		addu $t0, $t0, 1
#		j printo
	

#eprino:	#lw $ra, 0($sp)
		#addi $sp, $sp, 4
		#jr $ra
##########################################		

		#addu $a0, $t6, 1 		# $a0 = 1
#		add $a1, $t7, 1 		# $a1 = 6
		move $t6, $zero			# i= 0
		addu $t7, $zero, 5		# limit 5

again:	beq $t6, $t7, endag
		move $a0, $t6
		addu $a1, $t7, 1 		# $a1 = 6
		jal minidx
		move $t0, $v0
#		addu $a0, $t6, 1
		move $a0, $t6
		move $a1, $t0
		jal swap
		addu $t6, $t6, 1
		j again


endag:

############# for loop print #########
		la $a0, output
		li $v0, 4
		syscall

		move $t0, $zero			# i= 0
		addu $t1, $zero, 6		# limit 6
#		la $s3, array

print:	beq $t0, $t1, eprin
		move $t2, $t0			# i for address= i

		add $t2, $t2, $t2
		add $t2, $t2, $t2		# i * 4
		add $t2, $t2, $s0		# i + initial address
		
		lw $s2, 0($t2)			# load in the array 
		li $v0, 1
		move $a0, $s2
		syscall

		la $a0, output2
		li $v0, 4
		syscall

		addu $t0, $t0, 1
		j print
	

eprin:	lw $ra, 0($sp)
		addi $sp, $sp, 4
		jr $ra

################################################################
swap:	addi $sp, $sp, -4
		sw $ra, 0($sp)

		#get the arguments of the function
		la $s0, array			# get array address for index 0
		move $t1, $a0			# get the argument i
		move $t2, $a1			# get the argument k

		add $t1, $t1, $t1 
		add $t1, $t1, $t1		# 4 * x

		add $t2, $t2, $t2
		add $t2, $t2, $t2		# 4 * y

		add $t1, $t1, $s0		# address of element with index x
		add $t2, $t2, $s0		# address of element woth index y

		lw $t3, 0($t1)			# fetch element of index x
		lw $t4, 0($t2)			# fetch element of index y

#		li $v0, 1 				# print
#		move $a0, $t3
#		syscall
#		li $v0, 1
#		move $a0, $t4
#		syscall

		sw $t3, 0($t2)			# swap
		sw $t4, 0($t1)

		lw $t3, 0($t1)			# fetch element of index x
		lw $t4, 0($t2)			# fetch element of index y

#		li $v0, 1 				# print
#		move $a0, $t3
#		syscall
#		li $v0, 1
#		move $a0, $t4
#		syscall

		lw $ra, 0($sp)
		addi $sp, $sp, 4
		jr $ra

#################################################################
minidx:	addi $sp, $sp, -4
		sw $ra, 0($sp)

		la $s0, array
		move $t0, $a0			# $t0= mini= k
		move $t4, $a1			# $t4=n

		add $t1, $t0, $t0
		add $t1, $t1, $t1		# $t1 = 4 * index k
		add $t1, $t1, $s0		# address of index k
		lw $t2, 0($t1)			# get v[k]

		move $t5, $t2			# $t5= min
		addu $t3, $t0, 1 		# $t3= i= k + 1

loop:	beq $t3, $t4, end		# i < n
		add $t1, $t3, $t3
		add $t1, $t1, $t1		# $t1 = 4 * index k
		add $t1, $t1, $s0		# address of index k
		lw $t2, 0($t1)			# get v[i]
		bge $t2, $t5, inc		# v[i]< min
		move $t0, $t3
		move $t5, $t2

inc	:	addu $t3, $t3, 1
		j loop


end:	move $v0,$t0
		lw $ra, 0($sp)
		addi $sp, $sp, 4
		jr $ra	
