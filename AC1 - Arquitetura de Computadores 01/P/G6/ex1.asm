	.data
	
	.eqv SIZE, 3
	.eqv print_string, 4
	.eqv print_char, 11
	
str1:	.asciiz "Array"
str2:	.asciiz "de"
str3:	.asciiz "ponteiros"
array:	.word str1, str2, str3
	
	.text
	.globl main

main:	li	$t0, 0

for:	bge	$t0, SIZE, efor

	la	$t1, array
	
	sll	$t2, $t0, 2
	addu	$t2, $t2, $t1 	
	
	lw	$a0, 0($t2)
	li	$v0, print_string
	syscall
	
	li	$a0, '\n'
	li	$v0, print_char
	syscall

	addi	$t0, $t0, 1
	
	j	for

efor:	jr	$ra

# i:	$t0
# array:	$t1
# ck:	$t2
#
#define SIZE 3
#void main(void) {
#	static char *array[SIZE]={"Array", "de", "ponteiros"};
#	int i;
#	for(i=0; i < SIZE; i++) {
#		print_str(array[i]);
#		print_char('\n');
#	}
#}
